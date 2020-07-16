#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int* factorization(int num);
int main()
{
 int* factors;    //存储因式分解的因子
 int num ,i;  
 printf("请输入想分解的数字：");
 scanf("%d",&num);
 factors = factorization(num);
 printf("因式分解 %d = %d" ,num,factors[0]);//注意先写好A[0]
 for(i = 1; factors[i] != 0 ;i++)
	 printf(" * %d",factors[i]);
 return 0;
}

/*背：计算因式分解
  为什么终止条件： i <= temp ？ 强调 = 号？
    1.保证当此时temp不能被分解时(如5)，可以循环到temp，i=temp存起来
	   注： i <= num ，也可但没必要。
	2.同时下轮循环temp = 1；不满足 i = 2 <= temp ，退出循环。
*/
int* factorization(int num)
{
	int i , j = 0 ,*factors,temp;
	factors = (int*)malloc(sizeof(int)*MAX);
	memset(factors,0,sizeof(int)*MAX);  //初始为0，也是终止条件
    temp = num;
    for(i = 2 ; i <= temp ; i++) 	//不用两次循环
		{
			if(temp % i == 0)      //找到因子i
			{
              factors[j++] = i;     //存储因子i
			  temp = temp / i;     //得到被整除后的（temp/i）
			  i = 1;    //再错1: i重置1，i++下次循环会变成2,寻找因子
			}
		}
	return factors;
}