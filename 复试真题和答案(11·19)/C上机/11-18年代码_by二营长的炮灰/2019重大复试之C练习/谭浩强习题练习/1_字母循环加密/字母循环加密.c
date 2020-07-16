#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char* code(char* s);
int main()
{
   char* s = (char*)malloc(sizeof(char)*MAX);
   char* c;
   printf("请输入一段字符串：");
   gets(s);
   c = code(s);
   printf("加密后：%s\n",c);
   printf("解密后：%s\n",code(c));	  
   return 0;
}

//加密字符:加密后ASCII无需取余计算得来
//1.解密字符经过推理算出s[i] = 下面表达式
char* code(char* s)
{
	int i , len = strlen(s);
    for(i = 0 ; i < len ; i++)
	{
		if(islower(s[i]))
			s[i] = 'z' - (s[i] - 'a') ;
		else if(isupper(s[i]))
			s[i] = 'Z' - (s[i] - 'A') ;
		else
			continue; //非字母不改变
	}
	return s;
}

