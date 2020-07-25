#include<iostream>
#include<assert.h>
#include<bitset>
using namespace std;

#define ID_LEN   32
struct STR_A
{
	char aucID[ID_LEN];
	int iA;
};
struct STR_B
{
	char *paucID;
	int iB;
};
void funcA(struct STR_A stA, struct STR_B *pstB)
{
	pstB->paucID = stA.aucID;
}
void main()
{
	STR_A stA = { 0 };
	STR_B stB;

	strcpy(stA.aucID, "12345");
	funcA(stA, &stB);
	printf("%s\n", stB.paucID);
}


/*
void AddFunc(unsigned int a, unsigned int b, unsigned int *c)
{
	*c = a + b; //*c = 200+100
}
void main()
{
	unsigned char e = 200;
	unsigned char f = 100;
	unsigned char g = 0;
	AddFunc((unsigned int)e, (unsigned int)f, (unsigned int*)&g);
	printf("%d", g);
}


/*
void VarInit(unsigned char *pucArg)
{
	*(unsigned long*)pucArg = 1;
	return;
}
void main()
{
	unsigned long ulGlobal;
	VarInit((unsigned char*)&ulGlobal);
	printf("%lu", ulGlobal);
	return;
}


/*
char* GetStr(char **p)
{
	*p = "hello world";
	return *p;
}
void main()
{
	char *str = NULL;
	if (NULL != GetStr(&str))
	{
		printf("\r\n str = %s", str);
	}
	return;
}


/*
#define BUFFER_SIZE 256
void GetMemory(char **ppszBuf)
{
	if (NULL == ppszBuf)
	{
		assert(0);
		return;
	}
	*ppszBuf = (char *)malloc(BUFFER_SIZE);
	return;
}
void main()
{
	char *pszBuf = NULL;
	GetMemory(&pszBuf);
	strcpy(pszBuf, "hello world\r\n");
	printf("%s", pszBuf);
	free(pszBuf);
	return;
}


/*
#pragma pack(4)
int main()
{
	unsigned char puc[4];
	struct tagPIM
	{
		unsigned char ucPim1;
		unsigned char ucData0 : 1;
		unsigned char ucData1 : 2;
		unsigned char ucData2 : 3;
	}*pstPimData;

	pstPimData = (struct tagPIM*)puc;

	memset(puc, 0, 4);
	pstPimData->ucPim1 = 2;
	pstPimData->ucData0 = 3;
	pstPimData->ucData1 = 4;
	pstPimData->ucData2 = 5;

	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}
#pragma pack() /*恢复缺省对齐方式*/


