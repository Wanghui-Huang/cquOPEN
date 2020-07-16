#include <stdio.h>

int main ()
{
	double hn=100;
	double distance=0;
	int i;
	for(i=0;i<10;i++)
	{
		distance+=hn*2;
		hn/=2;
	}
	
	printf("10次行走的路程%lf，第十次反弹的高度%lf",distance-100,hn);
	return 0;
}
