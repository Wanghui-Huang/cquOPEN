#include <stdio.h>
#define SIZE 10000
//有一个天平有6中砝码，分别重 1，2,3,5,10,20 每种砝码 各有 5. 3 .2.2.1.1.个
//计算天平能称出的重量和种类
int ret[SIZE]={0}; 
int cnt;
int main ()
{
	int i,j,k,m,n,h;
	
	cnt=0;
	int sum; 
	for(i=0;i<=5;i++)
	{
		for(j=0;j<=3;j++)
		{
			for(k=0;k<=2;k++)
			{
				for(m=0;m<=2;m++)
				{
					for(n=0;n<=1;n++)
					{
						for(h=0;h<=1;h++)
						{
							sum=i+j*2+k*3+m*5+n*10+h*20;
							if(sum)
							{
								ret[sum]++;	
							}
							
						}
					}
				}
			}
		}
	} 
	
	for(i=0;i<SIZE;i++)
	{
		if(ret[i]>0)
		{
			cnt++;
		}
	}
	printf("一共有%d种重量",cnt);
	return 0;
}
//
//int is_duplicate (int sum)
//{
//	int i;
//	int flag=0;
//	for(i=0;i<cnt;i++)
//	{
//		if(ret[i]==sum)
//		{
//			flag=1;
//			break;
//		}
//	}	
//	
//	
//	return flag;
//} 

