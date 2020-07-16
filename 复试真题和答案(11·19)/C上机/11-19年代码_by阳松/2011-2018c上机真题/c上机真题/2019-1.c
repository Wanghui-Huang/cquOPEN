#include <stdio.h>
//99可以由多少对数相加而成

int main ()
{
	int i;
	int cnt=0;
	for(i=0;i<50;i++)
	{
		printf("99=%d+%d\n",i,99-i);
		cnt++;	
	}	
	
	printf("%d\n",cnt);
	return 0;
} 
