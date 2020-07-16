# include <stdio.h>
# include <string.h>
#include <stdlib.h>

#define N 200
#define SIZE 20
typedef struct word{
	char str[SIZE];				//指向单词的 字符指针 
	int count;			// 单词出现的频率 
	
}Word;

int divide (char *str,int len,Word *s[SIZE]);
void word_count (Word *s[SIZE],int cnt);
void sort (Word *s[SIZE],int cnt);



int main (){
	
	char str[N];
	Word *s[SIZE];
	int i,len;
	int cnt=0;//单词个数 
	
	FILE *fin;
	fin=fopen("filename.txt","r");
	
	fgets(str,N,fin);
	
	len=strlen(str);
	
	for(i=0;i<len;i++){
		if(str[i]==' '||str[i]==','||str[i]=='.'){
			str[i]='\0';
		}
	}
	
	cnt=divide (str,len,s);
	word_count (s,cnt);
	sort (s,cnt);
	//输出
	
	
	for(i=cnt-1;i>=0;i--){
		if(s[i]->count >0){
			printf("%s\t%d\n",s[i]->str ,s[i]->count );
		}
	} 
	
	return 0;
}



int divide (char *str,int len,Word *s[SIZE]){
	
	int flag=0,cnt=0;
	int i;
	int index;
	Word *ret=NULL; 
	
	for (i=0;i<len;i++){
		if(str[i]!='\0'){
			if(flag==0){
				flag=1;
				cnt++;
				index=i;
				
			}
		}else{
			if(flag==1){
				flag=0;
				ret=(Word*)malloc(sizeof(Word));			//malloc 拼写错误 
				strcpy(ret->str,&str[index]);
				s[cnt]=ret;
				s[cnt]->count=1;
			}
		}
		
	}
	
	return cnt;
}

void word_count (Word *s[SIZE],int cnt){
	int i,j;
	
	for(i=0;i<cnt;i++){
		if(s[i]->count!=0){
			for(j=i+1;j<cnt;j++){
			if(strcmp(s[i]->str,s[j]->str)==0){
				s[i]->count++;
				s[j]->count=0;
			}
			}
		}
		
	}
	
}

void sort (Word *s[SIZE],int cnt){
	
	int i,j;
	Word * temp;
	
	for(i=cnt-1;i>0;i--){
		for(j=0;j<i;j++){
			if(s[j]->count>s[j+1]->count){
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	
	
}


