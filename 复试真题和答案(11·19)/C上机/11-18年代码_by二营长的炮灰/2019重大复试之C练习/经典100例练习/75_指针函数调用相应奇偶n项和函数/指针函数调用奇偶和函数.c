#include<stdio.h>

double sumEven(int n);
double sumOdd(int n);
/*
 ATTENTION 0：函数指针/普通指针定义
   普通指针： double *ptr;
   函数指针： double *ptr(int a); //增加参数列表
      类似: double *p[2] 指针数组 区分 double (*p)[2] 指向数组指针
	  ——>函数指针名：double (*ptr)(int a); //增加括号*ptr结合表示指针
*/
int main() 
{
  int n;
  double (*psum)(int) , result; 
  scanf("%d",&n);
  if( n % 2 ==0)   
	  psum = sumEven; //加函数只有使用时
  else
      psum = sumOdd;
  result = (*psum)(n); //再错1：如何使用函数指针（调用其绑定的函数）！！
  printf("%lf",result);，
  return 0;
}

//求偶数和：1/2+1/4+...+1/n
double sumEven(int n)
{
	double sum = 0;
	int i;
	for(i = 2; i <= n; i+=2)//灵异事件:又调试半小时！i+2错误，应该i+=2!
	{
		sum += 1.0/i;
	}
	return sum;
}
//求奇数和：1/1+1/3+...+1/n
double sumOdd(int n)
{
	double sum = 0;
	int i;
	for(i = 1; i <= n; i+=2)
	{
		sum += 1.0/i;
	}
	return sum;
}
