#ifndef _LIST_H_
#define _LIST_H_

#include"common.h"

//定义链表节点
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;

//单链表带头结点
void ListInit(List *plist)  //ListNode **plist
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->next = NULL;
}

//尾插法创建单链表
void ListCreate_Tail(List *plist)
{}

//头插法创建单链表
void ListCreate_Head(List *plist)
{}

void ListShow(List plist)
{}

/*
//单链表不带头结点
void ListInit(List *plist)  //ListNode **plist
{
	*plist = NULL;
}

//尾插法创建单链表
void ListCreate_Tail(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->next= NULL;

	ListNode *p = *plist;
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		//连接节点
		p->next = s;
		p = s;
	}
}

//头插法创建单链表
void ListCreate_Head(List *plist)
{
	(*plist) = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->next = NULL;

	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		
		//连接节点
		s->next = (*plist);
		(*plist) = s;
	}
}

void ListShow(List plist)
{
	ListNode *p = plist;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
*/

#endif /* _LIST_H_ */