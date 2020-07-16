#include <stdio.h>
#define size 100
//写一个 strcmp 函数，实现比较字符ASCII 值，返回比较结果。
int str_compare (char *s1,char *s2);

int main ()
{
	char s1[size],s2[size];
	gets(s1);
	gets(s2);
	
	printf("%d",str_compare(s1,s2));
	return 0;
}

int str_compare (char *s1,char *s2)
{
	int i=0;
	while (s1[i]==s2[i]&&s2[i]!='\0')
	{
		i++;
	}
	
	
//	if(s1[i]-s2[i]>0)
//	{
//		return 1;
//	}else if(s1[i]-s2[i]<0) 
//	{
//		return -1;
//	}else
//	{
//		return 0;
//	}
//	
//	return s1[i]-s2[i];
}
