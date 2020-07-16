#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//一行一行读文件 ，要求在所有单词里面查找子串
//返回在第几个子串中的第几个位置 
#define size 100 
int fide_substr(char *main_str,char *substr);
int main ()
{
	char s[size][size];
	char substr[size];
	int i,cnt=0,ret; 
	FILE *fin=fopen("filename20.in","r");
	if(fin==NULL)
	{
		printf("文件打开失败");
		exit(1);	
	} 
	
	while (fscanf(fin,"%s",s[cnt])==1)
	{
		cnt++;
	}
	
	scanf("%s",substr);
	for(i=0;i<cnt;i++)
	{
		if((ret=fide_substr(s[i],substr))!=-1)
		{
			printf("第%d个子串从第%d个字母开始",i+1,ret+1);
			break; 
		}
	}
	
	if(i==cnt)
	{
		printf("查无此串");
	}
	return 0;
}




int fide_substr(char *main_str,char *substr)	//查找子串成功则返回子串开始的位置，失败则返回-1 
{
	int i,j;
	int len_m,len_s;
	len_m=strlen(main_str);
	len_s=strlen(substr);
	
	if(len_m<len_s)
	{
		return -1;
	}else
	{
		for(i=0;i<len_m;i++)
		{
			j=0;
			while (main_str[i+j]==substr[j]&&substr[j]!='\0')
			{
				j++;
			}
			if(j==len_s)
			{
				return i;
			}		
		}
		return -1;	
	}
	
}
