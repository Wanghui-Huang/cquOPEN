#include <stdio.h>
//将一个偶数拆分成任意两个素数之和。如：
int main ()
{
	int x;
	int i;
	scanf("%d",&x);
	for(i=2;i<x;i++)
	{
		if(is_prime(i)&&is_prime(x-i))
		{
			printf("%d,%d",i,x-i);
			break;
		}
	}
	
	
	return 0;
} 

int is_prime (int n)
{
	int i;
	int flag=1;
	if(n<2)
	{
		flag=0;
	}
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			flag=0;
			break;
		}
	}
	
	return flag;
	
}
