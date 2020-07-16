#include <stdio.h>

//定义一个正值数组，值由用户输入。删除其最大最小值，并求此时数组平均值。如: 输入： 1 2 3 4 5
//输出：平均值：3

#define M 50
int main ()
{
	int a[M];
	int i;
	double len=0,sum=0;
	int max,min;
	int temp;
	
	while (scanf("%d",&temp)!=EOF)
	{
		a[i++]=temp;
	}
	
	len=i;
	max=a[0];
	min=a[0];
	for(i=0;i<len;i++)
	{
		sum+=a[i];
		if(a[i]>max)
		{
			max=a[i];
		}
		if(a[i]<max)
		{
			min=a[i];
		}
	}
	
	sum=sum-max-min;
	len=len-2;
	printf("%lf",sum/len);
	return 0;
}
