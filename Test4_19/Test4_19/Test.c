#include<stdio.h>
#include<assert.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>

#include"head1.h"   //""  <> 引用的路劲不一样
#include"head2.h"
#include"head1.h"   //""  <> 引用的路劲不一样
#include"head2.h"
#include"head1.h"   //""  <> 引用的路劲不一样
#include"head2.h"

void main()
{
	int x = 50;
	int y = 8;
	printf("Max Value = %d\n", Max(x, y));
	printf("Min Value = %d\n", Min(x, y));
}

/*
void fun1()
{
	printf("This is fun1().\n");
}

void fun2()
{
	printf("This is fun2().\n");
}

void fun3()
{
	printf("This is fun3().\n");
}
//#define FUN1
#define FUN2

void main()
{
#ifdef FUN1
	fun1();
#elif defined(FUN2)
	fun2();
#else
	fun3();
#endif
}

/*
//开关宏
#define DISPLAY  

void main(int argc, char *argv[])
{
#undef DISPLAY

#ifdef DISPLAY
	printf("This is Test.\n");
#endif
}

/*
void main()
{
	int a = 10;
	assert(a != 0);  //??????
}

/*
#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

int MAX1(int a, int b)
{
	return a > b ? a : b;
}

void main()
{
	int x = 50;
	int y = 8;
	int z = MAX(x++, y++);  // ((5++) > (8++) ? (5++) : (8++));
	
	printf("x=%d y=%d z=%d\n", x, y, z);  //答案不固定
}


/*
//#用于去宏参数的真实值
//##用于宏连接
//续行符

#define BIT_STRUCT(name) \
struct Bit_##name\
{\
	int a;\
	char b;\
	char name[10];\
}
BIT_STRUCT(sgq);   //Bit_sgq
BIT_STRUCT(zjn);   //Bit_zjn
void main()
{
}

/*
#define PRINT(x) printf(#x "*" #x "= %d\n",x*x)

void main()
{
	PRINT(9);
}

/*
//心急吃不了热豆腐
#define ADD(a, b)  ((a)+(b))
#define MUL(a, b)  ((a)*(b))

void main()
{
	printf("add = %d\n", ADD(2,3));
	printf("mul = %d\n", MUL(2+3,3+4)); //MUL(2+3,3+4)   2+3 * 3+4

	printf("res = %d\n", ADD(2,3) * ADD(4,5)); //(2)+(3) * (4)+(5)
}

/*
#define LOG_ERROR(msg) printf("[ERROR]:%s: %d lines : %s\n", __FILE__, __LINE__, msg)
#define LOG_TRACE(msg) printf("[TRACE]:%s: %d lines : %s\n", __FILE__, __LINE__, msg)
#define LOG_DEBUG(msg) printf("[DEBUG]:%s: %d lines : %s\n", __FILE__, __LINE__, msg)

void main()
{
	FILE *fp = fopen("Test10.txt", "rb");  
	if(NULL == fp)
	{
		LOG_ERROR("Open File Error.");
		return;
	}
	else
		LOG_TRACE("Open File Successfully.")

	fclose(fp);
}

/*
void main()
{
	printf("file = %s\n", __FILE__);
	printf("line = %d\n", __LINE__);
	printf("date = %s\n", __DATE__);
	printf("time = %s\n", __TIME__);
}

/*
void main()
{
	printf("Hello Bit.\n");
}

/*
int main(void)
{
	double a[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double b = 0.0;
	size_t ret_code = 0;
	FILE *fp = fopen("Test5.txt", "wb"); // 必须用二进制模式
	fwrite(a, sizeof(*a), 5, fp); // 写 double 的数组
	fclose(fp);

	fp = fopen("Test5.txt", "rb");
	while ((ret_code = fread(&b, sizeof(double), 1, fp)) >= 1)
	{
		printf("%lf\n", b);
	}
	if (feof(fp))
		printf("End of file reached successfully\n");
	else if (ferror(fp)) 
	{
		perror("Error reading test.bin");
	}
	fclose(fp);
	fp = NULL;
}

/*
int main(void)
{
	int c; 
	FILE* fp = fopen("Test.txt", "w");
	if (!fp)
	{
		perror("File opening failed");
		return  -1;
	}
	
	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
	{
		putchar(c);
	}
	putchar('\n');
	
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");
	fclose(fp);
}

/*
int main()
{
	FILE *fpIn = fopen("Test.c", "r");
	if(NULL == fpIn)
	{
		printf("Open Test.c Error.\n");
		return -1;
	}
	FILE *fpOut = fopen("Test4.txt", "w");
	if(NULL == fpOut)
	{
		fclose(fpIn);
		printf("Open Test4.txt Error.\n");
		return -1;
	}

	//Copy
	while(!feof(fpIn))
	{
		char ch = fgetc(fpIn);
		fputc(ch, fpOut);
	}

	fclose(fpIn);
	fclose(fpOut);
	return 0;
}

/*
int main()
{
	FILE * pFile;
	long size;
	pFile = fopen("Test2.txt", "r");
	if (pFile == NULL) 
		perror("Error opening file");
	else
	{
		fseek(pFile, 0, SEEK_END); // non-portable
		size = ftell(pFile);
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
	}
	return 0;
}

/*
void main()
{
	FILE *fp = fopen("Test.txt", "r");  
	if(NULL == fp)
	{
		printf("Open File Failed.\n");
		return;
	}

	int pos = ftell(fp);
	printf("pos = %d\n", pos);
	char ch = fgetc(fp);
	printf("ch = %c\n", ch);
	ch = fgetc(fp);
	printf("ch = %c\n", ch);
	pos = ftell(fp);
	printf("pos = %d\n", pos);

	rewind(fp);
	pos = ftell(fp);
	printf("pos = %d\n", pos);

	ch = fgetc(fp);
	printf("ch = %c\n", ch);

	//
	fseek(fp, 10 ,SEEK_SET);
	ch = fgetc(fp);
	printf("ch = %c\n", ch);

	//
	fseek(fp, -4 ,SEEK_CUR);
	ch = fgetc(fp);
	printf("ch = %c\n", ch);

	//
	fseek(fp, -3 ,SEEK_END);
	ch = fgetc(fp);
	printf("ch = %c\n", ch);
	fclose(fp);
}

/*
int main()
{
	FILE *fpIn = fopen("Test.c", "r");
	if(NULL == fpIn)
	{
		printf("Open Test.c Error.\n");
		return -1;
	}
	FILE *fpOut = fopen("Test3.txt", "w");
	if(NULL == fpOut)
	{
		fclose(fpIn);
		printf("Open Test3.txt Error.\n");
		return -1;
	}

	//Copy
	char buf[128] = {0};
	char *res = fgets(buf, 128, fpIn);
	while(res != NULL)
	{
		fputs(buf, fpOut);
		memset(buf, 0, 128);
		res = fgets(buf, 128, fpIn);
	}

	fclose(fpIn);
	fclose(fpOut);
	return 0;
}

/*
int main()
{
	FILE *fpIn = fopen("Test.c", "r");
	if(NULL == fpIn)
	{
		printf("Open Test.c Error.\n");
		return -1;
	}
	FILE *fpOut = fopen("Test2.txt", "w");
	if(NULL == fpOut)
	{
		fclose(fpIn);
		printf("Open Test2.txt Error.\n");
		return -1;
	}

	//Copy
	char ch = fgetc(fpIn);
	while(ch != EOF)
	{
		fputc(ch, fpOut);
		ch = fgetc(fpIn);
	}

	fclose(fpIn);
	fclose(fpOut);
	return 0;
}

/*
void main()
{
	int ar[10] = {0};

	FILE *fp = fopen("Test1.txt", "rb");  
	if(NULL == fp)
	{
		printf("Open File Failed.\n");
		return;
	}

	fread(ar, sizeof(int), 10, fp);

	fclose(fp);
}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	int n = sizeof(ar) / sizeof(ar[0]);

	FILE *fp = fopen("Test1.txt", "wb");  
	if(NULL == fp)
	{
		printf("Open File Failed.\n");
		return;
	}

	fwrite(ar, sizeof(int), n, fp);

	fclose(fp);
}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	int n = sizeof(ar) / sizeof(ar[0]);

	FILE *fp = fopen("Test.txt", "a");
	if(NULL == fp)
	{
		printf("Open File Failed.\n");
		return;
	}

	for(int i=0; i<n; ++i)
		fprintf(fp, "%d ", ar[i]); //重定向

	fclose(fp);
}

/*
void main()
{
	int ar[10] = {0};
	FILE *fp = fopen("Test.txt", "r");
	if(NULL == fp)
	{
		printf("Open File Failed.\n");
		return;
	}

	for(int i=0; i<10; ++i)
	{
		//scanf("%d", &ar[i]); //标准输入 键盘
		fscanf(fp, "%d", &ar[i]);
	}

	fclose(fp);
}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	int n = sizeof(ar) / sizeof(ar[0]);

	FILE *fp = fopen("Test.txt", "w");
	if(NULL == fp)
	{
		printf("Open File Failed.\n");
		return;
	}

	for(int i=0; i<n; ++i)
		fprintf(fp, "%d ", ar[i]); //重定向

	fclose(fp);
}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	int n = sizeof(ar) / sizeof(ar[0]);

	FILE *fp = NULL; //文件
	fp = fopen("Test.txt", "w");
	//fp = fopen("C:\\Bit\\Test.txt", "w");
	//fp = fopen("..\Test.txt", "w");
	if(NULL == fp)
	{
		printf("Open File Failed.\n");
		return;
	}

	for(int i=0; i<n; ++i)
	{
		//printf("%d ", ar[i]);    //标准输出 -> 屏幕  
		fprintf(fp, "%d ", ar[i]); //重定向
	}
	//printf("\n");

	fclose(fp);
}
*/