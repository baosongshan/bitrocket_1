#include<iostream>
#include<vld.h>
#include<time.h>
using namespace std;

class Test;
ostream& operator<<(ostream &out, const Test &t);
istream& operator>>(istream &in, Test &t);

class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
	friend istream& operator>>(istream &in, Test &t);
public:
	Test(int d = 0) :m_data(d)
	{}
public:
	Test operator+(const Test &t)
	{
		//暂且
		Test tmp(m_data + t.m_data);
		return tmp;
	}
	Test operator-(const Test &t);
	Test operator*(const Test &t);
	Test operator/(const Test &t);
	Test operator%(const Test &t);
public:
	Test& operator+=(const Test &t)
	{
		m_data += t.m_data;  //10 += 20
		return *this;
	}
	Test& operator-=(const Test &t);
	Test& operator*=(const Test &t);
	Test& operator/=(const Test &t);
	Test& operator%=(const Test &t);
public:
	//++
	//--
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};

ostream& operator<<(ostream &out, const Test &t)
{
	out<<t.m_data;
	return out;
}

istream& operator>>(istream &in, Test &t)
{
	in>>t.m_data;
	return in;
}

void main()
{
	Test t;
	cout<<"input t value:>";
	cin>>t;
	cout<<"t = "<<t<<endl;
}

/*
void main()
{
	Test t1(10);
	cout<<"t1 = "<<t1<<endl;
	Test t2(20);
	cout<<"t2 = "<<t2<<endl;
	Test t;
	t = t1 + t2;  //t = t1.operator+(t2);
	cout<<"t = "<<t<<endl;
	t1 += t2;
	cout<<"t1 = "<<t1<<endl;
}

/*
class DateTime
{
public:
	DateTime()
	{
		time_t te;
		time(&te);
		struct tm *ptm = localtime(&te);

		m_year = ptm->tm_year + 1900;
		m_month = ptm->tm_mon + 1;
		m_day = ptm->tm_mday;;
		m_hour = ptm->tm_hour;
		m_minute = ptm->tm_min;
		m_second = ptm->tm_sec;
	}
public:
	void PrintDateTime()
	{
		cout<<m_year<<":"<<m_month<<":"<<m_day<<endl;
		cout<<m_hour<<":"<<m_minute<<":"<<m_second<<endl;
	}
private:
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_minute;
	int m_second;
};

void main()
{
	DateTime dt;

	int a = 10;
	cout<<a<<endl;
	double d = 12.34;
	cout<<d<<endl;
	cout<<dt<<endl;
}

/*
void main()
{
	time_t te;
	time(&te);
	//cout<<ctime(&te)<<endl;
	//cout<<te<<endl;
	struct tm *ptm = localtime(&te);
	cout<<ptm->tm_year+1900<<":"<<ptm->tm_mon+1<<":"<<ptm->tm_mday<<endl;
	cout<<ptm->tm_hour<<":"<<ptm->tm_min<<":"<<ptm->tm_sec<<endl;
}

/*
class DateTime
{
public:
	DateTime()
	{

	}
private:
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_minute;
	int m_second;
};

/*
class String
{
public:
	String(const char *str = "")
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(str)+1));
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = (char *)malloc(sizeof(char) * (strlen(s.m_data)+1));
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this != &s)  //1
		{
			free(m_data); //2  abc
			//异常不安全的代码
			m_data = (char *)malloc(sizeof(char) * (strlen(s.m_data)+1));  //3  
			strcpy(m_data, s.m_data);
		}
		return *this; //4
	}
	~String()
	{
		if(m_data != nullptr)
		{
			free(m_data);
			m_data = nullptr;
		}
	}
public:
	void PrintString()const
	{
		cout<<m_data<<endl;
	}
private:
	char *m_data;
};

void main()
{
	String s("HelloBit");
	s.PrintString();

	String s1 = s;
	s1.PrintString();

	String s2("abc");
	s2 = s1;
	s2.PrintString();

}

/*
class Test
{
public:
	//重载[参数列表]
    //int GetData(Test * const this)
	int GetData()
	{
		//m_data = 100;
		fun();
		show();
		return m_data;
	}
	//int GetData(const Test * const this)
	int GetData()const   //长方法
	{
		//this->m_data = 200;
		show();
		//fun();
		return m_data;
	}
public:
	//void fun(Test * const this);
	void fun()
	{
		cout<<"This is Test::fun()"<<endl;
	}
	void show()const
	{
		cout<<"This is Test::show()const"<<endl;
	}
private:
	int m_data = 10;
};

void main()
{
	Test t;
	int v1 = t.GetData();  //GetData(&t);
}

/*
class Test
{
public:
	//默认的构造函数
	//默认的拷贝构造函数-按成员拷贝
	//默认的赋值语句    -按成员赋值
	//默认的析构函数
public:
	//默认取地址运算符
	Test* operator&()
	{
		return this;  //*this
	}
	//默认常对象取地址运算符
	const Test* operator&()const
	{
		return this;
	}
private:
	int m_data = 0;  //C++11
	int m_a = 1;
	int m_x = 2;
};

void  main()
{
	const Test t;
	const Test *pt = &t;
}

/*
void  main()
{
	Test t;
	Test t1 = t;
	Test t2;
	t2 = t1;

	Test *pt = &t;
}

/*
class Test
{
public:
	//类型转换
	explicit Test(int d = 0) : m_data(d)
	{
		cout<<"Create Test Obj : "<<this<<endl;
	}
	Test(const Test &t)
	{
		cout<<"Copy Create Test Obj : "<<this<<endl;
		m_data = t.m_data;
	}
	//=重载   运算符的重载
	//Test& operator=(const Test &t)

	//t1 = t2;  t1.operator=(t2)
	Test&  operator=(const Test &t)
	{
		cout<<"Assign : "<<this<<" = "<<&t<<endl;
		
		//&t1 = &t2;
		if(this != &t)  //当前对象自己给自己赋值
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout<<"Free Test Obj : "<<this<<endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};

void main()
{
	int a = 10;
	int &b = a;
	int &c = b;



	c = a;
}

/*
void main()
{
	Test t(100);
	Test t1, t2, t3;
	t1 = t2 = t3 = t;  //连等赋值

	//t1.operator=(t2.operator=(t3.operator=(t)));

	//t1.operator=(t);  //
}

/*
void main()
{
	Test t;
	t = (Test)100;   //t.m_data = 100;

	int value = (int)t;   //value = t.m_data   //????
	//int value = t.GetData();
}

/*
void main()
{
	Test t;    //开辟空间
	//explicit 显示的
	t = (Test)200;   //  t.m_data = 200;
}

/*
void main()
{
	Test t;   //开辟空间
	t = 200;   //  t.m_data = 200;
	t = 'A';

	Test t1(t); //初始化
	Test t2;
	t2 = t1;    //赋值
}

/*
void main()
{
	Test t(10);
	Test t1(t);   //t1.m_data = t.m_data;
	Test t2;
	t2 = t1;
}
*/