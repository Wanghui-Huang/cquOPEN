#include <stdio.h>
#include <stdlib.h>

int compare (const void *a,const void *b);
typedef struct {
	int ID;
	char namen [20];
	double score1,score2;
	double avr;
}stu,*pstu;


int main ()
{
	FILE *fout,*fin;
	stu student[20];
	int i;
	int cnt;
	char name ;
	int ID;
	double score1,score2;
	fout=fopen("student.txt","wb");
	while (scanf("%d%s%lf%lf",&student[i].ID,student[i].namen,&student[i].score1,&student[i].score2)!=EOF)
	{
		student[i].avr =(student[i].score1+student[i].score2)/2;
		i++;
	}
	cnt=i;
	qsort(student,cnt,sizeof(stu),compare);
	for(i=0;i<cnt;i++)
	{
		printf("%s %lf\n",student[i].namen ,student[i].avr);
		fwrite(&student[i],sizeof(stu),1,fout);
	}
	fclose(fout);


	
	return 0;	
}

int compare (const void *a,const void *b)
{
	pstu  p1=(pstu)a;
	pstu p2=(pstu)b;
	return p1->avr - p2->avr  ;
}
