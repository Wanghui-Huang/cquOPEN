#include <stdio.h>
//输入一串主串，一串子串，计算子串在主串中出现的频率。如:
//ABCCDFEFCDCDFFCD  CDF	输出：2
#define size 100
int is_match (char *main_str,char *sub_str);
int main ()
{
	int i=0,cnt=0;
	char main_str[size],sub_str[size];
	gets(main_str);
	gets(sub_str);
	while (main_str[i]!='\0')
	{
		if(is_match(&main_str[i],sub_str))
		{
			cnt++;
		}
		i++;
	}
	
	printf("%d",cnt);
	
	return 0;
}

int is_match (char *main_str,char *sub_str)
{
	int i=0;
	while (main_str[i]==sub_str[i]&&sub_str[i]!='\0')
	{
		i++;		
	}
	if(sub_str[i]=='\0')
	{
		return 1;
	}else
	{
		return 0;
	}
} 
