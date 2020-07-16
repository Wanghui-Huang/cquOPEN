#include<stdio.h>
#include <stdlib.h>

//输入一系列整数，建立二叉排序树，并进行前序，中序，后序遍历。

typedef struct node {
    int value;
    struct node *left;
    struct node *right;

}Node,*pNode;

void insert_bstree (pNode *ppt,int value);
void pre_order (pNode pt);
void in_order (pNode pt);
void post_order (pNode pt);

int main ()
{
    pNode btree=NULL;
    int n;
    int i;
    int value;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        insert_bstree (&btree,value);
    }
    
    pre_order (btree);
    printf("\n");
    in_order ( btree);
    printf("\n");
    post_order ( btree);
    return 0;
}

void insert_bstree (pNode *ppt,int value)
{
    pNode pnew=(pNode)calloc(1,sizeof(Node));
    pnew->value=value;
    
    if(*ppt==NULL)
    {
       *ppt=pnew;
    }else
    {
        if(value<(*ppt)->value)
        {
            insert_bstree ( &(*ppt)->left,value);
        }else if(value>(*ppt)->value)
        {
            insert_bstree ( &(*ppt)->right,value);
        }

    }
}

void pre_order (pNode pt)
{
    if(pt!=NULL)
    {
        printf("%d ",pt->value);
        pre_order (pt->left);
        pre_order (pt->right);
    }
}

void in_order (pNode pt)
{
    if(pt!=NULL)
    {
        
        in_order (pt->left);
        printf("%d ",pt->value);
        in_order (pt->right);
    }
}

void post_order (pNode pt)
{
    if(pt!=NULL)
    {
        
        post_order (pt->left);
        post_order (pt->right);
        printf("%d ",pt->value);
    }
}
