#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPrime(int num);
int isSym  (int num);
int main()
{
  int num;
  int is4;  //四位数不会对称素数
  printf("请输入一个数字:\n");
  scanf("%d",&num);
  is4 = num >=1000 && num <= 9999;
  //错误1：isPrime && isSym 不传参数
  if(!is4 && isPrime(num) && isSym(num))
	  printf("%d 是对称素数！\n",num);
  else
	  printf("%d 不是对称素数！\n",num);
  return 0;
}

/*
      判断是否素数：一个数若可以进行因数分解，那么分解时得到的两个数一定是
  一个小于等于sqrt(n)，一个大于等于sqrt(n)，据此，代码遍历到sqrt(n)即可，
  因为若sqrt(n)左侧找不到约数，那么右侧也一定找不到约数
*/
 int isPrime(int num)
 {
	 int i ;
	 for(i = 2; i <= sqrt(num);i++)
	 {
		 if(num % i == 0)
			 return 0;         //注意如果不是就直接return退出函数
	 }
	 return 1 ;
 }

 //判断是否对称:计算该数的回文数，如321 计算出123 ，比较相等否
 //背：获取整数每一位，并操作模板
 int isSym  (int num)
 {
	 int temp = num;
	 int sum  =0;
	 while(temp != 0)
	 {
		 //每次计算出该数最低位temp%10，就加上之前计算的最低位*10进一位
		 sum = sum*10 + temp%10 ; //操作
		 temp = temp /10 ;       
	 }
	 return sum==num;    //错误3:不要写 sum == temp！！
 }