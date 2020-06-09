#include<iostream>
#include<string>
#include<vld.h>
#include<assert.h>
#include<vector>
#include<list>
using namespace std;

void main()
{
	vector<int> iv;
	iv.reserve(100);
	for(size_t i = 0; i<100; ++i)   //0 ~ 141  ==>12
	{
		iv.push_back(i);
		cout<<"capacity = "<<iv.capacity()<<endl;
	}
}


/*
void main()
{
	vector<int> iv;
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.reserve(10);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.reserve(5);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
}

/*
void main()
{
	vector<int> iv;
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.resize(100);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.resize(50);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
}

/*
void main()
{
	vector<int> iv;
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(1);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(2);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(3);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(4);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(4);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> iv3(ar, ar+10);
	for(const auto &e : iv3)
		cout<<e<<" ";
	cout<<endl;

	//vector<int>::iterator it = iv3.begin();  //STL
	auto it = iv3.begin();
	while(it != iv3.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	vector<int> iv;
	vector<int> iv1(10, 5);
	for(const auto &e : iv1)
		cout<<e<<" ";
	cout<<endl;

	vector<int> iv2 = iv1;
	for(const auto &e : iv2)
		cout<<e<<" ";
	cout<<endl;

	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> iv3(ar, ar+10);
	for(const auto &e : iv3)
		cout<<e<<" ";
	cout<<endl;
}

/*
namespace bit
{
	class string
	{
		typedef char* iterator;
		static size_t npos;
		friend ostream& operator<<(ostream &out, const string &s);
	public:
		string(const char *str = "")
		{
			if(str == nullptr)
			{
				_str = new char[1];
				_str[0] = '\0';
				_capacity = _size = 0;
			}
			else
			{
				_capacity = _size = strlen(str);
				_str = new char[_capacity + 1];
				strcpy(_str, str);
			}
		}
		string(const string &s) : _str(nullptr),_capacity(0),_size(0)
		{
			string tmp_str(s._str);
			swap(tmp_str);
		}
		string& operator=(string s)  //临时对象
		{
			swap(s);
			return *this;
		}
		~string()
		{
			if(_str)
			{
				delete []_str;
				_str = nullptr;
				_capacity = _size = 0;
			}
		}
	public:
		iterator begin()const
		{return _str;}
		iterator end()const
		{return _str+_size;}
	public:
		void push_back(char ch)
		{
			if(_size >= _capacity)
				reserve(_capacity * 2);
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
	public:
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char *str)
		{
			int len = strlen(str);     //3+300
			if(_size+len > _capacity)  //5
			{
				reserve((_size+len)*2);
			}
			strcat(_str, str);
			_size += len;
			return *this;
		}
		void append(const char* str)
		{
			*this += str;
		}
		char& operator[](int pos)
		{
			assert(pos>=0 && pos<_size);
			return _str[pos];
		}
	public:
		bool operator<(const string& s)
		{return (strcmp(_str, s._str)<0);}
		bool operator>=(const string& s)
		{return !(*this<s);}

		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);
	public:
		size_t find(char c, size_t pos = 0) const
		{
			for(size_t i=0;  i<_size; ++i)
			{
				if(_str[i] == c)
					return i;
			}
			return npos;
		}
		size_t find(const char* s, size_t pos = 0) const   //模式匹配
		{
			assert(s != nullptr);
			const char *str = _str + pos;
			while(*str != '\0')
			{
				const char *sub = s; 
				const char *cur = str;
				while(*sub!='\0' && *sub == *cur)
				{
					sub++;
					cur++;
				}
				if(*sub == '\0')
				{
					return str - _str;
				}
				else
					str++;
			}
			return npos;
		}
		
		string& insert(size_t pos, char c)
		{
			assert(pos>=0 && pos <=_size);
			if(_size+1 > _capacity)
				reserve(_capacity * 2);
			for(size_t i=_size; i>=pos; --i)
				_str[i+1] = _str[i];
			_str[pos] = c;
			_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str);  //自行完成
		string& erase(size_t pos, size_t len)
		{
			if(pos+len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str+pos, _str+pos+len);
				_size -= len;
			}
			return *this;
		}
	public:
		size_t size()const
		{return _size;}
		size_t length()const
		{return _size;}
		size_t capacity()const
		{return _capacity;}
		bool empty()const
		{return _size == 0;}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		const char* c_str()const
		{return _str;}
	public:
		void swap(string &s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}
	public:
		void resize(size_t n, char c = '\0')
		{
			if(n > _size)
			{
				if(n > _capacity)
				{
					reserve(n*2);
				}
				memset(_str+_size, c, n-_size);
			}
			_size = n;
			_str[n] = '\0';
		}
		void reserve(size_t n = 0)  //realloc
		{
			if(n > _capacity)
			{
				char *new_str = new char[n+1];
				strcpy(new_str, _str);
				delete []_str;
				_str = new_str;
				_capacity = n;
			}
		}
	private:
		char  *_str;  //字符串空间
		size_t _capacity; //容量
		size_t _size; //字符串有效长度  \0
	};

	ostream& operator<<(ostream &out, const string &s)
	{
		out<<s._str;
		return out;
	}

	size_t string::npos = (size_t)(-1);
};

void main()
{
	bit::string str = "abc";
	auto it = str.begin();
	while(it != str.end())
	{
		cout<<*it;   //iterator it ==> char *it,  *it  ++it
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	bit::string str("abc");
	cout<<"str = "<<str<<endl;
	str.insert(1,'x');
	cout<<"str = "<<str<<endl;

}

/*
void main()
{
	bit::string str = "abcdabcdeabcdabcefg";
	bit::string sub = "abcdef";
	size_t index = str.find(sub.c_str());
	cout<<index<<endl;
}

/*
void main()
{
	bit::string url = "http://bitedu.vip/thread-3011.htm";
	size_t index = url.find('v');
	
	if(index != string::npos)
		cout<<"index = "<<index<<endl;
	else
		cout<<"不存在."<<endl;
}

/*
void main()
{
	bit::string str("abc");
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	//str.reserve(20);
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;

	//str.push_back('x');
	//str.clear();
	//strlen(str.c_str());

	//str += "xyz";
	str.append("xyz");

	cout<<"str = "<<str<<endl;
}

/*
void main()
{
	bit::string str("abc");

	bit::string str1("xyz");

	//解耦
	str = str1;

}
*/