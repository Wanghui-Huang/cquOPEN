#include<stdio.h>
#include<ctype.h>

int main()
{
  char s[100];
  int i;
  int pos = 0 , max = 0,len = 0;
  printf("请输入一串字符串：");
  gets(s);
  for(i = 0 ; i < strlen(s); i++)
  {
	  if(isalpha(s[i]))
	  {
		  len++;
	  }
	  else
	  {
		  if(len > max) //当前记录长度大于max
		  {
			  pos = i - len; //该单词首字母位置
			  max = len;
		  }
		  len = 0;
	  }
  }
  for(i = 0 ; i < max ; i++)
	  printf("%c",s[i+pos]);
  return 0;
}