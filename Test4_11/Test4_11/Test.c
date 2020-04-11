#include<stdio.h>

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define MOD 5
#define QUIT 0

int Add(int a, int b){return a + b;}
int Sub(int a, int b){return a - b;}
int Mul(int a, int b){return a * b;}
int Div(int a, int b){return a / b;}
int Mod(int a, int b){return a % b;}
int Max(int a, int b){return a>b?a:b;}

//转移表
int(*fun_table[])(int, int) = {0, Add, Sub, Mul, Div, Mod, Max};

int main(int argc, char *argv[])
{
	//////////////////////////////////////////////////
	system("title 简易计算器");
	system("mode con cols=36 lines=10");
	system("color 0F");
	//////////////////////////////////////////////////

	int select = 1;
	while(select)
	{
		printf("************简易计算器**************\n");
		printf("* [1] 加法               [2] 减法  *\n");
		printf("* [3] 乘法               [4] 除法  *\n");
		printf("* [5] 模运算             [0] 退出  *\n");
		printf("************************************\n");
		printf("请选择:>");
		scanf("%d", &select);

		if(select == QUIT)
			break;

		printf("input a and b:>");
		int a, b;
		scanf("%d %d", &a, &b);

		int result = fun_table[select](a, b); //

		//char oper[] = {'+','-','*','/', '%'};
		if(select == ADD)
			printf("%d + %d=%d\n",a,b,result);
		else if(select == SUB)
			printf("%d - %d=%d\n",a,b,result);
		else if(select == MUL)
			printf("%d * %d=%d\n",a,b,result);
		else if(select == DIV)
			printf("%d / %d=%d\n",a,b,result);
		else if(select == MOD)
			printf("%d \%% %d=%d\n",a,b,result);
		system("pause");
		system("cls");
	}
	return 0;
}

