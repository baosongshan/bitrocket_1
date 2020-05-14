#ifndef _HEAP_H_
#define _HEAP_H_

#include"common.h"
#define HeapDataType int

typedef struct Heap
{
	HeapDataType *base;
	int           capacity;
	int           size;
}Heap;

void HeapInit(Heap *php, int n);
void MinHeapInsert(Heap *php, HeapDataType x);
void HeapPrint(Heap *php);
void AdjustUp(HeapDataType *base, int start);
//   AdjustDown();

void HeapInit(Heap *php, int n)
{
	assert(php != NULL);
	php->base = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
	assert(php->base != NULL);
	php->capacity = n;
	php->size = 0;
}

void MinHeapInsert(Heap *php, HeapDataType x)
{
	assert(php != NULL);
	if(php->size < php->capacity)
	{
		php->base[php->size] = x;
		
		//调整为小堆结构  从下往上调整
		AdjustUp(php->base, php->size);
		php->size++;
	}
}

void HeapPrint(Heap *php)
{
	for(int i=0; i<php->size; ++i)
		printf("%d ", php->base[i]);
	printf("\n");
}

void AdjustUp(HeapDataType *base, int start)
{
	int j = start;
	int i = (j-1)/2;
	while(j > 0)
	{
		if(base[j] < base[i])
		{
			Swap(&(base[j]), &(base[i]));
			j = i;
			i = (j-1)/2;
		}
		else
			break;
	}
}

#endif /* _HEAP_H_ */