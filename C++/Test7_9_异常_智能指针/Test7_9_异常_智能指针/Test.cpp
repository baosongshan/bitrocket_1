#include<iostream>
//#include<memory>
#include<vld.h>
using namespace std;

//拥有权的转义问题-->这是智能指针的核心
namespace bit
{
	template<class _Ty>
	class auto_ptr
	{
	public:
		auto_ptr(_Ty *_P=0):_Owns(_P!=0), _Ptr(_P)
		{}
		auto_ptr(const auto_ptr<_Ty> &_Y) : _Owns(_Y._Owns), _Ptr(_Y.release())
		{}
		auto_ptr<_Ty>& operator=(const auto_ptr<_Ty> &_Y)
		{
			//????????????????????????????
		}
		~auto_ptr()
		{
			if(_Owns)
				delete _Ptr;
		}
	public:
		//const auto_ptr<_Ty> *const this
		_Ty* release()const
		{
			((auto_ptr<_Ty> *const)this)->_Owns = false;
			//_Owns = false;
			return _Ptr;
		}
		_Ty& operator*()const
		{
			return *get();
		}
		_Ty* operator->()const
		{
			return get();
		}
		_Ty* get()const
		{
			return _Ptr;
		}
	private:
		bool _Owns;  //拥有权
		_Ty  *_Ptr;  //管理的指针
	};
};
void main()
{
	int *p = new int(10);
	bit::auto_ptr<int> ap(p);
	cout<<"*ap = "<<*ap<<endl;

	//bit::auto_ptr<int> ap1 = ap; //vc auto_ptr
	bit::auto_ptr<int> ap1;
	ap1 = ap; //vc auto_ptr
	cout<<"*ap1 = "<<*ap1<<endl;

	cout<<"*ap = "<<*ap<<endl;    //不需要  藕断丝连
}

