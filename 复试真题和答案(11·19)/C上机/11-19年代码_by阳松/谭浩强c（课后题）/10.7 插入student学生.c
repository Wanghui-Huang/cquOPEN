#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ID;
	char namen [20];
	double score1,score2;
	double avr;
}stu,*pstu;

int main ()
{
	FILE *fin,*fout;
	stu student[20];
	int i;
	stu snew; 

	int cnt=0;			//统计有多少个 stu 元素 
	fin=fopen("student.txt","rb");
	while (!feof(fin)){
		if(fread(&student[cnt],sizeof(stu),1,fin)==1)
		{
			cnt++;
			
		}
	}
	i=cnt-1;
	printf("%d\n",cnt);
	 
	printf("输入学生\n");
	
	scanf("%d%s%lf%lf",&snew.ID,snew.namen,&snew.score1,&snew.score2);
	snew.avr=(snew.score1+snew.score2)/2;
	
	while (i>=0&&snew.avr < student[i].avr )
	{
		student[i+1]=student[i];
		i--;
	} 
	student[i+1]=snew;
	cnt++;
	
	for (i=0;i<cnt;i++)
	{
		printf(" %s %lf\n",student[i].namen,student[i].avr);
	}
	
	return 0;
}
