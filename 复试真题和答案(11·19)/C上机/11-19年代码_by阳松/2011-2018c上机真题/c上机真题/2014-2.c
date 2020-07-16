#include <stdio.h>
#include <string.h>
#define size 100
int main ()
{
	char str1[size],str2[size];
	int len_1,len_2;
	int max_len;
	int s1[size]={0},s2[size]={0};
	int ret[size]={0};
	int i,flag=0;
	gets(str1);
	gets(str2);
	
	len_1=strlen(str1);
	len_2=strlen(str2);
	
	for(i=0;i<len_1;i++)
	{
		s1[len_1-1-i]=str1[i]-'0';
	}

	for(i=0;i<len_2;i++)
	{
		s2[len_2-1-i]=str2[i]-'0';
	}	
	
	max_len=len_1>len_2? len_1 :len_2 ;
	
	for(i=0;i<max_len;i++)
	{
		ret[i]+=s1[i]+s2[i];
		if(ret[i]>=10)
		{
			ret[i+1]+=ret[i]/10;
			ret[i]=ret[i]%10;
		}
	}
	
	for(i=size-1;i>=0;i--)
	{
		if(ret[i]||flag)
		{
			printf("%d",ret[i]);
			flag=1;
		}
	}
	
	
	return 0;
} 
