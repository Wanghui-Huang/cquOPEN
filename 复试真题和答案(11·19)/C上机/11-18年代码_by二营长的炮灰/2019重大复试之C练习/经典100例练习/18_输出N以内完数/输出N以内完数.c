#include<stdio.h>
#define N 1000
#define MAX 100

int isPerfectNum(int num);
int main()
{
  int i;
  printf("%d以内的全部完全数是：\n",N);
  for(i = 2 ; i <= N ; i++)
  {
	  if(isPerfectNum(i))
		  printf("%d  ",i);
  }
  return 0;
}
/*
  [背]判断是否完全数：求完全+数组求和
      [注]这里不是因式分解，而且能被num整除的所有数（除本身）
*/
int isPerfectNum(int num)
{
	int  temp = num , factors[MAX];
	int  sum = 0; 
	int i , j ;
	for(i = 1 ,j = 0 ; i < temp ; i++)
	{
		if(temp % i == 0)
		{
			factors[j++] = i;
			sum += i;
		}
	}
    return sum == num;
}






















/*
#include<stdio.h>
#include<stdlib.h>

int* perfectNum(int N);
int main()
{
  int N,i;
  int *pNum ;
  printf("请输入指定N以内的完全数：");
  scanf("%d",&N);
  pNum = perfectNum(N);
  for(i = 0 ; pNum[i] != 0 ; i++) //输出完全数
	  printf("%5d",pNum[i]);
  return 0;
}

//计算N以内的完全数
//完全数 = 除本身外其因子之和 。如 6 = 1+2+3
int* perfectNum(int N)
{
	int *pNum = (int*)malloc(sizeof(int)*100);
	int i , j ,k = 0,sum ;
	for(i = 2 ; i<= N/2 ;i++) //ATTENTION 1 : 寻找因子终止条件 i<N --> i <= N/2 
	{
	  sum = 0;     //易错1 ：每次进入循环sum = 0 ，进行数i的统计因子之和！
      for(j = 1 ; j < i ; j++) //寻找i所有除本身外因子
	  {
         if( i % j == 0)  
			 sum += j; //加上i所有因子,1是
	  }
	  if(sum == i) 
		  pNum[k++] = i;
	}
	pNum[k] = 0;//设置int数组终止条件
	return pNum;
}
*/