#include <stdio.h>
#include <math.h>

//用二分法求下面方程在 （-10,10）之间的根

int main ()
{
	double x1,x2;
	double fx1,fx2,fx0;
	double x0;
	scanf("%lf%lf",&x1,&x2);
	fx1=((2*x1-4)*x1+3)*x1-6;
	fx2=((2*x2-4)*x2+3)*x2-6;
	while (fx1*fx2>0)
	{
		scanf("%lf%lf",&x1,&x2);
		fx1=((2*x1-4)*x1+3)*x1-6;
		fx2=((2*x2-4)*x2+3)*x2-6;
	}
	
	
	while (fx1*fx2<0)
	{
		x0=(x1+x2)/2;
		fx0=((2*x0-4)*x0+3)*x0-6;
		if(fx0<1e-5)
		{
			break;
		}else if(fx0*fx2<0)
		{
			x1=x0;
			fx1=fx0;
		}else if(fx1*fx0<0)
		{
			x2=x0;
			fx2=fx0;
		}
	}
	
	
	printf("%lf",x0);
	return 0;	
	
} 
