#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"common.h"

#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表结构
typedef struct SeqList
{
	ElemType *base;
	size_t    capacity;
	size_t    size;
}SeqList;

///////////////////////////////////////////////////////////
//声明函数接口
void SeqListInit(SeqList *pst);
bool IsFull(SeqList *pst);
bool IsEmpty(SeqList *pst);
void SeqListPushBack(SeqList *pst, ElemType x);
void SeqListPushFront(SeqList *pst, ElemType x);
void SeqListShow(SeqList *pst);
void SeqListDestroy(SeqList *pst);

//////////////////////////////////////////////////////////
//函数接口实现
void SeqListInit(SeqList *pst)
{
	assert(pst != NULL);
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

bool IsFull(SeqList *pst)
{assert(pst != NULL);return pst->size >= pst->capacity;}
bool IsEmpty(SeqList *pst)
{assert(pst != NULL);return pst->size == 0;}

void SeqListPushBack(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if(IsFull(pst))
	{
		printf("顺序表空间已满,不能插入数据 %d\n", x);
		return;
	}

	pst->base[pst->size++] = x;
}

void SeqListPushFront(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if(IsFull(pst))
	{
		printf("顺序表空间已满,不能插入数据 %d\n", x);
		return;
	}
	for(size_t pos=pst->size; pos>0; --pos)
		pst->base[pos] = pst->base[pos-1];
	pst->base[0] = x;
	pst->size++;
}

void SeqListShow(SeqList *pst)
{
	assert(pst != NULL);
	for(size_t i=0; i<pst->size; ++i)
		printf("%d ", pst->base[i]);
	printf("\n");
}

void SeqListDestroy(SeqList *pst)
{
	assert(pst != NULL);
	if(pst->base)
		free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}

#endif /* _SEQLIST_H_ */