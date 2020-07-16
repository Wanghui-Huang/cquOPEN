#include <stdio.h>
#define size 100 
//n个人围成一圈报数，报到m个人时出局，又重新 报数 
int main ()
{
	int i,n,m;
	int arr[size];
	int cnt=0;
	int num=0,index;
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++)
	{
		arr[i]=1;
	}
	
	while (cnt<n)
	{
		for(i=0;i<n;i++)
		{
			if(arr[i]==1)
			{
				num++;
				if(num%m==0)
				{
					arr[i]=0;
					cnt++;		
				}	
			}	
			if(cnt==n)
			{
				index=i;
				break;
			}	
		}

	}
	
	printf("%d",index+1);
	return 0;
 } 
