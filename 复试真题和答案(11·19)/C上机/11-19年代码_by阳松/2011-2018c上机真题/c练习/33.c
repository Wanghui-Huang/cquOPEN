#include <stdio.h>
//用户输入指定 n，求 1+2!+3!+...+n!的和。如：
int factorial (int n);
int main ()
{
	int i,n;
	int ret=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		ret+=factorial(i);
	}
	
	printf("%d",ret);	
	return 0;
}

int factorial (int n)
{
	int i,sum=1;
	for(i=1;i<=n;i++)
	{
		sum=sum*i;
	}
	
	return sum;
	
}
