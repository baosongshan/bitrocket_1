#ifndef _TREE_H_
#define _TREE_H_

#include"common.h"

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;

#define LEVEL_ORDER
#ifdef LEVEL_ORDER

typedef struct LinkQueueNode
{
	BinTreeNode* data;
	struct LinkQueueNode *link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

void LinkQueueInit(LinkQueue *pq);
void LinkQueueEnQue(LinkQueue *pq, BinTreeNode* x);
void LinkQueueDeQue(LinkQueue *pq);
void LinkQueuePrint(LinkQueue *pq);
bool LinkQueueEmpty(LinkQueue *pq);
BinTreeNode* LinkQueueFront(LinkQueue *pq);

void LinkQueueInit(LinkQueue *pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}

void LinkQueueEnQue(LinkQueue *pq, BinTreeNode* x)
{
	assert(pq != NULL);
	LinkQueueNode *node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	node->link = NULL;

	if(pq->front == NULL)
		pq->front = pq->rear = node;
	else
	{
		pq->rear->link = node;
		pq->rear = node;
	}
}
void LinkQueueDeQue(LinkQueue *pq)
{
	assert(pq != NULL);
	if(pq->front != NULL)
	{
		LinkQueueNode *p = pq->front;
		pq->front = p->link;
		free(p);
	}
}
void LinkQueuePrint(LinkQueue *pq)
{
	assert(pq != NULL);
	LinkQueueNode *p = pq->front;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->link;
	}
	printf("\n");
}

bool LinkQueueEmpty(LinkQueue *pq)
{
	return pq->front == NULL;
}

BinTreeNode* LinkQueueFront(LinkQueue *pq)
{
	assert(pq->front != NULL);
	return pq->front->data;
}
#endif

#define ORDER_NOR
#ifdef ORDER_NOR
//链栈
typedef struct LinkStackNode
{
	BinTreeNode *data;
	struct LinkStackNode *link; //next
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode *top;
}LinkStack;

void LinkStackInit(LinkStack *pst);
void LinkStackPush(LinkStack *pst, BinTreeNode * x);
void LinkStackPop(LinkStack *pst);
BinTreeNode * LinkStackTop(LinkStack *pst);
bool LinkStackEmpty(LinkStack *pst);
void LinkStackPrint(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);

void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}

void LinkStackPush(LinkStack *pst, BinTreeNode * x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = pst->top;
	pst->top = node;
}
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	pst->top = p->link;

	free(p);
}
BinTreeNode * LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL);
	if(pst->top == NULL)
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	return pst->top->data;
}
void LinkStackPrint(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	while(p != NULL)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
	printf("\n");
}

void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	while(pst->top != NULL)
	{
		LinkStackNode *p = pst->top;
		pst->top = p->link;
		free(p);
	}
}

bool LinkStackEmpty(LinkStack *pst)
{
	return pst->top ==  NULL;
}
#endif


void BinTreeInit(BinTree *pbt);
//创建
void BinTreeCreate(BinTree *bt);
void BinTreeCreate_1(BinTreeNode **t);
BinTreeNode* BinTreeCreate_2();
void BinTreeCreateByStr(BinTree *bt, const char *str);
BinTreeNode* BinTreeCreateByStr_1(const char *str, int *pindex);

//恢复二叉树
void BinTreeCreateByVLR_LVR(BinTree *bt, const char *VLR, const char *LVR);
BinTreeNode* BinTreeCreateByVLR_LVR_1(const char *VLR, const char *LVR, int n);
void BinTreeCreateByLRV_LVR(BinTree *bt, const char *VLR, const char *LVR);
BinTreeNode* BinTreeCreateByLRV_LVR_1(const char *VLR, const char *LVR, int n);

