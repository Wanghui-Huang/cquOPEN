#include <stdio.h>
#include <math.h>
//用牛顿迭代发 求下面方程的根

int main ()
{
	double x,x0;
	double f,f1;
	x=1.5;
	
	x0=x;	
	f=((2*x0-4)*x0+3)*x0-6;
	f1= (6*x0-8)*x0+3;
	x=x0-f/f1;
	while (fabs(x-x0)>=1e-5)
	{
		x0=x;	
		f=((2*x0-4)*x0+3)*x0-6;
		f1= (6*x0-8)*x0+3;
		x=x0-f/f1;
	}
	
	printf("%lf",x);
	return 0;	
} 
