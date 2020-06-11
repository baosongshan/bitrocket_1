#include<iostream>
#include<vector>
#include<vld.h>
#include<assert.h>
#include<stack>
#include<queue>
#include<deque>
#include<functional>
using namespace std;

void main()
{
	deque<int> dq;
}

/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
public:
	bool operator<(const Date &dt)const
	{
		return   (_year<dt._year)
			  || (_year==dt._year&&_month<dt._month)
			  || (_year==dt._year&&_month==dt._month&&_day<dt._day); 
	}
public:
	int _year;
	int _month;
	int _day;
};

void main()
{
	priority_queue<Date> pq;
	pq.push(Date(2020,10,1));
	pq.push(Date(2020,5,10));
	pq.push(Date(2019,10,10));

	Date dt = pq.top();
	cout<<dt._year<<"-"<<dt._month<<"-"<<dt._day<<endl;
}

/*
void main()
{
	vector<int> v{3,2,7,6,0,4,1,9,8,5};
	//priority_queue<int, vector<int>, greater<int>> pq;
	priority_queue<int> pq;
	for(const auto &e : v)
		pq.push(e);

	cout<<"top = "<<pq.top()<<endl;
	while(!pq.empty())
	{
		int val = pq.top();
		pq.pop();
		cout<<val<<" 出堆."<<endl;
	}
}

/*
void main()
{
	queue<char> Q;
	Q.push('A');
	Q.push('B');
	Q.push('C');
	Q.push('D');
	Q.push('E');
	Q.push('F');

	//Q.pop();

	cout<<"size = "<<Q.size()<<endl;
	cout<<"front = "<<Q.front()<<endl;
	cout<<"back = "<<Q.back()<<endl;

	while(!Q.empty())
	{
		char val = Q.front();
		Q.pop();
		cout<<val<<" 出队."<<endl;
	}
}

/*
void main()
{
	stack<char> st;
	st.push('A');
	st.push('B');
	st.push('C');
	st.push('D');
	st.push('E');

	//st.pop();

	cout<<"size = "<<st.size()<<endl;
	cout<<"top = "<<st.top()<<endl;

	while(!st.empty())
	{
		char val = st.top();
		st.pop();
		cout<<val<<" 出栈."<<endl;
	}

}

/*
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector() : _start(nullptr),_finish(nullptr), _end_of_storage(nullptr)
		{}
		vector(initializer_list<T> il) : _start(nullptr),_finish(nullptr), _end_of_storage(nullptr)
		{
			reserve(il.size());
			for(auto &e : il)
				push_back(e);
		}
		~vector()
		{
			if(_start)
				delete []_start;
			_start = _finish = _end_of_storage = nullptr;
		}
	public:
		iterator begin()const
		{
			return _start;
		}
		iterator end()const
		{
			return _finish;
		}
	public:
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		bool empty()const
		{
			return _start == _finish;
		}
		T& operator[](int pos)
		{
			assert(pos>=0 && pos<size());
			return _start[pos];
		}
	public:
		void push_back(const T &x)
		{
			insert(end(), x);
		}
		iterator insert(iterator pos, const T &x)
		{
			if(size() >= capacity())
			{
				//扩容
				size_t offset = pos - _start;
				size_t new_capacity = (capacity()==0) ? 1 : capacity()*2;
				reserve(new_capacity);
				//更新失效的pos迭代器
				pos = _start + offset;
			}

			iterator end = _finish;
			while(end > pos)
			{
				*end = *(end-1);
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			iterator p = pos;
			while(p < _finish-1)
			{
				*p = *(p+1);
				p++;
			}
			_finish--;
			return pos;
		}
	public:
		void swap(vector<T> &v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		void resize(size_t n, const T &x = T())
		{
			if(n == size())
				return;
			if(n < size())
			{
				_finish = _start + n;
				return;
			}

			if(n > capacity())
				reserve(n);

			iterator it = _finish;
			_finish = _start + n;
			while(it != _finish)
			{
				*it = x;
				++it;
			}
		}
		void reserve(size_t n)
		{
			if(n > capacity())
			{
				size_t old_sz = size();
				T *new_start = new T[n];
				for(int i=0; i<old_sz; ++i)
					new_start[i] = _start[i];
				delete []_start;
				_start = new_start;
				_finish = _start + old_sz;
				_end_of_storage = _start + n;
			}
		}
	private:
		iterator _start;    
		iterator _finish;
		iterator _end_of_storage;
	};
};

void main()
{
	bit::vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
	for(int i=0; i<iv.size(); ++i)
		cout<<iv[i]<<" ";
	cout<<endl;

	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	//iv.reserve(50);
	iv.resize(20, 8);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	bit::vector<int> iv = {1,2,3};
	bit::vector<int> iv1 = {7,8,9};

	cout<<"iv = ";
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	cout<<"iv1 = ";
	for(const auto &e : iv1)
		cout<<e<<" ";
	cout<<endl;

	iv.swap(iv1);

	cout<<"iv = ";
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	cout<<"iv1 = ";
	for(const auto &e : iv1)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	bit::vector<int> iv;
	for(int i=1; i<=10; ++i)
		iv.push_back(i);

	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;

	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	iv.erase(iv.begin());

	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	iv.erase(iv.end());
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	auto pos = find(iv.begin(), iv.end(), 4);
	iv.erase(pos);
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

}

/*
void main()
{
	bit::vector<int> iv;
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;

	iv.reserve(10);
	iv.insert(iv.begin(), 1);
	iv.insert(iv.begin(), 2);
	iv.insert(iv.begin(), 3);
	iv.insert(iv.begin(), 4);
	iv.push_back(5);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;

	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;
}


/*
int main()
{
	vector<int> v{ 1, 2, 3, 4 };
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}

	for(const auto &e : v)
		cout<<e<<" ";
	cout<<endl;

	return 0;
}

/*
void main()
{
	vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	auto pos = find(iv.begin(), iv.end(), 6);
	if(pos != iv.end())
		cout<<"*pos = "<<*pos<<endl;
	else
		cout<<"要删除的数据不存在."<<endl;

	iv.resize(5);
	cout<<"*pos = "<<*pos<<endl;
}

/*
void main()
{
	vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	auto pos = find(iv.begin(), iv.end(), 6);
	if(pos != iv.end())
		cout<<"*pos = "<<*pos<<endl;
	else
		cout<<"要删除的数据不存在."<<endl;

	iv.reserve(100);

	pos = find(iv.begin(), iv.end(), 6);

	iv.push_back(100);
	
	cout<<"*pos = "<<*pos<<endl;

}

/*
void main()
{
	vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	for(int i=0; i<iv.size(); ++i)
		cout<<iv[i]<<" ";  //[] 不进行越界检测
	cout<<endl;

	for(int i=0; i<iv.size(); ++i)
		cout<<iv.at(i)<<" ";  // 会对边界的访问越界问题进行检测
	cout<<endl;
}

/*
void main()
{
	vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
	vector<int> iv1 = {10, 20, 30, 40, 50};

	iv.swap(iv1);

	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	for(const auto &e : iv1)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;
	iv.push_back(100);
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	//iv.push_front(200);    //push_front 
	iv.insert(iv.begin(), 200); //
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	iv.pop_back();
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	iv.erase(iv.begin());
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	auto pos = find(iv.begin(), iv.end(), 60);
	if(pos != iv.end())
		iv.erase(pos);
	else
		cout<<"要删除的数据不存在."<<endl;
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

}

/*
void main()
{
	vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
	
	auto it = iv.end();
	--it;
	cout<<*it<<endl;

	iv.resize(5);

	it = iv.end();
	--it;
	cout<<*it<<endl;

}


/*
void main()
{
	vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	vector<int>::iterator it = iv.begin();
	while(it != iv.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	vector<int>::reverse_iterator rit = iv.rbegin();
	while(rit != iv.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;

}
*/