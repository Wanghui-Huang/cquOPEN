#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int num ;
  int flag;
}node;

int compare (const void * a , const void *b );

int main ()
{
    int n;
    node a[101];
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf ("%d",&a[i].num);
    }
    for(i=0;i<n;i++)
    {
        scanf ("%d",&a[i].flag);
    }
    qsort( a, n, sizeof(node),compare  );
    
    for(i=0;i<n;i++)
    {
        printf ("%d\t%d\n",a[i].num,a[i].flag );
    }
    
    return 0;
}

int compare (const void * a , const void *b )
{
    node* pnode1=(node*)a;
    node* pnode2=(node*)b;
        
    return  pnode1-> num - pnode2-> num ;
 
}
