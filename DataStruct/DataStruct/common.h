#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<vld.h>

#define ElemType int

void Swap(ElemType *a, ElemType *b)
{
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif /* _COMMON_H_ */