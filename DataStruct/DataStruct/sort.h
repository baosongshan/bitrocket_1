#ifndef _SORT_H_
#define _SORT_H_

#include"common.h"

void PrintElement(int *elem, int first, int last);
void TestSort(int *elem, int first, int last);
void TestSortEfficiency();

//≤Â»Î≈≈–Ú
void InsertSort(int *elem, int first, int last);
void InsertSort_1(int *elem, int first, int last);
void InsertSort_2(int *elem, int first, int last);
void BinInsertSort(int *elem, int first, int last);
void TwoWayInsertSort(int *elem, int first, int last);
void ShellSort(int *elem, int first, int last);

//—°‘Ò≈≈–Ú
void SelectSort(int *elem, int first, int last);


////////////////////////////////////////////////////////
void PrintElement(int *elem, int first, int last)
{
	for(int i=first; i<last; ++i)
		printf("%d ",elem[i]);
	printf("\n");
}

//≤Â»Î≈≈–Ú
//÷±Ω”≤Â»Î≈≈–Ú - Ωªªª∞Ê
void InsertSort(int *elem, int first, int last)
{
	for(int i=first+1; i<last; ++i)
	{
		int end = i;
		while(end>first && elem[end]<elem[end-1])
		{
			Swap(&(elem[end]), &(elem[end-1]));
			end--;	
		}
	}
}
//÷±Ω”≤Â»Î≈≈–Ú - “∆∂Ø∞Ê
void InsertSort_1(int *elem, int first, int last)
{
	for(int i=first+1; i<last; ++i)
	{
		int end = i;
		int tmp = elem[end];
		while(end>first && tmp<elem[end-1])
		{
			elem[end] = elem[end-1];
			end--;	
		}
		elem[end] = tmp;
	}
}
//÷±Ω”≤Â»Î≈≈–Ú - …⁄±¯∞Ê
void InsertSort_2(int *elem, int first, int last)
{
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //…⁄±¯ ˝æ›
	for(int i=first+1; i<last; ++i)
	{
		elem[0] = elem[i];
		int end = i;
		while(elem[0] < elem[end-1])
		{
			elem[end] = elem[end-1];
			end--;
		}
		elem[end] = elem[0];
	}
}
//’€∞Î≤Â»Î≈≈–Ú
void BinInsertSort(int *elem, int first, int last)
{
	//int ar[] = {49, 38, 65, 97, 76, 13, 27, 49};
	for(int i=first+1; i<last; ++i)
	{
		int tmp = elem[i];
		int low = first;
		int high = i-1;
		while(low <= high)
		{
			int mid = (low+high) / 2;
			if(elem[mid] > tmp)
				high = mid-1;
			if(elem[mid] <= tmp)
				low = mid+1;
		}

		for(int j=i; j>low; --j)
			elem[j] = elem[j-1];
		elem[low] = tmp;
	}
}

//∂˛¬∑≤Â»Î≈≈–Ú
void TwoWayInsertSort(int *elem, int first, int last)
{
	int n = last - first;
	int *tmp = (int*)malloc(sizeof(int) * n);
	tmp[0] = elem[0];
	int start, end;
	start = end = 0;

	for(int i=first+1; i<last; ++i)
	{
		if(elem[i] < tmp[start])
		{
			start = (start-1+n) % n; //
			tmp[start] = elem[i];
		}
		else if(elem[i] >= tmp[end])
		{
			tmp[++end] = elem[i];
		}
		else
		{
			int j = end;
			while(elem[i] < tmp[j])
			{
				tmp[(j+1)%n] = tmp[j];
				j = (j-1+n) % n;
			}
			tmp[(j+1)%n] = elem[i];
			end++;
		}
	}

	int k = 0;
	for(int i=start; k<n; i=(i+1)%n)
		elem[k++] = tmp[i];

	free(tmp);
}
//œ£∂˚≈≈–Ú
void ShellSort(int *elem, int first, int last)
{
	int dk = last - first;
	while(dk > 1)
	{
		dk = dk/3+1;
		for(int i=first; i<last-dk; ++i)
		{
			if(elem[i+dk] < elem[i])
			{
				int end = i;
				int tmp = elem[end+dk];
				while(end>=first && tmp<elem[end])
				{
					elem[end+dk] = elem[end];
					end -= dk;
				}
				elem[end+dk] = tmp;
			}
		}
	}
}

//÷±Ω”—°‘Ò≈≈–Ú
int GetMinIndex(int *elem, int first, int last)
{
	int min_val = elem[first];
	int index = first;
	for(int i=first+1; i<last; ++i)
	{
		if(elem[i] < min_val)
		{
			min_val = elem[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int *elem, int first, int last)
{
	for(int i=first; i<last-1; ++i)
	{
		int index = GetMinIndex(elem, i, last);
		if(index != i)
			Swap(&elem[index], &elem[i]);
	}
}


void TestSort(int *elem, int first, int last)
{
	//InsertSort(elem, first, last);
	//InsertSort_1(elem, first, last);
	//InsertSort_2(elem, first, last);
	//BinInsertSort(elem, first, last);
	//TwoWayInsertSort(elem, first, last);
	//ShellSort(elem, first, last);
	SelectSort(elem, first, last);
}

void TestSortEfficiency()
{
	int n = 20000;
	int *a1 = (int *)malloc(sizeof(int) * n);
	int *a2 = (int *)malloc(sizeof(int) * n);
	int *a3 = (int *)malloc(sizeof(int) * n);
	int *a4 = (int *)malloc(sizeof(int) * n);
	int *a5 = (int *)malloc(sizeof(int) * n);
	int *a6 = (int *)malloc(sizeof(int) * n);
	srand(time(0));
	for(int i=0; i<n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	time_t start = clock();
	InsertSort(a1, 0, n);
	time_t end = clock();
	printf("InsertSort : %u\n", end-start);

	start = clock();
	InsertSort_1(a2, 0, n);
	end = clock();
	printf("InsertSort_1 : %u\n", end-start);

	start = clock();
	BinInsertSort(a3, 0, n);
	end = clock();
	printf("BinInsertSort : %u\n", end-start);

	start = clock();
	TwoWayInsertSort(a4, 0, n);
	end = clock();
	printf("TwoWayInsertSort : %u\n", end-start);

	start = clock();
	ShellSort(a5, 0, n);
	end = clock();
	printf("ShellSort : %u\n", end-start);

	start = clock();
	SelectSort(a6, 0, n);
	end = clock();
	printf("SelectSort : %u\n", end-start);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

/*
//œ£∂˚≈≈–Ú
int dlta[] = {5,3,2,1};
void _ShellSort(int *elem, int first, int last, int dk)
{
	for(int i=first; i<last-dk; ++i)
	{
		int end = i;
		int tmp = elem[end+dk];
		while(end>=first && tmp < elem[end])
		{
			//Swap(&elem[end+dk], &elem[end]);
			elem[end+dk] = elem[end];
			end -= dk;
		}
		elem[end+dk] = tmp;
	}
}
void ShellSort(int *elem, int first, int last)
{
	for(int i=0; i<sizeof(dlta)/sizeof(dlta[0]); i++)
	{
		_ShellSort(elem, first, last, dlta[i]);
	}
}
*/
#endif /* _SORT_H_ */