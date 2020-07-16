#include <stdio.h>
#include <stdlib.h>

//求每一行数字的最大公约数和最小公倍数，输入文件 filename16.in ,输出文件filename16.out
//从输入文件中读取数字，每一行两个数字，有多行
#define SWAP(a,b) {int temp;temp=a;a=b;b=temp;}

int max_yueshu (int m,int n);
int min_beishu (int m,int n);
 
int main ()
{
	int m,n;
	int max,min;
	FILE *fin,*fout;
	fin=fopen("filename16.in","r");
	fout=fopen("filename16.out","w");
	
	if(fin==NULL||fout==NULL)
	{
		printf("文件打开失败");
		exit(1); 
	}
	
	while (fscanf(fin,"%d%d",&m,&n)!=EOF)
	{
		//调用函数 求最大公约数和最小公倍数 
		max=max_yueshu (m,n);
		min=min_beishu (m,n);
		fprintf(fout,"%d %d\n",max,min);
	}
	
	return 0;	
} 



int max_yueshu (int m,int n)
{
	int t;
	if(m<n)
	{
		SWAP(m,n);
	}
		
	t=m%n;
	while (t!=0)
	{
		m=n;
		n=t;
		t=m%n;
	}
	return n;
}  


int min_beishu (int m,int n)
{
	int mult;
	mult=m*n;
	return mult/max_yueshu(m,n);
}
