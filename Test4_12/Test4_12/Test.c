#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//strxxx  \0
//strlen(), strcpy(), strcat(), strcmp()

size_t my_strlen( const char *string )
{
	//判断参数的有效性
	assert(string != NULL);
	size_t count = 0;
	while(*string != '\0')
	{
		count++;
		string++;
	}
	return count;
}
size_t my_strlen_1( const char *string )
{
	//判断参数的有效性
	assert(string != NULL);
	if(*string == '\0')
		return 0;
	else
		return my_strlen_1(string+1) + 1;
}
char *my_strcpy( char *strDestination, const char *strSource )
{
	//判断参数的有效性
	assert(strDestination!=NULL && strSource!=NULL);
	//参数保护
	char *pDest = strDestination;

	while(*strSource != '\0')
	{
		*pDest++ = *strSource++;
	}
	*pDest = '\0';
	return strDestination;
}
char *my_strcat( char *strDestination, const char *strSource )
{
	//判断参数的有效性
	assert(strDestination!=NULL && strSource!=NULL);
	//参数保护
	char *pDest = strDestination;

	while(*pDest != '\0')
		pDest++;

	while(*strSource != '\0')
		*pDest++ = *strSource++;

	*pDest = '\0';
	return strDestination;
}

int my_strcmp( const char *string1, const char *string2 )
{
	assert(string1!=NULL && string2!=NULL);

	while(*string1!='\0' && *string2!='\0')
	{
		if(*string1 > *string2)
			return 1;
		else if(*string1 < *string2)
			return -1;
		string1++;
		string2++;
	}

	if(*string1 != '\0')
		return 1;
	else if(*string2 != '\0')
		return -1;
	return 0;
}

int my_strcmp_1( const char *string1, const char *string2 )
{
	assert(string1!=NULL && string2!=NULL);
	int res = 0;
	while(*string1!='\0' || *string2!='\0')
	{
		//通过减法的方式完成 比较
		if((res = *string1 - *string2) != 0)
			break;
		string1++;
		string2++;
	}
	if(res > 0)
		res = 1;
	else if(res < 0)
		res = -1;
	return res;
}

char *my_strncpy( char *strDest, const char *strSource, size_t count );
char *my_strncat( char *strDest, const char *strSource, size_t count );
int   my_strncmp( const char *string1, const char *string2, size_t count );

void main()
{
	char str1[20] = "HelloBit.";
	char *str2 = "Linux";

	printf("str1 = %s\n", str1);
	char *res = strncpy(str1, str2, 5);  //Lin
	printf("str1 = %s\n", res);
}

