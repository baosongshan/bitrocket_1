#pragma once

#include<iostream>
using namespace std;

//一级空间配置器
template<int inst>
class __malloc_alloc_template
{
public:
	static void* allocate(size_t n) //malloc
	{
		void *result = malloc(n);
		if(0 == result)
		{
			result = oom_malloc(n);
		}
		return result;
	}
	static void  deallocate(void *p, size_t n) //free
	{
		free(p);
	}
	static void* reallocate(void *p, size_t old_sz, size_t new_sz) //realloc
	{
		void *result = realloc(p, new_sz);
		if(0 == result)
		{
			result = oom_realloc(p, new_sz);
		}
		return result;
	}
	static void(*set_malloc_handler(void(*f)()))()
	{
		void(*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return old;
	}
private:
	static void* oom_malloc(size_t n)
	{
		void *result = 0;
		return result;
	}
	static void* oom_realloc(void *p, size_t new_sz)
	{

	}

private:
	static void(*__malloc_alloc_oom_handler)(); //函数指针
};

template<int inst>
 void(*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;
