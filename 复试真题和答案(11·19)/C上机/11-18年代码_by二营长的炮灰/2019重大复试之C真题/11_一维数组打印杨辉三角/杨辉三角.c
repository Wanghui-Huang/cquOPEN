#include<stdio.h>
#define MAX 100

int main()
{
	int A[MAX] = {1}, N; //A[0] = 1，其余为0
	int n , i , space;
	printf("请指定杨辉三角的层数：");
	scanf("%d",&N);
    for(n = 1 ; n <= N ; n++)
	{
		//ATTENTION 1: 第N层右移0单位，第N-1层右移1单位
		for(space = N-n ; space > 0 ; space--)
			printf("  ");
		for(i = n-1 ; i > 0 ; i--) //第n层计算杨辉数字
		{
			A[i] = A[i] + A[i-1];
			printf("%5d",A[i]);//从最右1开始打印，但对称等价从最左
		}
		printf("%5d\n",A[0]); //再错1：注意换行
	}
	return 0;	
}





















/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int a[100] = {0} ;//易错1：第一个初始化为1，其余初始化为0
  int i , j , N ,space; 
  a[0] = 1;
  printf("请指定需要的杨辉三角层数：");
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++ )//杨辉三角N层循环
  {
	  //易错1：配合5%d，1一空格占2个整数位。
	  //第一层N空格，第二次N-1空格.. 
	  for(space=1; space <= N-i; space++)
          printf("  "); 
	  for(j = i ; j > 0 ; j-- ) //第i层i+1个数，对应下标[0,i],计算[i,1]数
	  {                         
            a[j] = a[j]+a[j-1]; //最右侧的1也是计算出来的
            printf("%5d", a[j]);//从最右侧1开始打印，但对称==从最左侧打印

	  }
	  printf("%5d\n",a[0]); //打印最左侧1
  }
 return 0;
                      
}
*/