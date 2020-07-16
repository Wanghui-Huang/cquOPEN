#include <stdio.h>

//找出链表的倒数第四个节点
typedef struct student {
	int number;
	char name [20];
	double score;
	struct student *next;
}stu,*pstu;

int main (){
	
	
	
	return 0;
}


pstu find_backward_list (pstu phead,int n)		//找到链表的倒数第n个结点 
{
	
	pstu prev,pcur;
	int cnt=0;//记录向后偏移了几个数字 
	prev=NULL;
	pcur=phead;
	while(pcur->next !=NULL&&cnt<n-1)
	{
		pcur=pcur->next ;
		cnt++; 
	}
	if(cnt==n-1)
	{
		while (pcur!=NULL)
		{
			if(prev==NULL)
			{
				prev=phead;
				
			} else
			{
				prev=prev->next ;
				
			}
			pcur=pcur->next ;
		}
	}
	
	return prev;
}