/*
class Test
{
public:
	void fun()
	{
		cout<<"This is Test::fun()"<<endl;
	}
};

void main()
{
	int *p = new int(10);
	bit::auto_ptr<int> ap(p);

	cout<<"*ap = "<<*ap<<endl;

	bit::auto_ptr<Test> ap1(new Test);
	ap1->fun();
}

/*
class Test
{
public:
	void fun()
	{
		cout<<"This is Test::fun()"<<endl;
	}
};

void main()
{
	int *p = new int(10); //
	auto_ptr<int> ap(p);  //智能 指针 30%~50% -> 50%  代理机构 代理机制
	cout<<*ap<<endl;

	Test *pt = new Test;
	auto_ptr<Test> ap1(pt); // * ->
	ap1->fun();
}

/*
int Div(int a, int b)throw(int, char, double)  //异常规范
{
	char ch = 'A';
	if(b == 0) // 发生异常
		throw b;
	return a / b;
}

void main()
{
	int *p = new int(10); //
	auto_ptr<int> ap(p);  //智能指针  自动指针
	try
	{
		int result = Div(10,0);
	}
	catch(int)
	{
		cout<<"Error."<<endl;
		return;
	}

	//........................

	//delete p;
}


/*
//栈满异常声明
template<typename T>
class pushOnFull
{ 
private:
	T _value;
public:
	pushOnFull(T i)
	{
		_value=i;
	}
	T value()
	{
		return _value;
	}
	void what()
	{
		cerr<<"栈满，"<<value()<<"未压入栈"<<endl;
	}
};

	//栈空异常声明
template<typename T>
class popOnEmpty
{
public:
	void what()
	{
		cerr<<"栈已空，无法出栈"<<endl;
	}
};

template<typename T>
class Stack
{
private:
	int top;                                    //栈顶指针（下标）
	T *elements;                               //动态建立的数值
	int maxSize;                               //栈最大允纳的元素个数
public:
	Stack(int sz = 20)                 //栈如不指定大小，设为20元素
	{
		maxSize = sz;
		elements = new T[maxSize];
		top = 0;
	}
	~Stack()
	{
		delete[] elements;
		elements = nullptr;
		maxSize = top = 0;
	}
	void Push(const T &data) throw(pushOnFull<T>)
	{
		if(IsFull())
			throw pushOnFull<T>(data);
		elements[top++] = data;
	}
	T Pop() throw(popOnEmpty<T>)
	{
		if(IsEmpty())
			throw popOnEmpty<T>();
		top--;
		return  elements[top];
	}

	T GetElem(int i)
	{
		return elements[i];
	} //返回指定元素
	void MakeEmpty()
	{
		top = 0;
	}                  //清空栈
	bool IsEmpty() const
	{
		return top == 0;
	}          //判栈空
	bool IsFull() const
	{
		return top == maxSize;
	}      //判栈满
	void PrintStack()
	{
		for(int i=top-1; i>=0; --i)
			cout<<elements[i]<<endl;
	}
};

void main()
{
	Stack<int> st(8);
	try
	{
		for(int i=1; i<=8; ++i)
			st.Push(i);

		st.PrintStack();

		for(int i=0; i<9; ++i)
			cout<<st.Pop()<<"出栈."<<endl;
	}
	catch(pushOnFull<int> &e)
	{
		e.what();
	}
	catch(popOnEmpty<int> &e)
	{
		e.what();
	}
}





/*
#define DefaultArraySize 5

template<typename elemType>
class Array
{
private:
	int        size;	
	elemType * ia ;
public:
	explicit Array(int sz=DefaultArraySize)
	{
		size = sz;
		ia=new elemType [size];	
	}
	~ Array()
	{
		delete [] ia;
	}
	elemType & operator[](int ix) const
	{
		//下标运算符[ ]重载
		if(ix<0 || ix>=size)  //下标越界
		{ 
			//增加异常抛出,防止索引值越界
			string eObj="out_of_range error in Array<elemType >::operator[]()";
			//throw out_of_range(eObj);	
			throw range_error(eObj.c_str());
		}
		return  ia[ix];//保留原来[ ]的所有索引方式	
	}
};

void main()
{
	Array<int> ar(10);
	for(int i=0; i<10; ++i)
		ar[i] = i+1;

	try
	{
		for (int i = 0; i <= 10; ++i)
			cout << ar[i] << " ";
		cout << endl;
	}
	catch(out_of_range &e)
	{
		cout<<e.what()<<endl;
	}
	catch(range_error &e)
	{
		cout<<e.what()<<endl;
	}
	

}



/*
void main()
{
	try
	{
		int *ptr = new int[536870910];

		delete []ptr;
	}
	catch(bad_alloc &e)
	{
		cout<<e.what()<<endl;
		//cout<<"bad alloc."<<endl;
	}

}

/*
class Base
{};
class D : public Base
{};
class C : public Base
{};
int Div(int a, int b)throw(int, char, double)  //异常规范
{
	char ch = 'A';
	D d;
	C c;
	if(b == 0) // 发生异常
		throw c;
	return a / b;
}

void  main()
{
	int a = 10;
	int b = 0;
	int result = 0;
	try
	{
		result = Div(a, b);
		cout<<"result = "<<result<<endl;
	}
	catch(int &x)
	{
		cout<<"Div<int> Error By Zero."<<endl;
	}
	catch(char &x)
	{
		cout<<"Div<char> Error By Zero."<<endl;
	}
	catch(D &e)
	{
		cout<<"Div<D> Error By Zero."<<endl;
	}
	catch(Base &e)
	{
		cout<<"Div<Base> Error By Zero."<<endl;
	}
	catch(...)
	{
		cout<<"Div<...> Error By Zero."<<endl;
	}
}

/*
double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	int* array = new int[10];
	try 
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;   //异常再次抛出
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}

/*
int Div(int a, int b)throw(int, char, double)  //异常规范
{
	if(b == 0) // 发生异常
		throw b;
	return a / b;
}

void  main()
{
	int a = 10;
	int b = 0;
	int result = 0;
	try
	{
		result = Div(a, b);
		cout<<"result = "<<result<<endl;
	}
	catch(int &x)
	{
		cout<<"Div Error By Zero."<<endl;
	}
}
*/