#include<iostream>    //输入输出流 in out stream
#include<algorithm>
#include"Test.h"
using namespace std;  //命名空间

//C++可以重载 C语言不可以
//函数的重载 -1名字相同  2参数列表不同 3不能只通过返回值的不同形成重载
extern "C" int Max(int a, int b)
{
	return a > b ? a : b;
}
extern "C" char Max(char a, char b)
{
	return a > b ? a : b;
}
double Max(double a, double b)
{
	return a > b ? a : b;
}
void main()
{
	cout<<Max(10,20)<<endl;
	cout<<Max('A','B')<<endl;   //隐示转换
	cout<<Max(10.12,20.23)<<endl;
}

/*
int Add(int a, int b, int c) //默认参数
{
	return a + b;
}

void main()
{
	printf("result = %d\n", Add(10, 20));
}

/*
int Add(int a=0, int b=0) //默认参数
{
	return a + b;
}

void main()
{
	printf("result = %d\n", Add(10));
}

/*
//名字冲突
namespace bit
{
	const int min(const int a, const int b)
	{
		return a > b ? b : a;
	}
};

void main()
{
	int a = 10;
	int b = 20;
	cout<<"Min Value = "<<bit::min(a,b)<<endl;
}

/*
namespace MySpace
{
	void fun()
	{
		cout << "This is fun 1." << endl;
	}
};
namespace YouSpace
{
	void fun()
	{
		cout << "This is fun 2." << endl;
	}
};

using YouSpace::fun; //
//using namespace YouSpace;
void main()
{
	MySpace::fun();
	fun();
}

/*
//条件编译
#define A

#ifdef A
void fun()
{
	cout<<"This is fun 1."<<endl;
}
#else
void fun()
{
	cout<<"This is fun 2."<<endl;
}
#endif

void main()
{
	fun();
}

/*
void main()
{
	int key;
	cout<<"请输入key:>";   //插入符   输出运算符  ::作用域访问符
	cin>>key;              //提取符   输入运算符

	cout<<"key = "<<key<<endl;
}

/*
void main()
{
	int key;
	std::cout<<"请输入key:>";   //插入符   输出运算符  ::作用域访问符
	std::cin>>key;              //提取符   输入运算符

	std::cout<<"key = "<<key<<std::endl;
}

/*
void main()
{
	int a = 10;
	char b = 'B';
	double c = 12.34;
	printf("a = %d, b = %c, c = %f\n", a, b, c);

	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
}
*/