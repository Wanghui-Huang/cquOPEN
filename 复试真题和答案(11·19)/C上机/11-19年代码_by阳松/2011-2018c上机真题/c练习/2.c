#include <stdio.h>
#include <string.h>
//输出一串字符中最长的单词。如:
#define size 100
int main ()
{
	char str[size];
	int i=0,len;
	int cnt,index,last;
	int flag=0,max_len=0,max_index;
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			if(flag==1)
			{
				flag=0;
				last=i;
				cnt=last-index;
				if(cnt>max_len)
				{
					max_len=cnt;
					max_index=index;
				}	
			}	
		}else
		{
			if(flag==0)
			{
				index=i;
				flag=1;
			}
		} 
	}
	
	if(flag==1)
	{
		flag=0;
		last=i;
		cnt=last-index;
		if(cnt>max_len)
		{
			max_len=cnt;
			max_index=index;
		}	
	}	
	
	
	while (str[max_index]!=' ')
	{
		printf("%c",str[max_index]);
		max_index++;
	}
	
	return 0;
}
