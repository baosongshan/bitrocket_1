#include"stl_alloc.h"

void main()
{
	int *pi = (int*)__malloc_alloc_template<0>::allocate(sizeof(int) *536870911);
}