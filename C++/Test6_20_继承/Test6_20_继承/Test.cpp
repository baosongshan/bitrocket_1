#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	int m_a = 1;
};

class B : virtual public A   //虚基类
{
public:
	int m_b = 2; 
};

class C : virtual public A
{
public:
	int m_c = 3;
};

void main()
{
	B b;
}

/*
//C   学习  功能函数
//C++ 学习  

class A
{
public:
	virtual void Eat()
	{
		cout<<"A::Eat()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"A::Sleep()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"A::Foot()"<<endl;
	}
};

class Person : public A
{
public:
	void Eat()
	{
		cout<<"Person::Eat()"<<endl;
	}
	void Sleep()
	{
		cout<<"Person::Sleep()"<<endl;
	}
	void Foot()
	{
		cout<<"Person::Foot()"<<endl;
	}
};

class Dog : public A
{
public:
	void Eat()
	{
		cout<<"Dog::Eat()"<<endl;
	}
	void Sleep()
	{
		cout<<"Dog::Sleep()"<<endl;
	}
	void Foot()
	{
		cout<<"Dog::Foot()"<<endl;
	}
};

class Pig : public A
{
public:
	void Eat()
	{
		cout<<"Pig::Eat()"<<endl;
	}
	void Sleep()
	{
		cout<<"Pig::Sleep()"<<endl;
	}
	void Foot()
	{
		cout<<"Pig::Foot()"<<endl;
	}
};

class Bug : public A
{
public:
	void Eat()
	{
		cout<<"Bug::Eat()"<<endl;
	}
	void Sleep()
	{
		cout<<"Bug::Sleep()"<<endl;
	}
	void Foot()
	{
		cout<<"Bug::Foot()"<<endl;
	}
};

//多态---用相同的接口实现不同的功能
void Active(A *pa)
{
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}

void main()
{
	Person per;
	Dog    dog;
	Pig    pig;
	Bug    bug;

	Active(&per);
	Active(&pig);
	Active(&dog);
	Active(&bug);
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
	void fun()
	{
		cout<<"D::fun()"<<endl;
	}
};

void main()
{
	D d;
	d.fun();

	Base *pb = &d;
	pb->fun();     //多态
}

/*
class A
{
public:
	int m_a = 1;
};

class B : virtual public A   //虚基类
{
public:
	int m_b = 2; 
};

class C : virtual public A
{
public:
	int m_c = 3;
};

class D : public B, public C
{
public:
	int m_d = 4;
};

void main()
{
	D d;
	d.m_d = 40;
	d.m_c = 30;
	d.m_b = 20;

	//d.B::m_a = 100;
	//d.C::m_a = 200;
	//d.m_a = 100;
}

/*
class Test
{
public:
	Test()
	{
		count++;
	}
	int GetCount()const
	{return count;}
private:
	static int count;
};
int Test::count = 0;

class D1 : public Test
{
public:

};
class D2 : public Test
{
public:

};
class D3 : public Test
{
public:

};
class D4 : public Test
{
public:

};

void main()
{
	D1 d1;
	cout<<d1.GetCount()<<endl;
	D2 d2;
	cout<<d1.GetCount()<<endl;
	D3 d3;
	cout<<d1.GetCount()<<endl;
	D4 d4;
	cout<<d1.GetCount()<<endl;
}


/*
class Test
{
public:
	Test()
	{
		count++;
	}
protected:
	int GetObjCount()const
	{return count;}
private:
	static int count;
};
int Test::count = 0;

class D1 : public Test
{
public:
	int GetCount()const
	{
		return GetObjCount();
	}
};
class D2 : public Test
{
public:
	int GetCount()const
	{
		return GetObjCount();
	}
};
class D3 : public Test
{
public:
	int GetCount()const
	{
		return GetObjCount();
	}
};
class D4 : public Test
{
public:
	int GetCount()const
	{
		return GetObjCount();
	}
};

void main()
{
	D1 d1;
	cout<<d1.GetCount()<<endl;
	D2 d2;
	cout<<d1.GetCount()<<endl;
	D3 d3;
	cout<<d1.GetCount()<<endl;
	D4 d4;
	cout<<d1.GetCount()<<endl;
}

/*
class Student;
class Person;
void Display(const Person& p, const Student& s);

class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name = "bss"; // 姓名
};

class Student : public Person
{
	friend void Display(const Person& p, const Student& s);
protected:
	string _stuNum = "zjn"; // 学号
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}

void main()
{
	Person per;
	Student stu;
	Display(per, stu);
}

/*
class Base1;
class D;
ostream& operator<<(ostream &out, const Base1 &b);
ostream& operator<<(ostream &out, const D &d);

class Base1
{
	friend ostream& operator<<(ostream &out, const Base1 &b);
public:
	Base1(int b = 0) : m_b(b)
	{
		cout<<"Base1::Base1()"<<endl;
	}
	~Base1()
	{
		cout<<"Base1::~Base1()"<<endl;
	}
private:
	int m_b = 0;
};

ostream& operator<<(ostream &out, const Base1 &b)
{
	out<<b.m_b;
	return out;
}

class D : public Base1
{
	friend ostream& operator<<(ostream &out, const D &d);
public:
	D(int d = 0) : m_d(d)
	{}
private:
	int m_d = 0;
};

ostream& operator<<(ostream &out, const D &d)
{
	out<<d.m_d;
	return out;
}


void main()
{
	Base1 b(100);
	cout<<"base = "<<b<<endl;

	D d(10);
	cout<<"D = "<<d<<endl;
}

/*
class Base1
{
public:
	Base1()
	{
		cout<<"Base1::Base1()"<<endl;
	}
	~Base1()
	{
		cout<<"Base1::~Base1()"<<endl;
	}
};

class Base2
{
public:
	Base2()
	{
		cout<<"Base2::Base2()"<<endl;
	}
	~Base2()
	{
		cout<<"Base2::~Base2()"<<endl;
	}
};

class Base3
{
public:
	Base3()
	{
		cout<<"Base3::Base3()"<<endl;
	}
	~Base3()
	{
		cout<<"Base3::~Base3()"<<endl;
	}
};

//多继承
//class D : public Base1, Base2, Base3
class D : public Base2, public Base1, public Base3
{
public:
	D():Base1(), Base3(), Base2()
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
private:
	Base3 b3;
	Base1 b1;
	Base2 b2;
	
};

void main()
{
	D d;
}


/*
class Base
{
public:
	Base(int b=0) :m_b(b)
	{
		cout<<"Base::Base()"<<endl;
	}
	Base(const Base &b)
	{
		cout<<"Base::Base(const Base &)"<<endl;
		m_b = b.m_b;
	}
	Base& operator=(const Base &b)
	{
		cout<<"Base::operator=(const Base &)"<<endl;
		m_b = b.m_b;
		return *this;
	}
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
private:
	int m_b;
};
class  D :  public Base  
{
public:
	D(int d = 0):m_d(0)
	{}
	D(const D &d):Base(d)
	{
		m_d = d.m_d;
	}
public:
	//同名隐藏
	void fun()
	{
		cout<<"D::fun()"<<endl;
	}
private:
	int m_d;
};

void main()
{
	D d(100);

	D d1 = d;

	D d2;
	d2 = d1;
}

/*
class Base
{
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	void fun(int a)
	{
		cout<<"Base::fun(int)"<<endl;
	}
private:
	int m_b = 0;
};
class  D :  public Base  
{
public:
	//同名隐藏
	void fun()
	{
		cout<<"D::fun()"<<endl;
	}
	void fun(int a,int b)
	{
		cout<<"D::fun(int a, int b)"<<endl;
	}
	void show()
	{
		cout<<"D::show()"<<endl;
	}
private:
	int m_d = 0;
};

void main()
{
	D d;
	d.fun();
	d.fun(0, 0);
	d.Base::fun(0);
}


/*
void main()
{
	D d;
	Base  *pb = &d;
	pb->fun();
	//d.fun();
}

/*
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // 姓名
	int _age = 18; // 年龄
};

class Teacher : public Person
{
public:
	void show()
	{
		cout<<"Teacher::show()"<<endl;
	}
protected:
	int _jobid; // 工号
};

void main()
{
	Teacher tcher;
	Person per;

	//tcher = per;
	Person *p = &tcher;
	p->Print();
	p->show();
}

/*
class Base
{
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
private:
	int m_b = 0;
};
class  D :  public Base  
{
public:
	void show()
	{
		cout<<"D::show()"<<endl;
	}
private:
	int m_d = 0;
};

void main()
{
	D d;
	Base b;

	//赋值兼容规则 --》很重要  多态
	b = d;  //   left_value = right_value;
	Base *pb = &d;
	Base &rb = d;


	//d = b;
}

/*
class Base
{
public:
	Base()
	{
#ifdef DISPLAY
		cout<<"Base::Base()"<<endl;
#endif
	}
	~Base()
	{
#ifdef DISPLAY
		cout<<"Base::~Base()"<<endl;
#endif
	}
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
protected:
	void list()
	{
		cout<<"Base::list()"<<endl;
	}
protected:
	void CallPrint()
	{
		print();
	}
private:
	void print()
	{
		cout<<"Base::print()"<<endl;
	}
private:
	int m_b = 0;
};

//站在子类角度
class D : private Base   //
{
public:
	D()
	{
#ifdef DISPLAY
		cout<<"D::D()"<<endl;
#endif
	}
	~D()
	{
#ifdef DISPLAY
		cout<<"D::~D()"<<endl;
#endif
	}
	void show()
	{
		cout<<"D::show()"<<endl;
		fun();
		list();
		CallPrint();
		//print();
		//myfun();
	}
private:
	void myfun()
	{
		cout<<"D::myfun()"<<endl;
	}
private:
	int m_d = 0;
};

class C : public D
{
public:
	void you_fun()
	{
		//fun();

	}
};


void main()
{
	D d;   //对象

	//d.fun();
	//d.list();
	//d.print();

}


/*
class Base
{
public:
	void fun()
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
	}
};

void main()
{
	D d;
	d.show();
	d.fun();
}

/*
class Base
{};

//子类          父类
class D : public Base
{};

void main()
{}
*/