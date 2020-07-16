#include <stdio.h>
#include <stdlib.h>

//有一个记录学生信息的文件，每一行记录一名学生的信息，格式入下 学号\t 姓名\t 性别\t 分数 1\t 分数 2\t 分数 3\n. 要求：
//（1）读取文件的内容，串成一个链表。 （2）按照总分递减排序将结果保存到原文件。
#define N 50

typedef struct student {
	int id;
	char name [20];
	int sex;
	double score1,score2,score3;
	double sum;
	struct student *next;
	
}stu,*pstu;

void insert_sort_list (pstu *pphead,pstu *pptail,pstu pnew)	;

int main (){
	FILE *fin,*fout;
	pstu phead,ptail;
//	int cnt=0;
	pstu p;
	int ret;
	phead=ptail=NULL;
	
	fin=fopen("filename.in","r");
	fout=fopen("filename.out","w");
	if(fin==NULL||fout==NULL)
	{
		printf("文件打开失败");
		exit(1); 
	}
	p=(pstu)calloc(1,sizeof(stu));
	while((ret=fscanf(fin,"%d%s%d%lf%lf%lf",&p->id ,p->name ,&p->sex ,&p->score1 ,&p->score2 ,&p->score3 ))==6)			//取地址忘了 
	{
		p->sum =p->score1 +p->score2+p->score3;
//		s[cnt++]=p;
		insert_sort_list (&phead,&ptail,p)	;
		
		p=(pstu)calloc(1,sizeof(stu));
		if(p==NULL)
		{
			printf("动态分派空间失败");
			exit(1); 
		}		
	}
	
	p=phead;
	while (p!=NULL)
	{
		fprintf(fout,"%d\t%s\t%d\t%lf\t%lf\t%lf\t%lf\n",p->id ,p->name ,p->sex ,p->score1 ,p->score2 ,p->score3,p->sum  );
		
		p=p->next ; 
	}
	return 0;
} 
 
void insert_sort_list (pstu *pphead,pstu *pptail,pstu pnew)			//插入链表 
{
	pstu pprev,pcur;
	pprev=pcur=*pphead;

	if(*pphead==NULL)			//当前链表为空 
	{			
		*pphead=pnew;
		*pptail=pnew;
	}else	if(pnew->sum >pcur->sum )			//在头结点 前面插入 
	{
		pnew->next =pcur;
		*pphead=pnew;
		
	}else					//插入为中间节点或者尾结点 
	{
		pcur=pcur->next ;
		while (pcur!=NULL)
		{
			if(pcur->sum > pnew->sum )
			{
				pprev=pcur;
				pcur=pcur->next ;
			}else
			{
				pnew->next =pcur;
				pprev->next =pnew;
				break;
			}
		}
		
		if (pcur==NULL)
		{
			pprev->next =pnew;
			*pptail=pnew;
		}
	}
	
	
}


