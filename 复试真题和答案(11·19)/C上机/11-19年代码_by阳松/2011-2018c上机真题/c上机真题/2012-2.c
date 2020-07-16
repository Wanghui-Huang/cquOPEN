#include <stdio.h>

//因式分解 
int main ()
{
	int x;
	int i;
	scanf("%d",&x);
	int n=x;
	printf("%d=",x);
	for(i=2;i<x;i++)
	{
		while(n%i==0)
		{
			printf("%d",i);
			n/=i;
			if(n!=1)
			{
				printf("*");
			}
		}
	}
	
 } 
