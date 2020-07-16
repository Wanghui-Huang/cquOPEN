#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define size 1000
//读文件中给出的一段英文，分隔符为 空格  英文句号 逗号 ，
//要求统计单词出现的次数，并且按照次数输出 
typedef struct {
	char str[20];
	int repeat_cnt;	
}Word,*pWord;

Word words[size];
int word_cnt=0;

void divede_word (char *s);
void my_copy (char *temp,char *s,int index,int last);
void insert_words (char *temp);
int compare (const void *a,const void *b);

int main ()
{
	char s[size];
	int i;
	FILE *fin=fopen("filename19.in","r"); 
	if(fin==NULL)
	{
		printf("文件打开失败"); 
		exit(1); 
	}
	fgets(s,size,fin);
	divede_word(s);
	qsort(words,word_cnt,sizeof(Word),compare) ;
	for(i=0;i<word_cnt;i++)
	{
		printf("%s出现了%d次\n",words[i].str,words[i].repeat_cnt);
	}
	
	
	return 0;
}

void divede_word (char *s)
{
	char temp[20]; 
	int i,len;
	int index,last;
	int flag=0;		//flag=1 代表当前正处在某个单词之中，flag=0;代表当前正处在分隔符之中 
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(isupper(s[i])||islower(s[i]))
		{
			if(flag==0) //代表单词开始 
			{
				flag=1;
				index=i; 
			}
		}else
		{
			if(flag==1)	//代表单词结束
			{
				flag=0;
				last=i;	//last 单词结束后一个字符的下标 
				my_copy(temp,s,index,last);
				insert_words(temp);
			}
		}
	}	
	if(flag==1)
	{
		last=i;
		my_copy(temp,s,index,last);
		insert_words(temp);
	}
}

void my_copy (char *temp,char *s,int index,int last)
{
	int i;
	int k;
	for(i=0,k=index;k<last;i++,k++)
	{
		temp[i]=s[k];
	}
	temp[i]='\0';	
}

void insert_words (char *temp)
{
	int i;
	for(i=0;i<word_cnt;i++)
	{
		if(strcmp(words[i].str ,temp)==0)
		{
			words[i].repeat_cnt ++;
			break;
		}
	}
	
	if(i==word_cnt)
	{
		strcpy(words[word_cnt].str ,temp);
		words[word_cnt].repeat_cnt =1;
		word_cnt++;
	}
	
}

int compare (const void *a,const void *b)
{
	pWord word1=(pWord)a;
	pWord word2=(pWord)b;
	return strcmp(word2->str ,word1->str);
}
