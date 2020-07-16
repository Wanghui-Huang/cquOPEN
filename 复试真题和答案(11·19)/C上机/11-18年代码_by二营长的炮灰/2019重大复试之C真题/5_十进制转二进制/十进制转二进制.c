#include<stdio.h>
#include<stdlib.h>
#define MAX 100

char* dectoB(int dec); //ATTENTION 0:这里用char*比int*好

int main()
{
	int dec;
	char* binary;
	printf("请输入一个十进制数字：");
	scanf("%d",&dec);
    binary = dectoB(dec);
	printf("对应二进制数：%s",binary);
	return 0;
}

//[背]整数转二进制：除2取余，判商赋商，逆序排列
//再错1:数字0 1记得转换成char类型,且只：binary[i] = r + '0';
//      binary[i] = (char)r;  错误！
char* dectoB(int dec)
{
   int r; //余数
   int q; //商
   int i , j;
   char* binary = (char*)malloc(sizeof(char)*MAX),temp;
   for(i = 0 ; q != 0 ; i++ )
   {
	   r = dec % 2;
	   binary[i] = r + '0'; 
	   q = dec / 2;
	   dec = q;
   }
   binary[i] = '\0';  //再错2：字符数组一定要记得设置'\0'
   i = i-1;  //i-1是此时binary最大下标
   for(j = 0 ; j < i ; j++,i-- )  //反转binary：实现二进制正序
   {
	   temp = binary[j];
	   binary[j] = binary[i];
       binary[i] = temp;
   } 
   return binary;
}























/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* intToB(int integer);
int* decToB(double decimal);
#define MAXSIZE 100

int main()
{
  //再次强调：c89最好把变量都定义在前面。否则疯狂报错！！
  double num;                 
  int integer;
  double decimal;
  int* B1 ,* B2;        //存储整数和小数部分对应的十进制数组
  int i ;
  printf("请输入一个十进制数： ");
  scanf("%lf",&num);    //错误1：double型变量应该用%lf！！
  integer = (int)num; //获取浮点数整数
  decimal = num - integer; //获取浮点数小数
  printf("\n （%f）2 =  ", num);
  //输出二进制
  B1 = intToB(integer);
  B2 = decToB(decimal);
  for(i = 0 ; B1[i] != -1 ; i ++); //找到B1末尾指向-1处
  while(i != 0)
  {
	  i--; //逆序输出
	  printf("%d",B1[i]);
  }
  printf(".");
  for(i = 0 ; B2[i] != -1 ; i ++)
  {
	  printf("%d",B2[i]);
  }
  return 0;
}

//整数转二进制：除2取余，判商赋商，逆序排列
int* intToB(int integer)
{
	int* B1 = (int*)malloc(sizeof(int) * MAXSIZE);
	//错误2：初始就计算商防止0时进入循环
	int quotient = integer / 2 ,remainder ; 
	int i = 0;
	while(quotient != 0)//ATTENTION 1 :当商不等于0
	{
      quotient  = integer / 2; //商
      remainder = integer % 2; //余数
	  B1[i++] = remainder; //错误2：保存商×保存余数！ 
      integer = quotient ;
	}
    B1[i] = -1; //设置终止条件
	return B1;
}

//小数部分转二进制：乘2取整，判小赋小，顺序排列
int* decToB(double num)
{
  int* B2 = (int*)malloc(sizeof(int) * MAXSIZE);
  int integer ;
  //错误4：初始就计算小数防止0时进入循环
  double dec =  num - (int)num ;  //错误5：千万注意小数部分定义成double！
  int i = 0;
  while(dec != 0)//ATTENTION 2 :当小数部分不等于0
  {
	  num = num*2;
      integer = (int)num; 
      dec = num - integer;
	  B2[i++] = integer;   //保存整数
	  num = dec;          //此时num被赋值为小数部分
  }
  B2[i] = -1; //终止条件
  return B2;
}
*/