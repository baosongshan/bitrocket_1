#include<iostream>
#include<new>
using namespace std;

class Int;
ostream& operator<<(ostream &out, const Int &i);
istream& operator>>(istream &in, Int &i);

class Int
{
	friend ostream& operator<<(ostream &out, const Int &i);
	friend istream& operator>>(istream &in, Int &i);
public:
	Int(int i = 0) : m_i(i)
	{}
	~Int()
	{}
public:
	Int operator++(int)  //后++
	{
		//Int tmp = *this;
		//m_i++;
		//return tmp;

		Int tmp = *this;
		++*this;
		return tmp;
	}
	Int& operator++()
	{
		m_i++;
		return *this;
	}
	Int operator--(int);
	Int& operator--();
public:
	Int operator+(const Int &i)
	{
		return Int(m_i+i.m_i);
	}
	Int operator-(const Int &i)
	{
		return Int(m_i-i.m_i);
	}
	Int operator*(const Int &i);
	Int operator/(const Int &i);
	Int operator%(const Int &i);
public:
	Int& operator+=(const Int &i)
	{
		m_i += i.m_i;
		return *this;
	}
	Int& operator-=(const Int &i);
	Int& operator*=(const Int &i);
	Int& operator/=(const Int &i);
	Int& operator%=(const Int &i);
public:
	Int operator>>(int offset)
	{
		return Int(m_i>>offset);
	}
	Int operator<<(int offset);
	Int& operator>>=(int offset);
	Int& operator<<=(int offset);
public:
	bool operator==(const Int &i)
	{return m_i == i.m_i;}
	bool operator!=(const Int &i)
	{return !(*this==i);}
private:
	int m_i;
};

ostream& operator<<(ostream &out, const Int &i)
{
	cout<<i.m_i;
	return out;
}
istream& operator>>(istream &in, Int &i)
{
	in>>i.m_i;
	return in;
}

void main()
{
	Int a = 2;
	Int v = a++;

	cout<<"a = "<<a<<endl;
	cout<<"v = "<<v<<endl;

}

