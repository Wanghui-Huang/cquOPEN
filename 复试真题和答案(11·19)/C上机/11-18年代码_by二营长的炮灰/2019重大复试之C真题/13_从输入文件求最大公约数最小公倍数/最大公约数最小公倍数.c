#include<stdio.h>

int gcd(int num1,int num2);
int main()
{
  FILE* in,*out;
  int num1,num2,g,lcm;
  in = fopen("number.in","r");
  out = fopen("number.out","w");//ATTENTION 0:以"w"每次打开都会清除文件
                     // 因为，"w"打开无论文件是否存在都会重新创建并覆盖
  if(!in || !out)
  {
	  printf("打开文件失败！\n");
	  exit(1);
  }
  while(!feof(in))
  {
	  //错误1:fscanf不用指明"r"
     fscanf(in,"%d %d",&num1,&num2);//空格分隔数字
     g = gcd(num1,num2);
	 lcm = num1 * num2 / g;//最大公倍
     fprintf(out,"%d %d\n",g,lcm);
  }
  fclose(in);//错误2：不关闭文件流
  fclose(out);
  return 0;
}

/*
  求最大公约数：穷举法找出最大能被两数整除的
  判断条件： i < sqrt(min) 错误，只能说明不是素数
             不能找到最大整除数。应该 i < min
 */
int gcd(int num1,int num2)//ATTENTION 1:不实现build会报错
{
  int min,g = 1,i ; //ATTENTION 2:初始g为1，防止没有最大公约
  min = num1 < num2? num1:num2;
  for(i = 2; i <= min;i++ ) //错误3:<=！最小数是最大公约情况
  {
    if( num1 % i == 0 && num2 % i == 0 )
	{
      g = i; //寻找最大公约数
	}
  }
  return g;
}