//递归遍历
void PreOrder(BinTree *bt);
void PreOrder_1(BinTreeNode *t);
void InOrder(BinTree *bt);
void InOrder_1(BinTreeNode *t);
void PostOrder(BinTree *bt);
void PostOrder_1(BinTreeNode *t);
void LevelOrder(BinTree *bt);
void LevelOrder_1(BinTreeNode *t);

//非递归遍历
void PreOrder_NoR(BinTree *bt);
void PreOrder_1_NoR(BinTreeNode *t);
void InOrder_NoR(BinTree *bt);
void InOrder_1_NoR(BinTreeNode *t);
void PostOrder_NoR(BinTree *bt);
void PostOrder_1_NoR(BinTreeNode *t);


//求二叉树的节点个数以及树的高度
int BinTreeCount(BinTree *bt);
int BinTreeCount_1(BinTreeNode *t);
int BinTreeHeight(BinTree *bt);
int BinTreeHeight_1(BinTreeNode *t);

//查询
BinTreeNode* BinTreeFind(BinTree *bt,   ElemType key);
BinTreeNode* BinTreeFind_1(BinTreeNode *t,   ElemType key);
BinTreeNode* BinTreeParent(BinTree *bt, ElemType key);
BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType key);

//拷贝二叉树
void BinTreeCopy(BinTree *bt1, BinTree *bt2);  //bt2 = bt1;
BinTreeNode* BinTreeCopy_1(BinTreeNode *t);

//判断二叉树
bool BinTreeEqual(BinTree *bt1, BinTree *bt2);
bool BinTreeEqual_1(BinTreeNode *t1, BinTreeNode *t2);

//摧毁二叉树
void BinTreeDestroy(BinTree *bt);
void BinTreeDestroy_1(BinTreeNode *t);
//==================================================

void BinTreeInit(BinTree *pbt)
{
	pbt->root = NULL;
}
void BinTreeCreate(BinTree *bt)
{
	//1 BinTreeCreate_1(&bt->root);
	//2
	bt->root = BinTreeCreate_2();
}
void BinTreeCreate_1(BinTreeNode **t)
{
	ElemType item;
	scanf("%c", &item);
	if(item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate_1(&(*t)->leftChild);
		BinTreeCreate_1(&(*t)->rightChild);
	}
}
BinTreeNode* BinTreeCreate_2()
{
	ElemType item;
	scanf("%c", &item);
	if(item == '#')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = BinTreeCreate_2();
		t->rightChild = BinTreeCreate_2();
		return t;
	}
}

void BinTreeCreateByStr(BinTree *bt, const char *str)
{
	int index = 0;
	bt->root = BinTreeCreateByStr_1(str, &index);
}

//"ABC##DE##F##G#H##";
BinTreeNode* BinTreeCreateByStr_1(const char *str, int *pindex)
{
	if(str[*pindex] == '#' || str[*pindex] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*pindex];
		(*pindex)++;
		t->leftChild = BinTreeCreateByStr_1(str, pindex);
		(*pindex)++;
		t->rightChild = BinTreeCreateByStr_1(str, pindex);
		return t;
	}
}

//恢复二叉树
void BinTreeCreateByVLR_LVR(BinTree *bt, const char *VLR, const char *LVR)
{
	int n = strlen(VLR);
	bt->root = BinTreeCreateByVLR_LVR_1(VLR, LVR, n);
}
BinTreeNode* BinTreeCreateByVLR_LVR_1(const char *VLR, const char *LVR, int n)
{
	if(n == 0)
		return NULL;
	int k = 0;
	while(VLR[0] != LVR[k])
		k++;
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = LVR[k]; //VLR[0];

	t->leftChild = BinTreeCreateByVLR_LVR_1(VLR+1, LVR, k);
	t->rightChild = BinTreeCreateByVLR_LVR_1(VLR+k+1, LVR+k+1, n-k-1);
	return t;
}
void BinTreeCreateByLRV_LVR(BinTree *bt, const char *VLR, const char *LVR);
BinTreeNode* BinTreeCreateByLRV_LVR_1(const char *VLR, const char *LVR, int n);

