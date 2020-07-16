#include<stdio.h>
#include<math.h>
#define n 1000

//double _sin(double x); //库中有定义，无需我来写
double area (double (*f)(double) , double a ,double b);
int main()
{
   double area_sin ,area_cos ,area_exp;
   area_sin = area(sin,0,1);  //易错1：传函数指针sin别带()!
   area_cos = area(cos,0,1);
   area_exp = area(exp,0,1);
   printf("sin[0,1]积分：%lf,cos[0,1]积分：%lf,exp[0,1]积分：%lf",area_sin,area_cos,area_exp);
   return 0;
}

//通用计算函数积分：函数指针的使用
double area (double (*f)(double) , double a ,double b)
{
   double det = (b -a) / n ;
   double area = 0;
   int i; 
   for(i = 1 ; i <= n ; i++)
   {
	   area += (*f)(a+det * i) * det; //易错2: f不是函数名，*f才是！  
   }
   return area;
}