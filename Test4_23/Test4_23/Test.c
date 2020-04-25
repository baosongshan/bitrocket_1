#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int FindChar(char *str, char ch)
{
    //assert(str != NULL);
    int count = 0;
    while(*str != '\0')
    {
        if(*str == ch)
            count++;
        str++;
    }
    return count;
}

int main()
{
    char str[100] = {0}; //Abcabc
    gets(str);
    char ch;    //A
    scanf("%c", &ch);
    
    int count = FindChar(str, ch);
    printf("%d", count);
    
    return 0;
}

/*
void main()
{
	char str[100] = {0}
	//scanf("%s", str);   //' ',  \n  hello bit
	gets(str);
	printf("str = %s\n", str);
}

/*
void main()
{
	char str[100] = {0};
	scanf("%s", str);   //' ',  \n  hello bit
	printf("str = %s\n", str);

	scanf("%s", str);   //' ',  \n  hello bit
	printf("str = %s\n", str);
}

/*
bool IsRotate(char *str, char *sub)
{
	assert(str!=NULL &&sub!=NULL);
	if(strlen(str) != strlen(sub))
		return false;
	char *tmp = (char *)malloc(sizeof(char) * strlen(str)*2+1);
	strcpy(tmp, str);
	strcat(tmp, str);
	char *res = strstr(tmp, sub);
	free(tmp);
	return (res != NULL);
}

void main()
{
	char *str = "HelloBit";
	char *sub = "BtiHello";

	bool flag = IsRotate(str, sub);
	if(flag)
		printf("True");
	else
		printf("False");
}

/*
//字符串

void Reverse(char *str, int start, int end) //[ ]
{
	assert(str != NULL);
	while(start < end)
	{
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

void LeftRound(char *str, int n)
{
	//1 验证参数的合法性
	assert(str != NULL);
	//2 移动的步长
	int len = strlen(str);
	if(len == 1)
		return;
	int step = n % len;

	//3 移动
	Reverse(str, 0, step-1);
	Reverse(str, step, len-1);
	Reverse(str, 0, len-1);
}

void main()
{
	char str[] = "ABCDEFGHIJK";
	int n = 2; //"CDEFGHIJKAB";
	LeftRound(str, n);
	printf("str = %s\n", str);
}

/*
void LeftRound(char *str, int n)
{
	//1 验证参数的合法性
	assert(str != NULL);
	//2 移动的步长
	int len = strlen(str);
	if(len == 1)
		return;
	int step = n % len;

	//3 移动
	char *tmp = (char*)malloc(sizeof(char) * len +1);
	memset(tmp, 0, sizeof(char)*len);
	strncpy(tmp, str+step, len-step);
	strncat(tmp, str, step);  // \0
	strncpy(str, tmp, len);
	free(tmp);
}

void main()
{
	char str[] = "ABCDEFGHIJK";
	int n = 2; //"CDEFGHIJKAB";
	LeftRound(str, n);
	printf("str = %s\n", str);
}

/*
void LeftRound(char *str, int n)
{
	//1 验证参数的合法性
	assert(str != NULL);
	//2 移动的步长
	int len = strlen(str);
	if(len == 1)
		return;
	int step = n % len;

	//3 移动
	while(step-- != 0)
	{
		char tmp = str[0];
		for(int i=0; i<len-1; ++i)
			str[i] = str[i+1];
		str[len-1] = tmp;
	}
}

void main()
{
	char str[] = "A";
	int n = 20; //"CDEFGHIJKAB";
	LeftRound(str, n);
	printf("str = %s\n", str);
}

/*
#define ROW  5
#define COL  5

bool FindNum(int ar[ROW][COL], int key)
{
	int r = 0;
	int c = COL-1;
	while(r<ROW && c>=0)
	{
		if(key < ar[r][c])
			c--;
		else if(key > ar[r][c])
			r++;
		else
			return true;
	}
	return false;
}

void main()
{
	int ar[ROW][COL] = {
						{1,  3,  5,  7,  9},
						{2,  4,  6,  8,  10},
						{11, 13, 15, 17, 19},
						{21, 23, 25, 27 ,29},
						{31, 33, 35, 37, 39}
					    };

	int key = 38;
	bool flag = FindNum(ar, key);
	if(flag)
		printf("key %d found.\n", key);
	else
		printf("key %d not found.\n", key);
}

/*
bool FindNum(int ar[ROW][COL], int key)
{
	//O(N^2)
	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			if(ar[i][j] == key)
				return true;
		}
	}
	return false;
}

void main()
{
	int ar[ROW][COL] = {
						{1,  3,  5,  7,  9},
						{2,  4,  6,  8,  10},
						{11, 13, 15, 17, 19},
						{21, 23, 25, 27 ,29},
						{31, 33, 35, 37, 39}
					    };

	int key = 230;
	bool flag = FindNum(ar, key);
	if(flag)
		printf("key %d found.\n", key);
	else
		printf("key %d not found.\n", key);
}

/*
int my_atoi(const char *str)
{
	assert(str != NULL);
	//跳过空格
	while(*str == ' ')
		str++;

	int flag = 1; //符号位. str跳过符号位
	if(*str == '-')
	{
		flag = -1;
		str++;
	}
	else if(*str == '+')
		str++;


	long long res = 0;
	while(*str != '\0')
	{
		if(*str<'0' || *str>'9') // 字符不是数字，代表字符串无效
			break;
		res = res * 10 + (*str-'0');  //4194
		if(res>INT_MAX || -res<INT_MIN)
			return 0;
		str++;
	}
	return flag*res;
}

void main()
{
	char *str = "0x8401814";   
	int res1 = atoi(str);  //4194
	printf("res1 = %d\n", res1);

	int res2 = my_atoi(str);  //4194  //要求支持16进制的计算
	printf("res2 = %d\n", res2);
}

/*
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字

void FindNumber(int ar[], int n, int *num1, int *num2)
{
	int res = 0;
	for(int i=0; i<n; ++i)
	{
		res ^= ar[i];   //0101 ==> 3  6
	}
	//分割结果
	int pos = 0;
	for(int i=0; i<32; ++i)
	{
		if(res & (1<<i))
		{
			pos = i;
			break;
		}
	}

	*num1 = 0;
	*num2 = 0;
	for(int i=0; i<n; ++i)
	{
		if(ar[i] & (1<<pos))  //表示ar[i]的pos为1  1 1 2 3 3 
		{
			*num1 ^= ar[i];
		}
		else                  //表示ar[i]的pos为0 4 4  5 5 6
		{
			*num2 ^= ar[i];
		}
	}
}

void main()
{
	//0000 0000 0000 0000 0000 0000 0000 0011   3 ^
	//0000 0000 0000 0000 0000 0000 0000 0110   6
	//0000 0000 0000 0000 0000 0000 0000 0101
	int ar[] = {1,2,4,3,0,5,5,4,3,1};
	int n = sizeof(ar) / sizeof(ar[0]);
	int num1, num2;
	FindNumber(ar, n, &num1, &num2);
	printf("num1 = %d, num2 = %d\n", num1, num2);
}

/*
int FindNumber(int ar[], int n)
{
	int res = 0;
	for(int i=0; i<n; ++i)
	{
		res ^= ar[i];
	}
	return res;
}

void main()
{
	//0011   3 ^
	//0110   6
	//0101
	int ar[] = {1,2,4,6,5,5,4,3,2,1};
	int n = sizeof(ar) / sizeof(ar[0]);
	printf("value = %d\n", FindNumber(ar, n));
}

/*
int FindNumber(int ar[], int n)
{
	int res = 0;
	for(int i=0; i<n; ++i)
	{
		res ^= ar[i];
	}
	return res;
}

void main()
{
	//0011   3 ^ 3
	//0011
	int ar[] = {1,2,4,5,5,4,3,2,1};
	int n = sizeof(ar) / sizeof(ar[0]);
	printf("value = %d\n", FindNumber(ar, n));
}

/*
//暴力搜索方式
int FindNumber(int ar[], int n)
{
	int j;
	for(int i=0; i<n; ++i)
	{
		for(j=0; j<n; ++j)
		{
			if(i!=j && ar[i] == ar[j])
				break;
		}
		if(j >= n)
			return ar[i];
	}
}

void main()
{
	int ar[] = {1,2,4,5,5,4,3,2,1};
	int n = sizeof(ar) / sizeof(ar[0]);
	printf("value = %d\n", FindNumber(ar, n));
}


/*
#define swapintbit(n) ((((n)&0x55555555)<<1) | (((n)&0xaaaaaaaa)>>1))  

void main()
{
	int n = -5;
	printf("%d\n", swapintbit(n));
	//1000 0000 0000 0000 0000 0000 0000 1001  -9
	//1111 1111 1111 1111 1111 1111 1111 0111  -9的补码

	//1000 0000 0000 0000 0000 0000 0000 0101
	//1111 1111 1111 1111 1111 1111 1111 1011  -5的补码
}

/*
void main()
{
	int a = -5; // 1000 0000 0000 0000 0000 0000 0000 0101
	            // 1111 1111 1111 1111 1111 1111 1111 1110  
				// 1111 1111 1111 1111 1111 1111 1111 1101 
	            // 1000 0000 0000 0000 0000 0000 0000 0010

	int res = a >> 2;  //-5 / 2^1 

	printf("%d\n", res);

}

/*
//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//写一个宏，可以将一个整数字的奇数位和偶数位交换

#define swapintbit(n) ((((n)&0x55555555)<<1) | (((n)&0xaaaaaaaa)>>1))

void main()
{
	// 1000 0100 0111 0111 0010 0110 0010 1011  //value
	// 0101 0101 0101 0101 0101 0101 0101 0101   //0x55555555
	// 0000 0100 0101 0101 0000 0100 0000 0001   //奇数
	// 0000 1000 1010 1010 0000 1000 0000 0010   //奇数<<1

	// 0000 0100 0111 0111 0010 0110 0010 1011  //value
	// 1010 1010 1010 1010 1010 1010 1010 1010  //0xaaaaaaaa
    // 0000 0000 0010 0010 0010 0010 0010 1010  //偶数
	// 0000 0000 0001 0001 0001 0001 0001 0101  //偶数 >> 1

	// 0000 1000 1010 1010 0000 1000 0000 0010   //奇数<<1
	// 0000 0000 0001 0001 0001 0001 0001 0101   //偶数 >> 1

	// 0000 1000 1011 1011 0001 1001 0001 0111  
	// 0000 0100 0111 0111 0010 0110 0010 1011  //value


	// 0101 0101 0101 0101 0101 0101 0101 0101|0 //0xAA AA AA AA >> 1
	//size_t value = 12345; 
	int value = 74917419;
	printf("swapintbit value = %d\n", swapintbit(value));
}

/*
typedef struct Test   
{
	double c;//8
	int a;  //0~4
	char b; //1 + 3
}Test;

#define offsetof(struct_type, member_name) (size_t)&(((struct_type*)0)->member_name)

void main()
{
	Test t;
	printf("offset = %d\n", (size_t)&t.a - (size_t)&t);  //
}

/*
//


void main()
{
	printf("offset = %d\n", offsetof(Test, b));
}

/*
void main()
{
	Test t;
	printf("&t = %p\n", &t);
	printf("&a = %p\n", &(t.a));
	printf("&b = %p\n", &(t.b));
	printf("&c = %p\n", &(t.c));
}
*/