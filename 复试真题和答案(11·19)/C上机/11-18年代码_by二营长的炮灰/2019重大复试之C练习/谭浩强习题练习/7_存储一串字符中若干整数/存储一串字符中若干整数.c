#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int main()
{
	char s[MAX];
	int nums[MAX] , num = 0;
	int flag = 1;  //易错0:初始为1，防止读入0进nums
	int i , j = 0 , len = strlen(s) ;
	printf("请输入一串字符：");
	gets(s);
    for(i = 0 ; i < len ; i++)
	{
       if(isdigit(s[i]))
	   {
		   flag = 0 ; //标识上次结束的是一串数字而非其它
		   num = num * 10 + s[i] - '0';
           if(i == len-1) //易错1：此时已经读到了字符末尾，不会执行else存
		   {
			   nums[j] = num; 
			   printf("%d\t",nums[j++]);
 
		   }     
	   }	   
	   else
	   {
		   if(flag == 0)//易错2：上次结束的是数字&&这次读入非数字才存下来 
		   {
			   nums[j] = num; 
			   printf("%d\t",nums[j++]);
		   }
		       
		   flag = 1;
	       num = 0;
	   }
	}
	return 0;
}