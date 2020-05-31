#include<iostream>
#include<assert.h>
//#include<vld.h>
using namespace std;

//8G  --> 物理损坏

void main()
{
	char *ptr = new char[0xffffffff]; //1111 1111 1111 1111 1111 1111 1111 1111
}

/*
class Test
{
public:
	Test(int data = 0) :m_data(data)
	{
		cout<<"Create Test Obj:"<<this<<endl;
	}
	~Test()
	{
		cout<<"Free Test Obj:"<<this<<endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};

void* operator new(size_t sz, Test *addr, int pos)
{
	return &addr[pos]; //用于寻找空间的起始位置
}
void main()
{
	Test ar[10];
	new(ar, 4) Test(100);     //placement new
}

/*

void* operator new(size_t sz, int *addr, int pos)
{
	return &addr[pos]; //用于寻找空间的起始位置
}
void main()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	new(p)int(2);  //new 
}

/*
void* operator new(size_t sz)
{
	void *ptr = malloc(sz);
	assert(ptr != nullptr);
	return ptr;
}

void operator delete(void *ptr)
{
	if(ptr != nullptr)
		free(ptr);
}

void* operator new[](size_t sz)
{
	void *ptr = malloc(sz);
	assert(ptr != nullptr);
	return ptr;
}
void operator delete[](void *ptr)
{
	if(ptr != nullptr)
		free(ptr);
}

class Test
{
public:
	Test(int data = 0) :m_data(data)
	{
		cout<<"Create Test Obj:"<<this<<endl;
	}
	~Test()
	{
		cout<<"Free Test Obj:"<<this<<endl;
	}
public:
	void* operator new(size_t sz)
	{
		void *ptr = malloc(sz);
		assert(ptr != nullptr);
		return ptr;
	}

	void operator delete(void *ptr)
	{
		if (ptr != nullptr)
			free(ptr);
	}

	void* operator new[](size_t sz)
	{
		void *ptr = malloc(sz);
		assert(ptr != nullptr);
		return ptr;
	}
	void operator delete[](void *ptr)
	{
		if (ptr != nullptr)
			free(ptr);
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
	Test *pt = new Test;  //new 操作符  1申请空间  2构造对象
	Test *pt1 = (Test*)::operator new(sizeof(Test));  //malloc 申请空间

	Test *pt2 = new Test[10];

	//delete pt;
	operator delete(pt);
	delete pt1;
	delete []pt2;
}

/*
class String;
ostream& operator<<(ostream &out, const String &s);

class String
{
	friend ostream& operator<<(ostream &out, const String &s);
public:
	String(const char *str="")
	{
		if(str == nullptr)
		{
			m_data = new char[1];
			m_data[0] = '\0';
		}
		else
		{
			m_data = new char[strlen(str)+1];
			strcpy(m_data, str);
		}
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data)+1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			delete []m_data;
			m_data = new char[strlen(s.m_data)+1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		if(m_data != nullptr)
		{
			delete []m_data;
			m_data = nullptr;
		}
	}
public:
	String operator+(const String &s)
	{
		int total_size = strlen(m_data) + strlen(s.m_data) + 1;
		char *new_data = new char[total_size];
		strcpy(new_data, m_data);
		strcat(new_data, s.m_data);

		String tmp;
		delete []tmp.m_data;
		tmp.m_data = new_data;
		return tmp;
	}
	String& operator+=(const String &s);
	bool operator==(const String &s)
	{
		return strcmp(m_data, s.m_data);
	}
	bool operator!=(const String &s);
	bool operator>(const String &s);
	bool operator<=(const String &s);
	bool operator<(const String &s);
	bool operator>=(const String &s);
private:
	char *m_data;
};
ostream& operator<<(ostream &out, const String &s)
{
	out<<s.m_data;
	return out;
}

void main()
{
	String s("Hello");
	String s1(s);   //nullptr  ""
	String s2(" Bit.");

	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;

	String s3 = s1 + s2;   //Hello Bit.
	cout<<"s3 = "<<s3<<endl;
	//s1 += s2;
	//if(s1 == s2)
	//{}
	//else if(s1 > s2)
	//{}
	//else if(s1 < s2)
	//{}
}

/*
class Test
{
public:
	Test(int data = 0) :m_data(data)
	{
		cout<<"Create Test Obj:"<<this<<endl;
	}
	~Test()
	{
		cout<<"Free Test Obj:"<<this<<endl;
	}
public:
	void InitTest(int data = 0)
	{
		m_data = data;
	}
	void DestroyTest()
	{
		m_data = 0;
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
	//Test t(10);   //静态开辟
	Test *p = new Test(100);        //动态开辟--> 构造方法
	cout<<p->GetData()<<endl;
	delete p;

	Test *p1 = new Test[10];  //10
	delete []p1;   //数组空间
}

/*
void Use_Malloc_Free()
{
	Test *p = (Test*)malloc(sizeof(Test));  //只负责申请空间
	p->InitTest();
	
	cout<<p->GetData()<<endl;

	p->DestroyTest();
	free(p);                                //只负责释放空间
}
void Use_New_Delete()
{
	Test *p = new Test;  //1申请空间   2构造对象
	cout<<p->GetData()<<endl;
	delete p;            //1析构对象   2释放空间
}

void main()
{
	Use_Malloc_Free();
	Use_New_Delete();
}


/*
void main()
{
	int *p1 = new int;       //1
	cout<<*p1<<endl;
	int *p2 = new int(1);    //1
	cout<<*p2<<endl;
	int *p3 = new int[10]{1,2,3,4,5,6,7,8,9,10};   //n  C++11

	Test *p4 = new Test;  //1
	cout<<p4->GetData()<<endl;
	Test *p5 = new Test(100);  //1
	cout<<p5->GetData()<<endl;

	Test *p6 = new Test[10];
	cout<<p6[0].GetData()<<endl;

	delete p1;
	delete p2;
	delete []p3;
	delete p4;
	delete p5;
	delete []p6;
}

/*
void main()
{
	int *p1 = (int*)malloc(sizeof(int));       //1
	assert(p1 != nullptr);
	int *p2 = (int*)malloc(sizeof(int) * 10);  //n
	assert(p2 != nullptr);

	Test *p3 = (Test*)malloc(sizeof(Test));    //1
	assert(p3 != nullptr);
	cout<<p3->GetData()<<endl;
	cout<<(*p3).GetData()<<endl;

	Test *p4 = (Test*)malloc(sizeof(Test)*10); //10
	assert(p4 != nullptr);
	cout<<p4[0].GetData()<<endl;

	free(p1);
	free(p2);
	free(p3);
	free(p4);
}
*/