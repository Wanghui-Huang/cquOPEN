#include <stdio.h>


int main ()
{
	double up,down;
	double sum=0;
	int i,t;
	up=2;
	down=1;
	double temp;
	for(i=0;i<20;i++)
	{
		temp=up/down;
		sum+=temp;
		t=up;
		up=up+down;
		down=t;
	}
	printf("%16.10lf",sum);
	return 0;
}
