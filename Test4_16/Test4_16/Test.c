#include<stdio.h>
#include<stdbool.h>

void main()
{
	int n;
	printf("input n:>");
	scanf("%d", &n);
	//int ar[20];     //n 决定下来  //10  30

	int *ar = (int*)malloc(sizeof(int) * n);  //
	for(int i=1; i<=n; ++i)
		ar[i-1] = i;

	for(int i=0; i<n; ++i)
		printf("%d ", ar[i]);
	printf("\n");

	free(ar);  //
}

/*
typedef union IpAddress
{
	struct
	{
		unsigned char ip1;
		unsigned char ip2;
		unsigned char ip3;
		unsigned char ip4;
	};
	unsigned long ip;
}IpAddress;

void main()
{
	unsigned long ip = 4917491419;  // ==> 192.168.0.100

	IpAddress MyIp;
	MyIp.ip = ip;

	printf("ip = %d.%d.%d.%d\n",MyIp.ip1, MyIp.ip2, MyIp.ip3, MyIp.ip4);
}

/*
//#pragma pack(1)
union Un1   //4
{
	char c[5];   //5
	int i;       //4
};

union Un2
{
	short c[7]; //14
	int i;      //4
};

void main()
{
	printf("size = %d\n", sizeof(union Un2));
}

/*
bool Check()
{
	int i = 0x00000001; //01 00 00 00   00 00 00 01
	return (i&0x01==1);
}

bool Check1()
{
	union
	{
		char ch;
		int  i;
	}un;

	un.i = 1;
	return (un.ch == 1);
}

void main()
{
	bool flag = Check1();
	if(flag)
		printf("This is Little.\n");
	else
		printf("This is Big.\n");
}

/*
typedef union Un
{
	int i;   //4
	char c;  //1
}Un;
void main()
{
	Un un;

	printf("0x%p\n", &(un.i));
	printf("0x%p\n", &(un.c));
	//下面输出的结果是什么？
	un.i = 0x11223344;
	un.c = 0x55;
	printf("%x\n", un.i);
}


/*
typedef union Test
{
	int a;     //
	double b;  //
	char c;    //
}Test;

void main()
{
	printf("%d\n", sizeof(Test));
}

/*
typedef enum Test
{
	ADD=-100,  //0
	SUB,      //-99
	MUL=200,
	DIV,
	MOD,
}Test;
void main()
{
	Test t;
	t = ADD;
}

/*
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define MOD 5

void main()
{
	printf("Test size = %d\n", sizeof(ADD)); //int
	printf("ADD = %d\n", ADD);
	printf("SUB = %d\n", SUB);
	printf("MUL = %d\n", MUL);
	printf("DIV = %d\n", DIV);
	printf("MOD = %d\n", MOD);
}

/*
typedef enum Test
{
	ADD=-100,  //0
	SUB,      //-99
	MUL=200,
	DIV,
	MOD,
}Test;

void main()
{
	printf("Test size = %d\n", sizeof(Test)); //int
	printf("ADD = %d\n", ADD);
	printf("SUB = %d\n", SUB);
	printf("MUL = %d\n", MUL);
	printf("DIV = %d\n", DIV);
	printf("MOD = %d\n", MOD);
}

/*
//位域的两个限制条件
//1 不能跨字节存储
//2 不能跨类型存储

struct S
{
	char a : 3;
	char b : 4;  //1
	char c : 5;  //1
	char d : 4;  //1
};
void main()
{
	printf("S size = %d\n", sizeof(struct S));

	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
}
/*
struct A
{
	int _a : 2;  //4   0000 0000 0000 000 0000000000 00000 00
	int _b : 5;
	int _c : 10;
	int _d : 30; //4   0000 0000 0000 000 00000000000000000
};
void main()
{
	printf("%d\n", sizeof(struct A)); //1
}

/*
typedef struct Test
{
	char a : 1; // 1 + 3
	int  b : 1; // 4
}Test;

void main()
{
	printf("%d\n", sizeof(Test)); //1
}

/*
typedef struct Test
{
	char a : 2;  //位域  //位段
	char b : 4;
	char c : 3;
}Test;

void main()
{
	printf("%d\n", sizeof(Test));
}

/*
struct S
{
	int data[1000];
	int num;
};

struct S s = { { 1, 2, 3, 4 }, 1000 };
//结构体传参
void print1(struct S s)
{
	printf("%d\n", s.num);
}
//结构体地址传参
void print2(struct S* ps)
{
	printf("%d\n", ps->num);
}

void main()
{
	print1(s);
	print2(&s);
}

/*
//默认情况：默认的对齐值 8字节
//1 基本数据类型有一个对齐值
//2 自定义类型也有一个对齐值=内部成员类型的最大值
//3 程序的指定对齐值：#pragma pack(n) n==2的幂次方
//4 程序的有效对齐值：程序的指定对齐值和数据类型对齐值的较小值

//空间换时间 策略

typedef struct Test
{
	double a;   //8
	short b;    //2
	char c;     //1 + 5
}Test;

void main()
{
	printf("%d\n", sizeof(Test));
}


/*
typedef struct Test   //8 
{
	char a;     //1
	double b;   //8
	int c;      //4
}Test;

void main()
{
	printf("%d\n", sizeof(Test));
}

/*
struct S3
{
	double d;
	char c;
	int i;
};
struct S4
{
	char c1; //1+7
	struct S3 s3;  //16
	double d;//8
};

void main()
{
	printf("%d\n", sizeof(struct S4));
}

/*
typedef struct Test 
{
	double d;
	char c;
	int i;
}Test;

void main()
{
	printf("%d\n", sizeof(Test));
}

/*
typedef struct Test 
{
	short a;       //2 + 6
	struct//类型
	{
		double c[10]; // 80
		int b;     //4
		char d;    //1 + 3
	};  //88
	int e;         //4 + 4 
}Test;

void main()
{
	printf("%d\n", sizeof(Test));
}

/*
#pragma pack(2)
typedef struct Test 
{
	short a;       //2 
	struct//类型
	{
		int b;     //4
		double c;  //8
		char d;    //1+1
	};  //14
	int e;         //4 
}Test;

void main()
{
	printf("%d\n", sizeof(Test));
}

/*
typedef struct Test
{
	short a;       //2 + 6
	struct
	{
		int b;     //4 + 4
		double c;  //8
		char d;    //1 + 7
	};  //24
	int e;         //4 + 4
}Test;

void main()
{
	printf("%d\n", sizeof(Test));
}

/*
//#pragma pack(1)
struct S1
{
	char c1; //1
	char i;  //1
	int c2;  //4
};
void main()
{
	printf("%d\n", sizeof(struct S1));
	struct S1 s;
}


/*
struct S1
{
	char c1; //1 + 3
	int i;   //4
	char c2; //1 + 3
};
void main()
{
	printf("%d\n", sizeof(struct S1));
}

/*
#pragma pack(1)
typedef struct Test  //4
{
	char a;    //1
	short b;   //2
	int c;     //4
}Test;

void main()
{
	printf("Test size = %d\n", sizeof(Test));
}

/*
#pragma pack(4)
typedef struct Test  //4
{
	char a;    //1 + 1
	short b;   //2
	int c;     //4
}Test;

void main()
{
	printf("Test size = %d\n", sizeof(Test));
}

/*
#pragma pack(4)
typedef struct Test   //8 
{
	char a;     //1 + 3
	double b;   //8
	int c;      //4
}Test;

void main()
{
	printf("Test size = %d\n", sizeof(Test));
	Test t;
	t.a = 'A';
	t.b = 12.34;
	t.c = 100;
}

/*
typedef struct Test   //8 
{
	char a;     //1 + 3
	int c;      //4
	double b;   //8
}Test;

void main()
{
	printf("Test size = %d\n", sizeof(Test));
}

/*
typedef struct Test   //8 
{
	char a;     //1 + 7
	double b;   //8
	int c;      //4 + 4
}Test;

void main()
{
	printf("Test size = %d\n", sizeof(Test));
	Test t;
	t.a = 'A';
	t.b = 12.34;
	t.c = 100;
}

/*
typedef struct Test
{
	char a;
	char b;
	char c;
}Test;

void main()
{
	printf("Test size = %d\n", sizeof(Test));
}

/*
typedef struct Test
{
	char a;
	double b;
	int c;
}Test, *PTest;

void main()
{
	Test t = {'A', 12.34, 100}; //定义了结构体的变量
	printf("a = %c, b = %f, c = %d\n", t.a, t.b, t.c);

	PTest pt = &t;
	printf("a = %c, b = %f, c = %d\n", pt->a, pt->b, pt->c);
}

/*
int main()
{
	char str[] = "- This, a sample string.";
	char * pch;

	pch = strtok(str, ",.- ");

	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
	return 0;
}
*/