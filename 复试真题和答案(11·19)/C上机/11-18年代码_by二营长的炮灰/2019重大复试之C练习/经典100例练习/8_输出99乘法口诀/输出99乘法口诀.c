#include<stdio.h>

int main()
{
	int i , j , k ;
	for( i = 1 ; i <= 9; i++)
	{
     	for(j = i, k = 1 ; j > 0 ; j--,k++)  //打印j组等式
		{
			printf("%d*%d = %d",i,k,i*k);
			printf(" "); //ATTENTION 1 :打印1空格，直接上面\t打印太宽
		}
		printf("\n");//换行
	}
    return 0;
}