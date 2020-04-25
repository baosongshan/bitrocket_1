#include"seqlist.h"

int main()
{
	SeqList mylist;
	SeqListInit(&mylist);

	ElemType item;
	int select = 1;
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

		}
	}
	SeqListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}