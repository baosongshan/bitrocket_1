
//#define __USE_MALLOC

#include"stl_alloc.h"

/*
class my_list
{};
*/

void main()
{
	simple_alloc<int, alloc> sa;
	int *p = sa.allocate();
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