#include <stdio.h>
#include <string.h>
//从键盘中输入一个字符串，将其中的小写字母全部转换为大写字母，并输出至  tset 文件中 

int main ()
{
	int i;
	char str[100];
	int len;
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(islower(str[i]))
		{
			str[i]=str[i]-32;
		}
	} 
	
	FILE *fp;
	fp=fopen("tset.txt","w");
	fputs(str,fp);
	
	
	return 0;
}
