#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char* encrypt(char* s);
char* decode(char* s);
int main()
{
  char s[MAX] , str_encrypt[MAX];w
  gets(s);   //gets()可读入空格
  str_encrypt = encrypt(s);
  printf("加密后：%s\n",str_encrypt);
  printf("解密后：%s\n",decode(str_encrypt));
  return 0;
}

//加密字符
char* encrypt(char* s)
{
  char *s1 = (char*)malloc(sizeof(char)*MAX);
  int i;
  for(i = 0 ; i < strlen(s); i++)
  {
	  s1[i] = s[i] + i + 5; //超过255会自动取余
  }
  s1[i] = '\0';//无数次错误1： 字符指针末尾加'\0'
  return s1;
}

//解密字符
char* decode(char* s)
{
  char *s1 = (char*)malloc(sizeof(char)*MAX);
  int i;
  for(i = 0 ; i < strlen(s); i++)
  {
	  s1[i] = s[i] - i - 5; 
  }
  s1[i] = '\0';
  return s1;
}