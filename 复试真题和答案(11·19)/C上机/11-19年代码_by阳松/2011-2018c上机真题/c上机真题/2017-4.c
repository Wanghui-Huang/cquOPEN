#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
//随机生成不大于100的是个不重复的数字 
#define size 11
int is_duplicate (int x);
int compare (const void *a,const void *b);

int cnt;
int arr[size];

int main ()
{
	int temp;
	int i;
	cnt=0;
	srand(time(NULL));
	while(cnt<10)
	{
		temp=rand()%21;
		if(!is_duplicate(temp))
		{
			arr[cnt++]=temp;
		}
	}
	
	qsort(arr,cnt,sizeof(int),compare);
	
	for(i=0;i<10;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}

int is_duplicate (int x)
{
	int flag=0;
	int i;
	for(i=0;i<cnt;i++)
	{
		if(arr[i]==x)
		{
			flag=1;
			break;
		} 
	}
	return flag;
}

int compare (const void *a,const void *b)
{
	int *m=(int *)a;
	int *n=(int *)b;
	return *m-*n;
}

