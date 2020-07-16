#include <stdio.h>
#include <string.h>

//下面的函数统计子字符串substr在字符串str中出现的次数，如果substr在str中不出现，则返回值0。请完成该函数。



int str_count(char *substr, char *str)
{
	int i,j,k;
	int len_str;
	len_str=strlen(str);
	int cnt=0;
	for(i=0;i<len_str;i++)
	{
		k=i;
		j=0;
		
		while (substr[j]==str[k]&&substr[j]!='\0')
		{
			k++;
			j++;
		}
		if(substr[j]=='\0')	
		{
			cnt++;
			j=0;
		}
	 } 
	
	return cnt;
}

int main ()
{
	char s[20];
	char subs[4];
	int ret;
	gets(s);
	gets(subs);
	
	ret=str_count(subs, s);
	
	printf("%d",ret);
	
	return 0;
}

//		for(j=0;j<len_substr;j++)
//		{
//			if(str[k]!=substr[j])
//			{
//				flag=0;
//			}
//		}
		