/*
void main()
{
	Int a = 1;
	Int b = 2;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	if(a != b)
		cout<<"a == b"<<endl;
	else
		cout<<"a != b"<<endl;

	Int v = a + b;
	cout<<"v = "<<v<<endl;

	a += b;
	cout<<"a = "<<a<<endl;
}

/*
//重载为友元函数
class Complex;
Complex operator+(int real, const Complex &c);
ostream& operator<<(ostream &out, const Complex &c);
istream& operator>>(istream &in, Complex &c);

//复数
class Complex
{
	friend Complex operator+(int real, const Complex &c);
	friend ostream& operator<<(ostream &out, const Complex &c);
	friend istream& operator>>(istream &in, Complex &c);
public:
	Complex(int real=0, int imag=0) : m_real(real), m_imag(imag)
	{
		cout<<"Create Complex obj : "<<this<<endl;
	}
	Complex(const Complex &c)
	{
		cout<<"Copy Create Complex obj : "<<this<<endl;
		m_real = c.m_real;
		m_imag = c.m_imag;
	}
	Complex& operator=(const Complex &c)
	{
		cout<<"Assign: "<<this<<" = "<<&c<<endl;
		if(this !=&c)
		{
			m_real = c.m_real;
			m_imag = c.m_imag;
		}
		return *this;
	}
	~Complex()
	{
		cout<<"Free Complex obj : "<<this<<endl;
	}
public:
	void PrintComplex()const
	{
		cout<<"("<<m_real<<","<<m_imag<<")"<<endl;
	}
public:
	//重载为成员方法
	Complex operator+(const Complex &c)
	{
		return Complex (this->m_real+c.m_real, this->m_imag+c.m_imag); //无名临时对象语法
	}
	Complex operator+(int real)
	{
		return Complex(m_real+real, m_imag);
	}
private:
	int m_real;
	int m_imag;
};

Complex operator+(int real, const Complex &c)
{
	return Complex(real+c.m_real, c.m_real);
}

ostream& operator<<(ostream &out, const Complex &c)
{
	out<<"("<<c.m_real<<","<<c.m_imag<<")";
	return out;
}

istream& operator>>(istream &in, Complex &c)
{
	in>>c.m_real>>c.m_imag;
	return in;
}

void main()
{
	Complex c1(1,2);
	Complex c2(3,4);
	cout<<c1<<endl;  //operator<<(cout, c1)==>cout<<endl

	Complex c;
	cin>>c;     //operator>>(cin, c);
	cout<<c<<endl;

	Complex c3 = c1 + c2; //
}

/*
void main()
{
	Complex c1(1,2);
	Complex c2(3,4);

	cout<<"c1 = ";
	c1.PrintComplex();
	cout<<"c2 = ";
	c2.PrintComplex();

	Complex c = c1 + c2; //c1.operator+(c2)==>operator+(&c1, c2)
	Complex c3 = c1 + 10; //(1,2)+10 ==>(11,2);  c1+

	//10+
	Complex c4 = 10 + c1;  //operator+(10, c1);

}

/*
class Test
{
public:
	class my_class   //内部类  //哑成员
	{
	public:
		my_class() :m_x(0),m_y(0)
		{}
	public:
		void my_show()
		{
			cout<<"my_class::show()"<<endl;
		}
	private:
		int m_x;
		int m_y;
	};
public:
	Test(int d = 10) : m_data(d)
	{}
public:
	void SetData(int data)
	{
		m_data = data;
	}
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data = 0;  //缺省值  C++11
};

class Test1
{
public:
	class my_class
	{};
};

void main()
{
	Test::my_class myt;
	myt.my_show();
}

/*
class B;

class A
{
	friend class B;  //友元类
public:
	A(int a=0, int b=0) :m_a(a), m_b(b)
	{}
	void list(B &b)
	{
		b.m_x = 1;
		b.m_y = 2;
	}
private:
	int m_a;
	int m_b;
};

class B
{
public:
	B(int x=0, int y=0) :m_x(x), m_y(y)
	{}
public:
	void fun(A &a)
	{
		a.m_a = 100;
		a.m_b = 200;
	}
	void show(A &a)
	{
		cout<<a.m_a<<":"<<a.m_b<<endl;
	}
private:
	int m_x;
	int m_y;
};

void main()
{
	A a;
	B b;
	b.fun(a);
	b.show(a);

	a.list(b);
}



/*
class Test;
void fun(const Test &t); //声明


class Test
{
	friend void fun(const Test &t);
public:
	Test(int d = 10) : m_data(d)
	{}
public:
	void SetData(int data)
	{
		m_data = data;
	}
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data = 0;  //缺省值  C++11
};

void fun(const Test &t)
{
	int value = t.m_data;
	//int value = t.GetData();
	cout<<"value = "<<value<<endl;
}

void main()
{
	Test t;
	//t.m_data = 100;
	t.SetData(100);
	fun(t);
}

/*
//#define SEQLIST_DEFAULT_SIZE 8

class seqlist
{
public:
	seqlist(int sz = SEQLIST_DEFAULT_SIZE)
	{
		capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE; //8
	}
private:
	//enum {SEQLIST_DEFAULT_SIZE = 8}; //常量
	static const int SEQLIST_DEFAULT_SIZE = 8;
	int *base;
	int capacity;
	int size;
};

void main()
{
	seqlist list(30);
}


/*
class Test
{
public:
	Test(int a) : m_data(a)
	{
		m_count++;
	}
	~Test()
	{
		m_count--;
	}

public:
	int GetCut()const
	{
		//GetCount();
		return m_count;
	}
	static int GetCount()//this
	{
		//GetCut();
		//this->m_data = 0;
		return m_count;
	}
public:
	int m_data; 
	static int m_count;  //
};

int Test::m_count = 0;

void main()
{
	cout<<"Object count = "<<Test::GetCount()<<endl;
	Test t1(1);
	cout<<"Object count = "<<Test::GetCount()<<endl;
	Test t2(2);
	Test t3(3);
	cout<<"Object count = "<<Test::GetCount()<<endl;
	
	{
		Test t4(5);
		cout<<"Object count = "<<Test::GetCount()<<endl;
	}
	cout<<"Object count = "<<Test::GetCount()<<endl;
}

/*
class Test
{
public:
	Test(int a) : m_a(a)
	{}
public:
	int GetData()const
	{
		return m_data;
	}
public:
	int m_a;
	static int m_data; //不属于任何对象，可以被任何对象共享
};

int Test::m_data = 0;

void main()
{
	Test::m_data = 0;  //不需要类的驱动
}

/*
void main()
{
	Test t1(10);
	Test t2(20);
	Test t3(30);

	t1.m_a = 1;
	t1.m_data = 100;

	Test::m_data = 10000;
}


/*
class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}
	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};

int main() 
{
	A aa(1);
	aa.Print();
	return 0;
}

/*
class A
{
public:
	A(int x) : m_x(x)
	{
		cout<<"A::A(int)"<<endl;
	}
private:
	int m_x;
};

class B
{
public:
	B(int y) : m_y(y)
	{
		cout<<"B::B(int)"<<endl;
	}
private:
	int m_y;
};

class C
{
public:
	C(int z) : m_z(z)
	{
		cout<<"C::C(int)"<<endl;
	}
private:
	int m_z;
};


class Test
{
public:
	Test(int a, int b, int c) : m_c(c), m_a(a), m_b(b) 
	{
	}
private:
	B m_b;
	A m_a;
	C m_c;
};

void main()
{
	Test t(10,20,30);
}

/*
class A
{
public:
	A(int x)
	{
		m_x = x;
	}
public:
	int m_x;
};

class Test
{
public:
	Test(int d) : m_data(d), m_a(d),m_ref(d),m_x(100)  //参数列表的初始化
	{
		//m_data = d;   //赋值
		//m_a = d;
		//m_ref = d;
		//m_x(100);
	}
private:
	int m_data;
	const int m_a;
	int &m_ref;
	A    m_x;
};

void main()
{
	Test t(10);
}

/*
class Goods{
public:
	Goods(){
		//m_name = new char[1];
		//m_name[0] ='\0';
		//m_len = 0;
		m_name = nullptr;
		m_len = 0;
	}
	Goods(const char * name) {
		cout << "默认构造函数执行" << endl;
		m_len = strlen(name);
		m_name = new char[m_len + 1];  //new char[m_len+1]
		strcpy(m_name, name);
	}
	Goods(const Goods& obj){
		cout << "拷贝构造函数执行" << endl;
		m_name = new char[obj.m_len + 1];
		strcpy(m_name, obj.m_name);
		m_len = obj.m_len;
	}
	Goods& operator= (const Goods& obj){
		cout << "赋值构造函数执行" << endl;
		if (this != &obj){
			delete[] m_name;
			m_name = nullptr;
			m_len = 0;
		}

		m_name = new char[obj.m_len + 1];
		m_len = obj.m_len;

		strcpy(m_name, obj.m_name);
		return *this;
	}
	~Goods(){
		cout << "析构函数执行" << endl;
		if (m_name != NULL){
			delete[] m_name;
			m_len = 0;
		}
	}
private:
	char * m_name;
	int m_len;
};

void palyBasketball( const Goods& pg3){
	cout << "go play basketball pg3" << endl;
}

int main(){
	Goods g1("basketball");
	Goods g2(g1);//第一种调用机制
	Goods g3 = g1;//第二种调用机制
	Goods g4;
	g4 = g1;//赋值构造函数的调用
	palyBasketball(g3);//第三种调用机制
	return 0;
}
*/