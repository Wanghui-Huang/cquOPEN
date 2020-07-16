#include<stdio.h>
#include<time.h> //注意引入时间库

int exist(int r[],int n);
int main()
{
  int r[10];
  int i ,temp;
  srand((int)time(0));//ATTENTION 0:设置随机数种子，防止序列一致
  for(i = 0 ; i < 10 ; i++)
  {
    temp = rand() % 101 ; //再错1：101
	if(!exist(r,temp)) //ATTENTION 1 : !0 = 1,!非0 = 0
	{
       r[i] = temp;
	   printf("%5d",r[i]);
	}
  }
  return 0;
}

//判断是否存在重复
int exist(int r[],int n)//[好]这里定义函数比直接写main里好
{
	int i;
	for(i = 0; i < 10 ; i++)
	{
      if(n == r[i]) //有重复
		   return 1;
	}
	return 0;
}