
//#define __USE_MALLOC

#include"stl_alloc.h"


template<class _Ty>
class list_node
{
public:
	list_node(_Ty d = _Ty()):data(d),next(nullptr),prev(nullptr)
	{}
public:
	_Ty  data;
	list_node *next;
	list_node *prev;
};

template<class _Ty, class Alloc=alloc>
class my_list
{
public:
	my_list():_Head(_Buynode()), _Size()
	{}
	void push_back(const _Ty &x)
	{
		list_node<_Ty> *_S = data_alloctor.allocate();
		construct(&(_S->data),x);

		_S->next = _Head;
		_S->prev = _Head->prev;
		_Head->prev->next = _S;
		_Head->prev = _S;
		_Size++;
	}
protected:
	list_node<_Ty>* _Buynode(_Ty v = _Ty())
	{
		list_node<_Ty> *_S = data_alloctor.allocate();
		construct(&(_S->data), v);
		_S->next = _S->prev = _S;
		return _S;
	}
private:
	list_node<_Ty> *_Head;
	size_t _Size;
	simple_alloc<list_node<_Ty>, Alloc> data_alloctor; //空间配置器的对象
};


void main()
{
	my_list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
}

/*
void main()
{
	simple_alloc<int, alloc> sa;
	int *p = sa.allocate();
	sa.deallocate(p);
}

/*
int main()
{
	int *p = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	int *p1 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	int *p2 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));

	int *p3 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int) * 32);
	int *p4 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int) * 10);

	__default_alloc_template<0,0>::deallocate(p, sizeof(int));
	return 0;
}

/*
void OutOfMemory()
{
	cout<<"Out Of Memory."<<endl; //free(p); //10000000000  ~GC()
	exit(1);
}

void main()
{	
	__malloc_alloc_template<0>::set_malloc_handler(OutOfMemory);
	try
	{
		int *pi0 = (int*)__malloc_alloc_template<0>::allocate(sizeof(int) * 536870911);
	}
	catch(bad_alloc & e)
	{
		cout<<e.what()<<endl;
	}

	//int *pi1 = (int*)__malloc_alloc_template<0>::allocate(sizeof(int) *10);
	//__malloc_alloc_template<0>::deallocate(pi1, sizeof(int)*10);
}
*/