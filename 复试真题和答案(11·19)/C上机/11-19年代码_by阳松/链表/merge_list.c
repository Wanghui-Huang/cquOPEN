#include <stdio.h>

//将两个有序链表合并成一个有序链表。
typedef struct student {
	int number;
	char name [20];
	double score;
	struct student *next;
}stu,*pstu;

int main (){
	
	
	
	return 0;
} 

pstu merge_list (pstu *pphead1,pstu *pptail1,pstu *pphead2,pstu *pptail2)		//将两个有序链表合并为一个有序链表 
{
	pstu p1,p2;
	p1=*pphead1;
	p2=*pphead2;
	*pphead1=*pptail1=NULL;
	*pphead2=*pptail2=NULL;
	 
	while (p1!=NULL&&p2!=NULL){
		if(p1->number < p2->number)
		{
			if(*pphead1==NULL)
			{
				*pphead1=*pptail1=p1;
				
			}else
			{
				(*pptail1)->next =p1;
				*pptail1=p1; 
			}
			
			p1=p1->next ;
		}else
		{
			if(*pphead1==NULL)
			{
				*pphead1=*pptail1=p2;
				
			}else
			{
				(*pptail1)->next =p2;
				*pptail1=p2; 
			}
			
			p2=p2->next ;
		}
	}
	
	if(p1==NULL)
	{
		(*pptail1)->next =p2;
		while(p2->next !=NULL)
		{
			p2=p2->next ;
		}
		*pptail1=p2;
	}else
	{
		(*pptail1)->next =p1;
		while(p1->next !=NULL)
		{
			p1=p1->next ;
		}
		*pptail1=p1;	
	}
	
}
