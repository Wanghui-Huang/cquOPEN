#include<stdio.h>

int main()
{
	__int64 n16_10;
	int n10_16;

	  //16转10(1)
	printf("请输入一个十六进制数(1)：");
	scanf("%X",&n16_10);
	printf("对应十进制数：%d\n",n16_10); //易错1：lld

	  //10转16(1)
	printf("请输入一个十进制数：");
	scanf("%d",&n10_16);
	printf("对应十六进制数：%X",n10_16); 
	return 0;
}