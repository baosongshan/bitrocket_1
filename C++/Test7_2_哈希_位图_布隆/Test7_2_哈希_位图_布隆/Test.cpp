#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<hash_set>
#include<hash_map>
#include<bitset>
using namespace std;


template<size_t _N>
class BitSet
{
	friend ostream& operator<<(ostream &out, BitSet<_N> &bt);
public:
	BitSet() : _bit((_N-1)/32+1), _bitCount(_N)
	{}
public:
	void Set(size_t pos)
	{
		if(pos >= _bitCount)
			return;
		size_t index = pos / 32;  //下标
		size_t offset = pos % 32;
		_bit[index] |= (1<<offset);
	}
	bool Test(size_t pos)
	{
		if(pos >= _bitCount)
			return false;
		size_t index = pos / 32;  //下标
		size_t offset = pos % 32;
		return _bit[index] & (1<<offset);
	}
	size_t size()const
	{
		return _bitCount;
	}
public:

private:
	vector<int> _bit;         //vector _bit(1);
	size_t      _bitCount;
};
ostream& operator<<(ostream &out, BitSet<10> &bt)
{
	for(size_t i=0; i<bt.size(); ++i)
	{
		if(bt.Test(i))
			out<<1;
		else
			out<<0;
	}
	return out;
}

void main()
{
	BitSet<10> bt;
	cout<<bt<<endl;
	bt.Set(2);
	cout<<bt<<endl;

}

