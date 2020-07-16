#include<stdio.h>
#define n 5

void sort(int A[][n]); //ATTENTION 0：A[][]非法
void swap(int A[][n],int i,int j,int i1,int j1);
int main()
{
	int A[n][n] = {{7,1,5,3,2},{5,4,8,0,9},{1,2,3,4,5},{6,7,8,9,10},{1,7,9,3,5}};
	sort(A);
	swap(A,n/2,n/2,n-1,n-1); //中心
	//swap(A,0,0,0,0); 
	swap(A,0,n-1,0,1); //右上角
	swap(A,n-1,0,0,2); //左下角
	swap(A,n-1,n-1,0,3); //右下角
	return 0;
}

/*
  线性二维数组排序：冒泡模板
  和字符串排序不同：①字符串依然相当是一维数组比较
                    ②交换的是地址（指针），这里交换元素。
*/
void sort(int A[][n])
{
	int i ,j,N = n*n ;
	int temp;
	for(i = 0 ; i < N ; i++) //线性访问二维数组
		for(j = 0 ; j < N-1-i ; j++)
		{
           if(A[j/n][j%n]> A[(j+1)/n][(j+1)%n]) //这里交换不了数组地址
			   swap(A,j/n,j%n,(j+1)/n,(j+1)%n);  
		}
}

void swap(int A[][n],int i,int j,int i1,int j1)
{
	int temp;
	temp = A[i][j];
    A[i][j] = A[i1][j1];
	A[i1][j1] = temp;
}