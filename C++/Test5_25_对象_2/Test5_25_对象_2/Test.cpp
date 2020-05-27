#include<iostream>
using namespace std;

class Test
{
public:
	//构造函数 -->自动调用
	Test(int data = 0)
	{
		m_data = data;
		cout<<"Create Test Obj : "<<this<<endl;
	}
	//拷贝构造方法  Test t1(t0);
	Test(const Test &t) //语法要求
	{
		m_data = t.m_data;
		cout<<"Copy Create Test Obj : "<<this<<endl;
	}

	//赋值语句   等号的重载
	Test& operator=(const Test &t)
	{
		cout<<"Assign :"<<this <<" = "<<&t<<endl;
		if(this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}

	//析构方法 -->收尸
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
	Test t1(10);
	Test t2 = t1;  //初始化 Test t2(t1);
}


/*
class seqlist
{
public:
	seqlist(int sz = 8)
	{
		capacity = sz;
		base = (int *)malloc(sizeof(int) * capacity);
		size = 0;
	}
	~seqlist()
	{
		//打扫战场
		free(base);
		capacity = size = 0;
	}
private:
	int *base;
	int capacity;
	int size;
};

void main()
{
	seqlist list(10);
}
/*
class Time
{
public:
	Time(int h=0, int m=0, int s=0):m_hour(h), m_minute(m), m_second(s)
	{}
	~Time()
	{}
private:
	int m_hour;
	int m_minute;
	int m_second;
};

class Test
{
public:
	
private:
	int m_data;
	Time m_time;
};

void main()
{
	Test t;
}


/*
//alt+f8
class Date
{
public:
	Date()
	{}
	Date(int year=0, int month=0, int day=0):_year(year),_month(month),_day(day)
	{}
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void main()
{
	Date d0;
}

/*
int main()
{
	Date d1;
	d1.SetDate(2018, 5, 1);
	d1.Display();

	Date d2;
	d2.SetDate(2018, 7, 1);
	d2.Display();
	return 0;
}

/*
class Test
{
public:
	//构造函数 -->自动调用
	Test(int data = 0)
	{
		m_data = data;
		cout<<"Create Test Obj : "<<this<<endl;
	}
	//拷贝构造方法  Test t1(t0);
	Test(const Test &t) //语法要求
	{
		m_data = t.m_data;
		cout<<"Copy Create Test Obj : "<<this<<endl;
	}

	//赋值语句   等号的重载
	Test& operator=(const Test &t)
	{
		cout<<"Assign :"<<this <<" = "<<&t<<endl;
		if(this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}

	//析构方法 -->收尸
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
	Test t1(10);
	Test t2 = t1;  //初始化 Test t2(t1);
}

/*
void main()
{
	Test t1(10);
	Test t2;
	t2 = t1;  //赋值 Test t2(t1);
}


/*
Test fun(Test pt)
{
	int value = pt.GetData();
	//cout<<"value = "<<value<<endl;
	Test tmp(value);
	return tmp;
}

void main()
{
	Test t1(10);
	Test t2(t1); // 1
	fun(t1);
}

/*
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = NULL;
	p->PrintA();
	p->Show();
}

/*
class Test
{
public:
	void SetData(int m_data = 0)
	{
		this->m_data = m_data;
	}
	//int GetData(Test *const this)
	int GetData()  //成员方法 this = &当前对象
	{
		//this = nullptr;
		return this->m_data;
	}
private:
	int m_data;
};

void main()
{
	Test t1, t2, t3; // ?  10 8  1
	//cout<<sizeof(Test)<<endl; // 1
	t1.SetData(10);
	t2.SetData(20);
	t3.SetData(30);

	//this
	cout<<"t1 data = "<<t1.GetData()<<endl;  //GetData(&t1);
	cout<<"t2 data = "<<t2.GetData()<<endl;
	cout<<"t3 data = "<<t3.GetData()<<endl;
}

/*
struct Student
{
	char name[10];
	int age;
	char sex[3];
};

void InitStu(Student *_this, char *name, int age, char *sex)  //this C
{
	strcpy(_this->name, name);
	_this->age = age;
	strcpy(_this->sex, sex);
}

void main()
{
	Student s1, s2, s3;
	InitStu(&s1, "张三", 20, "男");
	InitStu(&s3, "王爽", 28, "女");
}

/*
class Test
{
public:
	void SetData(int data = 0)
	{
		m_a = data;
	}
	int GetData()const  //成员方法 this = &当前对象
	{
		return this->m_a;
	}
private:
	int m_a;
};

void main()
{
	Test t1, t2, t3; // ?  10 8  1
	//cout<<sizeof(Test)<<endl; // 1
	t1.SetData(10);
	t2.SetData(20);
	t3.SetData(30);

	//this
	cout<<"t1 data = "<<t1.GetData()<<endl;
	cout<<"t2 data = "<<t2.GetData()<<endl;
	cout<<"t3 data = "<<t3.GetData()<<endl;
}

/*
class Test
{
	char m_ch; //1 +7
	double m_d; //8
	int m_b;   //4 +4
};

void main()
{
	cout<<sizeof(Test)<<endl;
}

/*
//画了一张图纸
class Test
{
	char ch; //1 +3
	int m_a; //4
	int m_b; //4
};

void main()
{
	cout<<sizeof(Test)<<endl;
}

/*
void main()
{
	Test t, t1, t2, t3; //空间
	t.m_a = 10;  //没有空间
}

/*
//封装性
class CGoods
{
public:
	void RegisterGoods(char *name, int count, float price)
	{
		strcpy(m_name, name);
		m_count = count;
		m_price = price;
		m_total_price = m_price * m_count;
	}
	const char* GetName()const //常方法
	{
		return m_name;
	}
	int   GetCount()const
	{
		return m_count;
	}
	float GetPrice()const
	{
		return m_price;
	}
	float GetTotalPrice()const
	{
		return m_total_price;
	}
private:
	char m_name[10];
	int m_count;
	float m_price;
	float m_total_price;
};


void main()
{
	CGoods c1, c2;
	c1.RegisterGoods("C++.pdf", 10, 65);
	c2.RegisterGoods("Java.pdf", 7, 55);

	cout<<c2.GetName()<<endl;
}

/*
class Test
{
	int m_a;
};

void main()
{
	Test t; //实例化对象
	t.m_a = 10;
}

/*
class Test
{
public:
	int m_a;  //数据成员、函数<方法>成员
protected:
	int m_b;
private:
	int m_c;
};

void main()
{
	Test t; //实例化对象
	t.m_a = 10;
	//t.m_b = 1;
	t.m_c = 2;
}
*/