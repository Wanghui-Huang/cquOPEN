#include<stdio.h>

int f(int n);
int main()
{
  int n;
  scanf("%d",&n);
  printf("%d",f(n));
  return 0;
}

//求n条直线可将一条平面分成多少个子平面
//递归推
int f(int n)
{
	if(n == 1)  return 2;
	return n+f(n-1);
}