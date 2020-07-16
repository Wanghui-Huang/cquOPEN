#include <stdio.h>
#include <string.h>

//输入一个字符串，取这个字符串的最长单词输出
#define M 100

void find_long_word (char *str);
int main ()
{
	char str [M];
	gets(str);
	find_long_word (str) ;
	
	return 0;	
} 


void find_long_word (char *str)
{
	int len =strlen(str);
	int index_key,last_key;
	int index;	//单词开始的下标 
	int i,max_len=0;
	int cnt=0;	//记录当前单词的个数 
	int flag=0;		//flag 为 1 单词开始，flag为0 时单词结束 
	
	for(i=0;i<len;i++)
	{
		if(islower(str[i])||isupper(str[i]))
		{
			if(flag==0)	//单词开始 
			{
				flag=1;
				cnt++;
				index=i; 
			}else if(flag==1)
			{
				cnt++;
			}
		}else 
		{
			if(flag==1)	//单词结束 
			{
				if(cnt>max_len)
				{
					max_len=cnt;
					index_key=index;
					last_key=i-1;
				}
				flag=0;
				cnt=0;
			}
		}	
	} 
	
	if(flag==1)
	{
		if(cnt>max_len)
		{
			max_len=cnt;
			index_key=index;
			last_key=i-1;
		}
		flag=0;
		cnt=0;
	}
	
	for(i=index_key;i<=last_key;i++)
	{
		printf("%c",str[i]);
	}
	
	printf("\n");
}
