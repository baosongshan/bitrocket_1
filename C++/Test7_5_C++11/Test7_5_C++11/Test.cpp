#include<iostream>
#include<vld.h>
#include<algorithm>
#include<functional>
#include<thread>
#include<windows.h>
#include<string>
using namespace std;

#define N 10

void thread_fun(unsigned long id)
{
	Sleep(1000);
	printf("This is [%d] thread\n", id);
}

void main()
{
	thread th[N];
	for(int i=0; i<N; ++i)
	{
		th[i] = thread(thread_fun, i);
	}

	th[0].get_id();

	for(int i=0; i<N; ++i)
		th[i].join();
}

/*
//子线程
void thread_fun(int n)
{
	for(int i=0; i<n; ++i)
	{
		cout<<"This is Child Thread."<<endl;
		Sleep(1000);
	}
}

//主线程
void main()
{
	
	thread th(thread_fun, 4);
	//th.detach();
	cout<<"child id = "<<th.get_id()<<endl;
	for(int i=0; i<10; ++i)
	{
		cout<<"This is Main Thread."<<endl;
	}
	th.join();//阻塞等待
}

/*
struct Student
{
	string name;
	string sex;
	int age;
};

void thread_fun(Student *ps)
{
	cout<<ps->name<<" : "<<ps->sex<<" : "<<ps->age<<endl;
}
void main()
{
	Student stu = {"Bit", "男", 10};
	thread th(thread_fun, &stu);

	th.join();
}

/*
void thread_fun(int n)
{
	for(int i=0; i<n; ++i)
	{
		cout<<"This is Child Thread."<<endl;
		Sleep(1000);
	}
}

void main()
{
	thread th(thread_fun, 4,a,b,c);

	///////////////////////////////////////////////////

	for(int i=0; i<10; ++i)
	{
		cout<<"This is Main Thread."<<endl;
	}

	th.join();
}

/*
class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}
	double operator()(double money, int year) //10000 * 10 * rate
	{
		return money * _rate * year;
	}
private:
	double _rate;
};

void main()
{
	Rate rt(0.2);
	cout<<rt(10000, 10)<<endl;

	double rate = 0.2;
	auto rt1 = [=](double money, int year)->double
	{
		return money * year * rate; 
	};
	cout<<rt1(10000, 10)<<endl;
}

/*
void main()
{
	auto f1 = []{};
	auto f2 = []{};

	cout<<typeid(f1).name()<<endl;
	cout<<typeid(f2).name()<<endl;

	//f1 = f2;
}

/*
void main()
{
	int x = 1;
	int y = 2;
	int z = 3;
	auto fun = [=,&x, m](int a, int b)->int
	{
		x = 100;
		cout<<"In Lambda x = "<<x<<endl;
		return a + b + x + y + z;
	}; //值捕获
	cout<<fun(10,20)<<endl;
	cout<<"x = "<<x<<endl;


}

/*
void main()
{
	auto fun = [](int a, int b)->int{return a + b;};
	auto fun1 = []()->int
	{
		cout<<"Hello Lambda."<<endl;
		return 0;
	};
	//cout<<typeid(fun).name()<<endl;
	cout<<fun(10,20)<<endl;
	fun1();
}

/*
void main()
{
	int array[] = {4,1,8,5,3,7,0,9,2,6};
	int n = sizeof(array) / sizeof(array[0]);
	//sort(array, array+n);
	//sort(array, array+n, greater<int>());
	sort(array, array+n, [](int a, int b)->bool{return (a < b);}); //lambda
}

/*
struct Goods
{
	string _name;
	double _price;

	bool operator>(const Goods &g)const
	{
		return this->_price > g._price;
	}
};
struct less_comp
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price <= gr._price;
	}
};

struct greater_comp
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};


int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };

	//sort(gds, gds + sizeof(gds) / sizeof(gds[0]), greater_comp());
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), greater<Goods>());

	return 0;
}

/*
void main()
{
	[]{};
}

/*
//谓词
template<class _Ty>
struct greater
{
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	
		return (_Left > _Right);
	}
};

void main()
{
	int array[] = {4,1,8,5,3,7,0,9,2,6};
	int n = sizeof(array) / sizeof(array[0]);
	//sort(array, array+n);
	//sort(array, array+n, greater<int>());
	sort(array, array+n, [](int a, int b)->bool{return (a < b);}); //lambda
}

/*
void Fun(int &x)
{
	cout << "lvalue ref" << endl;
}
void Fun(int &&x)
{
	cout << "rvalue ref" << endl;
}
void Fun(const int &x)
{
	cout << "const lvalue ref" << endl;
}
void Fun(const int &&x)
{
	cout << "const rvalue ref" << endl;
}

template<typename T>
void PerfectForward(T &&t)
{
	//Fun(t);
	Fun(forward<T>(t));
}

void main()
{
	int a = 10;
	PerfectForward(a);

	PerfectForward(100); //

	const int b = 20;
	PerfectForward(b);

	PerfectForward(move(b)); //
}

/*
class String
{
	friend ostream& operator<<(ostream &out, const String &s);
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = new char[1]{0};
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)	: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String(String &&s) : _str(s._str) //移动构造
	{
		s._str = nullptr;
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	String operator+(const String& s)  //res = s1 + s2;
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);

		delete []pTemp;

		return strRet;
		//return String(pTemp);
	}
	~String()
	{
		if (_str)
			delete[] _str;
	}
private:
	char* _str;
};

ostream& operator<<(ostream &out, const String &s)
{
	out<<s._str;
	return out;
}
/////////////////////////////////////////////////////////////////////////////////////////
class Person
{
public:
	Person(char* name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
private:
	String _name;
	String _sex;
	int    _age;
};
Person GetTempPerson()
{
	Person p("prety", "male", 18);
	return p;
}

void main()
{
	String s1("Hello ");
	String s2(s1);
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;

	String s3(move(s1));  //move可以将左值强转为右值，从而能够匹配右值引用
	cout<<"s3 = "<<s3<<endl;
	//cout<<"s1 = "<<s1<<endl;
}

/*
void main()
{
	//Person p0("bss","男",20);
	//Person p1(p0);

	Person per(GetTempPerson());
}




/*
void main()
{
	String s1("Hello ");
	String s2("Bit.");
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;

	String s3(move(s1));  //move可以将左值强转为右值，从而能够匹配右值引用
	cout<<"s3 = "<<s3<<endl;
	//cout<<"s1 = "<<s1<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int br[100];
	move(ar, ar+10, br);  //memcpy
}

/*
void main()
{
	String s1("Hello ");
	String s2("Bit.");
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;

	String s3(move(s1));  //move可以将左值强转为右值，从而能够匹配右值引用
	cout<<"s3 = "<<s3<<endl;
	//cout<<"s1 = "<<s1<<endl;
}

/*
void main()
{
	String s1("Hello ");
	String s2("Bit.");
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;

	String res = s1 + s2;
	cout<<"res = "<<res<<endl;

}

/*
void main()
{
	int a = 10;
	int &b = a;

	const int &c = 10;
	const int &d = a;

	int &&e = 10;

	int &&f = a;
}
*/