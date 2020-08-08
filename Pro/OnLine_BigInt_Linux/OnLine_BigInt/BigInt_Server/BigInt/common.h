#ifndef _COMMON_H_
#define _COMMON_H_

#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<memory.h>
#include<stdio.h>

using namespace std;

typedef unsigned char u_char;
typedef unsigned long u_long;

             // +          -
typedef enum{POSITIVE, NEGATIVE} Symbol;

#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

template<class Type>
void Swap(Type &a, Type &b)
{
	Type tmp = a;
	a = b;
	b = tmp;
}


#endif /* _COMMON_H_ */