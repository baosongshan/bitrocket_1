#include"Contact.h"

void InitContact(Contact *pct)
{
	assert(pct != NULL);

	pct->capacity = DEFAULT_CONTACT_SIZE;
	pct->data = (PersonInfo*)malloc(sizeof(PersonInfo) * pct->capacity);
	assert(pct->data != NULL);
	memset(pct->data, 0, sizeof(PersonInfo) * pct->capacity);
	pct->size = 0;

	LoadContact(pct);
}

static int FindByName(Contact *pct, char *name)
{
	for(size_t i=0; i<pct->size; ++i)
	{
		if(strcmp(pct->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

static void CheckCapacity(Contact *pct)
{
	if(pct->size >= pct->capacity)
	{
		//空间满了
		PersonInfo *new_data = (PersonInfo*)realloc(pct->data, sizeof(PersonInfo)*(pct->capacity*2));
		assert(new_data != NULL);
		pct->capacity *= 2;
		pct->data = new_data;
		printf("扩容成功.....\n");
	}
}


void AddContact(Contact *pct)
{
	assert(pct != NULL);

	//检查容量
	CheckCapacity(pct);

	char  name[MAX_NAME_SIZE];
	char  sex[3];
	char  tel[12];
	char  addr[MAX_ADDR_SIZE];
	short age;
	printf("姓名:>");
	scanf("%s", pct->data[pct->size].name);
	printf("性别:>");
	scanf("%s", pct->data[pct->size].sex);
	printf("年龄:>");
	scanf("%d", &(pct->data[pct->size].age));
	printf("电话:>");
	scanf("%s", pct->data[pct->size].tel);
	printf("住址:>");
	scanf("%s", pct->data[pct->size].addr);
	pct->size++;
	printf("新增通讯录人员信息成功......\n");
}

void ShowContact(Contact *pct)
{
	assert(pct != NULL);
	printf("**************************************************\n");
	printf("*%-10s%-8s%-8s%-12s%-30s\n", "姓名","性别","年龄","电话","住址");
	for(size_t i=0; i<pct->size; ++i)
	{
		printf("*%-10s%-8s%-8d%-12s%-30s\n", pct->data[i].name,
								 pct->data[i].sex,
								 pct->data[i].age,
								 pct->data[i].tel,
								 pct->data[i].addr);
	}
	printf("**************************************************\n");
}



void FindContact(Contact *pct)
{
	assert(pct != NULL);
	if(pct->size == 0)
	{
		printf("通讯录为空,不能查询.....\n");
		return;
	}

	char name[MAX_NAME_SIZE] = {0};
	printf("请输入要查询的名字:>");
	scanf("%s", name);
	int index = FindByName(pct, name);
	if(index == -1)
	{
		printf("查无此人.....\n");
		return;
	}

	printf("*%-10s%-8s%-8s%-12s%-30s\n", "姓名","性别","年龄","电话","住址");
	printf("*%-10s%-8s%-8d%-12s%-30s\n", pct->data[index].name,
								pct->data[index].sex,
								pct->data[index].age,
								pct->data[index].tel,
								pct->data[index].addr);
}
void DelContact(Contact *pct)
{
	assert(pct != NULL);
	if(pct->size == 0)
	{
		printf("通讯录为空,不能删除.....\n");
		return;
	}

	char name[MAX_NAME_SIZE] = {0};
	printf("请输入要删除的名字:>");
	scanf("%s", name);
	int index = FindByName(pct, name);
	if(index == -1)
	{
		printf("要删除的人不存在.....\n");
		return;
	}

	for(int i=index; i<pct->size; ++i)
		pct->data[i] = pct->data[i+1];
	pct->size--;
	printf("删除成功......\n");
}
void ModifyContact(Contact *pct)
{
	assert(pct != NULL);
	if(pct->size == 0)
	{
		printf("通讯录为空,不能修改.....\n");
		return;
	}
	char name[MAX_NAME_SIZE] = {0};
	printf("请输入要修改的名字:>");
	scanf("%s", name);
	int index = FindByName(pct, name);
	if(index == -1)
	{
		printf("要修改的人不存在.....\n");
		return;
	}

	int select = 1;
	while(select)
	{
		printf("你想修改什么信息(1-姓名 2-性别 3-年龄 4-电话 5-住址)\n");
		scanf("%d", &select);
		switch(select)
		{
		case 1:
			printf("请输入要修改的姓名:>");
			scanf("%s", pct->data[index].name);
			break;
		case 2:
			printf("请输入要修改的性别:>");
			scanf("%s", pct->data[index].sex);
			break;
		case 3:
			printf("请输入要修改的年龄:>");
			scanf("%d", &(pct->data[index].age));
			break;
		case 4:
			printf("请输入要修改的电话:>");
			scanf("%s", pct->data[index].tel);
			break;
		case 5:
			printf("请输入要修改的住址:>");
			scanf("%s", pct->data[index].addr);
			break;
		default:
			printf("修改选项出错，请重新选择.\n");
			continue;
		}
		break;
	}
	printf("修改成功......\n");	
}
void ClearContact(Contact *pct)
{
	printf("确定要清空通讯录吗?<Y/N> :>");
	char ch;
	fflush(stdin);  //清空缓冲区里的\n
	scanf("%c", &ch);
	if(ch=='N' || ch=='n')
		return;
	pct->size = 0;
	memset(pct->data, 0, sizeof(pct->data));
}
void SortContact(Contact *pct)
{
	for(int i=0; i<pct->size-1; ++i)
	{
		for(int j=0; j<pct->size-i-1; ++j)
		{
			if(strcmp(pct->data[j].name, pct->data[j+1].name) > 0)
			{
				PersonInfo tmp = pct->data[j];
				pct->data[j] = pct->data[j+1];
				pct->data[j+1] = tmp;
			}
		}
	}
	printf("排序成功.....\n");
}

void DestroyContact(Contact *pct)
{
	free(pct->data);
	pct->data = NULL;
	pct->capacity = pct->size = 0;
	printf("数据清理成功.....\n");
}

void SaveContact(Contact *pct)
{
	FILE *fp = fopen("contact.dat", "w");
	assert(fp != NULL);

	for(size_t index=0; index<pct->size; ++index)
	{
		fprintf(fp, "%-10s%-8s%-8d%-12s%-30s\n", pct->data[index].name,
								pct->data[index].sex,
								pct->data[index].age,
								pct->data[index].tel,
								pct->data[index].addr);
	}
	fclose(fp);
	printf("通讯录保存成功.....\n");
}

void LoadContact(Contact *pct)
{
	FILE *fp = fopen("contact.dat", "r");
	assert(fp != NULL);

	while(!feof(fp))
	{
		CheckCapacity(pct);
		int res = fscanf(fp, "%s %s %d %s %s", pct->data[pct->size].name, 
									 pct->data[pct->size].sex,
									 &(pct->data[pct->size].age),
									 pct->data[pct->size].tel,
									 pct->data[pct->size].addr);
		if(res == EOF) //达到了文件末尾
			break;
		pct->size++;
	}

	fclose(fp);
	printf("加载通讯录成功.....\n");
}