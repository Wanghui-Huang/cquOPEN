#include<stdio.h>
#include<ctype.h>  //ATTENTION 1 :调用判断是否大小写字母
#include<string.h> 
#define MAX 100

int main()
{
	char s[MAX];
	int k;
	int i,len;
	printf("请输入一串字符串和偏移k，空格隔开：");
	scanf("%s %d",s,&k);
    len = strlen(s);
	for(i = 0 ; i < len ; i++)
	{
		if(islower(s[i]))  s[i] = (s[i] - 'a' + k ) % 26 + 'a';
        if(isupper(s[i]))  s[i] = (s[i] - 'A' + k ) % 26 + 'A';
	}
	printf("加密后的字符串：%s",s);
	return 0;
}







/*
#include<stdio.h>
#include<ctype.h>  //ATTENTION 1 :调用判断是否大小写字母
#include<string.h> 
#define MAX 40

char* encrypt(char* str,int k);
int main()
{
  char str[MAX] ;
  int k;
  printf("请输入一串只有英文和数字的字符串：");
  gets(str);    //ATTENTION 2：gets()可读入空格
  printf("请输入偏移量k：");
  scanf("%d",&k);   
  printf("加密后的字符串：%s",encrypt(str,k));
  return 0;
}
/*   ASCII值：41 42 43 44 45 46 ...96
  加密字符串： A  B  C  D  E  F ...Z
    相对位置： 0  1  2  3  4  5 ...25
   ①：str[i] - 'A' 获取相对位置，如 45(E)-41(A)=4
          char本质是整型，存储的是ASCII值只有在输出%c才显示对应字符
       str[i]-'A' == str[i]的ASCII值-'A'的ASCII值
          但不是-'0'！我们要获得相对A的ASCII值,否则会出错
   ②：+k 加上偏移值
   ③：%26 相当于E往右移K个位置，%26导致循环数26字母
   ④：易错1：斧正偏移+'A' 得到E加密后真实ASCII值
   
char* encrypt(char str[],int k)
{
  int i;
  for(i = 0 ; i < strlen(str); i++)
  {
	  if(islower(str[i])) //如果是小写
		  str[i] = (str[i] - 'a' + k ) % 26 + 'a';
	  else if(isupper(str[i])) //upper大写
		  str[i] = (str[i] - 'A' + k ) % 26 + 'A';
  }
  return str ; //ATTENTION 3：函数体内可以返回数组，返回类型不可以
}
*/