#include <stdio.h>

//打印杨辉三角，利用一维组 
#define size 100 
void arr_cpy (int *a,int *b);

int main ()
{
	
	int ret[size]={0};
	int aux[size];
	ret[0]=1;
	int i,j,n,space;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		for(space=n-1;space>i;space--)	
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
			printf("%d",ret[j]);
			if(i!=j)
			{
				printf(" ");
				
			}else
			{
				printf("\n");
			}
		}
		arr_cpy(aux,ret);
		for(j=1;j<=i+1;j++)
		{
			ret[j]=aux[j]+aux[j-1];
		}
		
	}
	return 0;
}


void arr_cpy (int *a,int *b)
{
	int i;
	for(i=0;i<size;i++)
	{
		a[i]=b[i];	
	}
}
