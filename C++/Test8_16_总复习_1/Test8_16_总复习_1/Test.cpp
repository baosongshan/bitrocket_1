#include<iostream>
#include<assert.h>
#include<vld.h>
using namespace std;

class A
{
public:
	virtual void Eat()   = 0;    //定义接口  = NULL;
	virtual void Sleep() = 0;
	virtual void Foot()  = 0;
};

class B : public A
{
public:
	B(const B &b) = delete;
public:
	void Eat()
	{
		cout<<"B::Eat()"<<endl;
	}
};

void main()
{
	A *pa = new B;
	pa->Eat();

}

/*
class Base
{
public:
	virtual void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	virtual void fun(int a)
	{
		cout<<"Base::fun(int)"<<endl;
	}
};

class D : public Base
{
public:
	void fun()
	{
		cout<<"D::fun()"<<endl;
	}
	void fun(int a)
	{
		cout<<"D::fun(int)"<<endl;
	}
	virtual void show()
	{
		cout<<"D::show()"<<endl;
	}
};

void main()
{
	Base base;

	//

	D d;
	Base *pb =  &d;
	pb->fun(1);      //奇迹  A  B  C  D

	//pb->show();
}

/*
class A
{
public:
	int m_a = 100;
};

class B : virtual public A   //虚基类
{
public:
	int m_b = 1;
};

class C:  virtual public A
{
public:
	int m_c = 2;
};

class D : public B, public C
{
public:
	int m_d = 3;
};

void main()
{
	D d;
	d.m_b = 10;
	d.m_c = 20;

	d.C::m_a = 100;
	printf("d.B::m_a = %p\n", &(d.B::m_a));
	printf("d.C::m_a = %p\n", &(d.C::m_a));
	//printf("d.m_a = %p\n", &d.m_a);
}


/*
class Base
{
public:
	Base()
	{
		cout<<"Base::Base()"<<endl;
		this->disp();  //不起作用  
		m_base = new char[50];
	}
	virtual ~Base()  //析构函数的多态
	{
		cout<<"Base::~Base()"<<endl;
		delete []m_base;
	}
public:
	virtual void disp()
	{
		cout << "Hello,base" << endl;
	}
private:
	char *m_base;
};

class D : public Base
{
public:
	D()
	{
		cout<<"D::D()"<<endl;
		m_data = new char[100];
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
		delete []m_data;
	}
public:
	virtual void disp()
	{
		cout << "Hello,D" << endl;
	}
	void show()
	{
		cout<<"D::show()"<<endl;
		m_data[0] = 'A';
	}
private:
	char *m_data;
};

void active(Base *pb)
{
	//D *pd = dynamic_cast<D*>(pb);  //父类到子类的向下转换
	//if(pd != NULL)
	//	pd->show(); //存在不安全的隐患

	pb->show();
}

void main()
{
	D d;
	active(&d);

	Base b;
	active(&b);
}

/*
class A 
{
public:
	virtual ~A() 
	{
		cout << "~A()";
	}
};


class B 
{
public:
	virtual ~B() 
	{
		cout << "~B()";
	}
};
class C : public A, public B 
{
public:
	~C() 
	{
		cout << "~C()";
	}
};

int main() 
{
	C * c = new C;
	
	B * b1 = dynamic_cast<B *>(c);
	
	A * a2 = dynamic_cast<A *>(b1);   //A *a2 = c;

	//B * a2 = (c); 
	
	delete a2;
	
	return 0;
}

/*
class Base
{
public:
	Base()
	{
		cout<<"Base::Base()"<<endl;
		this->disp();  //不起作用  
		m_base = new char[50];
	}
	virtual ~Base()  //析构函数的多态
	{
		cout<<"Base::~Base()"<<endl;
		delete []m_base;
	}
public:
	virtual void disp()
	{
		cout << "Hello,base" << endl;
	}
private:
	char *m_base;
};

class D : public Base
{
public:
	D()
	{
		cout<<"D::D()"<<endl;
		m_data = new char[100];
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
		delete []m_data;
	}
public:
	virtual void disp()
	{
		cout << "Hello,D" << endl;
	}
private:
	char *m_data;
};

void main()
{
	//Base b;
	//D d;   //栈区开辟的空间  系统
	Base *pb = new D;  //动态开辟 动态释放
	delete pb;
}

/*
class base
{
public:
	virtual void disp()
	{
		cout << "Hello,base" << endl;
	}
};
class child1 :public base
{
public:
	void disp()
	{
		cout << "hello,child1" << endl;
	}
};
class child2 :public base
{
public:
	void disp()
	{
		cout << "hello,child2" << endl;
	}
};

void display(base *pb)
{
	pb->disp();
}

int main()
{
	base *pBase = NULL, obj_base;
	obj_base.disp();
	pBase = &obj_base;
	pBase->disp();

	child1 *pchild1 = NULL, obj_child1;
	obj_child1.disp();
	pchild1 = &obj_child1;
	pchild1->disp();

	child2 *pchild2 = NULL, obj_child2;
	obj_child2.disp();
	pchild2 = &obj_child2;
	pchild2->disp();

	pBase = &obj_child1;
	pBase->disp();

	display(&obj_base);
	display(&obj_child1);
	display(&obj_child2);
	return 0;
}


/*
class A
{ 
	virtual void g() 
	{ 
		cout << "A::g" << endl; 
	}
private: 
	virtual void f() 
	{ 
		cout << "A::f" << endl; 
	}
};

class B : public A 
{ 
	void g() 
	{ cout << "B::g" << endl; 
	} 
	virtual void h() 
	{ 
		cout << "B::h" << endl;
	} 
};

typedef void( *Fun )( void );
int main(int argc, char* argv[])
{
	B b; 
	Fun pFun; 
	for(int i = 0 ; i < 3; i++) 
	{ 
		pFun = ( Fun )*( ( int* ) * ( int* )( &b ) + i ); 
		pFun(); 
	}
	return 0;
}


/*
class  CBase
{
public:
	virtual void act1()    { cout << "CBase::act1()! ";    act2(); }
	void act2()        { cout << "CBase::act2()! ";    this->act3(); }
	virtual void act3()    { cout << "CBase::act3()! ";    act4(); }
	virtual void act4()    { cout << "CBase::act4()! ";    act5(); }
	void act5()        { cout << "CBase::act5()! "; }
};

class  CDerive : public  CBase
{
public:
	void act3()    { cout << "CDerive::act3()! ";        act4(); }
	void act4()    { cout << "CDerive::act4()! ";        act5(); }
	void act5()    { cout << "CDerive::act5()! "; }
};

void  main(void)
{
	CBase *pObj1 = new CBase;
	pObj1->act1();
	pObj1->act5();
	cout << endl;

	CBase *pObj2 = new CDerive;
	pObj2->act1();
	pObj2->act5();

	delete pObj1;
	delete pObj2;
}


/*
class A
{
public:
	virtual void sayhello()
	{
		cout << "hello A" << endl;
	}
private:
};

class B: public A
{
public:
	virtual void sayhello()
	{
		cout << "hello B" << endl;
	}
private:
	int a;
	int b;
	int x;
};

void main()
{
	B b;
	memset(&b, 0, sizeof(b));  //?????

	A *pa = &b;
	pa->sayhello();
}

/*
int main()
{
	A *pa = NULL;
	pa->sayhello();

	B *pb = NULL;
	pb->sayhello();
	
	system("pause");
	return 0;
}


/*
class Base
{
public:
	virtual void f()
	{
		this->print(); 
	}
	virtual void print(int i=6)
	{
		cout<<"Base:"<< i*i <<endl;
	}
};

class Derived : public Base
{
public:
	virtual void f()
	{
		this->print();  //
	}
	virtual void print(int i=10)
	{
		cout<<"Derived" << i*i<<endl;
	}
};

void bar(Base* p)
{
	p->print();
	p->f();
}
 
int main()
{
	Base * p = new Base;
	bar(p);

    Derived  * q = new Derived();
    bar(q);
	//q->print();
	//q->f();


	Base * r = (Base *)new Derived();
	bar(r);

	system("pause");
	return 0;
}


/*
class animal
{
protected:
	int age;
public:
	virtual void print_age(void) = 0;
};
class dog : public animal
{
public:
	dog(){ this->age = 2; }
	~dog(){}
	virtual void print_age(void){ cout << "wang. my age=" << this->age << endl; }
};
class cat :public animal
{
public:
	cat(){ this->age = 1; }
	~cat(){}
	virtual void print_age(void){ cout << " Miao,my age= " << this->age << endl; }
};
int main(void)
{
	cat kitty;
	dog jd;

	animal *pa;
	int *p = (int *)(&kitty);
	int *q = (int *)(&jd);

	p[1] = q[1] = 2;
	
	pa = &kitty;
	pa->print_age();
	pa = &jd;
	pa->print_age();
	return 0;
}


/*
class Base
{
public:
	int Bar(char x)
	{
		return (int)(x);
	}
	virtual int Bar(int x)
	{
		return (2 * x);
	}
};
class Derived : public Base
{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return (x / 2);
	}
};
int main(void)
{
	Derived Obj;
	Base *pObj = &Obj;
	printf("%d,", pObj->Bar((char)(100)));  //100
	printf("%d,", pObj->Bar(100));          //50
}


/*
//内存泄漏的检测

int GoodBye()
{
	cout<<"GoodBye."<<endl;
	return 0;
}

void main()
{
	//atexit(GoodBye);
	_onexit(GoodBye);
	//..................
	cout<<"Main End."<<endl;
	return;
}

/*
void main()
{
	// log
	cout<<__FILE__<<endl;
	cout<<__LINE__<<endl;
	cout<<__DATE__<<endl;
	cout<<__TIME__<<endl;
}

/*
int fun(int a, int b)
{
	return a + b;
}
void main()
{
	fun(10, 20);

	int(*pfun)(int, int);
	pfun = fun;

	//(*pfun)(10,20);
	(*(int(*)(int, int))0)(10,20);

}

/*
1、int *(*(*fun)(int*))[10];

2、int (*fun)(int *, int (*)(int *));

3、int (*fun[5])(int *);

4、int (*(*fun)[5])(int *);

5、int (*(*fun)(int *)) [5];

6、int*(*fun(int*))[5]

7、(*(void(*)())0)()

8、int *(*p(int))[3];

/*
class SmallInt
{
public:
	SmallInt(int i = 0);
	//重载插入和抽取运算符
	friend ostream &operator<<(ostream&os, const SmallInt &si);
	friend istream &operator>>(istream &is, SmallInt &si);

	//重载算术运算符
	SmallInt operator+(const SmallInt &si){ return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt &si){ return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt &si){ return SmallInt(val*si.val); }
	SmallInt operator/(const SmallInt &si){ return SmallInt(val / si.val); }
	//重载比较运算符
	bool operator==(const SmallInt &si){ return (val == si.val); }

	SmallInt& operator+=(const SmallInt &si)
	{
		val += si.val;
		
		while (val > 127)
			val -= 256;
		while (val < -128)
			val += 256;
		return *this;
	}
	SmallInt& operator+=(const SmallInt &si)
	{
		SmallInt tmp(val + si.val);
		*this = tmp;
		return *this;
	}
	SmallInt& operator+=(const SmallInt &si)
	{
		*this = *this + si;
		return *this;
	}
private:
	char val;
};

SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}

ostream &operator<<(ostream &os, const SmallInt &si)
{
	os << (int)si.val;
	return os;
}

istream &operator>>(istream &is, SmallInt &si)
{
	int tmp;
	is >> tmp;
	si = SmallInt(tmp);
	return is;
}

void main()
{

}

/*
class A
{
private:
	//…其它成员
	static int object_count;
public:
	A()
	{
		object_count++;
	}
	~A()
	{
		object_count--;
	}
	static int GetObjectCount()
	{
		return object_count;
	}
	virtual void func(int data){ cout << "class A : " << data << endl; }
	void func(char *str){ cout << "class A : " << str << endl; }
};

class B : public A{
	//…其它成员
public:
	void func() { cout << "function in B without parameter!\n"; }
	void func(int data) { cout << "class B : " << data << endl; }
	void func(char *str){ cout << "class B : " << str << endl; }
};

int A::object_count = 0;

void main()
{
  A *pA=new A[3];
  cout<<"There are "<<pA->GetObjectCount()<<" objects"<<endl;
  delete []pA;
  cout<<"There are "<<A::GetObjectCount()<<" objects"<<endl;
}


/*
int main(int argc, char *argv[])
{
	A *pA;
	B b;
	pA = &b;
	pA->func(1);
	pA->func("haha");
	return 0;
}


/*
//sum(n) = 1^2 + 2^2 + ..... n^2
long sum(int n)
{
	if(n == 1)
		return 1;
	else
		return sum(n-1)+n*n;
}

void main()
{
	cout<<sum(5)<<endl;
}

/*
int CalcDigital(char *str)
{
	assert(str != NULL);
	
	int count = 0;
	while(*str != '\0')
	{
		//if(*str>='0' && *str<='9')
		if(isdigit(*str))
			count++;
		str++;
	}
	return count;
}

void main()
{
	char *str = "ol4739ympic2000";
	//char *str = NULL;
	cout<<"count = "<<CalcDigital(str)<<endl;
}
*/