#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<windows.h>
#include<assert.h>
using namespace std;

class Test
{};

int Div(int a, int b)throw(int,char, double,Test) //异常规范 Centos Linux  g++
{
	char ch = 'A';
	double d = 12.34;
	short s = 10;
	if(b == 0)
	{
		//throw Test();   //类型
		throw d;
	}
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
	
	catch(int)//按类型捕获
	{
		cout<<"What<int>?> Div Error By Zero."<<endl;
	}
	catch(char)//按类型捕获
	{
		cout<<"What<char>?> Div Error By Zero."<<endl;
	}
	catch(double &d)
	{
		cout<<"What<double>: "<<d<<endl;
	}
	catch(...)
	{
		cout<<"What<...>?> Div Error By Zero."<<endl;
	}
}


/*
int Div(int a, int b)
{
	//assert(b != 0);
	if(b == 0)
	{
		cout<<"Div Error By Zero."<<endl;
		exit(1);
	}
	return a / b;
}

void  main()
{
	int a = 10;
	int b = 0;

	cout<<Div(a, b)<<endl;
}

/*
int number = 0;
mutex g_lock;

int ThreadProc1()
{
	for (int i = 0; i < 1000; i++)
	{
		unique_lock<mutex> lock(g_lock);  //g_lock.lock()
		++number;
		cout << "thread 1 :" << number << endl;
	}
	return 0;
}
int ThreadProc2()
{
	for (int i = 0; i < 1000; i++)
	{
		unique_lock<mutex> lock(g_lock);
		--number;
		cout << "thread 2 :" << number << endl;
	}
	return 0;
}

int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);

	t1.join();
	t2.join();

	cout << "number:" << number << endl;
	return 0;
}


/*
int number = 0;
mutex g_lock;

int ThreadProc1()
{
	for (int i = 0; i < 1000; i++)
	{
		lock_guard<mutex> lock(g_lock);  //g_lock.lock()
		++number;
		cout << "thread 1 :" << number << endl;
	}
	return 0;
}
int ThreadProc2()
{
	for (int i = 0; i < 1000; i++)
	{
		lock_guard<mutex> lock(g_lock);
		--number;
		cout << "thread 2 :" << number << endl;
	}
	return 0;
}

int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);

	t1.join();
	t2.join();

	cout << "number:" << number << endl;
	return 0;
}

/*
int number = 0;
mutex g_lock;

int ThreadProc1()
{
	for (int i = 0; i < 1000; i++)
	{
		g_lock.lock();
		++number;
		cout << "thread 1 :" << number << endl;
		g_lock.unlock();
	}
	return 0;
}
int ThreadProc2()
{
	for (int i = 0; i < 1000; i++)
	{
		g_lock.lock();
		--number;
		cout << "thread 2 :" << number << endl;
		g_lock.unlock();
	}
	return 0;
}

int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);

	t1.join();
	t2.join();

	cout << "number:" << number << endl;
	return 0;
}

/*
mutex mt;

void thread_fun1(int n)
{
	mt.lock();

	cout<<"This is thread fun1. "<<endl;
	Sleep(3000);
	if(n == 5)
		return;
	cout<<"thread fun1 wake up."<<endl;

	mt.unlock();
}
void thread_fun2(int n)
{
	mt.lock();

	cout<<"This is thread fun2."<<endl;
	Sleep(1000);
	cout<<"thread fun2 wake up."<<endl;

	mt.unlock();
}

void main()
{
	int n = 5;
	thread th1(thread_fun1, n);
	thread th2(thread_fun2, n);

	th1.join();
	th2.join();
	cout<<"Main Thread End."<<endl;
}

/*
atomic_long sum = {0}; //自身会进行互斥操作

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		sum++;
		//a
		//b
		//c
		//.......
	}
}

int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000); //sum++
	thread t2(fun, 10000000); //sum++
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;
	return 0;
}

/*
mutex mt;
unsigned long sum = 0;

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		mt.lock();
		sum++;
		mt.unlock();
	}
}

int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000); //sum++
	thread t2(fun, 10000000); //sum++
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;
	return 0;
}

/*
//互斥量
mutex mt;

void thread_fun1(int n)
{
	mt.lock();

	cout<<"This is thread fun1. "<<endl;
	Sleep(3000);
	cout<<"thread fun1 wake up."<<endl;

	mt.unlock();
}
void thread_fun2(int n)
{
	mt.lock();

	cout<<"This is thread fun2."<<endl;
	Sleep(1000);
	cout<<"thread fun2 wake up."<<endl;

	mt.unlock();
}


void main()
{
	int n = 5;
	thread th1(thread_fun1, n);
	thread th2(thread_fun2, n);

	th1.join();
	th2.join();
	cout<<"Main Thread End."<<endl;
}

/*
void thread_fun1(int n)
{
	mt.lock();
	for(int i=0; i<n; ++i)
	{
		cout<<"This is thread fun1."<<endl;
		Sleep(1000);
	}
	mt.unlock();
}
void thread_fun2(int n)
{
	mt.lock();
	for(int i=0; i<n; ++i)
	{
		cout<<"This is thread fun2."<<endl;
		Sleep(1000);
	}
	mt.unlock();
}


void main()
{
	int n = 5;
	thread th1(thread_fun1, n);
	thread th2(thread_fun2, n);

	th1.join();
	th2.join();
	cout<<"Main Thread End."<<endl;
}

/*
class thread_obj
{
public:
	thread_obj(thread &th) : th_obj(th)
	{}
	~thread_obj()
	{
		if(th_obj.joinable())
		{
			th_obj.join();
		}
	}
public:
	thread_obj(const thread_obj &) = delete;
	thread_obj& operator=(const thread_obj &) = delete;
private:
	thread  &th_obj;
};
////////////////////////////////////////////////////////////
void ThreadFunc() 
{
	cout << "ThreadFunc()" << endl;
}
bool DoSomething(int x) 
{ 
	if(x > 0)
		return true;

	return false;
}
//串行执行
int main()
{
	std::thread t(ThreadFunc);

	//t.detach();

	thread_obj obj(t);   //代理 t
	
	if (!DoSomething(0)) //>0 <0 =0
		return -1;

	//th.join();

	return 0;
}

/*
void ThreadFunc() { cout << "ThreadFunc()" << endl; }
void Test1() { throw 1; }
void Test2()
{
	int* p = new int[10];
	std::thread t(ThreadFunc);
	try
	{
		Test1();
	}
	catch (...)
	{
		delete[] p;
		throw;
	}
	t.join();
}

void main()
{
	Test2();
}

/*
void ThreadFunc() 
{
	cout << "ThreadFunc()" << endl;
}
bool DoSomething() 
{ 
	return false;
}
//串行执行
int main()
{
	std::thread t(ThreadFunc);
	t.join();

	if (!DoSomething())
		return -1;

	return 0;
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
	//this->fun();
	Test t;
	thread th(&(Test::fun), &t);

	th.join();
	th.join();
}

/*
void thread_fun1(int &a)
{
	a += 10;
	cout<<"In thread fun1 x = "<<a<<endl;
}

void thread_fun2(int *a)
{
	*a += 10;
	cout<<"In thread fun2 x = "<<*a<<endl;
}

void thread_fun3(int &a)
{
	a += 10;
	cout<<"In thread fun1 x = "<<a<<endl;
}


void main()
{
	int x = 10;
	int y = 10;
	int z = 10;
	thread th1(thread_fun1, x);

	thread th2(thread_fun2, &y);

	thread th3(thread_fun3, ref(z));
	
	th1.join();
	th2.join();
	th3.join();
	cout<<"In main x = "<<x<<endl;
	cout<<"In main y = "<<y<<endl;
	cout<<"In main z = "<<z<<endl;
}

/*
void thread_fun()
{
	cout<<"This is Child Thread."<<endl;
}

void main()
{
	thread th(thread_fun);

	thread th1 = move(th);

	if(th.joinable())
	{
		cout<<"th OK"<<endl;
		th.join();
	}
	else
	{
		cout<<"th error."<<endl;
		//th1.join();
	}

	if(th1.joinable())
	{
		cout<<"th1 OK"<<endl;
		th1.join();
	}
	else
		cout<<"th1 Error."<<endl;
}

/*
void thread_fun()
{
	cout<<"This is Child Thread."<<endl;
}

struct thread_obj
{
	void operator()()
	{
		cout<<"This is thread obj."<<endl;
	}
};
void thread_fun1()
{
	cout<<"This is thread fun1"<<endl;
}

void main()
{
	thread th(thread_fun);

	thread th1([]{cout<<"Hello Thread."<<endl;});

	thread_obj obj;
	thread th2(obj);

	cout<<"th id = "<<th.get_id()<<endl;
	cout<<"th1 id = "<<th1.get_id()<<endl;
	cout<<"th2 id = "<<th2.get_id()<<endl;

	thread th3;
	th3 = thread(thread_fun1);  //const --> 右值

	th.join();
	th1.join();
	th2.join();
	th3.join();
}

/*
void thread_fun()
{
	cout<<"This is Child Thread."<<endl;
}

void main()
{
	thread th(thread_fun);
	cout<<"th id = "<<th.get_id()<<endl;
	th.detach();
	cout<<"This is Main Thread."<<endl;
	//th.join();
	cout<<"Main End."<<endl;
}
*/