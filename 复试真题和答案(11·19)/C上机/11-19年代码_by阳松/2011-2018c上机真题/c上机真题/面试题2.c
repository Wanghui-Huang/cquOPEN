#include <stdio.h>
//计算n条直线能将1个平面分成多少个平面 
int divide_palne (int n);

int main ()
{
	int ret;
	int n=100;
	ret=divide_palne(n);
	printf("%d",ret);
	return 0;
 } 
 
int divide_palne (int n)
{
	if(n==1)
	{
		return 2;
	}else
	{
		return divide_palne (n-1)+n;
	}

}
