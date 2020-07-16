#include<stdio.h>

/*
  //ATTENTION 1：如果改为%X输出-1A,-12=ffffffd4而非ffffffffffffd4
*/
int main()
{
  __int64 A,B,sum;  //ATTENTION :__int64 等价于longlong，但vc6不支持
  while(1)
  {
  printf("请输入两个十六进制，中间空格隔开：-1A +2A\n");
  scanf("%I64X %I64X",&A,&B); //错误1：%I64X用来接收长整型16
  sum = A+B;                     
  printf("\n%I64X\n",sum);        
  }
  return 0;
}