#include <stdio.h> 
#include <stdlib.h>

//二叉树 新建二叉搜索树 

typedef struct node {
	int num;
	struct node *left;
	struct node *right;
}Node,*pNode;

void  insert_btree (pNode *pptree,int value);
void in_order (pNode pt);

int main ()
{
	int value;
	pNode pbtree=NULL;
	while (scanf("%d",&value)!=EOF)
	{
		insert_btree (&pbtree,value);
		
	}
	
	in_order (pbtree);
	
	return 0;
}


void  insert_btree (pNode *pptree,int value)
{
	
	if(*pptree==NULL)
	{
		pNode pnew=(pNode)calloc(1,sizeof(Node));
		pnew->num =value;		
		*pptree=pnew;
		
	}else if(value<(*pptree)->num)
	{
		insert_btree(&(*pptree)->left,value);
	}else 
	{
		insert_btree(&((*pptree)->right),value);
	}
}


void in_order (pNode pt)
{
	if(pt!=NULL)
	{
		in_order(pt->left );
		printf("%d\t",pt->num ) ;
		in_order(pt->right );
	}
}


