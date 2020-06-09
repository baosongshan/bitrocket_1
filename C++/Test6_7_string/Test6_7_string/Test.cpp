#include<iostream>
#include<string>
#include<vld.h>
using namespace std;

void main()
{
	string str = "abc";
	cout<<"str = "<<str<<endl;
	str.resize(2, '@');
	cout<<"str = "<<str<<endl;

	auto it = str.begin();
	while(it != str.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	string url = "http://bitedu.vip/thread-3011.htm";
	size_t index = url.find('z');
	
	if(index != string::npos)
		cout<<"index = "<<index<<endl;
	else
		cout<<"不存在."<<endl;
}


/*
void main()
{
	string str("abc");
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	str.reserve(20);
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	str.push_back('x');
	str+="yz";
	str += 'a';

	//str.append()
	
	cout<<str[10]<<endl;
	cout<<"str = "<<str<<endl;

}

/*
namespace bit
{
	//浅拷贝
	class string
	{
		friend ostream& operator<<(ostream &out, const string &s);
	public:
		string(const char *str = ""):m_use_count(new int(1))
		{
			if (nullptr == str)
				m_data = new char[1]{'\0'};
			else
			{
				m_data = new char[strlen(str) + 1];
				strcpy(m_data, str);
			}
		}
		string(const string &s):m_data(s.m_data),m_use_count(s.m_use_count)
		{
			//增加引用计数
			increment_ref_count();
		}
		string& operator=(const string &s)
		{
			if(this != &s)
			{
				decrement_ref_count();
				m_data = s.m_data;
				m_use_count = s.m_use_count;
				increment_ref_count();
			}
			return *this;
		}
		~string()
		{
			decrement_ref_count();
		}
	public:
		void increment_ref_count()
		{
			(*m_use_count)++;
		}
		void decrement_ref_count()
		{
			if(--(*m_use_count) == 0)
			{
				//释放数据空间
				delete []m_data;
				m_data = nullptr;

				//释放引用计数空间
				delete m_use_count;
				m_use_count = nullptr;
			}
		}
	public:
		//写时拷贝
		void to_upper()
		{
			char *new_data = new char[strlen(m_data)+1];
			strcpy(new_data, m_data);
			int *new_use_count = new int(1);

			char *pstr = new_data;
			while(*pstr != '\0')
			{
				*pstr -= 32;
				pstr++;
			}

			decrement_ref_count();
			
			m_data = new_data;
			m_use_count = new_use_count;
		}
	private:
		char *m_data;
		//引用计数
		int  *m_use_count;
	};

	ostream& operator<<(ostream &out, const string &s)
	{
		out<<s.m_data;
		return out;
	}
};

void main()
{
	bit::string str("abc"); //独立
	bit::string str1 = str;
	cout<<"str = "<<str<<endl;
	cout<<"str1 = "<<str1<<endl;

	str.to_upper();

	cout<<"str = "<<str<<endl;
	cout<<"str1 = "<<str1<<endl;
}

/*
void main()
{
	bit::string str("abc");
	bit::string str1 = str;
	cout<<"str = "<<str<<endl;
	cout<<"str1 = "<<str1<<endl;

	bit::string str2("xyz");
	bit::string str3(str2);

	str3 = str1;
}

/*
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				_str = new char[1]{'\0'};
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
		}
		string(const string &s)
		{
			_str = new char[strlen(s._str)+1];
			strcpy(_str, s._str);
		}
		string& operator=(const string &s)
		{
			if(this != &s)
			{
				string tmp_str(s);    //临时对象
				swap(_str, tmp_str._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
};

void main()
{
	bit::string str(nullptr);
	bit::string str1("abc");
	bit::string str2("xyz");
	str2 = str1;
}


/*
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				_str = new char[1]{'\0'};
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
		}
		string(const string &s)
		{
			_str = new char[strlen(s._str)+1];
			strcpy(_str, s._str);
		}
		string& operator=(const string &s)
		{
			if(this != &s)
			{
				char *tmp_str = new char[strlen(s._str)+1];  //ERROR
				delete []_str;
				_str = tmp_str;
				strcpy(_str, s._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
};

void main()
{
	bit::string str(nullptr);
	bit::string str1("abc");
	bit::string str2("xyz");
	str2 = str1;
}

/*
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				_str = new char[1]{'\0'};
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
		}
		string(const string &s) : _str(nullptr)
		{
			string tmp_str(s._str);   //临时对象
			swap(_str, tmp_str._str);
		}
		string& operator=(const string &s)
		{
			if(this != &s)
			{
				string tmp_str(s._str);
				swap(_str, tmp_str._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
};

void main()
{
	bit::string str1("abc");
	bit::string str2("xyz");
	str2 = str1;
}

/*
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				_str = new char[1]{'\0'};
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
		}
		string(const string &s)
		{
			_str = new char[strlen(s._str)+1];
			strcpy(_str, s._str);
		}
		string& operator=(const string &s)
		{
			if(this != &s)
			{
				delete []_str;
				_str = new char[strlen(s._str)+1];
				strcpy(_str, s._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
};

void main()
{
	bit::string str(nullptr);
	bit::string str1("abc");
	bit::string str2;
	str2 = str1;
}

/*
void main()
{
	vector<int> iv = {1,2,3,4,5,6};
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;
	reverse(iv.begin(), iv.end());
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	list<int> lt = {1,2,3,4,5,6,7,8,9,10};
	for(const auto &e : lt)
		cout<<e<<" ";
	cout<<endl;
	reverse(lt.begin(), lt.end());
	for(const auto &e : lt)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	string str = "12345678";
	string::iterator pos = str.begin();
	pos++;
	pos++;
	pos++;
	pos++;
	pos++;
	reverse(str.begin(), pos);
	cout<<str<<endl;
}

/*
string addStrings(string num1, string num2)
{
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int i, j, sign = 0;
	i = j = 0;
	int sum = 0;

	string res;

	while (i < num1.size() && j < num2.size())
	{
		sum = (num1[i] - '0') + (num2[j] - '0') + sign;
		if (sum >= 10)
		{
			sum -= 10;
			sign = 1;
		}
		else
			sign = 0;
		res += (sum + '0');
		i++;
		j++;
	}
	while (i < num1.size())
	{
		sum = (num1[i] - '0') + 0 + sign;
		if (sum >= 10)
		{
			sum -= 10;
			sign = 1;
		}
		else
			sign = 0;
		res += (sum + '0');
		i++;
	}

	while (j < num2.size())
	{
		sum = 0 + (num2[j] - '0') + sign;
		if (sum >= 10)
		{
			sum -= 10;
			sign = 1;
		}
		else
			sign = 0;
		res += (sum + '0');
		j++;
	}
	if (sign > 0)
		res += (sign + '0');
	reverse(res.begin(), res.end());
	return res;
}

void main()
{
	string num1 = "6";
	string num2 = "501";
	
	string result = addStrings(num1, num2);
	cout<<result<<endl;
}

/*
int StrToInt(string str)
{
	int len = str.size();
	if (len == 0)
		return 0;
	const char *pstr = str.c_str();
	if (pstr == NULL)
		return 0;
	//123
	int flag = 1; //符号位
	int i = 0;
	if (pstr[i] == '+')
	{
		flag = 1;
		i++;
	}
	else if (pstr[i] == '-')
	{
		flag = -1;
		i++;
	}

	long long result = 0;
	while (pstr[i] != '\0')
	{
		if (pstr[i] >= '0' && pstr[i] <= '9')
		{
			result = result * 10 + pstr[i] - '0';
			//if ((flag > 0 && result > 0x7fffffff) || (flag<0 && result>0x80000000))
			//	return 0;
			i++;
		}
		else
			return 0;
	}

	return (int)flag*result;
}


void main()
{
	string str = "-2147483649";
	cout<<StrToInt(str)<<endl;
}

/*
void main()
{
	char *str = "       1084018041571951";

	int value = atoi(str);

	cout<<"value = "<<value<<endl;
}
*/