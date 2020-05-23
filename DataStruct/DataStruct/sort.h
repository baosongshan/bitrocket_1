#ifndef _SORT_H_
#define _SORT_H_

#include"common.h"

void PrintElement(int *elem, int first, int last);
void TestSort(int *elem, int first, int last);
void TestSortEfficiency();

//插入排序
void InsertSort(int *elem, int first, int last);
void InsertSort_1(int *elem, int first, int last);
void InsertSort_2(int *elem, int first, int last);
void BinInsertSort(int *elem, int first, int last);
void TwoWayInsertSort(int *elem, int first, int last);
void ShellSort(int *elem, int first, int last);

//选择排序
void SelectSort(int *elem, int first, int last);
void HeapSort(int *elem, int first, int last);

//交换排序
void BubbleSort(int *elem, int first, int last);
void BubbleSort_1(int *elem, int first, int last);
void QuickSort_1(int *elem, int first, int last);
void QuickSort_2(int *elem, int first, int last);
void QuickSort_3(int *elem, int first, int last);

//归并排序
void MergeSort(int *elem, int first, int last);

//基数排序
void RadixSort(int *elem, int first, int last);
////////////////////////////////////////////////////////
void PrintElement(int *elem, int first, int last)
{
	for(int i=first; i<last; ++i)
		printf("%d ",elem[i]);
	printf("\n");
}

