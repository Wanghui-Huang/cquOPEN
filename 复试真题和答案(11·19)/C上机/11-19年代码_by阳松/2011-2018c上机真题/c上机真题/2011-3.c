#include <stdio.h>
#include <stdlib.h>

//完成一个单链表的初始化，插入，删除
typedef struct Node{
	int value;
	struct Node *next;	
}Node,*pNode;

typedef struct Link_list {
	struct Node *head;
	struct Node *tail;		
}Link_list,*pLink_list;

void init_list (pLink_list L1);
void insert_sort_list (pLink_list L1,int val);
void delete_list (pLink_list L1,int val);
void list_print (pLink_list L1);
int main ()
{
	int temp;
	Link_list L1;
	init_list(&L1);
	
	while (scanf("%d",&temp)!=EOF)
	{
		insert_sort_list (&L1,temp); 
	}
	
	list_print(&L1);
	printf("删除元素\n");
	while (scanf("%d",&temp)!=EOF)
	{
		delete_list(&L1,temp) ;
		printf("\n");
		list_print(&L1);
	}
	
	return 0;	
} 

void init_list (pLink_list L1)
{
	L1->head=L1->tail=NULL;
	
}

void insert_sort_list (pLink_list L1,int val)
{
	pNode pcur,pprev;
	pNode pnew=(pNode)calloc(1,sizeof(Node));
	pnew->value =val;
	
	pcur=pprev=L1->head;
	
	if(L1->head==NULL)		//
	{
		L1->head=L1->tail =pnew;
	}else if(val < pcur->value )	//插入在头结点之前 
	{
		pnew->next =L1->head;
		L1->head =pnew;
	}else 
	{
		pcur=pcur->next ;
		while (pcur!=NULL)
		{
			if(pcur->value < val)
			{
				pprev=pcur;
				pcur=pcur->next ;	
			} else		//插入节点的位置找到了 
			{
				pnew->next =pcur;
				pprev->next =pnew; 
				break;
			}
		}
		
		if(pcur==NULL)
		{
			pnew->next =pcur;
			pprev->next =pnew; 
			L1->tail =pnew;
		}
	} 
	
}

void delete_list (pLink_list L1,int val)		//删除节点值为val的节点 
{
	pNode pcur,pprev;
	pcur=pprev=L1->head;
	
	if(pcur ==NULL)
	{
		printf("所删除的链表为空，删除失败"); 
		
	} else if(pcur->value ==val)
	{
		L1->head=pcur->next ;
		if(L1->head ==NULL)
		{
			L1->tail =NULL;
		}
		free(pcur);	
		
	}else
	{
		pcur=pcur->next ;
		while(pcur!=NULL) 
		{
			if(pcur->value == val)
			{
				break;	
			}else
			{
				pprev=pcur;
				pcur=pcur->next ;	
			}
		}
		if(pcur==NULL)
		{
			printf("没有此元素"); 
		}else 
		{
			if(pcur==L1->tail)
			{
				pprev->next =NULL;
				L1->tail=pprev ;
			}else
			{
				pprev->next =pcur->next ;
			}
			free(pcur);	
		} 
	}
}

void list_print (pLink_list L1)
{
	pNode pcur=L1->head ;
	while(pcur!=NULL)
	{
		printf("%d\n",pcur->value )	;
		pcur=pcur->next ;
	} 
}
