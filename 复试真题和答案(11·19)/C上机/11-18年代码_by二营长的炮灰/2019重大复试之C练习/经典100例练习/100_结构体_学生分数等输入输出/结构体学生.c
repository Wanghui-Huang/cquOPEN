#include<stdio.h>

struct student
{
	int ID;
	char name[10];
	int cpp;
	int c;
	float average;
}stu;      //ATTENTION 1 : 结构体变量声明方式1
int main()
{
  FILE* out;
  struct student  s[2]; //ATTENTION 2 : 结构体变量声明方式2
  int i;
  for(i = 0 ; i < 2 ;i++)
  {
	//易错1：以逗号为分隔符会产生意料之外的错误，建议空格/*c
    scanf("%d %s %d %d",&s[i].ID,&s[i].name,&s[i].cpp,&s[i].c);
	s[i].average = (s[i].cpp + s[i].c) / 2.0;
  }
  //写入文件
  out = fopen("stu.out","w");
  for(i = 0 ; i < 2 ;i++)
  {
    fprintf(out,"%d,%s,%d,%d,%f\n",s[i].ID,s[i].name,s[i].cpp,s[i].c,s[i].average);
  }
  fclose(out);
  return 0;
}