#include <stdio.h>
//用二分递归法找出最小的整数 
int find_min (int *arr,int begin,int end);

int main ()
{
	int ret;
	int arr[5]={5,7,2,4,6};
	ret=find_min (arr,0,4);
	printf("%d",ret);
	return 0;
}


int find_min (int *arr,int begin,int end)
{
	
	int mid;
	int min_1,min_2;

	
	if(begin==end)
	{
		return arr[begin];
	}else if(begin<end)
	{
		mid=(begin+end)/2;
		min_1=find_min (arr,begin,mid);
		min_2=find_min (arr,mid+1,end);
		return min_1<min_2? min_1:min_2 ;
	}
	
	
	
 } 
