#include<stdio.h>
#include<string.h>
#define MAX 100

void move1_m(int A[],int N ,int m);
void move2_m(int A[],int N ,int m);
int main()
{
	int A[MAX] = {0}; //控制终止：1.设置-1等元素2.设置长度
	int i ,len, m ;
	/*
	 汇总：1.用ctrl+c结束会有不可意料错误 
	       2.可能会输入-1，但只能这么判断。读入字符%c再转数字只能转0-9
		   3.[注]这里不用getchar()
	*/
	printf("请输入数组元素，输入-1回车结束，元素空格相隔：");
	for(i = 0 ; scanf("%d",&A[i]) && A[i] != -1 ; i++);   
    len = i;
	printf("请指定数组偏移m：");
	scanf("%d",&m);
	move1_m(A,len,3);
	//move2_m(A,len,3);
	for(i = 0 ; i < len ; i++)
		printf("%d  ",A[i]);
	return 0;	
}
/*
  指定数组前N位循环右移1：为什么传长度N，-1不就可以判断终止吗？
      因为：为了可维护性，如果改变终止条件不是-1呢？
*/
void move1_m(int A[],int N,int m)
{
	int A1[MAX] = {0};
	int i;
	for(i = 0 ; A[i] != -1 ; i++)
	{
		A1[i] = A[(i+m)%N];
	}
	memcpy(A,A1,sizeof(int)*N);//再错1: int数组复制，指定字节
}

//循环右移思路2      
void move2_m(int A[],int N,int m)
{
   m = m % N;  //m取余
   int temp , i ,j; //temp记录A尾元素A[N-1]
   for(i = 0 ; i < m ; i++) //偏移m移动m次
   {
	   temp = A[N-1];
	   for(j = N-1; j > 0 ; j--)
	   {
		   A[j] = A[j-1]; //犯错:A[j-1] = A[j]
	   }
	   A[0] = temp; //尾元素偏移+1 = 首元素
   }
}






















/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void move1_m(int A[],int N,int m); //不用定义指针，没有交换
void move2_m(int A[],int N,int m); 
int main()
{
  int A[100] = {0}, i = 0 , N = 0 ,m;  //不定义数组原因：见下
  char c ;
  //ATTENTION 0：①让用户连续输入,SCANF()在前
               //②用户指定N更简单，for(i =0 ; i < N ;i++) {scanf()}
  while(scanf("%c",&c) && c != 'y') //scanf返回值是成功读入数个数>=0
  {
	  getchar();//极其易错1：getchar()读掉回车(或空格)，否则出错
	  A[i++] = c-'0';
	  N++;   //数组长度+1
  }
  printf("指定偏移：");
  scanf("%d",&m);
  for(i = 0 ; i < N ; i++) 
	  printf("%d",A[i]);
 // move1_m(A,N,m); 
  move2_m(A,N,m);
  for(i = 0 ; i < N ; i++) 
	  printf("%d",A[i]);
  return 0;
}

/*循环右移动数组：
ATTENTION 1:①虽然可传数组名A，但A（首地址）不能改变，无法像指针交换元素地址
            ②还有传数组长度，确定终止条件
       思路1：A [6] = {1 2 3 4 5 6}
	       (1) 先考虑如何右移一个单位？为了避免思考最后一位6移动越界循环移难题
		          ①将6暂存，12345往后移动 A[i] = A[i-1]
				  ②最后6右移动一位： A[0] = 6
		   (2)要移动m位，则重复(1)操作m次即可。
	   思路2: 对比字符向后偏移：s1[i] =(s[i]+m)%256; //会自动取余256可省
	       (1) 再定义一个数组 A1[6] 
	       (2) A1[i] = A[(i+m)%6] 
	二者不同：s1、s相当存字符对应下标(ASCII值)，s1[i]保存字符偏移后的下标
		         A1、A存的是值，A1[i]保存字符偏移后的下标，所对应值

void move1_m(int A[],int N,int m)
{
   int _m = m % N;  //m取余
   int temp , i ,j; //temp记录A尾元素A[N-1]
   for(i = 0 ; i < m ; i++) //偏移m移动m次
   {
	   temp = A[N-1];
	   for(j = N-1; j > 0 ; j--)
	   {
		   A[j] = A[j-1]; //犯错:A[j-1] = A[j]
	   }
	   A[0] = temp; //尾元素偏移+1 = 首元素
   }

}

//多定义一个数组，实现偏移
void move2_m(int A[],int N,int m)
{
	int A1[100] = {0} ,i;
    for(i = 0 ; i < N ; i++)
	{
		A1[i] = A[(i+m)%6]; //ATTENTION 1 :这里没有先对m取余
	}
	memcpy(A,A1,sizeof(A1));//ATTENTION 2 : int数组复制，sizeof获取A1长度100*4字节
}
*/