//插入排序
//直接插入排序 - 交换版
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
//直接插入排序 - 移动版
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
//直接插入排序 - 哨兵版
void InsertSort_2(int *elem, int first, int last)
{
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //哨兵数据
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
//折半插入排序
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

//二路插入排序
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
//希尔排序
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

//直接选择排序
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


void _AdjustDown(int *elem, int first, int last, int start)
{
	int n = last - first;
	int i = start;	
	int j = 2*i+1;

	int tmp = elem[i];
	while(j < n)
	{
		if(j+1<n && elem[j] < elem[j+1])
			j++;
		if(tmp < elem[j])
		{
			elem[i] = elem[j];
			i = j;
			j = 2*i+1;
		}
		else
			break;
	}
	elem[i] = tmp;

}
void HeapSort(int *elem, int first, int last)
{
	//调整成大堆
	int n = last - first;
	int curpos = n/2 - 1;
	while(curpos >= 0)
	{
		_AdjustDown(elem, first, last, curpos);
		curpos--;
	}
	
	//排序
	int end = last-1;
	while(end > first)
	{
		Swap(&elem[end], &elem[first]);
		end--;
		_AdjustDown(elem, first, end+1, first);
	}
}

//冒泡排序
void BubbleSort(int *elem, int first, int last)
{
	for(int i=first; i<last-1; ++i)
	{
		for(int j=first; j<last-i-1; ++j)
		{
			if(elem[j] > elem[j+1])
				Swap(&elem[j], &elem[j+1]);
		}
	}
}

//冒泡排序_交换改进版
void BubbleSort_1(int *elem, int first, int last)
{
	bool is_swap = false;
	for(int i=first; i<last-1; ++i)
	{
		for(int j=first; j<last-i-1; ++j)
		{
			if(elem[j] > elem[j+1])
			{
				Swap(&elem[j], &elem[j+1]);
				is_swap = true;
			}
		}

		if(!is_swap)
			break;
		else
			is_swap = false;
	}
}

//快速排序
//hoare版本
int _Partition_1(int *elem, int first, int last)
{
	int key = elem[first];
	while(first < last)
	{
		while(first<last && elem[last]>=key)
			last--;
		Swap(&elem[last], &elem[first]);
		
		while(first<last && elem[first]<key)
			first++;
		Swap(&elem[last], &elem[first]);
	}
	return first;
}
void QuickSort_1(int *elem, int first, int last)
{
	if(first >= last-1)
		return;

	int pos = _Partition_1(elem, first, last-1);

	QuickSort_1(elem, first, pos);   //[   )
	QuickSort_1(elem, pos+1, last);
}
//挖坑法
int _Partition_2(int *elem, int first, int last)
{
	int key = elem[first];
	while(first < last)
	{
		while(first<last && elem[last]>=key)
			last--;
		elem[first] = elem[last];
		
		while(first<last && elem[first]<key)
			first++;
		elem[last] = elem[first];
	}
	elem[first] = key;
	return first;
}
void QuickSort_2(int *elem, int first, int last)
{
	if(first >= last-1)
		return;

	int pos = _Partition_2(elem, first, last-1);

	QuickSort_2(elem, first, pos);   //[   )
	QuickSort_2(elem, pos+1, last);
}

//前后指针法
//三数取中法改进快速排序
int GetMidIndex(int *elem, int first, int last)
{
	int mid = (first + last) / 2;
	if(elem[first]>elem[last] && elem[first]<elem[mid])
		return first;
	else if(elem[last]>elem[first] && elem[last]<elem[mid])
		return last;
	return mid;
}

#define M 25

int _Partition_3(int *elem, int first, int last)
{
	int index = GetMidIndex(elem, first, last);
	if(index != first)
		Swap(&elem[index], &elem[first]);

	int key = elem[first];
	int pos = first;
	for(int i=first+1; i<=last; ++i)
	{
		if(elem[i] < key)
		{
			pos++;
			if(pos != i)
			{
				Swap(&elem[pos], &elem[i]);
			}
		}
	}
	Swap(&elem[first], &elem[pos]);
	return pos;
}
void QuickSort_3(int *elem, int first, int last)
{
	if(first >= last-1)
		return;

	if(last-first <= M)
		InsertSort_1(elem, first, last);
	else
	{
		int pos = _Partition_3(elem, first, last - 1);

		QuickSort_3(elem, first, pos);   //[   )
		QuickSort_3(elem, pos + 1, last);
	}
}

//归并排序
void _MergeSort(int *elem, int first, int last, int *tmp)
{
	if(first >= last)
		return;
	int mid = (first+last) / 2;
	_MergeSort(elem, first, mid, tmp);
	_MergeSort(elem, mid+1, last, tmp);

	//归并
	int begin1,end1, begin2,end2;
	begin1=first, end1=mid;
	begin2=mid+1, end2=last;

	int i = first;
	while(begin1<=end1 && begin2<=end2)
	{
		if(elem[begin1] < elem[begin2])
			tmp[i++] = elem[begin1++];
		else
			tmp[i++] = elem[begin2++];
	}

	while(begin1 <= end1)
	{
		tmp[i++] = elem[begin1++];
	}

	while(begin2 <= end2)
	{
		tmp[i++] = elem[begin2++];
	}

	memcpy(elem+first, tmp+first, sizeof(int)*(last-first+1));
}
void MergeSort(int *elem, int first, int last)
{
	int n = last - first;
	int *tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(elem, first, last-1, tmp);
	free(tmp);
}

//基数排序
#define K 3
#define RADIX 10
#include"list.h"

static SList list[RADIX];

//109
int _GetKey(int value, int k)
{
	int key;
	while(k >= 0)
	{
		key = value % 10; //0
		value /= 10;      //10
		k--;
	}
	return key;
}
void _Distribute(int *elem, int first, int last, int k)
{
	for(int i=first; i<last; ++i)
	{
		int key = _GetKey(elem[i], k);
		SListPushBack(&list[key], elem[i]);
	}
}
void _Collect(int *elem)
{
	int k = 0;
	for(int i=0; i<RADIX; ++i)
	{
		SListNode *p = list[i].head;
		while(p != NULL)
		{
			elem[k++] = p->data;
			SListPopFront(&list[i]);
			p = list[i].head;
		}
	}
}
void RadixSort(int *elem, int first, int last)
{
	for(int i=0; i<RADIX; ++i)
	{
		SListInit(&list[0]); //0 1 2 3 4 5 6 7 8 9
	}
	for(int i=0; i<K; ++i)
	{
		//1 分发
		_Distribute(elem, first, last, i);
		//2 回收
		_Collect(elem);
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
	//SelectSort(elem, first, last);
	//HeapSort(elem, first, last);
	//BubbleSort(elem, first, last);
	//BubbleSort_1(elem, first, last);
	//QuickSort_1(elem, first, last);
	//QuickSort_2(elem, first, last);
	//QuickSort_3(elem, first, last);
	//MergeSort(elem, first, last);
	RadixSort(elem, first, last);
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
	int *a7 = (int *)malloc(sizeof(int) * n);
	int *a8 = (int *)malloc(sizeof(int) * n);
	int *a9 = (int *)malloc(sizeof(int) * n);
	int *a10 = (int *)malloc(sizeof(int) * n);
	int *a11 = (int *)malloc(sizeof(int) * n);
	int *a12 = (int *)malloc(sizeof(int) * n);
	int *a13 = (int *)malloc(sizeof(int) * n);
	srand(time(0));
	for(int i=0; i<n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
		a10[i] = a1[i];
		a11[i] = a1[i];
		a12[i] = a1[i];
		a13[i] = a1[i];
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

	start = clock();
	HeapSort(a7, 0, n);
	end = clock();
	printf("HeapSort : %u\n", end-start);

	start = clock();
	BubbleSort(a8, 0, n);
	end = clock();
	printf("BubbleSort : %u\n", end-start);

	start = clock();
	BubbleSort_1(a9, 0, n);
	end = clock();
	printf("BubbleSort_1 : %u\n", end-start);

	start = clock();
	QuickSort_1(a10, 0, n);
	end = clock();
	printf("QuickSort_1 : %u\n", end-start);

	start = clock();
	QuickSort_2(a11, 0, n);
	end = clock();
	printf("QuickSort_2 : %u\n", end-start);

	start = clock();
	QuickSort_3(a12, 0, n);
	end = clock();
	printf("QuickSort_3 : %u\n", end-start);

	start = clock();
	MergeSort(a13, 0, n);
	end = clock();
	printf("MergeSort : %u\n", end-start);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
	free(a10);
	free(a11);
	free(a12);
	free(a13);
}

/*

void _Collect(int *elem)
{
	int k = 0;
	for(int i=0; i<RADIX; ++i)
	{
		SListNode *p = list[i].head;
		while(p != NULL)
		{
			elem[k++] = p->data;
			p = p->next;
		}
	}

	for(int i=0; i<RADIX; ++i)
		SListClear(&list[i]);

}

//希尔排序
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