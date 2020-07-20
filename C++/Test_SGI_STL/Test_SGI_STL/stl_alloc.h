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
		void(*my_malloc_handler)();
		void *result;
		for(; ;)
		{
			my_malloc_handler = __malloc_alloc_oom_handler;
			if(0 == my_malloc_handler)
				throw bad_alloc();
			(*my_malloc_handler)();
			result = malloc(n);
			if(result)
				return result;
		}
	}
	static void* oom_realloc(void *p, size_t new_sz)
	{
		void(*my_malloc_handler)();
		void *result;
		for(; ;)
		{
			my_malloc_handler = __malloc_alloc_oom_handler;
			if(0 == my_malloc_handler)
				throw bad_alloc();
			(*my_malloc_handler)();
			result = realloc(p, new_sz);
			if(result)
				return result;
		}
	}
private:
	static void(*__malloc_alloc_oom_handler)(); //函数指针
};

template<int inst>
 void(*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

 typedef __malloc_alloc_template<0> malloc_alloc;

 /////////////////////////////////////////////////////////////////////////////////////////////////////////
 //二级空间配置器

enum {__ALIGN = 8};
enum {__MAX_BYTES = 128};
enum {__NFREELISTS = __MAX_BYTES / __ALIGN}; // 128/8=16

template<bool threads, int inst>
class __default_alloc_template
{
public:
	static void* allocate(size_t n);
	static void  deallocate(void *p, size_t n);
	static void* reallocate(void *p, size_t old_sz, size_t new_sz);
private:
	static void* refill(size_t n);
	static char* chunk_alloc(size_t size, int &nobjs);
private:
	union obj
	{
		union obj *free_list_link; //链表指针
		char client_data[1];       //用户数据
	};
private:
	static size_t ROUND_UP(size_t bytes) //功能是提升为8的倍数
	{
		return (bytes + __ALIGN-1) & ~(__ALIGN-1); //4
	}
	static size_t FREELIST_INDEX(size_t bytes)
	{
		return (bytes + __ALIGN -1) / __ALIGN - 1;
	}
private:
	static obj* free_list[__NFREELISTS];
private:
	static char *start_free;
	static char *end_free;
	static size_t heap_size;
};

template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::start_free = 0;
template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::end_free = 0;
template<bool threads, int inst>
size_t __default_alloc_template<threads, inst>::heap_size = 0;
template<bool threads, int inst>
typename __default_alloc_template<threads, inst>::obj*
__default_alloc_template<threads, inst>::free_list[__NFREELISTS] = 
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

template<bool threads, int inst>
void* __default_alloc_template<threads, inst>::allocate(size_t n)
{
	if(n > __MAX_BYTES)
		return malloc_alloc::allocate(n);

	obj **my_free_list;
	obj *result;

	my_free_list = free_list + FREELIST_INDEX(n);
	result = *my_free_list;
	if(result == 0) //没有空间
	{
		void *r = refill(ROUND_UP(n));
		return r;
	}
	*my_free_list = result->free_list_link; // p = q->next;
	return result;
}

template<bool threads, int inst>
void* __default_alloc_template<threads, inst>::refill(size_t n)
{
	void *result;
	obj *cur_obj, *next_obj;

	int nobjs = 20; 
	char *chunk = chunk_alloc(n, nobjs);

	if(nobjs == 1)
		return chunk;

	obj **my_free_list;
	my_free_list = free_list + FREELIST_INDEX(n);
	result = (obj*) chunk;

	*my_free_list = next_obj = (obj *)(chunk+n);
	for(int i=1; ; i++)
	{
		cur_obj = next_obj;
		next_obj = (obj*)((char*)next_obj + n);
		if(nobjs - 1 == i)
		{
			cur_obj->free_list_link = 0;
			break;
		}
		else
			cur_obj->free_list_link = next_obj;
	}
	return result;
}

template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::chunk_alloc(size_t size, int &nobjs)
{
	size_t total_bytes = size * nobjs;
	size_t bytes_left = end_free - start_free;

	char *result;

	if(bytes_left >= total_bytes)
	{
		//剩余空间足够分配
		result = start_free;
		start_free += total_bytes;
		return result;
	}
	else if(bytes_left >= size)
	{
		//剩余空间至少满足一个块
		nobjs = bytes_left / size;
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;
		return result;
	}
	else
	{
		//剩余空间不足
		size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size>>4);

		//有剩余的内存池空间，但不满足于本次的申请
		if(bytes_left > 0)
		{
			obj ** my_free_list = free_list + FREELIST_INDEX(bytes_left);
			((obj*)start_free)->free_list_link = *my_free_list;
			*my_free_list = (obj*)start_free;
		}

		start_free = (char*)malloc(bytes_to_get);
		if(0 == start_free)
		{
			//申请空间失败
			obj **my_free_list, *p;
			for(size_t i=size; i<=__MAX_BYTES; i += __ALIGN)
			{
				my_free_list = free_list + FREELIST_INDEX(i);
				p = *my_free_list;
				if(0 != p)
				{
					*my_free_list = p->free_list_link;
					start_free = (char*)p;
					end_free = start_free + i;
					return chunk_alloc(size, nobjs);
				}
			}
			end_free = 0;
			start_free = (char*)malloc_alloc::allocate(bytes_to_get);
		}
		heap_size += bytes_to_get;
		end_free = start_free + bytes_to_get;
		return chunk_alloc(size, nobjs);
	}
}

template<bool threads, int inst>
void __default_alloc_template<threads, inst>::deallocate(void *p, size_t n)
{
	obj *q = (obj *)p;
	obj **my_free_list;

	if(n > __MAX_BYTES)
		malloc_alloc::deallocate(p, n);

	my_free_list = free_list + FREELIST_INDEX(n);
	q->free_list_link = *my_free_list;
	*my_free_list = q;
}


///////////////////////////////////////////////////////////////////////////////////
#ifdef __USE_MALLOC
typedef __malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc alloc;
#else
typedef __default_alloc_template<0,0> alloc;
#endif

template<class T, class Alloc>
class simple_alloc
{
public:
	//动态开辟数组空间
	static T* allocate(size_t n)
	{
		return 0==n ? 0 : (T*)Alloc::allocate(n * sizeof(T));
	}
	//动态开辟单个对象空间
	static T* allocate()
	{
		return (T*)Alloc::allocate(sizeof(T));
	}
	//动态释放数组空间
	static void deallocate(T *p, size_t n)
	{
		if(0 != n)
			Alloc::deallocate(p, n*sizeof(T));
	}
	//动态释放单个空间
	static void deallocate(T *p)
	{
		Alloc::deallocate(p, sizeof(T));
	}
};

///////////////////////////////////////////////////////////////////////////
template <class T1, class T2>
void construct(T1* p, const T2& value)
{
	new (p)T1(value);   //定位new
}