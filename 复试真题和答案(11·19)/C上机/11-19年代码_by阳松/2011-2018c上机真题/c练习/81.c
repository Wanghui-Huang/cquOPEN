#include <stdio.h>
#include <string.h>
//将一个 8 进制数转为 10 进制。如：
#define size 100
int main ()
{
	int i,len;
	int cnt=0,sum=0;
	char num[size];
	gets(num);
	
	len=strlen(num);
	for(i=0;i<len;i++)
	{
		sum=sum*8+(num[i]-'0');
	}	
	
	printf("%d",sum);
	return 0;
} 