//遍历
void PreOrder(BinTree *bt)
{
	PreOrder_1(bt->root);
}
void PreOrder_1(BinTreeNode *t)
{
	if(t != NULL)
	{
		printf("%c ", t->data);
		PreOrder_1(t->leftChild);
		PreOrder_1(t->rightChild);
	}
}

void InOrder(BinTree *bt)
{
	InOrder_1(bt->root);
}
void InOrder_1(BinTreeNode *t)
{
	if(t != NULL)
	{
		InOrder_1(t->leftChild);
		printf("%c ", t->data);
		InOrder_1(t->rightChild);
	}
}
void PostOrder(BinTree *bt)
{
	PostOrder_1(bt->root);
}
void PostOrder_1(BinTreeNode *t)
{
	if(t != NULL)
	{
		PostOrder_1(t->leftChild);
		PostOrder_1(t->rightChild);
		printf("%c ", t->data);
	}
}

void LevelOrder(BinTree *bt)
{
	LevelOrder_1(bt->root);
}
void LevelOrder_1(BinTreeNode *t)
{
	if(t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueueEnQue(&Q, t);
		while(!LinkQueueEmpty(&Q))
		{
			BinTreeNode *p = LinkQueueFront(&Q);
			LinkQueueDeQue(&Q);
			printf("%c ", p->data);
			if(p->leftChild != NULL)
				LinkQueueEnQue(&Q, p->leftChild);
			if(p->rightChild != NULL)
				LinkQueueEnQue(&Q, p->rightChild);
		}
	}
}


int BinTreeCount(BinTree *bt)
{
	return BinTreeCount_1(bt->root);
}
int BinTreeCount_1(BinTreeNode *t)
{
	if(t == NULL)
		return 0;
	else
		return BinTreeCount_1(t->leftChild) + BinTreeCount_1(t->rightChild)+1;
}
int BinTreeHeight(BinTree *bt)
{
	return BinTreeHeight_1(bt->root);
}
int BinTreeHeight_1(BinTreeNode *t)
{
	if(t == NULL)
		return 0;
	else
	{
		int left_h = BinTreeHeight_1(t->leftChild);
		int right_h = BinTreeHeight_1(t->rightChild);
		return (left_h > right_h ? left_h : right_h)+1;
	}
}

//查询
BinTreeNode* BinTreeFind(BinTree *bt,   ElemType key)
{
	return BinTreeFind_1(bt->root, key);
}
BinTreeNode* BinTreeFind_1(BinTreeNode *t,   ElemType key)
{
	BinTreeNode *p;
	if(t==NULL || t->data==key)
		return t;
	p = BinTreeFind_1(t->leftChild, key);
	if(p != NULL)
		return p;
	return BinTreeFind_1(t->rightChild, key);
}

BinTreeNode* BinTreeParent(BinTree *bt, ElemType key)
{
	return BinTreeParent_1(bt->root, key);
}
BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType key)
{
	BinTreeNode *p;
	if(t==NULL || t->data==key)
		return NULL;
	if((t->leftChild!=NULL && t->leftChild->data==key) 
	   || (t->rightChild!=NULL && t->rightChild->data==key))
		return t;
	p = BinTreeParent_1(t->leftChild, key);
	if(p != NULL)
		return p;
	return BinTreeParent_1(t->rightChild, key);
}

//拷贝二叉树
void BinTreeCopy(BinTree *bt1, BinTree *bt2)  //bt2 = bt1;
{
	bt2->root = BinTreeCopy_1(bt1->root);
}
BinTreeNode* BinTreeCopy_1(BinTreeNode *t)
{
	if(t == NULL)
		return NULL;
	else
	{
		BinTreeNode *tmp = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(tmp != NULL);
		tmp->data = t->data;

		tmp->leftChild = BinTreeCopy_1(t->leftChild);
		tmp->rightChild = BinTreeCopy_1(t->rightChild);
		return tmp;
	}
}

