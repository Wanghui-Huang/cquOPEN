#include <stdio.h>
//.已升序有序的数组 A[N],指定正整数M。使用二分查找法，
//查找在 A[N]中和M相等数的位 置，返回其下标 k； 
//如果没有找到则返回 A 中最大的 <M数的下标 k。
//如：A[5] = {1 , 3 , 15 ,70 , 108}
//,查找M=20，返回 k = 2。
int bianry_search (int *arr,int begin,int end,int key);

int main ()
{
	int ret;
	int arr[5] = {1,3,15,70,108};
	ret=bianry_search (arr,0,4,20);
	printf("%d",ret);
	
	return 0;
 } 
 
int bianry_search (int *arr,int begin,int end,int key)
{
	int mid;
	
	while (begin<end)
	{
		mid=(begin+end)/2;
		if(arr[mid]==key)
		{
			begin=mid;
			break;
		}else if(arr[mid] < key)
		{
			begin=mid+1;
		}else if(arr[mid] > key)
		{
			end=mid-1;
		}
	}
	
	if(arr[begin]<=key)
	{
		return begin;
	}else
	{
		return begin-1;
	}
}
