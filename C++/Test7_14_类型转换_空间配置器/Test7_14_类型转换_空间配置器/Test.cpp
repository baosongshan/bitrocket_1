#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;


void OutOfMemory()
{
	cout<<"Out Of Memory."<<endl; //delete 
	exit(1);
}

void main()
{
	set_new_handler(OutOfMemory); //用于预防内存不足的情况
	int *ptr = nullptr;
	try
	{
		ptr = new int[536870911]; //空间不足  malloc
	}
	catch(bad_alloc &e)
	{
		cout<<e.what()<<endl;
		return;
	}

	cout<<"new OK"<<endl;
	delete []ptr;
}

/*
namespace bit
{
	template<class T>
	T* _allocate(size_t size, T*)
	{
		T *tmp = (T*)::operator new(size * sizeof(T));
		if(tmp == 0)
		{
			cout<<"out of memory."<<endl;
			exit(1);
		}
		return tmp;
	}

	template<class T>
	void _deallocate(T *buffer)
	{
		::operator delete(buffer);
	}

	template<class T1, class T2>
	void _construct(T1 *p, const T2 &value)
	{
		new(p) T1(value);  //placement new 
	}

	template<class T>
	void _destroy(T *ptr)
	{
		ptr->~T();
	}
	
	//空间配置器
	template<class T>
	class allocator
	{
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef size_t size_type;
	public:
		//申请空间
		pointer allocate(size_type n, const void *hint=0)
		{
			return _allocate(n, (pointer)0);
		}
		//释放空间
		void deallocate(pointer p, size_type n)
		{
			_deallocate(p);
		}
		//构造对象
		void construct(pointer p, const T &value)
		{
			_construct(p, value);
		}
		//析构对象
		void destroy(pointer p)
		{
			_destroy(p);
		}
	};
};

void main()
{
	vector<int, bit::allocator<int> > iv;
	iv.push_back(1);
}


/*
void main()
{
	bit::allocator<int> alloc;
	int *ptr = alloc.allocate(10);
	for(int i=0; i<10; ++i)
		ptr[i] = i+1;

	for(int i=0; i<10; ++i)
		cout<<ptr[i]<<" ";
	cout<<endl;

	alloc.deallocate(ptr, 10);
}


/*
class Base
{
public:
	virtual void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
};

class D : public Base
{
public:
	void show()
	{
		cout<<"D::show()"<<endl;
		m_x = 100;
	}
public:
	int m_x = 0;
};

void Active(Base *pb)
{
	D *ptmp = dynamic_cast<D*>(pb);  //向下转换 //运行时的错误
	
	if(ptmp == nullptr)
		cout<<"dynamic_cast error."<<endl;
	else
		ptmp->show();
}

void main()
{
	//D d;
	Base d;
	Active(&d);
}

/*
void Active(Base *pb)
{
	D *ptmp = (D*)pb;  //运行时的错误
	ptmp->show();
}

void main()
{
	//D d;
	Base d;
	Active(&d);
}

/*
class A
{
private:
	int m_a = 0;
};
class B
{
private:
	int m_b = 1;
};
class C : public A, public B
{
private:
	int m_c = 2;
};
void main()
{
	C c;
	printf("%p, %p, %p\n", &c, static_cast<B*>(&c), reinterpret_cast<B*>(&c));
}

/*
void main()
{
	const int a = 10;
	const int *p = &a;

	cout<<"a = "<<a<<endl;
	int *q = reinterpret_cast<int*>(&a);
	*q = 100;
	cout<<"a = "<<a<<endl;

	volatile int b = 20; //易变性
	int *pb = const_cast<int*>(&b);
}

/*
void main()
{
	int a = 10;
	int b = 20;
	a = b;

	char ch = 'A';
	a = static_cast<int>(ch);

	double d = 12.34;
	a = static_cast<double>(d); //隐示转换

	//int *pi = static_cast<int*>(&ch);  //显示转换
	int *pi = reinterpret_cast<int*>(&ch);  //不相关类型
}

/*
void main()
{
	const int a = 10;
	const int *p = &a;

	cout<<"a = "<<a<<endl;
	int *q = const_cast<int*>(&a);
	*q = 100;
	cout<<"a = "<<a<<endl;

	volatile int b = 20; //易变性
	int *pb = const_cast<int*>(&b);
}

/*
void main()
{
	int a = 10;
	int b = 20;
	a = b;

	char ch = 'A';
	a = static_cast<int>(ch);

	double d = 12.34;
	a = static_cast<double>(d); //隐示转换

	//int *pi = static_cast<int*>(&ch);  //显示转换
	int *pi = (int*)&ch;  //不相关类型
}

/*
class Test
{
public:
	explicit Test(int data = 0) :m_data(data)
	{}
	operator int() //强制类型转换
	{
		return m_data;
	}
private:
	int m_data;
	int m_data1 = 0;
	int m_data2 = 0;
};

void main()
{
	Test t(10);

	t = (Test)20;

	int value = (int)t;
}

/*
int Max(int a, int b)
{
	return a > b ? a : b;
}

void main()
{
	//int *p = (int*)0x0012ff7c;  //地址 整数 -->16进制进行表示
	Max(1,2);
	Max('A','B');
	Max(12.34,23.45);
}

/*
void main()
{
	int a = 10;
	int b = 20;
	a = b;

	char ch = 'A';
	a = ch;

	double d = 12.34;
	a = d; //隐示转换

	int *pi = (int*)&ch;  //显示转换
}

/*
//线程不安全
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

/////////////////////////////////////////////////////////////////////////
//单件模式的模板

class Test
{
public:
	Test()
	{
		cout<<"Test::Test()"<<endl;
	}
	~Test()
	{
		cout<<"Test:~Test()"<<endl;
	}

private:
	int m_data = 0;
};

void main()
{
	Test *pt1 = LASingletonTemplateBase<Test>::get_instance_ptr();
	Test *pt2 = LASingletonTemplateBase<Test>::get_instance_ptr();
	Test *pt3 = LASingletonTemplateBase<Test>::get_instance_ptr();
	Test *pt4 = LASingletonTemplateBase<Test>::get_instance_ptr();
}
*/