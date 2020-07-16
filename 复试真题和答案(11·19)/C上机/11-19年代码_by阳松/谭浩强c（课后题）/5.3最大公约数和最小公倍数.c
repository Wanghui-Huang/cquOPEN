#include <stdio.h> 
//输出两个数，求出他们的最大公约数，和最小公倍数 


int main ()
{
	int m,n;
	int temp;

	int mul; 
	
	scanf("%d %d",&m,&n);	
	mul=n*m;
	
	if(m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	
	temp=m%n;
	while (temp!=0)
	{
		m=n;
		n=temp;
		temp=m%n;
	}
	
	printf("最大公约数为%d",n);
	//求最小公倍数了
	
	printf("最小公倍数为%d",mul/n) ;
	
	
	
	
	return 0;
}
