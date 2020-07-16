#include<stdio.h>
#define MAX 100

void del(int A[],int len, int p1 , int p2);
int main()
{
  int A[MAX] = {0}; //ATTENTION0 : {0}是全部初始0，{1}只A[0]=1其余0
  int i,min,max,len;
  float average , sum = 0;  //易错1：不给sum初始化使用会是奇怪的数
  i = max = min = len = 0;
  /*
    1.ATTENTION 1：连续赋值，ctrl+c退出
	2.使用while + scanf连续赋值必须getchar()读取空格/回车
	3.可能会有愚蠢的ox4001005错误，高冷忽略。
  */
  while((scanf("%d",&A[i++])) != EOF)
	  getchar(); 
  len = i - 1;
  for(i = 1; i < len ; i++)//背：一次遍历寻找到最大和最小
  {
	 if(A[i] < A[min])
	   min = i;
	 else if(A[i] > A[max]) //注意else if
	   max = i;
  }
  del(A,len,min,max);
  len = len - 2; //记录删除后数组长度
  for(i = 0; i < len ; i++)
    sum += A[i];
  average = sum / len;
  printf("平均值 = %f",average);
  return 0;
}
//背：o(n)删除数组满足条件的元素，这里指的删除下标p1、p2对应数
void del(int A[], int len,int p1 , int p2)
{
  int i , k = 0;
  for(i = 0; i < len ; i++) 
  {
    if( i == p1 || i == p2)
		continue;     //结束这次循环，i指针后移，k指针不变
	A[k++] = A[i] ; //如果不是要删除的就赋值，i、k一起后移
  }
}