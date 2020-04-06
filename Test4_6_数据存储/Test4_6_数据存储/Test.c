#include<stdio.h>
#include<stdbool.h>

void main()
{
	float f = 12.125;
}

/*
unsigned char i = 0;
int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}

/*
int main()
{
	char a[1000];  //字符串
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));  // \0
	return 0;
}


/*
void main()
{
	char *pc = "He\0llo C"; //字符串
	printf("len = %d\n", strlen(pc));
}

/*
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	return 0;
}

/*
void main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);  //9 8 7 6 5 4 3 2 1
	}
}



/*
void main()
{
	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);  //
}

/*
int main()
{
	char a = 128;  //-128 ~ 127  -128
	printf("%u\n", a);
	return 0;
}

/*
int main()
{
	char a = -128;
	printf("%u\n", a);
	//1000 0000 0000 0000 0000 0000 1000 0000  原码
	//1111 1111 1111 1111 1111 1111 0111 1111  反码 + 1
	//1111 1111 1111 1111 1111 1111 1000 0000  补码
	return 0;
}

/*
int main()
{
	char a = -1;
	signed char b = -1;

	unsigned char c = -1;  //1111 1111

	printf("a=%d,b=%d,c=%d", a, b, c);
	        //-1   -1
	return 0;
}

/*
bool CheckModel()
{
	int i = 1;  //int i = 00 00 00 01;
	return  (*(char*)&i) == 1;   //
}

void main()
{
	bool flag = CheckModel();
	if(flag)
		printf("This is Litter.\n");
	else
		printf("This is Big.\n");
}

/*
void main()
{
	int a = 123456789;
}

/*
void main()
{
	int a = -1;

	printf("a = %d\n", a);
	printf("a = %u\n", a);
}

/*
void main()
{
	char ch;
	int i;
	//无类型
	//void v;  //sizeof(void) 
	//int *p = NULL;

	void *pv;  //4
}


void main()
{
	unsigned char ch = 255+1;  //0 ~ 255
	printf("ch = %d\n", ch);
}

/*
void main()
{
	char ch = -128-1;  //-128 ~ 127 
	printf("ch = %d\n", ch);
}

/*
void main()
{
	//0 ~ 255
	for(unsigned char i = 0; i<256; ++i) //
	{
		printf("Hello C.\n");   //?
	}
}

/*
void main()
{
	//有符号的字符类型
	char ch1 = 150;

	//无符号的字符类型
	unsigned char ch3 = 150;
}

//人看
void main()
{
	int a = -10;
	printf("a = %d\n", a);
}

/*
void main()
{
	//有符号的字符类型
	char ch1;
	signed char ch2;  

	//无符号的字符类型
	unsigned char ch3;
}

/*
//类型的作用主要用于定义变量
void main()
{
	char ch; //ch 1
	int a; //开辟空间 //4
	double d; //8
}

/*
int main()
{
	printf("%d\n", sizeof(bool));      //1
	printf("%d\n", sizeof(char));      //1
	printf("%d\n", sizeof(short));     //2
	printf("%d\n", sizeof(int));       //4
	printf("%d\n", sizeof(float));     //4
	printf("%d\n", sizeof(long));      //4
	printf("%d\n", sizeof(double));    //8
	printf("%d\n", sizeof(long long)); //8
	return 0;
}
*/