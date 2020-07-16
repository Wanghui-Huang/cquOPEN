#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//每个案例第一行两个整数N，M，2 <= N，M <=200。
//接下来有N行，第i（i = 1,2，…，N）行每一行有一个数，
//表示读者i-1最喜欢的图书的编号P（1 <= P <= M）
//4 5
//2
//3
//2
//1

typedef struct {
	
	int cnt;		//记录他的潜在朋友数目 
	int book;
	
}stu,*pstu;

int main () {

	
	int n,m;
	int i,j;
	pstu s;
	int cnt;
	int book;
	while (scanf("%d %d",&n,&m)!=EOF)
	{
		s=(pstu)calloc(n,sizeof(stu));
		for(i=0;i<n;i++)
		{
			cnt=0;
			scanf("%d",&book);
			for(j=0;j<i;j++)
			{
				if(s[j].book ==book)
				{
					s[j].cnt ++;
					cnt++;
				}
			}
			s[i].book =book;
			s[i].cnt  =cnt;
		}
		
		for(i=0;i<n;i++)
		{
			if(s[i].cnt ==0)
			{
				printf("BeiJu");
			}else
			{
				printf("%d",s[i].cnt);
			}
			printf("\n");
		}
		
	}
	
	
	
	
	return 0;
} 
