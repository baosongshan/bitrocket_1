#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"

///////////////////////////////////////////////////////////////
//顺序栈
//顺序栈的扩容交由同学们自行完成

#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE     3

typedef struct SeqStack
{
	ElemType *base;
	size_t    capacity;
	int       top;
}SeqStack;

void SeqStackInit(SeqStack *pst);
bool SeqStackIsFull(SeqStack *pst);
bool SeqStackIsEmpty(SeqStack *pst);
void SeqStackPush(SeqStack *pst, ElemType x);
void SeqStackPop(SeqStack *pst);
ElemType SeqStackTop(SeqStack *pst); // SeqStackPeek();
void SeqStackPrint(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);

void SeqStackInit(SeqStack *pst)
{
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQ_STACK_DEFAULT_SIZE);
	assert(pst->base != NULL);
	pst->capacity = SEQ_STACK_DEFAULT_SIZE;
	pst->top = 0;
}

bool SeqStackIsFull(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}
bool SeqStackIsEmpty(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}

void SeqStackPush(SeqStack *pst, ElemType x)
{
	assert(pst != NULL);
	if(SeqStackIsFull(pst))
	{
		printf("栈空间已满，%d 不能入栈.\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}
void SeqStackPop(SeqStack *pst)
{
	assert(pst != NULL);
	if(SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	pst->top--;
}

ElemType SeqStackTop(SeqStack *pst)
{
	assert(pst != NULL);
	if(SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能取栈顶元素.\n");
		return;
	}

	return pst->base[pst->top-1]; 
}

void SeqStackPrint(SeqStack *pst)
{
	assert(pst != NULL);
	for(int i=pst->top-1; i>=0; --i)
		printf("%d\n", pst->base[i]);
	printf("\n");
}

void SeqStackDestroy(SeqStack *pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

///////////////////////////////////////////////////////////////
//链栈
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *link; //next
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode *top;
}LinkStack;

void LinkStackInit(LinkStack *pst);
void LinkStackPush(LinkStack *pst, ElemType x);
void LinkStackPop(LinkStack *pst);
ElemType LinkStackTop(LinkStack *pst);
void LinkStackPrint(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);

void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}

void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = pst->top;
	pst->top = node;
}
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	pst->top = p->link;

	free(p);
}
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL);
	if(pst->top == NULL)
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	return pst->top->data;
}
void LinkStackPrint(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	while(p != NULL)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
	printf("\n");
}

void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	while(pst->top != NULL)
	{
		LinkStackNode *p = pst->top;
		pst->top = p->link;
		free(p);
	}
}

#endif /* _STACK_H_ */