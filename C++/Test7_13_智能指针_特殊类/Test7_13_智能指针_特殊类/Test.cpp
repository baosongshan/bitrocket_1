#include<iostream>
#include<vld.h>
#include<string>
#include<memory>
#include<thread>
#include<mutex>
using namespace std;

template<typename T>
class LASingletonTemplateBase
{
private:
	static T* sm_instance;
protected:
	LASingletonTemplateBase()
	{
		assert(sm_instance == 0);
		sm_instance = static_cast<T*>(this);
	}
	virtual ~LASingletonTemplateBase()
	{
		assert(sm_instance != 0);
		sm_instance = 0;
	}

public:
	static T* get_instance_ptr()
	{
		if (sm_instance == 0)
		{
			sm_instance = new T();
		}
		return sm_instance;
	}

	static T& get_instance_ref()
	{
		if (sm_instance == 0)
		{
			sm_instance = new T();
		}
		return *sm_instance;
	}

	static void remove_instance()
	{
		assert(sm_instance);
		if (sm_instance)
		{
			delete sm_instance;
		}
		assert(sm_instance == 0);
	}
};

template<typename T>
T* LASingletonTemplateBase<T>::sm_instance = 0;

class Test
{};

/*
mutex mt;

//懒汉模式
class Test
{
public:
	static Test* CreateInstance()
	{
		if(_instance == nullptr)   //双检机制
		{
			mt.lock();
			if(_instance == nullptr)
			{
				_instance = new Test;
			}
			mt.unlock();
		}
		
		return _instance;
	}
protected:
	Test()
	{
		cout<<"Test::Test()"<<endl;
	}
private:
	static Test *_instance;
};

Test* Test::_instance = nullptr;

void thread_fun()
{
	for(int i=0; i<10; ++i)
	{
		Test *pt = Test::CreateInstance();
		printf("pt = %p\n", pt);
	}
}

void main()
{
	thread t1(thread_fun);
	thread t2(thread_fun);
	
	t1.join();
	t2.join();
}

/*
//饿汉模式
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	// 构造函数私有
	Singleton(){};
	// C++98 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
private:
	static Singleton m_instance;
};
Singleton Singleton::m_instance;  //使用的非常频繁非常多

void main()
{
	//....
	int a = 10;
}

/*
class Test
{
public:
	static Test* CreateInstance()
	{
		if(_instance == nullptr)
		{
			_instance = new Test;
		}
		return _instance;
	}
protected:
	Test()
	{}
private:
	static Test *_instance;
};

Test* Test::_instance = nullptr;

void main()
{
	Test *pt = Test::CreateInstance();
	Test *pt1 = Test::CreateInstance();
	Test *pt2 = Test::CreateInstance();
	Test *pt3 = Test::CreateInstance();
	Test *pt4 = Test::CreateInstance();
	Test *pt5 = Test::CreateInstance();
}

/*
class Test
{
public:
	Test(int data = 0) : m_data(data)
	{}
private:
	int  m_data = 0;
};

void main()
{
	Test t1;
	Test t2;
	Test t3 = t2;
}


/*
#include<boost/noncopyable.hpp>
using namespace boost;

class Base final
{
};

class D : public Base
{};

void main()
{
	D d;
}

/*
class Test : noncopyable
{
public:
	Test(int data = 0) : m_data(data)
	{}
private:
	int  m_data = 0;
};

void main()
{
	Test t(1);
	Test t1;
	Test t2;

	Test t3;
	//t3 = t;
	//Test t4 = t3;
}

/*
class Test
{
public:
	Test(int data = 0) : m_data(data)
	{}
private:
	Test(const Test&);
	Test& operator=(const Test &t);
private:
	int  m_data = 0;
};

void main()
{
	Test t(1);
	Test t1;
	Test t2;

	Test t3;
	t3 = t;
}

/*
//只能在栈上创建对象  方法二
class Test
{
public:
	Test(int data = 0) : m_data(data)
	{}
	Test(const Test &);
private:
	void* operator new(size_t sz);
	void* operator new(size_t sz, int pos);
private:
	int  m_data = 0;
};

void main()
{
	Test t;
	Test *pt = new Test;   //new operator    operator new
}

/*
//只能在栈上创建对象  方法一
class Test
{
public:
	static Test& CreateInstance(int data = 0)
	{
		return Test(data);
	}
private:
	Test(int data = 0) : m_data(data)
	{}
	Test(const Test &);
private:
	int  m_data = 0;
};

void main()
{
	Test &pt = Test::CreateInstance();
	Test *pt = new Test;
}


/*
//只能在堆上创建
class Test
{
public:
	static Test* CreateInstance(int data = 0)
	{
		return new Test(data);
	}
private:
	Test(int data = 0) :m_data(data)
	{}
	Test(const Test &);
private:
	int  m_data = 0;
};

void main()
{
	Test *pt = Test::CreateInstance();
	//Test t = *pt;
}

/*
//#include<boost/smart_ptr.hpp>
//using namespace boost;

struct listNode
{
	int data;
	std::weak_ptr<listNode> prev;
	std::weak_ptr<listNode> next;
	listNode()
	{
		cout<<"listNode::listNode()"<<endl;
	}
	~listNode()
	{
		cout<<"listNode::~listNode()"<<endl;
	}
};

//定制删除器  函数
void Del(listNode *pn)
{
	cout<<"Del pn"<<endl;
	delete []pn;
}

void DelMalloc(int *pn)
{
	cout<<"DelMalloc pn"<<endl;
	delete []pn;
}

void main()
{
	listNode *pa = new listNode[5];
	shared_ptr<listNode> spa(pa, Del);       //delete _px;

	int *ptr = (int*)malloc(sizeof(int)*10);
	shared_ptr<int> spa1(ptr, DelMalloc);
}

/*
struct listNode
{
	int data;
	//shared_ptr<listNode> prev;
	//shared_ptr<listNode> next;

	weak_ptr<listNode> prev;
	weak_ptr<listNode> next;

	~listNode()
	{
		cout<<"listNode::~listNode()"<<endl;
	}
};

void main()
{
	shared_ptr<listNode> node1(new listNode);
	shared_ptr<listNode> node2(new listNode);

	cout<<"node1 use_count = "<<node1.use_count()<<endl;
	cout<<"node2 use_count = "<<node1.use_count()<<endl;

	node1->next = node2;
	node2->prev = node1;

	cout<<"node1 use_count = "<<node1.use_count()<<endl;
	cout<<"node2 use_count = "<<node1.use_count()<<endl;

}
	

/*
template<class T>
class Shared_Ptr
{
public:
	Shared_Ptr(T *_P = 0) : _Ptr(_P), _UseCount((size_t*)new int(1)),_Mutex(new mutex)
	{}
	Shared_Ptr(const Shared_Ptr<T> &_Y) 
		: _Ptr(_Y._Ptr),_UseCount(_Y._UseCount),_Mutex(_Y._Mutex)
	{
		Increment();
	}
	Shared_Ptr<T>& operator=(const Shared_Ptr<T> &_Y)
	{
		if(this != &_Y)
		{
			//释放资源
			Decrement();
			_Ptr = _Y._Ptr;
			_UseCount = _Y._UseCount;
			Increment();
		}
		return *this;
	}
	~Shared_Ptr()
	{
		Decrement();
	}
public:
	T& operator*()const
	{
		return *_Ptr;
	}
	T* operator->()const
	{
		return _Ptr;
	}
	void reset(T *_P = 0)
	{
		if(_Ptr != _P)
			Decrement();
		_Ptr = _P;
		_UseCount = (size_t*)new int(1);
	}
public:
	size_t use_count()const
	{
		return *_UseCount;
	}
	bool unique()const
	{
		return (use_count() == 1);
	}
public:
	void Increment()
	{
		_Mutex->lock();
		++*_UseCount;   //临界区
		_Mutex->unlock();
	}
	void Decrement()
	{
		bool delete_flag = false;
		_Mutex->lock();
		if(--*_UseCount == 0)
		{
			delete _Ptr;
			delete _UseCount;
			delete_flag = true;
		}
		_Mutex->unlock();
		if(delete_flag)
			delete _Mutex;
	}
private:
	T *_Ptr;
	size_t *_UseCount;
	mutex *_Mutex;
};


class Date
{
public:
	Date() : year(0),month(0),day(0)
	{}
public:
	int year;
	int month;
	int day;
};

mutex mt;
void SharePtrFunc(Shared_Ptr<Date>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		Shared_Ptr<Date> copy(sp);
		mt.lock();
		copy->year++;
		copy->month++;
		copy->day++;
		mt.unlock();
	}
}

void main()
{
	Shared_Ptr<Date> sp(new Date);

	const size_t n = 10000000;
	thread t1(SharePtrFunc, sp, n);
	thread t2(SharePtrFunc, sp, n);
	t1.join();
	t2.join();
	cout << sp->year << endl;
	cout << sp->month << endl;
	cout << sp->day << endl;
}

/*
void thread_fun(Shared_Ptr<int> &sp, int n)
{
	for(int i=0; i<n; ++i)
	{
		cout<<"use_count = "<<sp.use_count()<<endl;
		Shared_Ptr<int> copy(sp);
		cout<<"use_count = "<<sp.use_count()<<endl;
	}
	cout<<"use_count = "<<sp.use_count()<<endl;
}



void main()
{
	int n = 2;
	int *p = new int(100);

	Shared_Ptr<int> sp(p);

	thread th1(thread_fun, sp, n);
	thread th2(thread_fun, sp, n);

	cout<<"sp use_count ="<<sp.use_count()<<endl;

	th1.join();
	th2.join();
}

/*
void main()
{
	int *p = new int(100);
	int *q = new int(200);
	int *x = new int(1);
	Shared_Ptr<int> sp(p);
	cout<<"*sp = "<<*sp<<endl;
	cout<<"use_count = "<<sp.use_count()<<endl;
	Shared_Ptr<int> sp1 = sp;
	cout<<"use_count = "<<sp.use_count()<<endl;

	{
		Shared_Ptr<int> sp2 = sp1;
		cout<<"use_count = "<<sp.use_count()<<endl;
	}
	cout<<"use_count = "<<sp.use_count()<<endl;


	Shared_Ptr<int> sp2(q);
	Shared_Ptr<int> sp3(sp2);

	sp2 = sp1;

	sp3.reset(x);
}
*/