#include <stdio.h> 
#include <stdlib.h>


void delete_duplicate (int *num,int *len,int n);
int compare (const void * a , const void *b );



int main ()
{
	
	int a[100];
	int i;
	int n;
	int len;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	qsort( a, n, sizeof(int),compare);

	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n",a[i]);	
	delete_duplicate(a,&len,n);
	for(i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}


void delete_duplicate (int *a,int *len,int n)
{
    int i;
    int k=1;
    int temp=a[0];
    for (i=1;i<n;i++)
    {
        if(a[i]!=temp)
        {
            a[k++]=a[i];
            temp=a[i];
        }
    }
    
    *len=k;
}

int compare (const void * a , const void *b )
{
    int* a1=(int*)a;
    int* a2=(int*)b;
        
    return  *a1 - *a2;
 
}

