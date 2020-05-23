//#include"seqlist.h"
//#include"list.h"
//#include"stack.h"
//#include"queue.h"
//#include"tree.h"
//#include"heap.h"

#include"sort.h"

void main()
{
	//int ar[] = {10, 6, 7, 1, 3, 9, 4, 2};
	//int ar[] = {49, 38, 5, 65, 97, 76, 13, 27, 49};
	//int ar[] = {12482, 15804, 6044, 10888, 26446, 2762, 9119, 23855, 14976, 508};
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //哨兵数据
	int ar[] = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 0, n);
	TestSort(ar, 0, n);
	PrintElement(ar, 0, n);
	TestSortEfficiency();
}

/*
void main()
{
	int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //哨兵数据
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 1, n);
	TestSort(ar, 1, n);
	PrintElement(ar, 1, n);
	//TestSortEfficiency();
}

/*
void main()
{
	//int ar[] = {49, 38, 65, 97, 76, 13, 27, 49};
	//int ar[] = {12482, 15804, 6044, 10888, 26446, 2762, 9119, 23855, 14976, 508};
	int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //哨兵数据
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 1, n+1);
	TestSort(ar, 0, n);
	PrintElement(ar, 0, n);
	TestSortEfficiency();
}


/*
//5! = 5*4*3*2*1
unsigned long long Factorial(int n)
{
	unsigned long long result = 1;
	for(int i=1; i<=n; ++i)
		result *= i;
	return result;
}

//n! = n * 4!==> n比较大
unsigned long long Factorial_R(int n)
{
	if(n == 1)
		return 1;
	else
		return n * Factorial_R(n-1);
}

void main()
{
	int n;
	printf("input n:>");
	scanf("%d", &n);
	unsigned long long res = Factorial(n);
	printf("%u\n", res);
}

/*
void main()
{
	char *str = "Hello Bit.";
	char ch = 'l';
	char *res = strchr(str, ch);
}

/*
void Func1(int N)
{
	int count = 0;
	//N^2
	for (int i = 0; i < N; ++i)       //N 0 1 2 ...... N
	{
		for (int j = 0; j < N; ++j)   //N N N N ...... N
		{
			++count;
		}
	}

	//2 * N
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}

	//10
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("count = %d\n", count);

	//N^2 + 2*N + 10
}

void main()
{
	int N = 1000;
	unsigned long start_time = clock();  //
	Func1(N);
	unsigned long end_time = clock();
	printf("time = %d\n", end_time - start_time);
}

/*
#define ROW 5
#define COL 5

void main()
{
	int **ppa = (int**)malloc(sizeof(int*) * ROW);
	for(int i=0; i<ROW; ++i)
	{
		ppa[i] = (int*)malloc(sizeof(int) * COL);
	}

	//int ppa[ROW][COL];
	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			ppa[i][j] = i+j;
		}
	}

	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			printf("%d ",ppa[i][j]);
		}
		printf("\n");
	}


	//释放
	for(int i=0; i<ROW; ++i)
		free(ppa[i]);
	free(ppa);
}

/*
void main()
{
	int ar[] = {27,15,19,18,28,34,65,49,25,37};
	int n = sizeof(ar) / sizeof(ar[0]); //

	Heap minheap;
	HeapInit(&minheap, n);

	for(int i=0; i<n; ++i)
		MinHeapInsert(&minheap, ar[i]);
	HeapPrint(&minheap);

	while(!HeapEmpty(&minheap))
	{
		printf("%d ", MinHeapRemove(&minheap));
		//HeapPrint(&minheap);
	}
	printf("\n");
}

/*
void main()
{
	int ar[] = {27,15,19,18,28,34,65,49,25,37};
	int n = sizeof(ar) / sizeof(ar[0]); //

	Heap minheap;
	HeapInit(&minheap, n);
	HeapSort(&minheap, ar, n);
}

/*
void main()
{
	int ar[] = {27,15,19,18,28,34,65,49,25,37};
	int n = sizeof(ar) / sizeof(ar[0]); //

	Heap minheap;
	HeapInit(&minheap, n);

	for(int i=0; i<n; ++i)
		MinHeapInsert(&minheap, ar[i]);
	HeapPrint(&minheap);

	while(!HeapEmpty(&minheap))
	{
		printf("%d ", MinHeapRemove(&minheap));
		//HeapPrint(&minheap);
	}
	printf("\n");
}


/*
void main()
{
	char ar[] = {'A','B', 'G', 'C', 'D', 'Z', 'H', 'X', 'Y', 'E', 'F'};
	int n = sizeof(ar) / sizeof(ar[0]);
	SeqBinTree sbt;
	SeqBinTreeInit(&sbt);

	SeqBinTreeInsert(&sbt, ar, n);
	SeqBinTreePrint(&sbt);
}

/*
//ABC##DE##F##g#H##

void main()
{
	const char *VLR = "ABCDEFGH";  //VLR+LVR ==> 
	const char *LVR = "CBEDFAGH";
	const char *LRV = "CEFDBHGA";  //LRV+LVR ==>     //VLR + LRV ==> ?

	BinTree bt;
	BinTreeCreateByVLR_LVR(&bt, VLR, LVR);
}

/*
void main()
{
	const char *VLR = "ABCDEFGH";  //VLR+LVR ==> 
	const char *LVR = "CBEDFAGH";
	const char *LRV = "CEFDBHGA";  //LRV+LVR ==>     //VLR + LRV ==> ?

	const char *str = "ABC##DE##F##G#H##";
	BinTree  bt;
	BinTreeInit(&bt);
	BinTreeCreateByStr(&bt, str);

	printf("VLR: ");
	PreOrder_NoR(&bt);
	printf("\n");

	printf("LVR: ");
	InOrder_NoR(&bt);
	printf("\n");

	printf("LRV: ");
	PostOrder_NoR(&bt);
	printf("\n");

	BinTreeDestroy(&bt);
}

/*
void main()
{
	const char *str = "ABC##DE##F##G#H##";
	const char *str1 = "ABC##DE##F##G#H##";
	BinTree  bt, bt1;
	BinTreeInit(&bt);
	BinTreeInit(&bt1);
	BinTreeCreateByStr(&bt, str);

	//BinTreeCopy(&bt, &bt1);
	BinTreeCreateByStr(&bt1, str1);

	bool flag = BinTreeEqual(&bt, &bt1);
	if(flag)
		printf("Equal.\n");
	else
		printf("Not Equal.\n");

}

/*
void main()
{
	const char *str = "ABC##DE##F##G#H##";
	BinTree  bt;
	BinTreeInit(&bt);
	BinTreeCreateByStr(&bt, str);

	char key = 'X';
	//BinTreeNode *p = BinTreeFind(&bt, key);
	BinTreeNode *p = BinTreeParent(&bt, key);
	if(p == NULL)
		printf("查找的节点不存在.\n");
	else
		//printf("data = %c\n", p->data);
		printf("parent = %c\n", p->data);

}

/*
void main()
{
	//const char *str = "AB#DF###CE###";
	const char *str = "ABC##DE##F##G#H##";
	BinTree  bt;
	BinTreeInit(&bt);
	//BinTreeCreate(&bt);
	BinTreeCreateByStr(&bt, str);

	printf("VLR: ");
	PreOrder(&bt);
	printf("\n");

	printf("LVR: ");
	InOrder(&bt);
	printf("\n");

	printf("LRV: ");
	PostOrder(&bt);
	printf("\n");

	printf("Level: ");
	LevelOrder(&bt);
	printf("\n");

	printf("Size = %d\n", BinTreeCount(&bt));
	printf("Height = %d\n", BinTreeHeight(&bt));
}

/*
void main()
{
	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEnQue(&Q, 1);
	LinkQueueEnQue(&Q, 2);
	LinkQueueEnQue(&Q, 3);
	LinkQueueEnQue(&Q, 4);

	LinkQueueDeQue(&Q);
	LinkQueuePrint(&Q);

}

/*
void main()
{
	CircleQueue Q;
	CircleQueueInit(&Q);

	CircleQueueEnque(&Q, 1);
	CircleQueueEnque(&Q, 2);
	CircleQueueEnque(&Q, 3);
	CircleQueueEnque(&Q, 4);
	CircleQueueEnque(&Q, 5);
	CircleQueueEnque(&Q, 6);
	CircleQueueEnque(&Q, 7);
	CircleQueueEnque(&Q, 8);

	CircleQueueDeque(&Q);

	CircleQueueEnque(&Q, 9);
	CircleQueuePrint(&Q);

	printf("对头 = %d\n", CircleQueueFront(&Q));
}


/*
void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q);

	SeqQueueEnque(&Q, 1);
	SeqQueueEnque(&Q, 2);
	SeqQueueEnque(&Q, 3);
	SeqQueueEnque(&Q, 4);
	SeqQueueEnque(&Q, 5);
	SeqQueueEnque(&Q, 6);
	SeqQueueEnque(&Q, 7);
	SeqQueueEnque(&Q, 8);

	SeqQueueDeque(&Q);

	SeqQueueEnque(&Q, 9);
	SeqQueuePrint(&Q);
}

/*
void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q);

	SeqQueueEnque(&Q, 1);
	SeqQueueEnque(&Q, 2);
	SeqQueueEnque(&Q, 3);
	SeqQueueEnque(&Q, 4);
	SeqQueueEnque(&Q, 5);
	SeqQueueEnque(&Q, 6);
	SeqQueueEnque(&Q, 7);
	SeqQueueEnque(&Q, 8);
	SeqQueueEnque(&Q, 9);
	SeqQueuePrint(&Q);

	printf("对头 = %d\n", SeqQueueFront(&Q));

	SeqQueueDeque(&Q);
	SeqQueuePrint(&Q);

	SeqQueueDeque(&Q);
	SeqQueuePrint(&Q);

	printf("对头 = %d\n", SeqQueueFront(&Q));

}

/*
void main()
{
	LinkStack st;
	LinkStackInit(&st);

	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);
	LinkStackPrint(&st);

	LinkStackPop(&st);
	LinkStackPrint(&st);

	LinkStackDestroy(&st);
}

/*
void main()
{
	SeqStack st;
	SeqStackInit(&st);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackPush(&st, 6);
	SeqStackPush(&st, 7);
	SeqStackPush(&st, 8);
	SeqStackPush(&st, 9);
	SeqStackPrint(&st);

	ElemType val = SeqStackTop(&st);
	SeqStackPop(&st); //6
	printf("%d 出栈.\n", val);

	val = SeqStackTop(&st);
	SeqStackPop(&st); //5
	printf("%d 出栈.\n", val);
	SeqStackPrint(&st);

	SeqStackDestroy(&st);
}

/*
int main()
{
	DCList mylist;
	DCListInit(&mylist);

	DCListNode *p;
	ElemType item, key;
	int select = 1;
	int pos = 0;
	while(select)
	{
		printf("***********************************************\n");
		printf("* [1] push_back              [2] push_front   *\n");
		printf("* [3] show_list              [0] quit_system  *\n");
		printf("* [4] pop_back               [5] pop_front    *\n");
		printf("* [*6] insert_pos            [7] insert_val   *\n");
		printf("* [*8] delete_pos            [9] delete_val   *\n");
		printf("* [10] find_val              [11] length      *\n");
		printf("* [*12] capacity             [13] sort        *\n");
		printf("* [14] reverse               [15] clear       *\n");
		printf("* [16] remove_all  自己实现                   *\n");
		printf("***********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;
		switch(select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]:>");
			while(scanf("%d", &item), item!=-1)
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]:>");
			while(scanf("%d", &item), item!=-1)
			{
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			//DCListSort(&mylist);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			DCListDeleteByVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if(p == NULL)
				printf("要查找的值不存在.\n");
			else
				printf("要查找的值为:> %d\n", p->data);
			break;
		case 11:
			printf("seqlist len = %d\n", DCListLength(&mylist));
			break;
		case 12:
			//printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			DCListSort(&mylist);
			printf("顺序表排序成功......\n");
			break;
		case 14:
			DCListReverse(&mylist);
			break;
		case 15:
			DCListClear(&mylist);
			printf("清除数据表成功......\n");
			break;
		case 16:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			break;
		}
	}
	DCListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}

/*
int main()
{
	SList mylist;
	SListInit(&mylist);

	SListNode *p;
	ElemType item, key;
	int select = 1;
	int pos = 0;
	while(select)
	{
		printf("***********************************************\n");
		printf("* [1] push_back              [2] push_front   *\n");
		printf("* [3] show_list              [0] quit_system  *\n");
		printf("* [4] pop_back               [5] pop_front    *\n");
		printf("* [*6] insert_pos            [7] insert_val   *\n");
		printf("* [*8] delete_pos            [9] delete_val   *\n");
		printf("* [10] find_val              [11] length      *\n");
		printf("* [*12] capacity             [13] sort        *\n");
		printf("* [14] reverse               [15] clear       *\n");
		printf("* [16] remove_all  自己实现                   *\n");
		printf("***********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;
		switch(select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]:>");
			while(scanf("%d", &item), item!=-1)
			{
				SListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]:>");
			while(scanf("%d", &item), item!=-1)
			{
				SListPushFront(&mylist, item);
			}
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			//SeqListSort(&mylist);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = SListFind(&mylist, key);
			if(p == NULL)
				printf("要查找的值不存在.\n");
			else
				printf("要查找的值为:> %d\n", p->data);
			break;
		case 11:
			printf("seqlist len = %d\n", SListLength(&mylist));
			break;
		case 12:
			//printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SListSort(&mylist);
			printf("顺序表排序成功......\n");
			break;
		case 14:
			SListReverse(&mylist);
			break;
		case 15:
			SListClear(&mylist);
			printf("清除数据表成功......\n");
			break;
		case 16:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			break;
		}
	}
	SListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}

/*
void main()
{
	int a = 0;
	int b = 2;

	//int value = ++a && ++b;
	int value = a++ || ++b;  //短路求值

	printf("a = %d\n", a); //1
	
	printf("b = %d\n", b); //
}


void Test_List()
{
	List mylist; //
	ListInit(&mylist);
	//ListCreate_Tail(&mylist);
	ListCreate_Head(&mylist);
	ListShow(mylist);
}

void main()
{
	Test_List();
}

/*
int main()
{
	SeqList mylist;
	SeqListInit(&mylist);

	ElemType item, key;
	int select = 1;
	int pos = 0;
	while(select)
	{
		printf("***********************************************\n");
		printf("* [1] push_back              [2] push_front   *\n");
		printf("* [3] show_list              [0] quit_system  *\n");
		printf("* [4] pop_back               [5] pop_front    *\n");
		printf("* [6] insert_pos             [7] insert_val   *\n");
		printf("* [8] delete_pos             [9] delete_val   *\n");
		printf("* [10] find_val              [11] length      *\n");
		printf("* [12] capacity              [13] sort        *\n");
		printf("* [14] reverse               [15] clear       *\n");
		printf("* [16] remove_all  自己实现                   *\n");
		printf("***********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;
		switch(select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]:>");
			while(scanf("%d", &item), item!=-1)
			{
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]:>");
			while(scanf("%d", &item), item!=-1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			SeqListSort(&mylist);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SeqListDeleteByVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if(pos == -1)
				printf("要查找的值不存在.\n");
			else
				printf("要查找的值的位置为:> %d\n", pos);
			break;
		case 11:
			printf("seqlist len = %d\n", SeqListLength(&mylist));
			break;
		case 12:
			printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SeqListSort(&mylist);
			printf("顺序表排序成功......\n");
			break;
		case 14:
			SeqListReverse(&mylist);
			break;
		case 15:
			SeqListClear(&mylist);
			printf("清除数据表成功......\n");
			break;
		case 16:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SeqListRemoveAll(&mylist, key);
			break;
		}
	}
	SeqListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}
*/