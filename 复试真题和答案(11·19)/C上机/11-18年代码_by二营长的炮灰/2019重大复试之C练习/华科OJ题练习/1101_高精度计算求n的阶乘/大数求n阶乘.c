#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

int* multiply(int a[],int b);
int main()
{
	int N;
	int i;
	int* result = (int*)malloc(sizeof(int)*MAX);
	memset(result,-1,sizeof(int)*MAX);//ATTENTION 1：终止条件不要设置0
	printf("请指定计算多少位的阶乘：");
	scanf("%d",&N);
	result[0] = 1; //初始为1
    for(i = 1 ; i <= N ; i++)
	{
	   result = multiply(result,i); 
	}
	printf("计算结果：");
    for(i = 0 ; result[i] != -1 ; i++)
        printf("%d",result[i]);
	return 0;
}
//大数a和非大数b相乘：b乘a低，结果存低，其余进位
int* multiply(int a[],int b)
{
	int* result = (int*)malloc(sizeof(int)*MAX);
	int len;
	int i,j;
	int temp , carry = 0;
	memset(result,-1,sizeof(int)*MAX);
	for(len = 0 ; a[len] != -1 ; len++); //获取大数a长度
	for(i = len-1,j=0 ; i >= 0 ; i--,j++)
	{
		temp = a[i]*b + carry;
		result[j] = temp % 10; //保存最低位
		carry = temp / 10;
	}
	if(carry != 0)
      result[j] = carry; //保存最后一次相乘的进位
	else 
		j = j-1; //再错1：进位为0时，把j指向数组最后一个位置！
	//将结果反转：反转模板
	for(i = 0 ; i < j ; i++,j--)
	{
		temp = result[i];
		result[i] = result[j];
		result[j] = temp;
	}
	return result;
}





























/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* f(int n);
int main()
{ 
	int n,i,len;
	char* result; 
	printf("请指定阶乘n计算：");
	scanf("%d",&n);
	result = f(n);
	len = strlen(result) ;
	for(i = strlen(result)-1; i >= 0;i--) //要-1
		  printf("%c",result[i]);
	return 0;
}

/*
   模拟计算n阶乘：
   1.     895   由于乘数35（<n）不可能会是大数。可用35和895每个
   	  *    35
	  ————     数字相乘模拟计算。(和手工模拟有所不同)     
	      175 //存下此时5，进位为17
		 315  //35 * 9 + 上次进位17
	  ————
	     332   //存下此时2，进位33
		280
	  ————
	    313    //存下此时3，进位完成。
		       //最后保存最后一次进位
   2.为方便计算可定义result[] 逆序存储结果方便，，如720: result[] = 027。
      和大数相加不同：大数由用户输入（这里是计算出），正序的。
	                  麻烦，干脆转成模式计算。
   3.容易得知：这里必然是两层循环，可先考虑 上次结果*i （内层循环），见1.
//
char* f(int n)
{
	char* result =(char*)malloc(sizeof(char)*1000);
	int i,j ,len,carry,temp;
	//极其易错1 ：字符数组一定要自己加'\0'!否则strlen错！(除非知道长度)
	//result = "1"; 
	//极其易错2:""相当重新分配空间，并指向常量，下面修改其元素值会出错！
	result[0] = '1'; 
    len = 1;         
	for(i = 1 ; i <= n ; i++) //n个数需计算阶乘
	{
		carry = 0 ; //极其易错3 ：每次进来都要carry = 0；防止存到上次进位
		for(j = 0 ; j < len;j++ ) //每次都要用i*当前result长度次数
		{
		   temp = i*(result[j] - '0') + carry; //易错1:当前相乘结果+上一次进位
		   carry = temp / 10 ; 
           result[j] = temp %10 + '0';//最低位存	   
		}        
		//保存最后一次未存的temp高位(就是carry)
		while(carry != 0)
		{
          result[len++] = carry % 10 + '0'; //获取最低位
		  carry = carry / 10 ; //去掉最低位
		}
	}
    result[len] = '\0';  //易错3:记得'\0'，这里虽然知道长度，main里无法获取
	return result;
}
*/