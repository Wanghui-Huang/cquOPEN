# include <stdio.h> 
# include <string.h> 
#include <stdlib.h>
//读文件中给出的一段英文，分隔符为空格，英文逗号，句号，，要求记录每个单词出现的次数，并且按次数输出单词 

#define SIZE 50
#define N 100
int * sort (char *s1[SIZE]);
void mycopy (char s[][SIZE],char *str,int index,int tail,int cnt);
void divide(char s[][SIZE],char *str);

int cnt=0;//单词的个数 

int main (){
	
	FILE *in;
	char str[N];
	char s[SIZE][SIZE];
	char *s1[SIZE]; 
	int *ret;
	
	int i,j,max,index_p;
		
	in=fopen("filename.txt","r");
	
	fgets(str,N,in); 
	
	puts(str);
	
	divide(s,str);
	
	for(i=0;i<SIZE;i++){
		s1[i]=NULL;
	} 
	
	for (i=1;i<cnt;i++){
		s1[i]=s[i];
	}
	
	ret=sort(s1);
	
	for(i=0;i<cnt;i++){
		max=ret[0];
		index_p=0;
		for(j=1;j<cnt;j++){
			if(ret[j]>max){
				max=ret[j];
				index_p=j;
			}	
		}
		if(ret[index_p]>0){
			printf("%s",s1[index_p]);
			ret[index_p]=0;
		}
		
	} 
	
	return 0;
}

void divide(char s[][SIZE],char *str){
	
	char ch;
	int index;
	int i;
	int len;
	int flag=0;
	int cnt=0;   //单词的个数
	
	len=strlen(str);
	
	for(i=0;i<len;i++){
		ch=str[i];
		if(ch==' '||ch==','||ch=='.'){
			if(flag==1){
				cnt++;
				mycopy(s,str,index,i,cnt-1);	//将这个单词存入二维数组 
				flag=0;							//单词开始标志 置0 
			}
		
		}else{
			
			if(flag==0){
				flag=1;							//单词开始标志 置1
				index=i;						//index 表示单词的第一个字母 
			}
		} 
		
		
		
	}
}


void mycopy (char s[][SIZE],char *str,int index,int tail,int cnt){
	
	int i;
	int j=0;		//二维数组的列号 
	i=index;
	
	for (i=index;i<tail;i++){
		s[cnt][j]=str[i];
		j++;
	}
		
}


int * sort (char *s1[SIZE]){
	
	int *ret=(int *)malloc(sizeof(int)*cnt);
	memset(ret,0,sizeof(int)*cnt);
	 
	int i,j;
	char *t;
	
	for(i=0;i<cnt;i++){
		if(s1[i]!=NULL){
			for(j=i+1;j<cnt;j++){
				if(strcmp(s1[i],s1[j])==0){
					ret[i]++;
					s1[j]=NULL;
				}
			}
		}
	}
	
	
	
}




