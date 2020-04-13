#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<assert.h>

struct Test
{
	char a;   //1
	double b; //8
	int c;    //4
};

void main()
{
	int a = 10;
	printf("a size = %d\n" ,sizeof(a));
	char ch = 'A';
	printf("ch size = %d\n" ,sizeof(ch));
	double d = 10.12;
	printf("d size = %d\n" ,sizeof(d));

	struct Test t;
	printf("t size = %d\n" ,sizeof(t));
}

/*
struct Date
{
	int year;
	int month;
	int day;
};
struct Time
{
	int hour;
	int minute;
	int second;
};
struct Birthday
{
	struct Date date;
	struct Time time;
};

struct Person
{
	char name[10];
	int age;
	struct Birthday bday;
};

void main()
{
	struct Person p;
	strcpy(p.name, "张三");
	p.age = 20;
}

/*
typedef struct Node
{
	int data;
	struct Node *next; //4
}Node;

void main()
{
	Node *pnode = NULL;
}

/*
struct Node
{
	int data;
	struct Node *next; //4
	char val;
};

void main()
{

}

/*
struct
{
	char a;
	int b;
}x;

struct 
{
	char a;
	int b;
}*p;

void main()
{
	p = &x;
}

/*
struct Test
{
	char a;
	double b;
	int c;
}k,m,n;

struct
{
	char a;
	double b;
	int c;
}x,y,z;

void main()
{
	struct Test a, b, c;
	a.c = 1;
	b.c = 2;
	c.c = 3;

	x.c = 4;
	y.c = 5;
	z.c = 6;
}


/*
typedef struct Test
{
	char a;
	double b;
	int c;
}Test;

#define ULONG unsigned long 
typedef unsigned long  u_long;

void main()
{
	unsigned long x = 100;
	ULONG y = 200;
	u_long z = 300;

	Test t;   //struct Test t;
	t.a = 'A';
	t.b = 12.34;
	t.c = 100;
}

/*
//
struct Student
{
	char id[19];
	char name[11];
	float height;
	float weight;
	int   age;
};

void PrintStuInfoByVal(struct Student s)
{
	printf("size = %d\n", sizeof(s));
	printf("%-20s%-10s%-10s%-12s%-3s\n","id","name","height","weight","age");
	printf("%-20s%-10s%-10f%-12f%-3d\n", s.id, s.name, s.height, s.weight, s.age);
}

void PrintStuInfoByPonint(struct Student *ps)
{
	printf("size = %d\n", sizeof(ps));
	printf("%-20s%-10s%-10s%-12s%-3s\n","id","name","height","weight","age");
	//printf("%-20s%-10s%-10f%-12f%-3d\n", (*ps).id, (*ps).name, (*ps).height, (*ps).weight, (*ps).age);
	printf("%-20s%-10s%-10f%-12f%-3d\n", ps->id, ps->name, ps->height, ps->weight, ps->age);
}

void main()
{
	struct Student stu = {"610110200004137612","张三", 60.5, 175.0, 22}; //结构体变量
	PrintStuInfoByVal(stu);
	PrintStuInfoByPonint(&stu);

	stu.id;

	struct Student *ps = &stu;
	ps->id;
}

/*

void main()
{
	char ch[] = "a";
	printf("ch size = %d\n", sizeof(ch));

	char ch1[] = "男";
	printf("ch1 size = %d\n", sizeof(ch1));
}



/*
void main()
{
	char ch;
	int a;   //单一变量

	// 复合变量  数组
	//int a1, a2, a3, a4 ......a10;  a10000
	int ar[10]; // 10 int
}

/*
void *my_memset( void *dest, int c, size_t count )
{
	assert(dest != NULL);
	char *pdest = (char*)dest;
	while(count-- != 0)
	{
		*pdest++ = c;
	}
	return dest;
}
int my_memcmp( const void *buf1, const void *buf2, size_t count )
{
	assert(buf1!=NULL && buf2!=NULL);
	const char *pbuf1 = (char*)buf1;
	const char *pbuf2 = (char*)buf2;

	int res = 0;
	while(count-- != 0)
	{
		if((res = *pbuf1-*pbuf2) != 0)
			break;
		pbuf1++;
		pbuf2++;
	}
	if(res > 0)
		res = 1;
	else if(res < 0)
		res = -1;
	return res;
}
//考虑内存覆盖的情形
void *my_memcpy( void *dest, const void *src, size_t count )
{
	assert(dest!=NULL && src!=NULL);
	char *pdest = (char*)dest;
	const char *psrc = (char*)src;

	//1 无覆盖
	if(psrc >= pdest || pdest >= psrc+count)
	{
		while (count-- != 0)
		{
			*pdest++ = *psrc++;
		}
	}
	//2 有覆盖
	else
	{
		pdest = pdest + count - 1;
		psrc = psrc + count - 1;
		while(count-- != 0)
		{
			*pdest-- = *psrc--;
		}
	}
	return dest;
}

void *my_memmove( void *dest, const void *src, size_t count )
{
	assert(dest!=NULL && src!=NULL);
	char *pdest = (char*)dest;
	const char *psrc = (char*)src;

	//1 无覆盖
	if(psrc >= pdest || pdest >= psrc+count)
	{
		while (count-- != 0)
		{
			*pdest++ = *psrc++;
		}
	}
	//2 有覆盖
	else
	{
		pdest = pdest + count - 1;
		psrc = psrc + count - 1;
		while(count-- != 0)
		{
			*pdest-- = *psrc--;
		}
	}
	return dest;
}

void main()
{
	char dest[20] = "abcdefghijkl";

	printf("dest = %s\n", dest);
	my_memcpy(dest+2, dest, 4);
	//memcpy(dest+2, dest, 4);
	//memmove(dest+2, dest, 4); //内存覆盖的情形
	printf("dest = %s\n", dest);
}

/*
void main()
{
	char dest[20] = "abcdefghijkl";
	char src[] = "xyz";

	printf("dest = %s\n", dest);
	memcpy(dest, src, 4);
	printf("dest = %s\n", dest);
}

/*
void main()
{
	int ar1[] = {1,2,3,4,50,6,7,8};
	int ar2[] = {1,2,3,4,60,8,9,0};

	int res2 = my_memcmp(ar1, ar2, sizeof(int)*5);
	printf("res = %d\n",res2);
}

/*
void main()
{
	char buffer[10];
	my_memset(buffer, 0, sizeof(char)*10);
}

/*
void main()
{
	char dest[20] = "abcdefghijkl";
	char src[] = "xyz";

	printf("dest = %s\n", dest);
	memmove(dest, src, 3);
	//memcpy();
	printf("dest = %s\n", dest);
}

/*
void main()
{
	int ar[10];
	int br[10] = {1,2,3,4,5,6,7,8,9,10};
	memcpy(ar, br, sizeof(int)*10);
}

/*
void main()
{
	char dest[20] = "abcdefghijkl";
	char *src = "xyz";

	printf("dest = %s\n", dest);
	//strcpy();
	memcpy(dest, src, 4);
	printf("dest = %s\n", dest);
}

/*
void main()
{
	int ar1[] = {1,2,3,4,50,6,7,8};
	int ar2[] = {1,2,3,4,6,8,9,0};

	int res2 = memcmp(ar1, ar2, sizeof(int)*5);
	printf("res = %d\n",res2);
}


/*
#define BUFFER_SIZE 256

void main()
{
	char *str1 = "Hello";
	char *str2 = "Hello";

	int ar1[] = {1,2,3,4,50,6,7,8};
	int ar2[] = {1,2,3,4,6,8,9,0};

	int res = strcmp(str1, str2);  //string 
	int res1 = memcmp(str1, str2, 5);

	//int res2 = strcmp(ar1, ar2);
	int res2 = memcmp(ar1, ar2, sizeof(int)*8);
}

/*
void main()
{
	char str[BUFFER_SIZE];
	memset(str, 0, sizeof(char)*BUFFER_SIZE);

	int ar[10];
	memset(ar, 0, sizeof(int)*10);

}

/*
void MyToLower1(char *str)
{
	assert(str != NULL);
	for(int i=0; i<strlen(str); ++i)
	{
		if(str[i]>='a' && str[i]<='z')
			str[i] -= 32;
	}
}

void MyToLower2(char *str)
{
	assert(str != NULL);
	while(*str != '\0')
	{
		if(islower(*str))
			*str = toupper(*str);
		str++;
	}
}

void main()
{
	char str[] = "This is Test string.";
	//MyToLower1(str);
	MyToLower2(str);
	printf("str = %s\n", str);
}

/*
void main()
{
	FILE *fp = fopen("Test.txt", "r"); //Test.txt
	if(fp == NULL)
	{
		printf("Open Test.txt Error :%s.\n", strerror(errno));  //errno 系统定义的 全局变量
		//printf("Open Test.txt Error :%d.\n", errno);
		return;
	}
	else
		printf("Open Test.txt Successfully.\n");

}

/*
int main()
{
	char *p = "zhangpengwei@bitedu.tech";   //1234567@qq.com   xxxxx@163.com   xxxxx@126.com
	const char* sep = ".@";
	char arr[30];
	char *str = NULL;
	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
}

/*
int main()
{
	char str[] = "- This, a sample string.";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n", str);

	pch = strtok(str, " ,.-");

	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
	return 0;
}

/*
int main()
{
	char str[] = "This is a simple string";
	char * pch;
	pch = strstr(str, "smple");
	strncpy(pch, "sample", 6);
	puts(str);
	return 0;
}

/*
void main()
{
	char *Dest = "xyzabc xyz lmn jkl xyz hji";
	char *Src = "xyz";

	char *res = strstr(Dest, Src);
	printf("res = %s\n", res);
}

/*
char str[] =    "lazy";
char string[] = "The quick brown dog jumps over the lazy fox";
char fmt1[] =   "         1         2         3         4         5";
char fmt2[] =   "12345678901234567890123456789012345678901234567890";

void main( void )
{
   char *pdest;
   int  result;
   printf( "String to be searched:\n\t%s\n", string );
   printf( "\t%s\n\t%s\n\n", fmt1, fmt2 );

   pdest = strstr( string, str );
   result = pdest - string + 1;
   if( pdest != NULL )
      printf( "%s found at position %d\n\n", str, result );
   else
      printf( "%s not found\n", str );
}
*/
