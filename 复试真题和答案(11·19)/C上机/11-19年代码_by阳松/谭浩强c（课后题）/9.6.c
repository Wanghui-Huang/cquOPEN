#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//n个人围成一排，从第一个人开始报数，报到 m 的人出列，问最后剩下的人的最初编号是 多少 
int fun (int *arr,int n,int m);

int main ()
{
	
	int n,m;
	int i;
	int index;
	scanf("%d%d",&n,&m);
	int *arr;
	arr=(int *)calloc(n,sizeof(int));
                                                		//	memset(arr,1,n);   //memset 只能单字节赋值，如果用memset给int 型变量赋值就会出现问题 
	for(i=0;i<n;i++)
	{
		arr[i]=1;
	}
	index=fun(arr,n,m);
	printf("最后剩下的人的编号是%d",index+1);
	return 0;
}

int fun (int *arr,int n,int m)
{
	
	int i;
	int num=0,ret;
	int cnt=0;		//代表出队的人数 
	while (cnt<n)
	{

		for(i=0;i<n;i++)
		{
			if (arr[i]==1)
			{
				num++;
				if(num%m==0)
				{
					cnt++;
					arr[i]=0;
					printf("%d ",i+1);
				}
			}
			if(cnt==n)
			{
				ret=i;
				break;
			}
		}	

	}
	
	
	return ret;
}


