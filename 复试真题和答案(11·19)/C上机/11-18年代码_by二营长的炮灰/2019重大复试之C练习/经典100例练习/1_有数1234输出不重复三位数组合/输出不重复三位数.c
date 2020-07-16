#include<stdio.h>
#define N 5 //再错1：可能出现的数字是4个但要写5 0-4

int isdifferent(int num);
int main()
{
/*
   int i , j ,k ,n;
  //1.利用砝码问题思想：解决计算千百位不重复三位数
   //之前的问题1：n = i*100+j*10+k和sum = i*5+j*2+1不同：n一定不会重复出现！
   for(i = 1 ; i <= 4 ; i++ )//千
	   for(j = 1 ; j <= 4 ; j++ ) //百
		   for(k = 1 ; k <= 4 ; k++ ) //十
		   {
			   if(i!=j && i!=k && k!=j ) //ijk不同n一定不会重复
			   {
				 n = i*100+j*10+k;
				 printf("%d\n",n);
			   }	  
		   }
}
*/
  int i;
  for(i = 1234 ; i <= 4321 ; i++)
  {
	  if(isdifferent(i))
		  printf("%d\t",i);
  }
  return 0; 
}
//[背]判断num是否数不同：一位数组+循环获取低位操作模板
int isdifferent(int num)
{
	int A[N] = {0},low;
	int temp = num;
	while(temp != 0)
	{
		low = temp%10;
		if(low==0 ||low>4 ||++A[low]>1)//再错2：还要判断只能出现1-4
			return 0;
		temp = temp/10;
	}
	return 1; 
}