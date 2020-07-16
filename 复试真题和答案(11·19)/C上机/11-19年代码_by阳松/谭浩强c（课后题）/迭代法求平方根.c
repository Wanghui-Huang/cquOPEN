#include <stdio.h> 
#include <math.h>
//用迭代发，求 x=a^0.5  x1=1/2(x0 + a/x0 )  要求前后求出的两次  x的差值 小于 10的-5 次方 

int main ()
{
	double x0,x1;
	double a;
	scanf("%lf",&a);
	x0=1;
	x1=0.5*(x0 + a/x0 );
	while (fabs(x1-x0)>=1e-5)
	{
		x0=x1;
		x1=0.5*(x0 + a/x0 );
	}
	
	printf("%8.5lf",x1);
	
	return 0;
}
