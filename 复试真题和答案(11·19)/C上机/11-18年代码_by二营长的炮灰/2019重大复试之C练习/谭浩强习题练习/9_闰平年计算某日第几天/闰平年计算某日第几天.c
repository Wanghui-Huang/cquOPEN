#include<stdio.h>
struct Date
{
	int year;
	int month;
	int day;
}date; // 易错:这里的date是变量，直接用！如果加了typedef是类型！
int days(int year,int month,int day);
int main()
{
  int day;
  printf("请输入年 月 日，以空格分隔：");
  scanf("%d %d %d",&date.year,&date.month,&date.day); 
  day = days(date.year,date.month,date.day);
  printf("该天是 %d 年第 %d 天", date.year,day);
  return 0;
}
  
int days(int year,int month,int day)
{
   int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};  
   int sum,i;
   sum=day;
   for(i=0;i<month-1;i++)
  	     sum+=a[i]; 
  //闰年: 1.能被4整除但不能被100整除 2.能被400整除
  if(((year%4==0 && year%100!=0)|| year%400==0) && month>2)
      sum = sum + 1; //加1天
  return sum;
}


