#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXKG 1001 //ATTENTION 1: 不是1000，因为要求还要考虑1000g

int* farmarWeighing(int n1,int n2,int n3,int n5,int n10,int n20);
int main()
{
  int n1,n2,n3,n5,n10,n20 ,i,* N ;
  printf("请输入1，2,3,5,10,20克砝码个数,如：5 3 2 2 1 1\n");
  scanf("%d %d %d %d %d %d",&n1,&n2,&n3,&n5,&n10,&n20);
  //N =farmarWeighing(5,3,2,2,1,1);
  N =farmarWeighing(n1,n2, n3, n5, n10, n20);
  for(i = 1 ;i < MAXKG ; i++ )
  {
	  if(N[i]) //重量i对应称重方式不为0
       printf(" %d克:共有%d种方式称重\n",i,N[i]);
  }
  return 0;
}

/*
  题目要求求出能称出的重量不大于1000克和方式个数，如 1克 有3种方式
  N* :	下标存能称的重量，值存方式个数
*/
int* farmarWeighing(int n1,int n2,int n3,int n5,int n10,int n20)
{
	int i,j,k,l,m,n,sum;
	int* N = (int*)malloc(sizeof(int) * MAXKG); 
	memset(N,0,sizeof(int) * MAXKG);//ATTENTION 2: [0-1000]被初始0，含1000克
	for(i = 0 ; i<= n1 ;i++) //错误2：小于等于号！
		for(j = 0 ; j<= n2 ;j++)
			for(k = 0 ; k<= n3 ;k++)
				for(l = 0 ; l<= n5 ;l++)
					for(m = 0 ; m<= n10 ;m++)
						for(n = 0 ; n<= n20 ;n++)
						{
							sum = i*1 + j*2 + k*3 + l*5 + m*10 + n*20;
                            if(sum)//ATTENTION 3：if(0)不执行，其余正负都执行 
								N[sum] ++; //sum克对应称重方式+1
						}
    return N;
}