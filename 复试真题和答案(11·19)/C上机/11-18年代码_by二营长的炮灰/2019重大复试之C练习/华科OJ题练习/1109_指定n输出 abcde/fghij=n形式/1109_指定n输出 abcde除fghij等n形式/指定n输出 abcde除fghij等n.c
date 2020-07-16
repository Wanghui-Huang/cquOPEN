#include<stdio.h>

int diffrent(int a , int b);
int main()
{
	int n;
	int abcde,fghij; 
    //double abcdefghij ; //ab将数a-数b，合为一数判断不同(错误1：数太大)
	printf("请输入指定n：");
	scanf("%d",&n);
	//1.0 暴力循环 （98762-1234）* （98762-1234)执行不下去
	//2.0 给了指定n，遍历fghij++同时* n ,算出abcde，abcde,fghij不同则满足 
	for(fghij = 1234 ; fghij*n <= 98765 ; fghij++)
	{
		abcde = fghij * n;
		if(diffrent(abcde,fghij))
			printf("%d / % d = %d \n" ,abcde,fghij,n);
	}
	return 0;
}

//判断数字是否每位都不同
int diffrent(int abcde , int fghij)
{
	int A[10] = {0};
	int low ; //获取最低位
	//易错2：是四位数前面0也要考虑不要重复
	if(abcde >= 1000 && abcde <= 9999) //是4位数
		A[0]++;
    if(fghij >= 1000 && fghij <= 9999) //是4位数
		A[0]++;
	while(abcde) //易错 3 ：while(!abcde) abcde为0才执行，错误！
	{
		low = abcde % 10;
		A[low]++; //标识此时n某位数字low，个数+1
		if(A[low] > 1)
			return 0; //存在某位数字存在个数>1
		abcde = abcde /10;
	}
	while(fghij) 
	{
		low = fghij % 10;
		A[low]++; 
		if(A[low] > 1)
			return 0; 
		fghij = fghij /10;
	}
	return 1;
}