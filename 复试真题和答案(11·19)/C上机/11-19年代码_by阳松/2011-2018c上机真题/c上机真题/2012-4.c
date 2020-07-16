#include <stdio.h>

//十进制转二进制
#define SIZE 100

void int_binary (int x);
void dec_binary (double dec);

int main()
{
	double x;
	int integer;
	double dec;
	
	scanf("%lf",&x);
	integer=(int)x;
	dec=x-integer;
	
	int_binary (integer);
	printf(".");
	dec_binary (dec);
	return 0;	
} 

void int_binary (int x)
{
	int i=0; 
	int ret[SIZE];
	while (x>0)
	{
		ret[i++]=x%2;
		x/=2;
	}
	i--;
	for(;i>=0;i--)
	{
		printf("%d",ret[i]);
	}
}

void dec_binary (double dec)
{
	int i=0; 
	int cnt=0;
	int ret[SIZE];
	while (dec!=0)
	{
		dec*=2;
		if(dec>=1)
		{
			ret[i++]=1;
			dec-=1;	
		}else
		{
			ret[i++]=0;
		}	
	} 

	cnt=i;
	for(i=0;i<cnt;i++)
	{
		printf("%d",ret[i]);
	}

} 
