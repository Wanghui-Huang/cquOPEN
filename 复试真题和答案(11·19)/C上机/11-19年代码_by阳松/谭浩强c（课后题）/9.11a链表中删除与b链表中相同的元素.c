#include <stdio.h>
#include <stdlib.h>


//有两个链表 a，b，从a链表中删除与b链表中相同的元素

typedef struct student{
	int num;
	struct student *next;
}Node,*pNode;
int main ()
{
	
	return 0;	
} 

void delete_list_a (pNode phead1,pNode phead2)		//假设两个链表是有序的 
{
	pNode p1,prev;
	pNode p2= phead2;
	p1=prev= phead1;
	pNode pt;
	while (p1==NULL||p2==NULL)
	{
		if(p1->num <p2->num )
		{
			prev=p1;
			p1=p1->next ;
		}else if(p1->num >p2->num)
		{
			p2=p2->next ;
		}else		//两个节点的学号相同 ，那么就删除 phead1 的节点 
		{
			//删除 链表的节点
			pt=p1;
			p1=pt->next ;
			
			if(pt==phead1)
			{
				phead1=phead1->next ;
				free(pt);
			}else
			{
				prev->next =p1;
				free(pt);
			}
			
		}
	}
}
