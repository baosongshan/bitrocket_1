#include<iostream>
#include"Max.h"
#include<assert.h>
#include<array>
#include<list>  //容器
#include<stack>
#include<string>
#include<functional>
using namespace std;

void main()
{
	int ar[] =  {5,4,3,8,9,0,1,2};
	sort(ar, ar+8);

	list<int> mylist = {5,4,3,8,9,0,1,2};

	for(const auto &e : mylist)
		cout<<e<<"-->";
	cout<<"Over"<<endl;

	mylist.sort(greater<int>());

	for(const auto &e : mylist)
		cout<<e<<"-->";
	cout<<"Over"<<endl;

}

/*
void main()
{
	string str("Hello");
	cout<<str<<endl;
	cout<<"size = "<<str.size()<<endl;
}

/*
void main()
{
	array<int, 10> ar;
	stack<int> st;
	st.push(1);
	st.push(2);

	st.pop();
	cout<<st.top()<<endl;
}

/*
void main()
{
	list<int> mylist;
	for(int i=1; i<=10; ++i)
		mylist.push_back(i);

	for(const auto &e : mylist)
		cout<<e<<"-->";
	cout<<"Over"<<endl;
}

/*
//类 模板
template<typename Type>
class seqlist
{
public:
	seqlist(int sz = SEQLIST_DEFAULT_SIZE)
	{
		capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
		base = new Type[capacity];
		size = 0;
	}
	~seqlist()
	{
		delete []base;
		base = nullptr;
		capacity = size = 0;
	}
public:
	void push_back(const Type &x);
	Type& operator[](int pos)
	{
		assert(pos>=0 && pos<size);
		return base[pos];
	}
	void show_list()const
	{
		for(int i=0; i<size; ++i)
			cout<<base[i]<<" ";
		cout<<endl;
	}
private:
	enum {SEQLIST_DEFAULT_SIZE = 8};
	Type *base;
	int  capacity;
	int  size;
};

template<typename Type>
void seqlist<Type>::push_back(const Type &x)
{
	if(size < capacity)
	{
		base[size++] = x;
	}
}

void main()
{
	seqlist<char> list1;  //char
	seqlist<int>  list2;  //int

	list1.push_back('a');
	list1.push_back('b');
	list1.push_back('c');
	list1.push_back('d');
	//list1.show_list();

	cout<<list1[2]<<endl;

	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);
	//list2.show_list();
}


/*
//类 模板
template<typename Type>
class seqlist
{
public:
	seqlist(int sz = SEQLIST_DEFAULT_SIZE)
	{
		capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
		base = new Type[capacity];
		size = 0;
	}
	~seqlist()
	{
		delete []base;
		base = nullptr;
		capacity = size = 0;
	}
public:
	void push_back(const Type &x)
	{
		if(size < capacity)
		{
			base[size++] = x;
		}
	}
	void show_list()const
	{
		for(int i=0; i<size; ++i)
			cout<<base[i]<<" ";
		cout<<endl;
	}
private:
	enum {SEQLIST_DEFAULT_SIZE = 8};
	Type *base;
	int  capacity;
	int  size;
};

void main()
{
	seqlist<char> list1;  //char
	seqlist<int>  list2;  //int

	list1.push_back('a');
	list1.push_back('b');
	list1.push_back('c');
	list1.push_back('d');
	list1.show_list();

	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);
	list2.show_list();
}

/*
//不支持分离编译  --> 干好干漂亮
//泛化
template<typename Type>
Type Max(Type a, Type b)
{
	return a > b ? a : b;   //int > double
}

//特化
template<>
int Max(int a, int b)
{
	return a > b ? b : a;
}

void main()
{
	cout<<Max('A', 'X')<<endl;
	cout<<Max(20, 10)<<endl;
	cout<<Max(23.23, 25.34)<<endl;
}

/*
template<typename Type1, typename Type2>
Type1 Max(Type1 a, Type2 b)
{
	return a > b ? a : b;   //int > double
}


void main()
{
	cout<<Max('A', 'X')<<endl;
	cout<<Max(20, 10)<<endl;
	cout<<Max(23, 25.34)<<endl;
}


/*
class Student
{
	friend ostream& operator<<(ostream &out, const Student &s);
public:
	Student(char *name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}
public:
	bool operator>(const Student &s)
	{
		return age > s.age;
	}
private:
	char name[10];
	int age;
};

ostream& operator<<(ostream &out, const Student &s)
{
	out<<s.name<<" : "<<s.age<<endl;
	return out;
}

//函数模板
//template<class Type>
template<typename Type>
Type Max(Type a, Type b)
{
	cout<<typeid(Type).name()<<endl;
	return a > b ? a : b;
}

void main()
{
	cout<<Max('A', 'X')<<endl;
	cout<<Max(20, 10)<<endl;
	cout<<Max(23.12, 25.34)<<endl;

	cout<<Max(Student("bss",30), Student("lyy", 250))<<endl;
}

/*
void main()
{
	//cout<<Max(10, (int)11.23)<<endl;
	//cout<<Max((double)10, 11.23)<<endl;
	cout<<Max<int>(10, 11.23)<<endl;
}

/*
//参数类型的推导 推演
void main()
{
	cout<<Max('A', 'X')<<endl;
	cout<<Max(20, 10)<<endl;
	cout<<Max(23.12, 25.34)<<endl;

	cout<<Max(Student("bss",30), Student("lyy", 250))<<endl;
}

/*
//冗余程度较高
int Max(int a, int b)
{
	return a > b ? a : b;
}
char Max(char a, char b)
{
	return a > b ? a : b;
}
double Max(double a, double b)
{
	return a > b ? a : b;
}

void main()
{
	cout<<Max('A', 'X')<<endl;
	cout<<Max(20, 10)<<endl;
	cout<<Max(23.12, 25.34)<<endl;
}
*/