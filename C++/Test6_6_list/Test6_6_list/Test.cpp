#include<iostream>
#include<list>
#include<functional>
#include<string>
using namespace std;
void main()
{
	string str1 = "Hello";
	cout<<str1[6]<<endl;       //[] 不进行越界检查
	cout<<str1.at(0)<<endl;    //进行越界检查
}

/*
void main()
{
	string str1 = "Hello";
	string str2 = "Hello";
	if("abc" == str2)
		cout<<"str1 == str"<<endl;
	else
		cout<<"str1 != str2"<<endl;
}

/*
void main()
{
	string str1 = "Hello";
	string str2 = "Bit.";
	string str = str1 + str2;
	cout<<str<<endl;

	string str3;
	cout<<"input str3 : ";
	//cin>>str3;
	getline(cin, str3);
	cout<<"str3 = "<<str3<<endl;
}

/*
void main()
{
	string str = "http://www.cplusplus.com/reference/list/list/list/";
	size_t start_pos = str.find('w');
	size_t end_pos = str.find('m');
	                           //起始位置    长度
	string tmp_str = str.substr(start_pos, end_pos-start_pos+1);
	cout<<tmp_str<<endl;
}

/*
void main()
{
	string str = "http://www.cplusplus.com/reference/list/list/list/";
	//size_t pos = str.find("refr", 0, 3);
	size_t pos = str.rfind('c');

	if(pos != string::npos)
		cout<<"pos = "<<pos<<endl;
	else
		cout<<"查找的字符不存在."<<endl;
}

/*
int my_strlen(const char *str)
{
	int count = 0;
	while(*str++ != '\0')
		count++;
	return count;
}

void main()
{
	string str("abcxyz");  //C
	cout<<str<<endl;

	cout<<"str length = "<<my_strlen(str.c_str())<<endl;
}

/*
void main()
{
	string str("abcxyz");  //C
	cout<<str<<endl;
	str.push_back('h');
	str.append("k");
	str+="lmn";
	cout<<str<<endl;
}

/*
void main()
{
	string str("abcxyz");  //C
	cout<<str<<endl;

	for(int i=0; i<str.size(); ++i)
		cout<<str[i];
	cout<<endl;

	auto it = str.begin();
	while(it != str.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;

	for(const auto &e : str)
		cout<<e;
	cout<<endl;

	auto rit = str.rbegin();
	while(rit != str.rend())
	{
		cout<<*rit;
		rit++;
	}
	cout<<endl;
}

/*
void fun(int n)
{
	string str;
	str.reserve(100);  //1  效率提升
	for(int i=0; i<n; ++i)
	{
		cout<<"capacity = "<<str.capacity()<<endl;
		str.push_back('a');
	}
}

void main()
{
	fun(100);
}

/*
void main()
{
	string str("abcxyz");
	cout<<"str = "<<str<<endl;
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;	 

	//str.resize(10, '\0'); //重新调整元素的个数
	//str.resize(10,'y'); //重新调整元素的个数
	//str.resize(3, 'y');
	str.resize(20);

	str.reserve(10);

	cout<<"str = "<<str<<endl;
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
}

/*
void main()
{
	string str("abcxyz");
	cout<<"size = "<<str.size()<<endl;
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	
}

/*
void main()
{
	string str1;
	cout<<"str1 = "<<str1<<endl;
	string str2("abcxyz");
	cout<<"str2 = "<<str2<<endl;
	string str3(10, '@');
	cout<<"str3 = "<<str3<<endl;
	string str4(str3);
	cout<<"str4 = "<<str4<<endl;
}

/*
namespace bit
{
	template<class T>
	class list;
	template<class T>
	class ListIterator;

	template<class T>
	class ListNode
	{
		friend class list<T>;
		friend class ListIterator<T>;
	public:
		ListNode(T data = T()) :next(nullptr), prev(nullptr), value(data)
		{}
		~ListNode()
		{}
	private:
		ListNode *next;
		ListNode *prev;
		T         value;
	};

	template<class T>
	class ListIterator
	{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> slef;
	public:
		ListIterator(PNode _P) : _Ptr(_P)
		{}
		PNode Mynode()const
		{
			return _Ptr;
		}
	public:
		T& operator*()const
		{
			return _Ptr->value;
		}
		slef& operator++()
		{
			_Ptr = _Ptr->next;
			return *this;
		}
		slef& operator--()
		{
			_Ptr = _Ptr->prev;
			return *this;
		}
		bool operator!=(const slef &lt)
		{
			return _Ptr != lt._Ptr;
		}
		bool operator==(const slef &lt)
		{
			return _Ptr == lt._Ptr;
		}
	private:
		PNode _Ptr;
	};

	template<class T>
	class list
	{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> iterator;
	public:
		list()
		{
			CreateHead();
		}
		list(int n, const T &v = T())
		{
			CreateHead();
			for(int i=0; i<n; ++i)
				push_back(v);
		}
		template<class _It>
		list(_It first, _It last)
		{
			CreateHead();
			while(first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(initializer_list<T> il)
		{
			CreateHead();
			for(const auto &e : il)
				push_back(e);
		}
		list(list<T> &lt)
		{
			CreateHead();
			list tmp_list(lt.begin(), lt.end());
			swap(tmp_list);
		}
		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
	public:
		void push_back(const T&x)
		{
			insert(end(), x);
		}
		void push_front(const T&x)
		{
			insert(begin(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		void swap(list<T> &lt)
		{
			std::swap(_pHead, lt._pHead);
		}
		void clear()
		{
			erase(begin(), end());
		}
	public:
		iterator begin()
		{
			return iterator(_pHead->next);
		}
		iterator end()
		{
			return iterator(_pHead);
		}
	public:
		iterator insert(iterator pos, const T &x)
		{
			PNode s = new ListNode<T>(x);
			PNode p = pos.Mynode();

			s->next = p;
			s->prev = p->prev;
			s->prev->next = s;
			s->next->prev = s;

			return iterator(s);
		}
		void erase(iterator first, iterator last)
		{
			while(first != last)
			{
				first = erase(first);
			}
		}
		iterator erase(iterator pos)
		{
			PNode p = pos.Mynode();
			PNode q = p->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;

			return iterator(q);
		}
	protected:
		void CreateHead()
		{
			_pHead = new ListNode<T>;
			_pHead->next = _pHead->prev = _pHead;
		}
	private:
		PNode _pHead;
	};
};

void main()
{
	bit::list<int> lt1 = {1,2,3,4,5,};
	
	
	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	///bit::list<int> lt2 = lt1;
	//lt1.erase(lt1.begin());
	//lt1.pop_front();
	//lt1.pop_back();
	lt1.clear();

	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	bit::list<int> lt1 = {1,2,3,4,5,};
	bit::list<int> lt2 = {6,7,8,9,10};
	
	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
	cout<<"lt2 = ";
	for (const auto &e : lt2)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	//lt1.swap(lt2);


	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
	cout<<"lt2 = ";
	for (const auto &e : lt2)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	bit::list<int>  lt1(ar, ar+10);

	auto it = lt.begin();
	while(it != lt.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}


/*
void main()
{
	list<int> lt1{1, 2, 3, 4, 5};
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
	auto it = lt1.begin();
	while(it != lt1.end())
	{
		it = lt1.erase(it);
	}
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	list<int> lt1{1, 2, 3, 4, 5};
	
	auto pos = find(lt1.begin(), lt1.end(), 3);
	cout<<*pos<<endl;
	
	pos = lt1.erase(pos);

	cout<<*pos<<endl;   //迭代器失效

	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	list<int> lt1{1, 2, 3, 4, 5};
	list<int> lt2{10, 9, 8, 7, 6};
	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	lt2.sort();
	cout<<"lt2 = ";
	for (const auto &e : lt2)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	lt1.merge(lt2);  //合并两个有序链表

	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	cout<<"lt2 = ";
	for (const auto &e : lt2)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	list<int> lt1{3, 2, 4, 5, 1};
	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	//lt1.remove(3);
	//lt1.sort();
	lt1.sort(greater<int>());
	
	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	list<int> lt1{1, 2, 3, 4, 5};
	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	lt1.clear();
	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	list<int> lt1{1, 2, 3, 4, 5};
	list<int> lt2{10, 9, 8, 7, 6};

	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	cout<<"lt2 = ";
	for (const auto &e : lt2)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	lt1.swap(lt2);

	cout<<"lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	cout<<"lt2 = ";
	for (const auto &e : lt2)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	list<int> lt1{1, 2, 3, 8, 9, 10};

	auto it = find(lt1.begin(), lt1.end(), 3);
	lt1.erase(it);

	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	list<int> lt1{1, 2, 3, 8, 9, 10};
	cout<<"size = "<<lt1.size()<<endl;
	cout<<"front = "<<lt1.front()<<endl;
	cout<<"back = "<<lt1.back()<<endl;

	lt1.push_front(20);
	lt1.push_back(30);

	lt1.insert(lt1.begin(), 40);
	lt1.insert(lt1.end(), 50);

	auto pos = find(lt1.begin(), lt1.end(), 8);
	lt1.insert(pos, 60);

	if(!lt1.empty())
	{
		for (const auto &e : lt1)   //begin()  end()   ++
			cout << e << " ";
		cout << endl;
	}
	else
	{
		cout<<"list empty."<<endl;
	}
}

/*
void main()
{
	list<int> lt1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//C++11 for
	for(const auto &e : lt1)   //begin()  end()   ++
		cout<<e<<" ";
	cout<<endl;
	//手动定义迭代器
	list<int>::iterator it = lt1.begin();
	while(it != lt1.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;
	//自动推导
	auto it1 = lt1.begin();
	while(it1 != lt1.end())
	{
		cout<<*it1<<" ";
		++it1; //it++
	}
	cout<<endl;
	//反向迭代
	auto it2 = lt1.end();
	--it2;
	while(it2 != lt1.begin())
	{
		cout<<*it2<<" ";
		--it2;
	}
	cout<<*it2;
	cout<<endl;

	//反向迭代器
	list<int>::reverse_iterator rit = lt1.rbegin();
	while(rit != lt1.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}

/*
void main()
{
	list<int> lt1;
	list<int> lt2(10, 5);
	list<int> lt3 = lt2;

	for(const auto &e : lt2)
		cout<<e<<" ";
	cout<<endl;

	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	list<int> lt4(ar, ar+10);
	for(const auto &e : lt4)
		cout<<e<<" ";
	cout<<endl;

	list<int> lt5(lt4.begin(), lt4.end());
	for(const auto &e : lt5)
		cout<<e<<" ";
	cout<<endl;
}
*/