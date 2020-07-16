#include <stdio.h>
#include <stdlib.h>

typedef struct tag{
	int value;
	struct tag *pnext;

}Node,*pNode;

typedef struct {
	int cnt;
	pNode top;

}Stack,*pStack;

void init_stack (pStack s);
void push_stack (pStack s,int value);
void pop_stack (pStack s);
int top_stack (pStack s);
int isempty_stack (pStack s);
int size_stack (pStack s);

int main (){
	int value; 
	Stack s;		//新建一个栈 
	init_stack(&s);
	while (scanf("%d",&value)!=EOF)
	{
		push_stack(&s,value);
		
	}
	
	while (isempty_stack(&s)!=1)
	{
		pop_stack(&s);
		printf("%d\n",top_stack (&s));
	}
	
	
	return 0;
}


void init_stack (pStack s)
{
	s->top=NULL;
	s->cnt =0;

}

void push_stack (pStack s,int value)
{
	pNode pnew;
	pnew=(pNode)calloc(1,sizeof(Node));			//calloc 分配的堆内存默认所有元素赋值为 1 
	pnew->value =value;
	pnew->pnext =s->top ;
	s->top =pnew;
	s->cnt ++;
}

void pop_stack (pStack s)
{
	pNode pcur;
	if(s->top ==NULL)
	{
		printf("当前栈为空");
	}else
	{
		pcur=s->top ;
		s->top =pcur->pnext ;
		free(pcur);
		s->cnt --;
	}

}

int top_stack (pStack s)
{
	if(s->top ==NULL)
	{
		printf("当前栈为空");
		return -1;
	}else
	{
		return s->top->value ;
	}	
}

int isempty_stack (pStack s)
{
	return !s->cnt ; 
}

int size_stack (pStack s)
{
	return s->cnt ;
}