/*
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define MOD 5
#define QUIT 0

int Add(int a, int b){return a + b;}
int Sub(int a, int b){return a - b;}
int Mul(int a, int b){return a * b;}
int Div(int a, int b){return a / b;}
int Mod(int a, int b){return a % b;}

int main(int argc, char *argv[])
{
	//////////////////////////////////////////////////
	system("title 简易计算器");
	system("mode con cols=36 lines=10");
	system("color 0F");
	//////////////////////////////////////////////////

	int select = 1;
	while(select)
	{
		printf("************简易计算器**************\n");
		printf("* [1] 加法               [2] 减法  *\n");
		printf("* [3] 乘法               [4] 除法  *\n");
		printf("* [5] 模运算             [0] 退出  *\n");
		printf("************************************\n");
		printf("请选择:>");
		scanf("%d", &select);

		if(select == QUIT)
			break;

		printf("input a and b:>");
		int a, b;
		scanf("%d %d", &a, &b);

		int result = 0;
		switch(select)
		{
		case ADD:
			result = Add(a, b);
			break;
		case SUB:
			result = Sub(a, b);
			break;
		case MUL:
			result = Mul(a, b);
			break;
		case DIV:
			result = Div(a, b);
			break;
		case MOD:
			result = Mod(a, b);
			break;
		default:
			printf("Command Error, Please Input Again....\n");
			system("pause");
			system("cls");
			continue;
		}

		//char oper[] = {'+','-','*','/', '%'};
		if(select == ADD)
			printf("%d + %d=%d\n",a,b,result);
		else if(select == SUB)
			printf("%d - %d=%d\n",a,b,result);
		else if(select == MUL)
			printf("%d * %d=%d\n",a,b,result);
		else if(select == DIV)
			printf("%d / %d=%d\n",a,b,result);
		else if(select == MOD)
			printf("%d \%% %d=%d\n",a,b,result);
		system("pause");
		system("cls");
	}
	return 0;
}

/*
void fun1()
{
	printf("This is fun1.\n");
}
void fun2()
{
	printf("This is fun1.\n");
}
void fun3()
{
	printf("This is fun1.\n");
}

void main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int* ar[3] = {&a, &b, &c};

	void(*br[3])() = {&fun1, &fun2, &fun3};
}


/*
//代码1
(*(void (*)())0)();

//代码2
void (*signal(int , void(*)(int)))(int);

/*
//指针数组 数组指针 
//函数指针 指针函数
int * (* (*fun) (int *)) [10]

/*
用变量a给出下面的定义
a) 一个整型数  int a;
b) 一个指向整型数的指针
c) 一个指向指针的指针，它指向的指针是指向一个整型数
d) 一个有10个整型数的数组
e) 一个有10个指针的数组，该指针是指向一个整型数的。
f) 一个指向有10个整型数数组的指针
g) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数
h) 一个有10个指针的数组，该指针指向一个函数，
   该函数有一个整型参数并返回一个整型数

a> int a;
b> int* a;
c> int** a;
d> int a[10];
e> int* a[10];
f> int (a*)[10];
g> int (*a)(int);
h> int(*a[10])(int)



/*
void fun()
{
	printf("Hello Bit.\n");
}
int max(int a, int b)
{
	return a > b ? a : b;
}

void main()
{
	fun();

	void(*pfun)(); // 函数指针

	pfun = &fun;
	(*pfun)();

	pfun = fun;
	pfun();

	int(*pfun1)(int, int);
	pfun1 = max;  //Error
	pfun1(10,20);
}

/*
void main()
{
	printf("%p\n", fun);
	printf("%p\n", &fun);  // 等价

	fun();
}

/*
void main()
{
	fun();
	max(10,20);
}

/*
//test1函数能接收什么参数？
void test1(int *p)
{}

//test2函数能接收什么参数？
void test2(char* p)
{}

void test3(int **ptr)
{}

void main()
{
	int a = 10;
	int *pa = &a;

	test3(&pa);

}

/*
void main()
{
	int a = 10;
	test1(&a);

	int ar[3] = {0};
	test1(ar);

	char ch = 'A';
	test2(&ch);

	char cr[3] = {'a','b','c'};
	test2(cr);
}

/*
void test(int arr[])//ok?
{}
void test1(int arr[10])//ok?
{}
void test2(int *arr)//ok?
{}
void test3(int *arr[])//ok?  //Error  int **arr
{}
void test4(int **arr)
{}


void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(ar[0]);
	//test3(ar);

	int *br[10] = {0};
	test4(br);
}

/*
int arr[5];
int* parr1[10];
int (*parr2)[10];

int (* parr3[10])[5];  //数组指针 数组

/*
#define ROW 5
#define COL 5

void PrintArray2(int(*pa)[COL], int row, int col)
{
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			printf("%d ", pa[i][j]);
		}
		printf("\n");
	}
}

void PrintArray3(int pa[ROW][COL], int row, int col)
{
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			printf("%d ", pa[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int ar[ROW][COL] = {0};
	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			ar[i][j] = i+j;
		}
	}

	PrintArray3(ar, ROW, COL);
}

/*
void PrintArray1(int a[], int n)
{
	for(int i=0; i<n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintArray1(ar, n);
}


/*
void PrintArray1(int a[])
{
	printf("ar size = %d\n", sizeof(a));
	int n = sizeof(a) / sizeof(a[0]);
	for(int i=0; i<n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};

	printf("ar size = %d\n", sizeof(ar));

	int n = sizeof(ar) / sizeof(ar[0]);
	PrintArray1(ar);
}

/*
void PrintArray()
{}

void main()
{
	int ar[ROW][COL] = {0};
	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			ar[i][j] = i+j;
		}
	}

	PrintArray();
}

/*
void main()
{
	int ar[ROW][COL] = {0};
	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			ar[i][j] = i+j;
		}
	}

	//printf("%d\n", sizeof(ar)); //25 * 4

	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			printf("%d ",ar[i][j]);
		}
		printf("\n");
	}

	////////////////////////////////////////////////////////
	int (*pa)[COL] = ar;
	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			printf("%d ",pa[i][j]);
		}
		printf("\n");
	}

	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			printf("%d ", *(*(pa+i)+j));
		}
		printf("\n");
	}
}

/*
//人
void main()
{
	int a[3] = {1,2,3};
	a[0] = 10; // *(a+0) //
	a[1] = 20;
	a[2] = 30;

	0[a] = 100;// *(0+a) ==> 0[a];  维护高
}

/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	for(int i=0; i<10; ++i)
		printf("%d ", ar[i]);   //下标  [ ) 0 1 2 3 4 5 6 7 8 9 
	printf("\n");

	for(int i=0; i<10; ++i)
		printf("%d ", *(ar+i));   //下标  [ ) 0 1 2 3 4 5 6 7 8 9 
	printf("\n");

	int *pa = ar;
	for(int i=0; i<10; ++i)
		printf("%d ", *(pa+i));   //指针
	printf("\n");

	for(int i=0; i<10; ++i)
		printf("%d ", pa[i]);
	printf("\n");
}

/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("%p\n", &ar[0]);
	printf("%p\n", ar);
	printf("%p\n", &ar);

	printf("%d\n", sizeof(&ar[0]));  //4   4   4
	printf("%d\n", sizeof(ar));      //10  40  4
	printf("%d\n", sizeof(&ar));     //4   4   4

	int(*pa)[10] = &ar;
	//pa + 1;
}

/*
int main()
{
	int a = 10;
	int *pa = &a;
	return 0;
}
*/