//判断二叉树
bool BinTreeEqual(BinTree *bt1, BinTree *bt2)
{
	return BinTreeEqual_1(bt1->root, bt2->root);
}
bool BinTreeEqual_1(BinTreeNode *t1, BinTreeNode *t2)
{
	if(t1==NULL && t2==NULL)
		return true;
	if(t1==NULL || t2==NULL)
		return false;

	if(t1->data==t2->data 
	   && BinTreeEqual_1(t1->leftChild, t2->leftChild)
	   && BinTreeEqual_1(t1->rightChild, t2->rightChild))
	   return true;

	return false;
}

//摧毁二叉树
void BinTreeDestroy(BinTree *bt)
{
	BinTreeDestroy_1(bt->root); 
}
void BinTreeDestroy_1(BinTreeNode *t)
{
	if(t == NULL)
		return;
	BinTreeDestroy_1(t->leftChild);
	BinTreeDestroy_1(t->rightChild);
	free(t);
}


//非递归遍历
void PreOrder_NoR(BinTree *bt)
{
	PreOrder_1_NoR(bt->root);
}
void PreOrder_1_NoR(BinTreeNode *t)
{
	if(t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		LinkStackPush(&st, t);
		while(!LinkStackEmpty(&st))
		{
			BinTreeNode *top = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ",top->data);
			if(top->rightChild != NULL)
				LinkStackPush(&st, top->rightChild);
			if(top->leftChild != NULL)
				LinkStackPush(&st, top->leftChild);
		}
	}
}

void InOrder_NoR(BinTree *bt)
{
	InOrder_1_NoR(bt->root);
}
void InOrder_1_NoR(BinTreeNode *t)
{
	if(t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		BinTreeNode *top;
		
		BinTreeNode *cur = t;
		while(cur || !LinkStackEmpty(&st))
		{
			while(cur)
			{
				LinkStackPush(&st, cur);
				cur = cur->leftChild;
			}
			top = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ",top->data);

			cur = top->rightChild;
		}
	}
}
void PostOrder_NoR(BinTree *bt)
{
	PostOrder_1_NoR(bt->root);
}
void PostOrder_1_NoR(BinTreeNode *t)
{
	if(t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		BinTreeNode *top, *prev = NULL;  //prev指向当前访问节点的前驱节点
		BinTreeNode *cur = t;
		while(cur || !LinkStackEmpty(&st))
		{
			while(cur)
			{
				LinkStackPush(&st, cur);
				cur = cur->leftChild;
			}
			top = LinkStackTop(&st);
			if(top->rightChild==NULL || top->rightChild == prev)
			{
				printf("%c ",top->data);
				prev = top;
				LinkStackPop(&st);
			}
			else
			{
				cur = top->rightChild;
			}
		}
	}
}


///////////////////////////////////////////////////////////////////////////
//树的顺序存储结构
typedef struct SeqBinTree
{
	char *data;
	int   capacity;
	int   size;
}SeqBinTree;

void SeqBinTreeInit(SeqBinTree *psbt);
void SeqBinTreeInsert(SeqBinTree *psbt, char ar[], int n);
void SeqBinTreePrint(SeqBinTree *psbt);

void SeqBinTreeInit(SeqBinTree *psbt)
{
	psbt->data = (char*)malloc(sizeof(char) * 100);
	psbt->capacity = 100;
	psbt->size = 0;
}

void SeqBinTreeInsert(SeqBinTree *psbt, char ar[], int n)
{
	for(int i=0; i<n; ++i)
	{
		psbt->data[psbt->size++] = ar[i];
	}
}

void SeqBinTreePrint(SeqBinTree *psbt)
{
	for(int i=0; i<psbt->size; ++i)
	{
		printf("%c ",psbt->data[i]);
	}
	printf("\n");
}

#endif /* _TREE_H_ */