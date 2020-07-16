#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int strcmp01(char* s1,char* s2);
int main()
{
	char** s,*temp; 
	int n;
	int i,j;
	printf("请指定输入01字符串个数：");
	scanf("%d",&n);
	s = (char**)malloc(sizeof(char*)*n); //再错1：指定二维数组大小
    for( i = 0 ; i < n ; i++)
	{
		s[i] = (char*)malloc(sizeof(char)*MAX);
		printf("请输入第%d串：",i+1);
		scanf("%s",s[i]);
	}
	//[背]尾冒泡排序：不写函数？1.简单2.每一轮可确定一个数直接输出
	for(i = 0 ; i < n ; i++) //不写n-1，方便输出第n大字符串
	{
		for(j = n-1 ; j-i > 0 ; j--)//j-i表示执行j-i次，每轮递减
		{
			if(strcmp01(s[j],s[j-1]) == -1)
			{
				temp = s[j]; 
				s[j] = s[j-1]; 
				s[j-1] = temp;
			}
		}
		printf("%s\n",s[i]); //输出每轮最小
	}
    return 0;
}

//比较01字符串大小
int strcmp01(char* s1,char* s2)
{
	int len1,len2,s1_cout1 = 0,s2_cout1 = 0;
	int i,j;
	len1 = strlen(s1);
    len2 = strlen(s2);
	if(len1 > len2)  return 1;
	if(len1 < len2)  return -1;
	//字符等长，开始比较1个数
	for(i = 0 ; i < len1 ; i++)
		if(s1[i] == '1')  s1_cout1++;
	for(j = 0 ; j < len2 ; j++)
		if(s2[j] == '1')  s2_cout1++;
	if(s1_cout1 == s2_cout1)  return 0;
	if(s1_cout1 >  s2_cout1)  return 1;
	if(s1_cout1 <  s2_cout1)  return -1;
}









/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100
int strcmp01(char str1[],char str2[]);
void strSort01(char *s[],int N);

int main()
{
    
	/*
	  错误1：为什么定义指针数组？
	         比较时交换指针即可。数组名是常量就只能strcpy复制开销大。
      错误2：char *s[10] 和 char (*s)[10] 区别？
	       char *s[10]：[]优先级更高先和s结合，表示s是数组，有10个char*
		   char (*s)[10]：s先和*结合表示s是指针，指向有10个元素的数组。
	
   int N , i; 
   char **s; 
   printf("请指定要输入的字符串个数:");
   scanf("%d", &N); //错误2：＋&呀！
   s = (char**)malloc(sizeof(char*) * N); //动态指定二维数组大小
   //   char *s[N]; //错误3：数组s[]中[]必须常量
   for(i = 0; i < N ; i++)
   {
	 s[i] = (char*)malloc(sizeof(char) * MAXSIZE);
     printf("\n请输入字符串%d :",i);
	 scanf("%s",s[i]);
   } 
   //输出
   strSort01(s,N);
   for(i = 0; i < N ; i++)
   {
	   printf("%s\n",s[i]);
   }
	/*strcmp01()测试通过
   char* s1 = "0011";
   char* s2 = "1000";
   char* s3 = "11000";
   int a = strcmp01(s1,s2); //应该为1
   int b = strcmp01(s1,s3); //应该为-1
   int c = strcmp01(s2,s3); //应该为-1
   
   return 0;
}

//比较两串01字符串的大小
//ATTENTION 1: strcmp()函数比较和长度无关，只比较
//遇到的第一个不同字符的ASCII码大小
int strcmp01(char *s1,char *s2) //传指针开销小点
{
  int count0_s1,count0_s2,i;
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  if(len1 > len2) 
	  return 1 ;
  if(len1 < len2)
	  return -1 ;
  //执行到这说明等长,统计0个数，0多小
  for(i = 0 ; i < len1 ; i++)
  {
	  if(s1[i] == '0')
	  {
       count0_s1++;
	  }
  }
  for(i = 0 ; i < len2 ; i++)
  {
	  if(s2[i] == '0') //一开始写s1..找半天错误
	  {
       count0_s2++;
	  }
  }
  if(count0_s1 == count0_s2)//0(或者说1)个数相等
	  return 0;
  if(count0_s1 > count0_s2) //错误4:0多说明更小！
	  return -1;
  if(count0_s1 < count0_s2)
	  return 1;
}

//多个01字符串排序
//ATTENTION1 :数组名作参数会退化成指针取不到数组长度
//所以还传递字符串个数N
void strSort01(char **s,int N) 
{
 char *ptemp ;//因为稍后交换指针是地址，定义临时指针
 int i , j ;
 for(i = 0 ; i < N- 1 ; i++) //n数交换法有n-1轮
	 for(j = i+1; j < N ; j++) //动态指针j指向i+1开始
	 {
	  //最深错误5：写if(strcmp01(s[i] , s[j] ))
		 //会导致s[i] < s[j] 取 -1时也执行
       if(strcmp01(s[i] , s[j] ) == 1) //升序排列，交换保持top最小
	   {
		   ptemp = s[i];
		   s[i] = s[j];
		   s[j] = ptemp;
	   }
	 }
}
*/