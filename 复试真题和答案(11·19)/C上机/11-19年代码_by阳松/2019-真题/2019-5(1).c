# include <stdio.h>
#include <string.h>
#include <stdlib.h>

//读文件中给出的一段英文，分隔符为空格，英文逗号，句号，，要求记录每个单词出现的次数，并且按次数输出单词 

#define N 200		//N 表示str 字符数组的容量 
#define SIZE 20		//SIZE 表示 字符指针数组的 长度，即单词的个数 容量，同时也是单个单词长度的容量		

void mycopy (char *s[SIZE],int cnt,char *str,int head,int tail);
int divide (char *s[SIZE],char *str);

void count_words(int *a,char* s[SIZE],int cnt);

typedef struct word{
	char *s;				//指向单词的 字符指针 
	int conut;			// 单词出现的频率 
	
}word;
 
int main (){
	
	char str[N];
	char *s[SIZE];		//字符指针数值 容量为 SIZE  
	FILE *fin;			//文件指针
	int a[SIZE];		// 数组 a 中存储了单词的统计次数  其中 i 表示单词的下标，a[i] 表示下标为 i 的单词出现的此时 
	
	word w[SIZE];		//结构体数组  
	word temp;
	int i;
	int j;
	int cnt_1;
	 
	int cnt;			//单词个数 
	fin=fopen("filename.txt","r");
	
	fgets(str,N,fin);
	
//	puts(str);			//输出从文件读出的一段英文 
	
	cnt=divide(s,str);		//将str 中的一段英文 拆分为单词 存入 字符指针数组中 
	
	printf("%d\n",cnt);
	
//	for(i=0;i<cnt;i++){
//		printf("%s\n",s[i]);
//	} 
	
	count_words(a,s,cnt);	//进行 单词计数 		//“这个函数有大问题” 
	
	for(i=0,j=0;i<cnt;i++){
		if(a[i]>0){
			w[j].s =s[i];
			w[j].conut =a[i];
			j++	;
		}
	}
	//进行输出 
	cnt_1=j;				//没有重复的单词数 
	
	for(i=cnt_1-1;i>0;i--){
		for(j=0;j<i;j++){
			if(w[j].conut >w[j+1].conut ){
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
			}
		}
	}
	
	for(i=cnt_1-1;i>=0;i--){
		printf("%s\t\t%d\n",w[i].s ,w[i].conut );
	}

	
	return 0;
} 

int divide (char *s[SIZE],char *str){		//divide 函数的返回值是切分单词的个数 
	
	int i;
	int len;
	int flag=0;		//flag==1 代表当前正在读取一个单词， flag==0 代表当前没有读取一个单词 //flag 默认置为 ‘1’ 
	int cnt=0;		//cnt 表示单词个数 	初始单词数为0 
	int index;		//代表单词的开头字母在str中的下标 
	len=strlen(str);
	
	for(i=0;i<len;i++){
		if(str[i]==' '||str[i]==','||str[i]=='.'){
			if(flag==1){
				//代表一个单词结束 
				cnt++; 
				mycopy(s,cnt,str,index,i); 		//调用mycopy函数 将当前单词复制到字符指针数组中 
				flag=0;
			}
		}else{
			if(flag==0){
				//代表一个单词开始 
				index=i;
				flag=1;
			}
		} 
	} 

	return cnt;	
}

void mycopy (char *s[SIZE],int cnt,char *str,int head,int tail){		//mycopy 函数将divide函数切分的单词 复制到字符指针数组中 
	
	char *ret; 
	int i,j=0;
	ret=(char*)malloc(sizeof(char)*SIZE);
	
	for(i=head;i<tail;i++){
		ret[j++]=str[i];
	} 
	ret[j]='\0';
	
	s[cnt-1]=ret;
} 


//这个函数从字符指针数组中统计单词出现的次数，并将统计结果存入 int 数组中

void count_words(int *a,char* s[SIZE],int cnt){
	
	int i,j;
	
	char * aux[cnt];
	
	for(i=0;i<cnt;i++){
		aux[i]=s[i];		//将字符指针数组，复制一个备份 
	}
	

	
	for(i=0;i<cnt;i++){
		a[i]=0;				//将统计单词出现次数的数组 a 初始化为 0  
		if(strcmp(aux[i],"-1")!=0){		//先判断该单词是否已经统计过，如果为 NULL 则为统计过的单词 
			a[i]++;
			for (j=i+1;j<cnt;j++){
				if(strcmp(aux[i],aux[j])==0){				// "segmentation fault"   "strcmp () 输入的参数不能为NULL"
					a[i]++;
					strcpy(aux[j],"-1"); 
				}
			}	
		}
		
	}
//程序结束 
} 

 
