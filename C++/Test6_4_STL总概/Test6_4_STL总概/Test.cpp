#include<iostream>
#include<assert.h>
#include<vector>
#include<list>
#include<array>
using namespace std;

void main()
{
	list<int> lt1;
	list<int> lt2(10, 2);
	for(const auto &e : lt2)
		cout<<e<<" ";
	cout<<endl;

	list<int> lt3 = lt2;
	for(const auto &e : lt3)
		cout<<e<<" ";
	cout<<endl;

	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	list<int> lt4(ar, ar+10);
	for(const auto &e : lt4)
		cout<<e<<" ";
	cout<<endl;
}



/*
namespace bit
{
	template<class _Ty>
	_Ty* _Allocate(size_t _N, _Ty*)
	{
		if (_N < 0)
			_N = 0;
		return ((_Ty *)operator new((size_t)_N * sizeof (_Ty))); 
	}
	template<class _T1, class _T2>
	void _Construct(_T1* _P, const _T2& _V)
	{
		new ((void*)_P) _T1(_V);   //定位new
	}
	template<class _Ty>
	void _Destroy(_Ty* _P)
	{
		_P->~_Ty();
	}

	//空间配置器
	template<class _Ty>
	class myallocator
	{
	public:
		typedef size_t size_type;
		typedef size_t difference_type;
		typedef _Ty*   pointer;
		typedef const _Ty* const_pointer;
		typedef _Ty&       reference;
		typedef const _Ty& const_reference;
		typedef _Ty value_type;
		//申请空间
		pointer allocate(size_type _N, const void *)
		{
			return (_Allocate((difference_type)_N, (pointer)0));
		}
		//以字符大小申请空间
		char* _Charalloc(size_type _N)
		{
			return (_Allocate((difference_type)_N,(char*)0));
		}
		//释放空间
		void deallocate(void* _P, size_type)
		{
			operator delete(_P); //  free
		}
		//构造对象
		void construct(pointer _P, const _Ty& _V)
		{
			_Construct(_P, _V);
		}
		//析构对象
		void destroy(pointer _P)
		{
			_Destroy(_P);
		}
	};
	/////////////////////////////////////////////////////////////////////////////
	//STL 带头结点的双向循环链表
	template<class _Ty, class _A = myallocator<_Ty> >
	class list
	{
	public:
		//类型的萃取
		typedef _Ty        value_type;
		typedef _Ty*       pointer_type;
		typedef _Ty&       reference_value;
		typedef const _Ty* const_pointer_type;
		typedef const _Ty& const_reference_type;
		typedef size_t     size_type;
	public:
		struct _Node;
		typedef _Node* _Nodeptr;
		struct _Node
		{
			_Nodeptr _Next;
			_Nodeptr _Prev;
			_Ty      _Value;
		};

		struct _Acc 
		{
			typedef _Nodeptr& _Nodepref; 
			typedef _Ty&      _Vref;

			static _Nodepref _Next(_Nodeptr _P)
			{return _P->_Next;}
			static _Nodepref _Prev(_Nodeptr _P)
			{return _P->_Prev;}
			static _Vref _Value(_Nodeptr _P)
			{return _P->_Value;}
		};
	public:
		//迭代器类   -- 内部类
		class iterator
		{
		public:
			iterator(_Nodeptr _P) : _Ptr(_P)
			{}
			_Ty& operator*()
			{
				return _Acc::_Value(_Ptr);
			}
			iterator& operator++()
			{
				_Ptr = _Acc::_Next(_Ptr);
				return *this;
			}
			iterator operator++(int)
			{
				iterator tmp = *this;
				++*this;
				return tmp;
			}
			bool operator!=(const iterator &it)
			{return _Ptr != it._Ptr;}
			bool operator==(const iterator &it)
			{return _Ptr == it._Ptr;}

			_Nodeptr _Mynode()
			{
				return _Ptr;
			}
		private:
			_Nodeptr _Ptr;
		};
	public:
		list() : _Head(_Buynode()), _Size(0)
		{}
	public:
		iterator begin()
		{
			return iterator(_Acc::_Next(_Head));
		}
		iterator end()
		{
			return iterator(_Head);
		}
	public:
		void push_back(const _Ty &x)
		{
			insert(end(), x);
		}
		void push_front(const _Ty &x)
		{
			insert(begin(), x);
		}
	public:
		iterator insert(iterator _P, const _Ty& _X = _Ty())  //默认零值
		{
			_Nodeptr _S = _P._Mynode();
			_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
			_S = _Acc::_Prev(_S);
			_Acc::_Next(_Acc::_Prev(_S)) = _S;
			//_Acc::_Value(_S) = _X; //
			allocator.construct(&_Acc::_Value(_S), _X);
			++_Size;
			return (iterator(_S));
		}
	protected:
		_Nodeptr _Buynode(_Nodeptr _Narg=0, _Nodeptr _Parg=0)
		{
			_Nodeptr _S = (_Nodeptr)allocator._Charalloc(sizeof(_Node));
			assert(_S != nullptr);
			_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
			_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
			return _S;
		}
	private:
		//内部类型、函数
		_A       allocator; //空间配置对象 --> 空间配置器
		_Nodeptr _Head;
		size_type _Size;
	};

};

void main()
{
	bit::list<int> mylist;
	mylist.push_back(1);
}

/*
void main()
{
	bit::list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	mylist.push_back(5);
	mylist.push_back(6);

	mylist.push_front(10);

	//迭代器模式
	bit::list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Over."<<endl;
}


/*
void main()
{
	vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
	list<int>   ilist = {1,2,3,4,5,6,7,8,9,10};
	array<int, 10> ia = {1,2,3,4,5,6,7,8,9,10};

	auto it1 = iv.begin();
	while(it1 != iv.end())
	{
		cout<<*it1<<" ";
		++it1;
	}
	cout<<endl;

	list<int>::iterator it2 = ilist.begin();
	while(it2 != ilist.end())
	{
		cout<<*it2<<" ";
		++it2;
	}
	cout<<endl;

	array<int, 10>::iterator it3 = ia.begin();
	while(it3 != ia.end())
	{
		cout<<*it3<<" ";
		++it3;
	}
	cout<<endl;
}
*/