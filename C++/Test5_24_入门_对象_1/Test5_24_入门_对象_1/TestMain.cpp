#include<iostream>
//#include"Test.h"
using namespace std;


class CGoods
{
public:
	void RegisterGoods(char *name, size_t count, float price);
	float GetTotalPrice();
	char* GetName();
	size_t GetCount();
	float GetPrice();
private:
	char m_name[20];
	size_t m_count;
	float  m_price;
	float m_total_price;
};

void CGoods::RegisterGoods(char *name, size_t count, float price)
{
	strcpy(m_name, name);
	m_count = count;
	m_price = price;
	m_total_price = m_price * m_count;
}
float CGoods::GetTotalPrice()
{
	return m_total_price;
}
char* CGoods::GetName()
{
	return m_name;
}
size_t CGoods::GetCount()
{
	return m_count;
}
float CGoods::GetPrice()
{
	return m_price;
}

void main()
{
	CGoods c1, c2;
	c1.RegisterGoods("C++", 10, 56.9);
	c2.RegisterGoods("Java", 8, 45);

	cout<<"name = "<<c1.GetName()<<endl;
	cout<<"price = "<<c1.GetPrice()<<endl;
	cout<<"total price = "<<c1.GetTotalPrice()<<endl;

	cout<<"name = "<<c2.GetName()<<endl;
	cout<<"price = "<<c2.GetPrice()<<endl;
	cout<<"total price = "<<c2.GetTotalPrice()<<endl;
}

/*
class CGoods
{
public:
	void RegisterGoods(char *name, size_t count, float price)
	{
		strcpy(m_name, name);
		m_count = count;
		m_price = price;
		m_total_price = m_price * m_count;
	}
	float GetTotalPrice()
	{
		return m_total_price;
	}
	char* GetName()
	{
		return m_name;
	}
	size_t GetCount()
	{
		return m_count;
	}
	float GetPrice()
	{
		return m_price;
	}
private:
	char m_name[20];
	size_t m_count;
	float  m_price;
	float m_total_price;
};

void main()
{
	CGoods c1, c2;
	c1.RegisterGoods("C++", 10, 56.9);
	c2.RegisterGoods("Java", 8, 45);

	cout<<"name = "<<c1.GetName()<<endl;
	cout<<"price = "<<c1.GetPrice()<<endl;
	cout<<"total price = "<<c1.GetTotalPrice()<<endl;

	cout<<"name = "<<c2.GetName()<<endl;
	cout<<"price = "<<c2.GetPrice()<<endl;
	cout<<"total price = "<<c2.GetTotalPrice()<<endl;
}

/*
//封装 ==》 数据+方法
class Test
{
public:
	double d;
private:
	char ch;
private:
	int a;
};

void main()
{
	Test t;
	t.d = 12.34;
	t.ch = 'a';
}

/*
typedef struct Test
{
	int a;
	double b;
	char c;
}Test;

class Test1
{
	int a;
	double b;
	char c;
};

void main()
{
	Test t;     //定义变量-结构体变量
	t.a = 10;
	t.c = 'A';

	Test1 t1;   //实例化 - 对象  格局
	t1.a = 10;
	t1.c = 'A';
}

/*
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}

void main()
{
	f(0);
	f((int*)NULL);  //指针 宏
	f(nullptr); //类型

	cout<<sizeof(nullptr)<<endl;
}

/*
void main()
{
	int *p = NULL;
	int *q = 0;

	int *ptr = nullptr;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(ar[0]);
	
	for(int i=0; i<n; ++i)
		cout<<ar[i]<<" ";
	cout<<endl;

	for(const auto &e : ar)
	{
		//continue
		//break
		cout<<e<<" ";
	}
	cout<<endl;
}

/*
void main()
{
	int a = 1;
	auto p = &a;
	cout<<typeid(p).name()<<endl;

	auto &b = a;
	cout<<typeid(b).name()<<endl;

	auto x=1.23, y=12.34;

	int ar[] = {1,2,3};
	cout<<typeid(ar).name()<<endl;
	auto br = ar;  //首元素的地址
	cout<<typeid(br).name()<<endl;

}

/*
void fun(auto a)
{
	cout<<"a = "<<a<<endl;
}
void main()
{
	fun(10);
}

/*
struct Test
{};
void main()
{
	int a = 10;
	char ch = 'a';
	Test t;

	auto b = t;  //自动推导

	auto x = b;

	cout<<typeid(b).name()<<endl;
}

/*
void main()
{
	fun(10,20);
}
*/