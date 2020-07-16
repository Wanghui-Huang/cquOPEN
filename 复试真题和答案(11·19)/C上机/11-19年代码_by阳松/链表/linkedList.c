#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//增 删 改 查 

typedef struct student {
	int number;
	char name [20];
	double score;
	struct student *next;
}stu,*pstu;

void printList (pstu phead);
void insert_head_list (pstu *pphead,pstu *pptail,int num,char name [20]);
void insert_tail_list (pstu *pphead,pstu *pptail,int num,char name [20]);
void insert_sort_list (pstu *pphead,pstu *pptail,int num,char name [20]);
void delete_list (pstu *pphead,pstu *pptail,int num);
void modify_list (pstu phead,int num,double score);
pstu find_list (pstu phead,int num);


pstu find_backward_list (pstu phead,int n); 
void reverse_list (pstu *pphead,pstu *pptail); 
void delete_duplicete_list (pstu phead);
pstu merge_list (pstu *pphead1,pstu *pptail1,pstu *pphead2,pstu *pptail2);

int main (){
	int num;
	char name [20];
	double score; 
	pstu pt=NULL;
	pstu phead,ptail,phead1,ptail1;
	phead=NULL;		//链表的初始化 
	ptail=NULL;
	
	phead1=NULL;		//链表的初始化 
	ptail1=NULL;
		
	while (printf("输入学生信息"),scanf("%d%s",&num,name)!=EOF){
//		insert_head_list(&phead,&ptail,num,name);
//		insert_tail_list(&phead,&ptail,num,name);
		insert_sort_list(&phead,&ptail,num,name);
	}
	printList (phead);
	
	printf("\n" );
	
	while (printf("输入学生信息"),scanf("%d%s",&num,name)!=EOF){
//		insert_head_list(&phead,&ptail,num,name);
//		insert_tail_list(&phead,&ptail,num,name);
		insert_sort_list(&phead1,&ptail1,num,name);
	}
	printList (phead1);
	
		
//	printf("开始删除节点" );
//	while (scanf("%d",&num)!=EOF){
//		delete_list(&phead,&ptail,num);
//		printList (phead);;
//	}
//	printf("开始修改结点" );
//	while (scanf("%d%lf",&num,&score)!=EOF){
//		modify_list (phead,num,score);
//		printList (phead);;
//	}


//	printf("开始查找倒数第n个结点结点" );
//	scanf("%d",&num);
//	pt=find_backward_list (phead,num); 
//	if(pt==NULL)
//	{
//		printf("链表中无此元素" ); 
//	}else 
//	{
//		printf("%s %lf",pt->name ,pt->score ); 
//	 } 
	
	printf("\n" );
	merge_list (&phead,&ptail,&phead1,&ptail1);
	printList (phead);
	
	return 0;
}


void insert_head_list (pstu *pphead,pstu *pptail,int num,char name [20]){
	pstu pnew;
	pnew=(pstu)calloc(1,sizeof(stu));
	pnew->number =num;
	strcpy(pnew->name,name);
	if(NULL==*pphead){
		*pphead=pnew;
		*pptail=pnew;
	}else {
		pnew->next =*pphead;
		*pphead=pnew;
	}

} 

void printList (pstu phead){
	pstu p=phead;
	while (p!=NULL){
		printf("%d %s %lf\n",p->number ,p->name ,p->score );
		p=p->next ;
	}
	
}


void insert_tail_list (pstu *pphead,pstu *pptail,int num,char name [20]){
	pstu pnew;
	pnew=(pstu)calloc(1,sizeof(stu));
	pnew->number =num;
	strcpy(pnew->name,name);
	if(NULL==*pphead){
		*pphead=pnew;
		*pptail=pnew;
	}else {
		(*pptail)->next  =pnew;				//注意要加括号 
		*pptail=pnew;
	}	
}

void insert_sort_list (pstu *pphead,pstu *pptail,int num,char name [20]){
	pstu pnew;
	pstu ppre,pcur;
	ppre=pcur=*pphead;
	pnew=(pstu)calloc(1,sizeof(stu));
	pnew->number =num;
	strcpy(pnew->name,name);
	if(NULL==pcur){				//链表为空 
		*pphead=pnew;
		*pptail=pnew;
	}else if(num<pcur->number )//新增节点插入头节点 之前 
	{					
		pnew->next =pcur;
		*pphead=pnew;
	}else						// 新增节点插入链表中间或者链表尾部 
	{
		pcur=pcur->next ;
		while (pcur!=NULL)
		{
			if(pcur->number <num){
				ppre=pcur;
				pcur=pcur->next ;
			}else
			{
				pnew->next =pcur;
				ppre->next =pnew;
				break;
			}
		} 
		
		if(pcur==NULL)
		{
			ppre->next =pnew;		//或者*ptail->next=pnew 
			*pptail=pnew;
		}
	}

}


void delete_list (pstu *pphead,pstu *pptail,int num)		
{
	
	pstu pprev, pcur ;
	pprev=pcur=*pphead;
	
	if (NULL==*pphead)			//链表为空 
	{
		printf("链表为空");	
	}else if(num==pcur->number )	//删除节点为 头结点 
	{
		*pphead=(*pphead)->next ;
		free(pcur);
		if(NULL==*pphead)
		{
			*pptail=NULL;	
		}
	}else						//删除节点为 中间节点 或者尾结点 
	{
		pcur =pcur->next ;
		while (pcur!=NULL)
		{
			if(pcur->number ==num)
			{
				pprev->next =pcur->next ;
				free(pcur); 
				break;
			}
			pprev=pcur;
			pcur=pcur->next ;
			
		}
	 	
	 	if(pcur==*pptail){
	 		*pptail=pprev;
		 }
		if(NULL==pcur)
		{
			printf("删除的节点不存在\n"); 
		}
	 } 	
}


void modify_list (pstu phead,int num,double score)			//修改链表元素 
{
	pstu pt=phead;
	while (pt!=NULL){
		if(pt->number ==num)
		{
			pt->score =score;
			break;
		}
		pt=pt->next ;
	}
	if(pt==NULL)
	{
		printf("修改失败"); 
	}
	
} 

pstu find_list (pstu phead,int num)						//查找元素 
{
	pstu pt=phead;
	while (pt!=NULL)
	{
		if(pt->number ==num)
		{
			break;
		}
		pt=pt->next;
	}
	return pt;
}


