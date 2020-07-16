#include <stdio.h> 
#include <stdlib.h>

//二叉树 新建水平二叉树 

typedef struct bnode {
	int value;
	struct bnode *left;
	struct bnode *right;
}BNode,*pBNode;

//新建链式队列

typedef struct lnode {
	pBNode pb;					//指向二叉树节点的指针 
	struct lnode *next;
	
}LNode,*pLNode; 

typedef struct Queue {
	int queue_cnt;
	struct lnode *front;
	struct lnode *rear;
}Queue,* pQueue; 

//先建一个队列 ，所有函数都可以访问这个队列 
Queue queue; 

void en_queue (pQueue pqueue,pBNode pb); 
pBNode cat_queue (pQueue pqueue);
void de_queue (pQueue pqueue);
int is_empty_queue (pQueue pqueue);
void insert_bitree (pBNode *bitree,int value);

void in_order (pBNode pt); 

int main ()
{
	int value ;
	int i;
	pBNode bitree=NULL;
	int a[10]={20,65,32,15,36,87,5,63,39,14};
	
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);	
	}
	printf("开始建树\n");	
	
	for(i=0;i<10;i++)
	{
		insert_bitree(&bitree,a[i]);
	}
//	while (scanf("%d",&value)!=EOF)
//	{
//		//建树 
//		insert_bitree(&bitree,value);
//		
//	}
	//中序遍历 
	in_order (bitree); 
	
	return 0;
}


void insert_bitree (pBNode *bitree,int value)
{
	pBNode pnew_BNode=(pBNode)calloc(1,sizeof(BNode));
	pnew_BNode->value =value;
	
	en_queue(&queue,pnew_BNode);
		pBNode ret;  //用于接收 cat_queue 返回的指向树节点的指针 
	if(*bitree==NULL)				//当树为空时 ，将指向树的指针指向第一个新节点 
	{
		*bitree= pnew_BNode; 
	}else
	{
		if(is_empty_queue(&queue)!=1)
		{
			ret=cat_queue(&queue);
			if(ret->left ==NULL)		//若该节点的左指针为NULL，就将新建的节点指针连接到该节点的左指针上 
			{
				ret->left =pnew_BNode;
			}else
			{
				ret->right =pnew_BNode;
				//出队 
				de_queue(&queue);
			}
		}
	}
	
}

void in_order (pBNode pt)		//二叉树中序遍历 
{
	if(pt!=NULL)
	{
		in_order(pt->left );
		printf("%d\t",pt->value  ) ;
		in_order(pt->right );
	}
}

void en_queue (pQueue pqueue,pBNode pb)
{
	 pLNode pnew_queue=(pLNode)calloc(1,sizeof(LNode));
	 pnew_queue->pb =pb;
	 if(pqueue->front ==NULL)
	 {
	 	pqueue->front=pqueue->rear =pnew_queue;
	 }else
	 {
	 	pqueue->rear->next =pnew_queue;
	 	pqueue->rear=pnew_queue;
	 }
 	pqueue->queue_cnt ++;	
}

void de_queue (pQueue pqueue)
{
	pLNode pcur;

	pcur=pqueue->front ;
	pqueue->front =pcur->next ;

	free(pcur);
	if(pqueue->front==NULL)
	{
		pqueue->rear =NULL;
	}
	pqueue->queue_cnt --;

}

pBNode cat_queue (pQueue pqueue)
{
	pLNode pcur;
	pBNode ret;
	pcur=pqueue->front ;
	ret=pcur->pb ;
	return ret;
}

int is_empty_queue (pQueue pqueue)
{
	if(pqueue->queue_cnt ==0)
	{
		return 1;
	}else
	{
		return 0;
	}
}
