#include<stdio.h>

void printSpace(int n);
void printSpark(int n);
int main()
{
	int N;
	int i;
	printf("请指定要打印的菱形层数：");
	scanf("%d",&N);
	for(i = 1 ; i <= N ; i++)
	{
		if( i <= N/2+1 )//上半层
		{
			printSpace(N/2+1 - i); //先打印空格
            printSpark(2*i-1);     //再打印*号
		}
		else//下半层
		{
			printSpace(i - (N/2+1)); //先打印空格
            printSpark(2*(N-i)+1);    //再打印*号
		}
	}
	return 0;
}
void printSpace(int n)
{
	int i;
	for(i = 0 ; i < n ; i++)  printf(" ");
}
void printSpark(int n)
{
	int i;
	for(i = 0 ; i < n ; i++)  printf("*");
	printf("\n");  //再错1：打完*号就要换行了
}




















/*
#include<stdio.h>

int main()
{
  int space;
  int i , j ,N;
  printf("请输入边长：");
  scanf("%d",&N);
  //先打印上半部分N层
  for( i = 0 ; i < N ;i++) //上半部分N层
  {
	  for(space = N-1-i ; space > 0 ;space--)//打印第i层空格
		  printf(" ");
	  for(j = 0 ; j < 2*i + 1 ; j++)//打印第i层*
		  printf("*");   
	  printf("\n");
  }
  //再打印下半部分N-1层
  //易错1：注意 j = 2*(N-2-i) + 1 ，把下半部分层从第0层开始算得出
  for( i = 0 ; i < N - 1 ;i++) //下半部分N-1层
  {
	  for(space = 0 ; space < i+1 ;space++)//打印第N+i层空格
		  printf(" ");
	  for(j = 2*(N-2-i) + 1 ; j > 0 ; j--)//打印第N+i层*
		  printf("*");   
	  printf("\n");
  }
  return 0;
}
*/