/*
void main()
{
	char str1[20] = "HelloBit.";
	char *str2 = "Linux";

	printf("str1 = %s\n", str1);
	char *res = strncat(str1, str2, 3);
	printf("str1 = %s\n", res);
}


void main()
{
	char *str1 = "HealoBit";
	char *str2 = "HelloBit";

	int res = strncmp(str1, str2, 3);
	printf("res = %d\n", res);
}

/*void main()
{
	char *str1 = "HealoBit";
	char *str2 = "HelloBitfafa";

	int res = my_strcmp(str1, str2);
	printf("res = %d\n", res);
}
/*
void main()
{
	char str1[20] = "HelloBit.";
	char *str2 = "Linux";

	printf("str1 = %s\n", str1);
	char *res = my_strcat(str1, str2);
	printf("str1 = %s\n", res);
}

/*
void main()
{
	char str1[20] = "HelloBit.";
	char *str2 = "Linux";

	printf("str1 = %s\n", str1);
	char *res = my_strcpy(str1, str2);
	printf("str1 = %s\n", res);
}

/*
void main()
{
	char *str = "Hello Bit.";
	//char *str = "";   \0
	//char *str = NULL;
	printf("strlen = %d\n", strlen(str));
	printf("my_strlen = %d\n", my_strlen_1(str));
}

/*
//int strcmp( const char *string1, const char *string2 );
void main()
{
	char str1[] = "hello";
	char *str2 = "helloabc";

	//if(str1 == str2);

	int res = strcmp(str1, str2); // str1>str:1 str1=str2:0 str1<str2:-1
	printf("res = %d\n", res);
}

/*
//char *strcat( char *strDestination, const char *strSource );
void main()
{
	char str1[20] = "Hello ";  //Bit.
	char *str2 = "Bit.";

	printf("str1 = %s\n", str1);
	strcat(str1, str2);  //连同\0一起链接
	printf("str1 = %s\n", str1);
}

/*
//char *strcpy( char *strDestination, const char *strSource );
void main()
{
	char *str1 = "HelloLinux";  //字符串常量
	char *str2 = "Bit.";

	printf("str1 = %s\n", str1);
	strcpy(str1, str2);  //连同\0一起拷贝
	printf("str1 = %s\n", str1);
}

/*
void main()
{
	char str1[20] = "HelloLinux";
	char *str2 = "Bit.";

	printf("str1 = %s\n", str1);
	strcpy(str1, str2);  //连同\0一起拷贝
	printf("str1 = %s\n", str1);
}

/*
int main()
{
	const char*str1 = "abcdef";
	const char*str2 = "bbb";

	printf("str2 len = %d\n", strlen(str2));
	printf("str1 len = %d\n", strlen(str1));

	//size_t strlen( const char *string );

	if (strlen(str2) - strlen(str1) > 0)
	{
		printf("str2>str1\n");
	}
	else
	{
		printf("srt1>str2\n");
	}
	return 0;
}

/*
void main()
{
	size_t sz = 0;
	unsigned ing sz1 = 0;  //
}

/*
void main()
{
	char *str = "Hello";
	printf("str len = %d\n", strlen(str));   //长度
	printf("str size = %d\n", sizeof(str));  //大小

	//strlen(str[0]);
}

/*
void main()
{
	char str[] = "Hello";
	printf("str len = %d\n", strlen(str));   //长度
	printf("str size = %d\n", sizeof(str));  //大小

	char str1[10] = "Hello";
	printf("str1 len = %d\n", strlen(str1));   //长度
	printf("str1 size = %d\n", sizeof(str1));  //大小

	char str2[10] = {'H','e','l','l','o'};
	printf("str2 len = %d\n", strlen(str2));   //长度 
	printf("str2 size = %d\n", sizeof(str2));  //大小

	char str3[] = {'H','e','l','l','o'};
	printf("str3 len = %d\n", strlen(str3));   //长度 
	printf("str3 size = %d\n", sizeof(str3));  //大小
}

/*
int main()
{
	int a[4] = { 1, 2, 3, 4 };

	int *ptr1 = (int *)(&a + 1);

	int *ptr2 = (int *)((int)a + 1);

	printf("%x,%x\n", ptr1[-1], *ptr2);

	return 0;
}

/*
int main(int argc, char * argv[])
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };  //逗号表达式
	//int a[3][2] = { 1, 3, 5 }; 
	//int a[3][2] = {{0,1}, {2,3}, {4,5}};
	int *p;
	p = a[0];
	printf("%d", p[0]);
}


/*
int int_cmp(const void * p1, const void * p2)
{
	return (*(int *)p1 - *(int *)p2);  // >0 =0 <0
}

void _swap(void *p1, void * p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}
void bubble(void *base, int count, int size, int(*cmp)(void *, void *))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j<count - i - 1; j++)
		{
			//  cmp(a,b){return a - b;}
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) > 0)
			{
				_swap((char *)base + j*size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}

void PrintArray(int ar[], int n)
{
	for(int i=0; i<n; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}

void main()
{
	int ar[] = {3,5,7,8,100,2,9,103,10,7,4,1,23,12,56,73,45};
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintArray(ar, n);
	//BubbleSort(ar, n);
	//qsort(ar, n, sizeof(ar[0]), compare); //回调函数
	bubble(ar, n, sizeof(int), int_cmp);
	PrintArray(ar, n);
}


/*
//冒泡排序
void BubbleSort(int ar[], int n)
{
	for(int i=0; i<n-1; ++i)
	{
		for(int j=0; j<n-i-1; ++j)
		{
			if(ar[j] > ar[j+1])
			{
				int tmp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = tmp;
			}
		}
	}
}


int compare (const void *elem1, const void *elem2)
{
	//return (*(int*)elem1 - *(int *)elem2);  // >0 <0  ==0
	return (*(int*)elem2 - *(int *)elem1);
}

void main()
{
	int ar[] = {3,5,7,8,100,2,9,103,10,7,4,1,23,12,56,73,45};
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintArray(ar, n);
	//BubbleSort(ar, n);
	qsort(ar, n, sizeof(ar[0]), compare); //回调函数
	PrintArray(ar, n);
}

/*
int Max(int a, int b)
{
	return a > b ? a : b;
}
int Min(int a, int b)
{
	return a > b ? b : a;
}

/////////////////////////////////////////////////////////
//通用函数
//回调函数  回过头来调用的函数
int fun(int a, int b, int(*pfun)(int,int) )
{
	//return (*pfun)(a,b);
	return pfun(a,b);
}

void main()
{
	int a = 10;
	int b = 20;

	int res = fun(a, b, Min);
	printf("res = %d\n", res);

}

/*
int fun(int a, int b)
{
	return a + b;
}

//argc = argument count  参数个数
//argv = argument value  参数值

// 0   1 2
//Add 10 20

int main(int argc, char *argv[])
{
	int res = fun(atoi(argv[1]), atoi(argv[2]));
	printf("%d + %d = %d\n",atoi(argv[1]),atoi(argv[2]),res);
	return 0;
}

/*
int main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);
	for(int i=0; i<argc; ++i)
	{
		printf("%s\n", argv[i]);
	}
	return 0;
}

/*
int fun(int a, int b)
{
	return a + b;
}

//argc = argument count  参数个数
//argv = argument value  参数值

int main(int argc, char *argv[])
{
	int a, b;
	printf("input a and b:>");
	scanf("%d %d", &a, &b);
	int res = fun(a, b);
	printf("%d + %d = %d\n",a,b,res);
	return 0;
}

/*
//ADD

int fun(int a, int b)
{
	return a + b;
}

int main(int argc, char *argv[])
{
	int a, b;
	printf("input a and b:>");
	scanf("%d %d", &a, &b);
	int res = fun(a, b);
	printf("%d + %d = %d\n",a,b,res);
	return 0;
}

/*
void (*signal(int, void(*)(int)))(int)    ;


void main()
{
	void(*pfun)();

	0;

	(*(void(*)())0)();

}

/*
void main()
{
	int a = 10;
	double b = 12.34;

	a = b;       //隐示转换
	a = (int)b;  //显示转换


	(int)b;

}

/*
//代码1
(*(void (*)())0)();

//代码2
void (*signal(int , void(*)(int)))(int);

/*
int (*func)(int *, int (*)(int *));
//
int (*func[5])(int *);
//
int (*(*func)[5])(int *);
//
int (*(*func)(int *)) [5];
//
int*(*func(int*))[5];

/*
void main()
{
	int(*a)();      //指针->函数

	int(*a[10])();  //数组用来保存了函数指针 -->转义表
}
*/