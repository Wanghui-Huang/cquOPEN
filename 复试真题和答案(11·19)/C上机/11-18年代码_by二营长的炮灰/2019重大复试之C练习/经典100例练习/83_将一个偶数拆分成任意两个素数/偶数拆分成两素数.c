#include<stdio.h>
#include<math.h>

int isPrime(int num);
int main()
{
  int n , i;
  scanf("%d",&n);
  for(i = 2 ; i <= n ; i++) 
  {
	  if(isPrime(i) && isPrime(n-i))// i+n-i = n,巧妙之处
		  printf("%d,%d\n",i,n-i);
  }
  return 0;
}
/*
  判读是否是素数，灵异事件：2019/2/23 12:38
  不加math.h，sqrt()不报错，但是不生效。最后i=num%num==0，非素数
*/
int isPrime(int num)
{
	int i;
	for( i = 2 ; i <= sqrt(num) ; i++) //注意=
    {
		if(num % i == 0) 
		  return 0;
	}
    return 1; //ATTETION 1:1是素数，这里也会直接返回1不用判断
} 