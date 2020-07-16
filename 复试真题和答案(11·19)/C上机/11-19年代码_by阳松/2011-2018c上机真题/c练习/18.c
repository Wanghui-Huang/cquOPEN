#include <stdio.h>
//一个数如果恰好等于它的因子之和（1 是，本身不是），这个数就称为"完数
//例如 6=1 ＋2＋3.编程找出 N以内的所有完数。
int is_perfect (int x);

int main ()
{
	int i;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(is_perfect(i))
		{
			printf("%d ",i);
		}
	}
	

	return 0;
} 

int is_perfect (int x)
{
	int sum=0,i;
	for(i=1;i<x;i++)
	{
		if(x%i==0)
		{
			sum+=i;
		}

	}
	
	if(sum==x)
	{
		return 1;
	}else
	{
		return 0;
	}
	
}