/*
unsigned long FUNC_C(unsigned long ulAction)
{
	unsigned long ulResult = 0;
	switch (ulAction)
	{
	case 1:
	{
					 ulResult += 1;
					 break;
	}
	case 2:
	{
					 ulResult += 1;
	}
	default:
	{
			   ulResult += 1;
	}
	}
	printf("ulResult = %u", ulResult);
	return ulResult;
}
void main()
{
	FUNC_C(2);
}


/*
//#pragma pack(1)
#pragma pack(4)
union tagAAAA
{
	struct
	{
		char ucFirst;  //1 + 1
		short usSecond;//2
		char ucThird;  //1 + 1
	}half;

	short kk; //2
}number;

struct tagBBBB
{
	char ucFirst;  //1+1
	short usSecond;//2
	char ucThird;  //1+1
	short usForth; //2
}half;

struct tagCCCC
{
	struct
	{
		char ucFirst;  //1+1
		short usSecond;//2
		char ucThird;  //1+1
	}half;
	long kk;           //4
};

void main()
{
	cout<<sizeof(union tagAAAA)<<endl;
	cout<<sizeof(struct tagBBBB)<<endl;
	cout<<sizeof(struct tagCCCC)<<endl;
}


/*
int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
void main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d\n", k);
	k = fun(j, m);
	printf("%d\n", k);
	return;
}


/*
#pragma pack(2)
struct tagAAA
{
	unsigned char ucld : 1;
	unsigned char ucPara0 : 2; //1
	unsigned char ucState : 6; //1
	unsigned char ucTail : 4;  //1
	double ucAvail;     //8
	unsigned char ucTail2 : 4; //1
	unsigned char ucData;      //1
}AAA_S;

void main()
{
	cout<<sizeof(AAA_S)<<endl;
}

/*
#define CHAR char
#define ULONG unsigned long
#define VOID void

CHAR *VOS_strncpy(CHAR *pcDest, const CHAR *szSrc, ULONG ulLength)
{
	CHAR *pcPoint = pcDest;
	if ((NULL == szSrc) || (NULL == pcDest))
	{
		return NULL;
	}
	while (ulLength && (*pcPoint = *szSrc))
	{
		pcPoint++;
		szSrc++;
		ulLength--;
	}
	if (!ulLength)
	{
		*pcPoint = '\0';
	}
	return pcDest;
}
VOID main(VOID)
{
	CHAR szStrBuf[]  = "1234567890";
	CHAR szStrBuf1[] = "1234567890";
	strncpy(szStrBuf, "ABC", strlen("ABC"));     //ABC4567890
	VOS_strncpy(szStrBuf1, "ABC", strlen("ABC"));//ABC
	printf("Str1 = %s\nStr2 = %s", szStrBuf, szStrBuf1);
}


/*
unsigned short *pucCharArray[10][10];
   typedef union unRec
	{
		unsigned long ullndex;
		unsigned short usLevel[7];
		unsigned char ucPos;
}REC_S;
REC_S stMax, *pstMax;

void main()
{
	cout<<sizeof(pucCharArray)<<endl;
	cout<<sizeof(stMax)<<endl;
    cout<<sizeof(pstMax)<<endl;
	cout<<sizeof(*pstMax)<<endl;
}



/*
unsigned short *sum(unsigned char a, unsigned char b)
{
	static unsigned short s = 0;
	s = a + b;
	return &s;
}
int main()
{
	unsigned short *p = NULL;
	unsigned char a = 1, b = 2;
	p = sum(a, b);
	printf("%u + %u", a, b);
	printf(" = %u\n", *p); //1 + 2 = 
	return 0;
}


/*
int main()
{
	//char ch = 128;
	char c;  //-128 ~ 127
	unsigned char uc; //0 ~ 255
	unsigned short us;//0 ~ 65535
	c = 128;   //-128
	uc = 128;

	us = c + uc;
	printf("0x%x\n", us);    //0x0

	us = (unsigned char)c + uc;
	printf("0x%x\n", us);   //0x100

	// -128    -128
	us = c + (char)uc;  //-256
	printf("0x%x\n", us);   //0xff00
	return 0;
}

/*
void main()
{
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;   // 0 ~ 255
	c = a + b;
	printf("%d %d", a + b, c);
}


/*
void main()
{
	union
	{
		short k;
		char i[2];
	}*s, a;
	s = &a;

	s->i[0] = 0x39;
	s->i[1] = 0x38;
	printf("%x\n", a.k);
}


/*
int g_fun = 0; //全局变量

void main()
{
	unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
	unsigned long *pulPtr;
	
	pulPtr = pulArray;
	*(pulPtr + 3) += 3;
	printf("%d, %d\n", *pulPtr, *(pulPtr + 3));

}

/*
void main()
{
	int a = 10;

	{
		int b = a;
		cout<<"b = "<<b<<endl;
	}

	cout<<"b = "<<b<<endl;
}

/*
void RightLoopMove(char *pStr, unsigned short steps)
{
	assert(pStr != NULL);
	int len = strlen(pStr);
	steps %= len;

	for(size_t i=0; i<steps; ++i)   //O(n) -> O(n^2)  //控制移动的步长次数
	{
		char tmp = pStr[len-1];
		for(size_t j=len-1; j>0; --j)  //循环往后移动字符
			pStr[j] = pStr[j-1];
		pStr[0] = tmp;
	}
}

void main()
{
	char str[] = "abcdefghi"; //1亿
	cout<<"str = "<<str<<endl;
	RightLoopMove(str, 5);
	cout<<"str = "<<str<<endl;
}


/*
void RightLoopMove(char *pStr, unsigned short steps)
{
	assert(pStr != NULL);
	int len = strlen(pStr);
	char *tmp = (char*)malloc(sizeof(char) * (len+1));  //O(n)
	assert(tmp != NULL);

	steps %= len; //重要条件

	strcpy(tmp, pStr+(len-steps));
	strncat(tmp, pStr, len-steps);
	tmp[len] = '\0';
	strcpy(pStr, tmp);

	free(tmp);
	tmp = NULL; //留下一个好印象
}

void main()
{
	char str[] = "abcdefghi";
	cout<<"str = "<<str<<endl;
	RightLoopMove(str, 20);
	cout<<"str = "<<str<<endl;
}

/*
void bit_set(unsigned char *p_data, unsigned char position, bool flag)
{
	assert(p_data!=NULL && position<=8);
	if(flag)
		*p_data |= (0x01<<(position-1));
	else
		*p_data &= ~(0x01<<(position-1));
}

//0000 0000

void main()
{
	unsigned char data = 123;  //0111 1011
	bitset<8> bt1((int)data);
	cout<<"bt1 = "<<bt1<<endl;
	bit_set(&data, 4, false);
	//cout<<(int)data<<endl;     //0111 1111
	bitset<8> bt2((int)data);
	cout<<"bt2 = "<<bt2<<endl;
}

/*
void bit_set(unsigned char *p_data, unsigned char position, bool flag)
{
	assert(p_data!=NULL && position<=8);
	if(flag)
	{
		switch(position)
		{
		case 1:
			*p_data |= 0x01;  //0000 0001
			break;
		case 2:
			*p_data |= 0x02;  //0000 0010
			break;
		case 3:
			*p_data |= 0x04;  //0000 0100
			break;
		case 4:
			*p_data |= 0x08;  //0000 1000
			break;
		case 5:
			*p_data |= 0x10;  //0001 0000
			break;
		case 6:
			*p_data |= 0x20;  //0010 0000
			break;
		case 7:
			*p_data |= 0x40;  //0100 0000
			break;
		case 8:
			*p_data |= 0x80;  //1000 0000
			break;
		}
	}
	else
	{
		switch(position)
		{
		case 1:
			*p_data &= ~0x01;  //1111 1110
			break;
		case 2:
			*p_data &= ~0x02;  //0000 0010
			break;
		case 3:
			*p_data &= ~0x04;  //0000 0100
			break;
		case 4:
			*p_data &= ~0x08;  //0000 1000
			break;
		case 5:
			*p_data &= ~0x10;  //0001 0000
			break;
		case 6:
			*p_data &= ~0x20;  //0010 0000
			break;
		case 7:
			*p_data &= ~0x40;  //0100 0000
			break;
		case 8:
			*p_data &= ~0x80;  //1000 0000
			break;
		}
	}
}

//0000 0000

void main()
{
	unsigned char data = 123;  //0111 1011
	bitset<8> bt1((int)data);
	cout<<"bt1 = "<<bt1<<endl;
	bit_set(&data, 4, false);
	//cout<<(int)data<<endl;     //0111 1111
	bitset<8> bt2((int)data);
	cout<<"bt2 = "<<bt2<<endl;
}

/*
//释放空间
//释放指针

void main()
{
	char *str = (char *)malloc(57);
	strcpy(str, "Bit");
	free(str);
	str = NULL;

	//free(str);  str==NULL  野指针

	if (str != NULL)
	{
		strcpy(str, "C++");
		printf(str);
	}
}


/*
void GetMemory(char **p)
{
	*p = (char *)malloc(57);
}
void main()
{
	char *str = NULL;
	GetMemory(&str);
	strcpy(str, "Hello Bit.");
	printf(str);
	free(str); //内存泄漏
}


/*
char* GetMemory(void)
{
	static char p[] =  "Hello Bit.";
	return p;
}
void main()
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}


/*
void GetMemory(char **p)
{
	*p = (char*)malloc(57);
}
void main()
{
	char *str = NULL;
	GetMemory(&str);
	strcpy(str, "Hello Bit.");
	printf(str);
	free(str);
}


/*
int func(int a[])
{
	cout<<sizeof(a)<<endl;
	return 0;
}

void main()
{
	char str[] = "Welcome to Bit";
	int Array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char *p = str;
	int  n;
	
	cout<<strlen(str)<<endl; //14
	cout<<sizeof(str)<<endl; //15
	cout<<sizeof(Array)<<endl; //36
	cout<<sizeof(p)<<endl;  //4
	cout<<sizeof(n)<<endl; //4
	func(Array);  //4
}


/*
void fun(int ar[10][10])
{
	cout<<sizeof(ar)<<endl; //
}

void main()
{
	int ar[10][10] = {0};
	fun(ar);
}

/*
void main()
{
	short *ar[10][10] = {0};
	cout<<sizeof(ar)<<endl; //4 200 400
}

/*
void main()
{
	char *str = "Hello";
	cout<<sizeof(str)<<endl; //4
	cout<<strlen(str)<<endl; //5

	char str1[] = "Hello";
	cout<<sizeof(str1)<<endl; //6
	cout<<strlen(str1)<<endl; //5

	char str3[10] = "Hello";
	cout<<sizeof(str3)<<endl; //10
	cout<<strlen(str3)<<endl; //5

	char str4[10];
	for(int i=0; i<5; ++i)
		str4[i] = 'a' + i;
	cout<<sizeof(str4)<<endl; //10
	cout<<strlen(str4)<<endl; //
}

/*
int fun(int a, int b)
{
	return a + b;
}

int* fun1(int ar[], int n)  //fun1是一个返回指针的函数  指针函数
{
	for(int i=0; i<n; ++i)
		ar[i] = i+1; //1 2 ...n
	return ar;
}

int main(int argc, char *argv[])
{
	int ar[3] = {10,20,30};
	int (*pa)[3] = &ar;  //pa 是指向数组的指针   数组指针

	int a=10, b=20, c=30;
	int* pb[3] = {&a, &b, &c}; //pb 是保存指针的数组  指针数组

	int(*pfun)(int,int); //pfun 是一个指向函数的指针  函数指针
	pfun = fun;
	cout<<pfun(10,20)<<endl;

	return 0;
}
*/