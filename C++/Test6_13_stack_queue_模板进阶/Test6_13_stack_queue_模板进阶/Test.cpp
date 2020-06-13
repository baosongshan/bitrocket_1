#include<iostream>
#include<list>
#include<array>
#include<forward_list>
#include<assert.h>
#include<vector>
#include<deque>
#include<queue>
#include<functional>
#include<bitset>
using namespace std;


template<class Type>
class ListNode
{
public:
	//int d = int()
	//char d = char()
	//Test d = Test();
	//零初始化
	ListNode(Type d = Type()) : data(d),next(nullptr)
	{}
private:
	Type data;
	ListNode *next;
};

struct Test
{
	Test():m_a(0),m_b(0)
	{}
	int m_a;
	int m_b;
};

void main()
{
	ListNode<Test> node;
}
/*
void main()
{
	int a = int();   //int()  struct class C++基于对象  Java 完全 int a
}

/*
template<class T1, class T2>
class Data
{
public:
	Data() 
	{
		cout << "Data<T1, T2>" << endl; 
	}
private:
	T1 _d1;
	T2 _d2;
};

template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

void main()
{
	Data<int, double> d1;
	Data<double, int> d2;
}
/*
template<>
class Data<char,char>
{
public:
	Data() 
	{
		cout << "Data<char, char>" << endl; 
	}
private:
	char _d1;
	char _d2;
};

template<>
class Data<int,int>
{
public:
	Data() 
	{
		cout << "Data<int, int>" << endl; 
	}
private:
	int _d1;
	int _d2;
};

void main()
{
	Data<char, char> d1;
	Data<int, int> d2;
	Data<double, double> d3;
	Data<int, double> d4;
}

/*
//模板的偏特化
template<class T>
class Data<T,T>
{
public:
	Data() 
	{
		cout << "Data<T, T>" << endl; 
	}
private:
	T _d1;
	T _d2;
};

void main()
{
	Data<char, char> d1;
	Data<int, int> d2;
	Data<double, double> d3;
	Data<int, double> d4;
}


/*
//泛型函数
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}
//特殊函数  --> 特化
template<>
bool IsEqual<char*>(char* &left, char* &right)
{
	return strcmp(left, right) == 0;
}

void Test()
{
	char *pa = "hello";
	char *pb = "hello";

	char p1[] = "hello";
	char p2[] = "hello";
	if (IsEqual(pa, pb))
		cout <<" p1 == p2"<< endl;
	else
		cout << "p1 != p2" << endl;
}

void main()
{
	int a = 10;
	int b = 10;
	cout<<IsEqual(a, b)<<endl;

	Test();
}


/*
template<class T, size_t N=8>
class seqlist
{
private:
	T base[N];  //常量使用
};

void main()
{
	seqlist<int, 20> lt;
}

/*
namespace bit
{
	//make_heap   push_heap  pop_heap
	template<class T, class Cont=vector<T>, class Compare=less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last):c(first, last)
		{
			int n = c.size();
			int start = n/2 - 1; //找到二叉树的最后一个分支
			while(start >= 0)
			{
				_AdjustDown(start, n);
				start--;
			}
		}
		void push(const T &x)
		{
			c.push_back(x);
			_AdjustUp(c.size()-1);
		}
		void pop()
		{
			std::swap(c[0], c[c.size()-1]);
			c.pop_back();
			_AdjustDown(0, c.size());
		}
		void show_heap()const
		{
			for(int i=0; i<c.size(); ++i)
				cout<<c[i]<<" ";
			cout<<endl;
		}

	protected:
		void _AdjustDown(int start, int n)
		{
			int i = start;
			int j = 2*i + 1;
			while(j < n)
			{
				//if(j+1<n && c[j]<c[j+1])
				if(j+1<n && comp(c[j],c[j+1]))  //less(c[j],c[j+1])
					j++;
				//if(c[i] < c[j])
				if(comp(c[i],c[j]))
				{
					T tmp = c[i];
					c[i] = c[j];
					c[j] = tmp;

					i = j;
					j = 2*i+1;
				}
				else
					break;
			}
		}
		void _AdjustUp(int start)
		{
			int j = start;
			int i = (j-1)/2;
			while(i >= 0)
			{
				//if(c[j] > c[i])
				if(comp(c[j], c[i]))
				{
					T tmp = c[i];
					c[i] = c[j];
					c[j] = tmp;

					j = i;
					i = (j-1)/2;
				}
				else
					break;
			}
		}
	private:
		Cont c;       //容器
		Compare comp; //比较仿函数
	};
};

void main()
{
	//bit::priority_queue<int> pq;
	vector<int> v{3,2,7,60,4,1,9,8,5};
	//bit::priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
	bit::priority_queue<int> pq(v.begin(), v.end());
	pq.show_heap();

	pq.push(15);
	pq.show_heap();

	pq.pop();
	pq.show_heap();
}

/*
namespace bit
{
	//make_heap   push_heap  pop_heap
	template<class T, class Cont=vector<T>, class Compare=less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last):c(first, last)
		{
			make_heap(c.begin(), c.end(), comp);
		}
	public:
		bool empty()const
		{
			return c.size()==0;
		}
		size_t size()const
		{
			return c.size();
		}
		void push(const T &x)
		{
			c.push_back();
			push_heap(c.begin(), c.end(), comp);
		}
		void pop()
		{
			pop_heap(c.begin(), c.end(), comp);
			c.pop_back();
		}
		T top()
		{
			return c.front();
		}
	private:
		Cont c;       //容器
		Compare comp; //比较仿函数
	};
};

void main()
{
	vector<int> v{3,2,7,60,4,1,9,8,5};
	bit::priority_queue<int> pq(v.begin(), v.end());

	//pq.pop();
	//cout<<"front = "<<pq.top()<<endl;


	while(!pq.empty())
	{
		int val = pq.top();
		pq.pop();
		cout<<val<<" 出堆"<<endl;
	}

}

/*
namespace bit
{
	template <class InputIterator, class T>
	ptrdiff_t count(InputIterator first, InputIterator last, const T& value)
	{
		ptrdiff_t ret = 0;
		while (first != last)
		{
			if (*first++ == value) 
				++ret;
		}
		return ret;
	}

	// 统计满足pred条件的元素在[first, last)中的个数
	template <class InputIterator, class Predicate>
	ptrdiff_t count_if(InputIterator first, InputIterator last, Predicate pred)
	{
		ptrdiff_t ret = 0;
		while (first != last) 
		{
			if (pred(*first++))
				++ret;
		}
		return ret;
	}
};

struct IsOdd
{
	bool operator()(int i)
	{ 
		return ((i % 2) == 1);
	}
};


int main()
{
	// 统计10在v1中出现的次数
	vector<int> v1{ 10, 20, 30, 10,30, 20, 10, 10, 20 };
	cout << bit::count(v1.begin(), v1.end(), 10) << endl;
	
	vector<int> v2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,13};
	cout << bit::count_if(v2.begin(), v2.end(), IsOdd()) << endl;
	return 0;
}

/*
void main()
{
	vector<int> v{3,2,7,60,4,1,9,8,5};
	make_heap(v.begin(),v.end(), greater<int>());    //[  )

	auto it = v.end();
	while(it != v.begin())
	{
		//pop_heap(v.begin(), it);
		pop_heap(v.begin(), it, greater<int>());
		it--;
	}
	
	for(auto e : v)
		cout<<e<<" ";
	cout<<endl;
}

/*
namespace bit
{
	template<class _Ty>
	struct plus
	{
		_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
			return (_Left + _Right);
		}
	};

};
//仿函数
void main()
{
	bit::plus<int> pl;   //函数对象
	minus<int> mu;
	cout<<pl(10,20)<<endl;    //pl(10,20);
	cout<<pl.operator()(20,30)<<endl;
	cout<<mu(100, 30)<<endl;
}

/*
void main()
{
	vector<int> v{3,2,7,60,4,1,9,8,5};
	make_heap(v.begin(),v.end(), greater<int>());    //[  )

	auto it = v.end();
	while(it != v.begin())
	{
		//pop_heap(v.begin(), it);
		pop_heap(v.begin(), it, greater<int>());
		it--;
	}
	
	for(auto e : v)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	//1 2
	//priority_queue<int, vector<int>, greater<int>> pq;  //默认大堆
	priority_queue<int> pq;  //默认大堆
	vector<int> v{3,2,7,60,0,4,1,9,8,5};
	for(const auto &e : v)
		pq.push(e);

	cout<<"front = "<<pq.top()<<endl;
}

/*
void main()
{
	deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_front(3);
	dq.pop_back();

	for(const auto &e : dq)
		cout<<e<<" ";
	cout<<endl;
}

/*
namespace bit
{
	template<class T, class Cont=vector<T>>
	class stack
	{
	public:
		stack()
		{}
		void push(const T &x)
		{
			c.push_back(x);
		}
		T& top()
		{
			return c.back();
		}
		void pop()
		{
			c.pop_back();
		}
		bool empty()const
		{
			return c.empty();
		}
	private:
		Cont c;
	};

	template<class T, class Cont=list<T>>
	class queue
	{
	public:
		queue()
		{}
		void push(const T &x)
		{
			c.push_back(x);
		}
		void pop()
		{
			c.pop_front();
		}
		T front()const
		{
			return c.front();
		}
		bool empty()const
		{
			return c.empty();
		}
	private:
		Cont c;
	};
}

void main()
{
	bit::queue<int, vector<int>> Q;
	
	for(int i=1; i<=5; ++i)
		Q.push(i);

	while(!Q.empty())
	{
		int val = Q.front();
		Q.pop();
		cout<<val<<" 出队."<<endl;
	}
	
}

/*
namespace bit
{
	template<class T>
	class stack
	{
	public:
		stack()
		{}
		void push(const T &x)
		{
			c.push_back(x);
		}
		T& top()
		{
			return c.back();
		}
		void pop()
		{
			c.pop_back();
		}
		bool empty()const
		{
			return c.empty();
		}
	private:
		list<T> c;
	};
}

void main()
{
	bit::stack<int> st;
	for(int i=1; i<=5; ++i)
		st.push(i);

	while(!st.empty())
	{
		int val = st.top();
		st.pop();
		cout<<val<<" 出栈."<<endl;
	}
}

/*
namespace bit
{
	template<class T>
	class stack
	{
	public:
		stack()
		{}
		void push(const T &x)
		{
			c.push_back(x);
		}
		T& top()
		{
			return c.back();
		}
		void pop()
		{
			c.pop_back();
		}
		bool empty()const
		{
			return c.empty();
		}
	private:
		vector<T> c;
	};
}

void main()
{
	bit::stack<int> st;
	for(int i=1; i<=5; ++i)
		st.push(i);

	while(!st.empty())
	{
		int val = st.top();
		st.pop();
		cout<<val<<" 出栈."<<endl;
	}
}

/*
namespace bit
{
	template<class T>
	class stack
	{
	public:
		stack(int sz = STACK_DEFAULT_SIZE)
		{
			_capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
			_base = new T[_capacity];
			_top = 0;
		}
		~stack()
		{
			if(_base)
			{
				delete []_base;
				_capacity = _top = 0;
			}
		}
	public:
		void push(const T &x)
		{
			if(_top >= _capacity)
				return;
			_base[_top++] = x;
		}
		void pop()
		{
			if(_top == 0)
				return;
			_top--;
		}
		T& top()const
		{
			assert(_top != 0);
			return _base[_top-1];
		}
		bool empty()const
		{
			return _top == 0;
		}
	private:
		enum{STACK_DEFAULT_SIZE = 8};
		T *_base;
		size_t _capacity;
		size_t _top;
	};
};

void main()
{
	bit::stack<int> st;
	for(int i=1; i<=5; ++i)
		st.push(i);

	while(!st.empty())
	{
		int val = st.top();
		st.pop();
		cout<<val<<" 出栈."<<endl;
	}
}


/*
void main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	//STL 容器
	array<int, 10> ar = {1,2,3,4,5,6,7,8,9,10};

	forward_list<int> lt;
}
*/