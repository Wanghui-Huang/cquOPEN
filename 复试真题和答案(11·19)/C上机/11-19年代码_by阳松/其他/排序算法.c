#include <stdio.h>
#include <time.h>
#define N 13


void print_arr (int arr[N]);
void bubble_sort (int arr[N]);
void insert_sort (int arr[N]) ;
void select_sort (int arr[N]) ;
void quick_sort  (int arr[N],int left,int right) ;
void max_value_heap (int arr[N],int begin,int end);
void heap_sort (int arr[N],int begin,int end);


int main ()
{
	
	int arr[N];
	int i;
	
	srand(time(NULL));			//随机数种子 
	
	for (i=0;i<N;i++)
	{
		arr[i]=rand()%100;
	}
	
	print_arr (arr);
	
	
//	bubble_sort(arr);
//	insert_sort(arr);
//	select_sort(arr);
//	insert_sort(arr);
//	quick_sort(arr,0,N-1);
	
	heap_sort (arr,0,N-1);
	print_arr (arr);
	return 0;
}

void print_arr (int arr[N])
{
	int i;
	for (i=0;i<N;i++)
	{
		printf("%d\t",arr[i]);
	}
	
	printf("\n——————————————————————————————————————————\n");
	
 } 
 
void bubble_sort (int arr[N])
{
	
	int i,j;
	int temp;
	
	for(i=N-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

}


void insert_sort (int arr[N]) 
{
	int i,j;
	int temp;
	for (i=1;i<N;i++)
	{
		temp=arr[i];
		j=i-1;
		while (j>=0&&arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		
		arr[j+1]=temp;
	}
}


void select_sort (int arr[N]) 
{
	int i,j;
	int min_pos;
	int temp;
	
	for(i=0;i<N-1;i++)
	{
		min_pos=i;
		for(j=i+1;j<N;j++)
		{
			if(arr[j]<arr[min_pos])
			{
				min_pos=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min_pos];
		arr[min_pos]=temp;
		
	}
	
}


void quick_sort  (int arr[N],int left,int right) 
{
	int i,j;
	int temp;
	
	if(left<right)
	{
		i=left;
		j=right;
		temp=arr[i];
		
		while (i<j)
		{
			while (i<j&&arr[j]>=temp)
			{
				j--;
			}
			if(i<j)
			{
				arr[i]=arr[j];
			}
			while (i<j&&arr[i]<=temp)
			{
				i++;
			}
			if(i<j)
			{
				arr[j]=arr[i];
			}
		}
		
		arr[i]=temp;
		quick_sort(arr,left,i-1) ;
		quick_sort(arr,i+1,right) ;	
	}	
	
}


void heap_sort (int arr[N],int begin,int end)		//函数的参数是数组的下标 
{	
	int start;
	int i;
	int temp;
	if(end%2!=0)			//end%2!=0 end是左孩子 
	{
		start=end/2; 
	} else
	{
		start=(end-1)/2;
	}
	//建立大根堆 
	for(i=start;i>=begin;i--)
	{
		max_value_heap(arr,i,end);
	}
	
	for(i=end;i>begin;i--){
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		max_value_heap (arr,0,i-1);
	} 
	
}

void max_value_heap (int arr[N],int begin,int end)
{
	int dad=begin;
	int son=begin*2+1;		//左子节点 
	int temp;

	
	while (son<=end)
	{
		if(son+1<=end&&arr[son+1]>arr[son])
		{
			son++;
		} 
		
		if(arr[dad]<arr[son])
		{
			temp=arr[dad];
			arr[dad]=arr[son];
			arr[son]=temp;
		}
		dad=son;
		son=son*2+1;
	}
	
}
