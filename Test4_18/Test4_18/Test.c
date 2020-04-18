#include<stdio.h>
#include<stdlib.h>
#include<vld.h>
#include<assert.h>
//柔性数组成员
//1 不开辟空间
//2 只能是最后一个成员

typedef struct st_type
{
	int i;
	int *pa; //柔性数组成员
}type_a;
void main()
{
	printf("type_a size = %d\n", sizeof(type_a));  //8
	int i = 0;
	                            //  4                 //10 int
	type_a *p = (type_a*)malloc(sizeof(type_a));
	p->i = 10;

	p->pa = (int*)malloc(sizeof(int) * 10);
	for (i = 0; i < 10; i++)
	{
		p->pa[i] = i;
	}

	free(p->pa);
	free(p);
}

/*
typedef struct st_type
{
	int i;
	int a[0]; //柔性数组成员
}type_a;
void main()
{
	printf("type_a size = %d\n", sizeof(type_a));
	int i = 0;
	                            //  4                 //10 int
	type_a *p = (type_a*)malloc(sizeof(type_a) + 100 * sizeof(int));

	p->i = 10;
	for (i = 0; i < 10; i++)
	{
		p->a[i] = i;
	}

	free(p);
}

/*
typedef struct Test
{
	char a;
	char pstr[0]; 
}Test;

void main()
{
	printf("size = %d\n", sizeof(Test));
	char str[] = "hellfjlajfkajlkajlo";
	char str1 = "abcdef";
	Test t;
	printf("pstr = %s\n", t.pstr);
}

/*
typedef struct Test
{
	char a;
	int b;
	char *pstr;  //4
}Test;

void main()
{
	char *str = "hello";
	Test *pt = (Test*)malloc(sizeof(Test) + strlen(str) + 1);
	assert(pt != NULL);

	//pt->pstr = (char*)pt + sizeof(Test);
	pt->pstr = (char*)(pt + 1);
	strcpy(pt->pstr, str);

	printf("str = %s\n", pt->pstr);
}

/*
void main()
{
	Test t;
	t.pstr = (char*)malloc(sizeof(char)*10);
	assert(t.pstr != NULL);

	strcpy(t.pstr, "hellofjoafoajfoa");

	printf("str = %s\n", t.pstr);
}

/*
typedef struct st_type
{
	int i;
	int a[0]; //柔性数组成员
}type_a;

void main()
{
	int *p = (int*)malloc(sizeof(int)*10);
}

/*
void main()
{
	printf("type_a size = %d\n", sizeof(type_a));
	int i = 0;
	                            //  4                 //10 int
	type_a *p = (type_a*)malloc(sizeof(type_a) + 10 * sizeof(int));

	//业务处理
	p->i = 10;
	for (i = 0; i < 10; i++)
	{
		p->a[i] = i;
	}
	free(p);
}


/*
typedef struct Test
{
	int a;
	int b;
	int c;
	int ar[0];
}Test;

void main()
{
	printf("size = %d\n", sizeof(Test));
}

/*
char *GetMemory(void)
{
	//局部变量
	static  char p[] = "hello world";
	return p;
}
void Test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}
void main()
{
	Test();
}

/*
void Test(void)
{
	char *str = (char *)malloc(100);
	strcpy(str, "hello");
	free(str); //野指针  str == NULL
	//str = NULL;

	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}
void main()
{
	Test();
}


/*
void GetMemory(char **p, int num)
{
	*p = (char *)malloc(num);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);

	free(str);
	str = NULL;
}
void main()
{
	Test();
}

/*
char *GetMemory(void)
{
	//局部变量
	static char p[] = "hello world";
	return p;
}
void Test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}
void main()
{
	Test();
}

/*
void GetMemory(char **p)
{
	*p = (char *)malloc(100);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(&str);//传值
	strcpy(str, "hello world");
	printf(str);

	//free(str);
}
void main()
{
	Test();
}


/*
void main()
{
	int *ptr = (int*)malloc(sizeof(int) * 10);
	assert(ptr != NULL);
	free(ptr);
	ptr = NULL;
	//一定要杜绝
	if(ptr != NULL)
	{
		for(int i=0; i<10; ++i)
			ptr[i] = i+1;
	}

	//free(ptr);
}

/*
void main()
{
	int *ptr = (int*)malloc(sizeof(int) * 10);
	assert(ptr != NULL);
	//1 2 3 4 5 6 7 8 9 10
	ptr++;
	ptr--;
	free(ptr);
}

/*
void test()
{
	int *p = (int *)malloc(sizeof(int)*536870911);

	//p合法性要判断

	*p = 20;//如果p的值是NULL，就会有问题
	printf("%d\n", *p);
	free(p);
}
void main()
{
	test();
}

/*
//heap
//void *malloc( size_t size );
//void *calloc( size_t num, size_t size );
//void *realloc( void *memblock, size_t size );

//stack空间不能由用户释放
//void *_alloca( size_t size );

void main()
{
	int *ptr = (int*)_alloca(sizeof(int) * 10);
	assert(ptr != NULL);
	//free(ptr);
}

/*
void* my_realloc( void *memblock, size_t size )
{
	//1 申请一个更大的空间
	void *new_memblock = malloc(size);
	if(new_memblock == NULL)
		return NULL;

	//2 把原来的数据进行拷贝
	memcpy(new_memblock, memblock, size);

	//3 释放原有空间
	free(memblock);
	
	//4 返回新的空间地址
	return new_memblock;
}

void main()
{
	int *ptr1 = (int *)malloc(sizeof(int) * 5);//
	assert(ptr1 != NULL);
	for(int i=0; i<5; ++i)  //1 2 3 4 5
		ptr1[i] = i+1;

	//很容易出错
	int *tmp= my_realloc(ptr1, sizeof(int)*10);
	if(tmp != NULL)
	{
		ptr1 = tmp;
	}
	else
	{
		free(ptr1);
		return;
	}

	for(int i=5; i<10; ++i)  //1 2 3 4 5
		ptr1[i] = i+1;

	for(int i=0; i<10; ++i)
		printf("%d ",ptr1[i]);
	printf("\n");
}

/*
//1 2 3 4 5 6 7 8 9 10
void main()
{
	int *ptr1 = (int *)malloc(sizeof(int) * 5);//
	assert(ptr1 != NULL);
	for(int i=0; i<5; ++i)  //1 2 3 4 5
		ptr1[i] = i+1;

	//很容易出错
	int *tmp= realloc(ptr1, sizeof(int)*10000000000);
	if(tmp == NULL)
	{
		free(ptr1);
		return;
	}

	for(int i=5; i<100000; ++i)  //1 2 3 4 5
		ptr1[i] = i+1;

	for(int i=0; i<100000; ++i)
		printf("%d ",ptr1[i]);
	printf("\n");
}

/*
void main()
{
	int *ptr1 = (int *)malloc(sizeof(int) * 10);//
	assert(ptr1 != NULL);

	int *ptr2 = (int *)calloc(10, sizeof(int)); //calloc 会使用0进行初始化
	assert(ptr2 != NULL);

	free(ptr1);
	free(ptr2);
	ptr1 = NULL;
	ptr2 = NULL;
}

/*
typedef struct Student
{
	char *name; //没有字符串空间
	int age;
	char sex[3];
}Student;

void main()
{
	Student *ps = (Student *)malloc(sizeof(Student));
	assert(ps != NULL);
	ps->age = 20;
	strcpy(ps->sex,"男");

	ps->name = (char*)malloc(sizeof(char)*10);
	assert(ps->name != NULL);
	strcpy(ps->name, "张三");
}

/*
void main()
{
	int *ptr = (int*)malloc(sizeof(int)*10);
	//int *ptr = NULL;
	free(ptr);  //预防野指针
	ptr = NULL;

	free(ptr);
}

/*
void main()
{
	for(;;)
	{
		int *ptr = (int*)malloc(sizeof(int)*10);
		free(ptr);
	}
}

/*
void main()
{
	int *ptr = (int*)malloc(sizeof(int)*10);
	assert(ptr != NULL);

	for(int i=0; i<10; ++i)  //本身C语言不检查越界操作
		ptr[i] = i+1;

	for(int i=0; i<10; ++i)
		printf("%d ",ptr[i]);
	printf("\n");

	//free(ptr);
}

/*
void main()
{
	//int n = 536870911;
	int n = 10;
	int *ar;  //ar 没有空间

	ar = (int*)malloc(sizeof(int)*n); // 2
	if(NULL == ar)  //
	{
		printf("bad allocator.\n");
		return;
	}
	for(int i=0; i<10; ++i)
		ar[i] = i+1;

	for(int i=0; i<10; ++i)
		printf("%d ",ar[i]);
	printf("\n");

	int *br = (int*)malloc(sizeof(int)*1);

	//内存泄漏
	free(ar);
	free(br);
}

/*
void main()
{
	int n;
	printf("input n:>");
	scanf("%d", &n);

	int *ar;  //ar 没有空间

	ar = (int*)malloc(sizeof(int)*n); // 2
	for(int i=0; i<10; ++i)
		ar[i] = i+1;
}

/*
//哲学家
void main()
{
	char ch = 'a';
	int *pi = (int*)&ch;   //类型不同
	double d = 12.34;

	//void * 泛型指针
	void *pv = &ch;
	pv = &d;

	*(double*)pv;  //
}

/*
void main()
{
	int n;
	printf("input n:>");
	scanf("%d", &n);

	int *ar = malloc(sizeof(int) * n);
}

/*
//#define n 10

void main()
{
	const int n = 100; //常量
	int ar[n];   //Error
}

/*
int fun(int a, int b)
{
	int v = a + b;
	return v;
}

void main()
{
	int a = 10;
	int b = 20;

	int res = fun(a, b);
}


int main()
{
	//静态开辟
	int a = 0;
	char ar[10] = {0};

	return 0;
}
*/