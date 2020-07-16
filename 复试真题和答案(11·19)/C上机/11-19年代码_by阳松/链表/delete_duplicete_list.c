#include <stdio.h>

//删除单链表中重复的元素

typedef struct student {
	int number;
	char name [20];
	double score;
	struct student *next;
}stu,*pstu;

int main (){
	
	
	
	return 0;
}


void delete_duplicete_list (pstu phead)			//删除链表重复的元素，假设链表有序 
{
	
	pstu prev,pcur,ptemp;
	prev=pcur=phead;
	ptemp=NULL;
	
	pcur=pcur->next ;
	
	while (pcur!=NULL){
		if(prev->number ==pcur->number ){
			ptemp=pcur->next ;
			free(pcur);
			prev->next =ptemp;
			pcur=ptemp;
		}
		prev=pcur ;
		pcur=pcur->next ;
	}

}
