#include<stdio.h>

int findM(int A[],int M ,int s , int r);
int main()
{
	int k , M;  //k记录位置最近M数在A中下标
	int A[] = {1 , 3 ,15 ,70 , 108};
	scanf("%d",&M);
	k = findM(A,M,0,4);
	printf("%d",k);
	return 0;
}

//递归查M
//ATTENTION 0：考虑M=20 s=3 r=4 mid = 3
//此时满足左侧，findM(A,M,3,2) 3<2
int findM(int A[],int M ,int s , int r)
{
	int mid = (s+r)/2;
	if(A[mid] == M)  return mid;
    if(s > r)  return r;
	if(M < A[mid]) //M在左侧
		findM(A,M,s,mid-1); //和前不同，mid已经考虑，-1
	else//右侧
		findM(A,M,mid+1,r);    
}