/*
void main()
{
	bitset<33> bt;
	cout<<sizeof(bt)<<endl;
}

/*
void main()
{
	bitset<10> bt;
	cout<<bt<<endl;
	bt.set(3);
	
	//bt.set(3, false);
	cout<<bt<<endl;

	cout<<bt.none()<<endl;

	cout<<bt.to_ullong()<<endl;

	bt.flip();
	cout<<bt<<endl;

	cout<<"count = "<<bt.count()<<endl;
	bt.reset();

	bt[1] = 1;

	cout<<bt<<endl;

	cout<<bt.none()<<endl;
	cout<<bt.any()<<endl;
}

/*
void main()
{
	//没顺序
	pair<int, string> v1 = {1,"abc"};
	pair<int, string> v2 = {5,"xyz"};
	pair<int, string> v3 = {3,"lmn"};
	pair<int, string> v4 = {4,"opq"};
	pair<int, string> v5 = {53,"opq"};
	pair<int, string> v6 = {10,"ttyu"};
	hash_map<int, string> unmap;

	cout<<"bucket count = "<<unmap.bucket_count()<<endl;
	for(int i=0; i<unmap.bucket_count(); ++i)
		cout<<i<<" : "<<unmap.bucket_size(i)<<endl;

	//unordered_multimap<int, string> unmap;
	unmap.insert(v1);
	unmap.insert(v2);
	unmap.insert(v3);
	unmap.insert(v4);
	unmap.insert(v5);
	unmap.insert(v6);

	cout<<"bucket count = "<<unmap.bucket_count()<<endl;
	for(int i=0; i<unmap.bucket_count(); ++i)
		cout<<i<<" : "<<unmap.bucket_size(i)<<endl;

	for(auto &e : unmap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	hash_set<int> hset;
	for(int i=1; i<100; i+=3)
		hset.insert(i);

	for(auto &e : hset)
		cout<<e<<" ";
	cout<<endl;

	unordered_set<int> unset;
	for(int i=1; i<100; i+=3)
		unset.insert(i);

	for(auto &e : unset)
		cout<<e<<" ";
	cout<<endl;
}

//map  set  rbtree
/*
void  main()
{
	unordered_set<int> unset;
	for(int i=1; i<100; i+=3)
		unset.insert(i);

	for(auto &e : unset)
		cout<<e<<" ";
	cout<<endl;

}

/*
//size_t bucket_count()const 返回哈希桶中桶的总个数
//size_t bucket_size(size_t n)const 返回n号桶中有效元素的总个数
//size_t bucket(const K& key)

void main()
{
	//没顺序
	pair<int, string> v1 = {1,"abc"};
	pair<int, string> v2 = {5,"xyz"};
	pair<int, string> v3 = {3,"lmn"};
	pair<int, string> v4 = {4,"opq"};
	pair<int, string> v5 = {53,"opq"};
	pair<int, string> v6 = {10,"ttyu"};
	unordered_map<int, string> unmap;

	cout<<"bucket count = "<<unmap.bucket_count()<<endl;
	for(int i=0; i<unmap.bucket_count(); ++i)
		cout<<i<<" : "<<unmap.bucket_size(i)<<endl;

	//unordered_multimap<int, string> unmap;
	unmap.insert(v1);
	unmap.insert(v2);
	unmap.insert(v3);
	unmap.insert(v4);
	unmap.insert(v5);
	unmap.insert(v6);

	cout<<"bucket count = "<<unmap.bucket_count()<<endl;
	for(int i=0; i<unmap.bucket_count(); ++i)
		cout<<i<<" : "<<unmap.bucket_size(i)<<endl;


	cout<<"index : "<<unmap.bucket(1)<<endl;

}

/*
void main()
{
	//没顺序
	pair<int, string> v1 = {1,"abc"};
	pair<int, string> v2 = {5,"xyz"};
	pair<int, string> v3 = {3,"lmn"};
	pair<int, string> v4 = {4,"opq"};
	pair<int, string> v5 = {53,"opq"};
	pair<int, string> v6 = {3,"ttyu"};
	unordered_map<int, string> unmap;
	//unordered_multimap<int, string> unmap;
	unmap.insert(v1);
	unmap.insert(v2);
	unmap.insert(v3);
	unmap.insert(v4);
	unmap.insert(v5);
	unmap.insert(v6);

	for(auto &e : unmap)
		cout<<e.first<<" : "<<e.second<<endl;

	unmap[10] = "ABC";

	cout<<"size = "<<unmap.size()<<endl;

	auto it = unmap.begin();
	while(it != unmap.end())
	{
		cout<<it->first<<" : "<<it->second<<endl;
		++it;
	}

	auto res = unmap.find(53);
	if(res != unmap.end())
		unmap.erase(res);
	else
		cout<<"查找的数据不存在."<<endl;

	it = unmap.begin();
	while(it != unmap.end())
	{
		cout<<it->first<<" : "<<it->second<<endl;
		++it;
	}
}

/*
const int PRIMECOUNT = 28;
const size_t primeList[PRIMECOUNT] =   //素数表
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};

size_t GetNextPrime(size_t prime)
{
	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] > prime)
			return primeList[i];
	}
	return primeList[i];
}

//标记值
enum State{ EMPTY, EXIST, DELETE };

template<class Type>
class HashTable
{
	struct Elem
	{
		//pair<K, V> _val;  //值
		Type  _val;
		State _state;     //状态
	};
public:
	HashTable(size_t capacity = 3) : _ht(capacity), _size(0)
	{
		for (size_t i = 0; i < capacity; ++i)
			_ht[i]._state = EMPTY;
	}
	bool Insert(const Type& val)
	{
		// 检测哈希表底层空间是否充足
		_CheckCapacity();
		size_t hashAddr = HashFunc(val);
		size_t old_hashAddr = hashAddr;
		while (_ht[hashAddr]._state == EXIST) //发生冲突
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val== val)
				return false;
			hashAddr = (hashAddr+1) % (_ht.capacity());
			if (hashAddr == old_hashAddr)
				//hashAddr = 0;
				return false;
		}
		// 插入元素
		_ht[hashAddr]._state = EXIST;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}
	int Find(const Type& key)
	{
		size_t hashAddr = HashFunc(key);
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val == key)
				return hashAddr;
			hashAddr = (hashAddr+1) % (_ht.capacity());
		}
		return -1;
	}
	bool Erase(const Type& key)
	{
		int index = Find(key);
		if (-1 != index)
		{
			_ht[index]._state = DELETE;
			_size--;
			return true;
		}
		return false;
	}
	size_t Size()const
	{
		return _size;
	}

	bool Empty() const
	{
		return _size() == 0;
	}
	void Swap(HashTable<Type>& ht)
	{
		std::swap(_ht, ht._ht);
	}
private:
	size_t HashFunc(const Type& key)
	{
		//return key() % _ht.capacity();   //除留余数法
		return key % _ht.capacity();   //除留余数法
	}
protected:
	void _CheckCapacity()
	{
		if (_size * 10 / _ht.capacity() >= 7) //转换为整数   //0.7
		{
			HashTable<Type> newHt(GetNextPrime(_ht.capacity()));
			//需要重新调整数据
			for (size_t i = 0; i < _ht.capacity(); ++i)
			{
				if (_ht[i]._state == EXIST)
					newHt.Insert(_ht[i]._val);
			}
			Swap(newHt);
		}
	}
private:
	vector<Elem> _ht;
	size_t       _size;
};
/////////////////////////////////////////////////////////////////////

size_t BKDRHash(const char *str)  
{  
    register size_t hash = 0;  
    while (size_t ch = (size_t)*str++)  
    {         
        hash = hash * 131 + ch;        
    }  
    return hash;  
}  

size_t SDBMHash(const char *str)  
{  
    register size_t hash = 0;  
    while (size_t ch = (size_t)*str++)  
    {  
        hash = 65599 * hash + ch;         
        //hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
    }  
    return hash;  
}  

void main()
{
	string str0 = "www.baidu_com";
	string str1 = "www.baidu.com";
	char  *str2 = "www.taobao.com";

	size_t index0 = BKDRHash(str0.c_str());
	size_t index1 = SDBMHash(str0.c_str());

}

/*
class Student
{
public:
	bool operator==(const Student &s)
	{
		return (id==s.id && name==s.name);
	}
	const int operator()()const
	{
		return id;
	}
public:
	int id;
	string name;
};

void main()
{
	vector<int> iv = {1,8,15,22,29,36,43,50};
	HashTable<int> ht(3);

	for(auto &e : iv)
		ht.Insert(e);

	ht.Erase(29);

	ht.Insert(50);


}

/*
void main()
{
	Student stu[] = {{1,"abc"}, {8,"xyz"}};
	HashTable<Student> ht(7);
	ht.Insert(stu[0]);
	ht.Insert(stu[1]);

}

/*
void main()
{
	vector<int> iv = {1,8,15,22,29,36,43,50};
	HashTable<int> ht(3);

	for(auto &e : iv)
		ht.Insert(e);

	ht.Erase(29);

	ht.Insert(50);


}
*/