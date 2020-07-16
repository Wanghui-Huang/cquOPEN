#include<stdio.h>
#define MAX 1000

int* findPower2(int N);
int main()
{
  int *p2,N ,i; 
  scanf("%d",&N); //ATTENTION 0：gets(&N)错误，只能是字符串
  p2 = findPower2(N);
  //错误1：获取int数组不能strlen(p2),只能sizeof(数组名)/sizeof(int)
  for(i = 0 ; p2[i] != -1; i++)
     printf("%4d",p2[i]);
  return 0;
}

/*
  函数：返回所有指定N内是2的幂次数
  分析：一个数a是2幂次，则二进制必是 100..0形式，a-1 是 011..1形式
        它们按位与 & 则必为000..0
*/
int* findPower2(int N)
{
  int *p2 ,i,k = 0 ;
  p2 = (int*)malloc(sizeof(int)*MAX);
  for( i = 2 ; i < N ; i++)
  {
	  if((i & i-1) == 0) 
		  p2[k++] = i;
  }
  p2[k] = -1;//设置终止条件
  return p2;
}