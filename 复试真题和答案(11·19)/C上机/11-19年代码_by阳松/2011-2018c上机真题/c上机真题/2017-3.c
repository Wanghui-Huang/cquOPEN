#include <stdio.h>
//找出指定整数N范围内的 所有2的幂次数 
#define size 10000
int main ()
{
	int n;
	int arr[size]={0};
	int i;
	scanf("%d",&n);
	for(i=2;i<=n;i*=2)
	{
		arr[i]=1;
	} 
	 
	for(i=1;i<=n;i++)
	{
		if(arr[i]==1)
		{
			printf("%d ",i);
		}	
	} 
	return 0;
}
