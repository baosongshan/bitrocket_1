#include<iostream>
#include<vector>
using namespace std;



template<class Type>
class HashNode
{
public:
	HashNode(Type d = Type()) : data(d), link(nullptr)
	{}
	~HashNode()
	{}
public:
	Type data;
	HashNode *link;
};

template<class Type, size_t _N=13>
class HashTable
{
public:
	HashTable() : _size(0)
	{
		memset(_ht, 0, sizeof(HashNode<Type>*)*_N);
	}
	~HashTable()
	{
		clear();
	}
public:
	void Insert(const Type &x)
	{
		_CheakCapacity();
		int index = Hash(x);
		//头插法
		HashNode<Type>*s = _Buynode(x);
		s->link = _ht[index];
		_ht[index] = s;
		_size++;
	}
	HashNode<Type>* Find(const Type &key)
	{
		int index = Hash(key);
		HashNode<Type> *p = _ht[index];
		while(p!=nullptr && p->data!=key)
			p = p->link;
		return p;
	}
	void Remove(const Type &key)
	{
		HashNode<Type> *p = Find(key);
		if(p == nullptr)
			return;

		if(p->link != nullptr)
		{
			p->data = p->link->data;
			p->link = p->link->link;
			p = p->link;
		}
		else
		{
			int index = Hash(key);
			HashNode<Type> *prev = _ht[index];
			if(prev == p)
				_ht[index] = nullptr;
			else
			{
				while(prev->link != p)
				prev = prev->link;

				prev->link = nullptr;
			}
		}
		delete p;
		_size--;
	}
	void clear()
	{
		for(int i=0; i<_N; ++i)
		{
			HashNode<Type> *p = _ht[i];
			while(p != nullptr)
			{
				_ht[i] = p->link;
				delete p;
				p = _ht[i];
			}
		}
	}
	size_t size()const
	{
		return _size;
	}
public:
	void PrintHash()const
	{
		for(int i=0; i<_N; ++i)
		{
			cout<<i<<" : ";
			HashNode<Type> *p = _ht[i];
			while(p != nullptr)
			{
				cout<<p->data<<"-->";
				p = p->link;
			}
			cout<<"NIL"<<endl;
		}
	}
protected:
	int Hash(const Type &key)
	{
		return key % _N; // 除留余数法
	}
	HashNode<Type>* _Buynode(const Type &x)
	{
		HashNode<Type> *_S = new HashNode<Type>(x);
		return _S;
	}
protected:
	void _CheakCapacity();   //size >= _ht.capacity(); 留作作业交给同学们自行完成
private:
	HashNode<Type>* _ht[_N];  //
	size_t          _size;
};

void main()
{
	vector<int> iv = {1, 3, 14, 27, 40};
	HashTable<int> ht;
	for(auto &e : iv)
		ht.Insert(e);

	cout<<"size = "<<ht.size()<<endl;

	//HashNode<int>* res = ht.Find(270);
	ht.PrintHash();
	cout<<endl;
	ht.Remove(3);
	ht.PrintHash();
	cout<<endl;

	ht.clear();
	ht.PrintHash();

}


/*
//现在有一个用来存放整数的Hash表，Hash表的存储单位称为桶，每个桶能放3个整数，
//当一个桶中要放的元素超过3个时，则要将新的元素存放在溢出桶中，每个溢出桶也能放3个元素，
//多个溢出桶使用链表串起来。此Hash表的基桶数目为素数P，Hash表的hash函数对P取模。代码定义如下：

#define P 7
#define NULL_DATA -1
struct bucket_node	
{
	int data[3];
	struct bucket_node *next;
};
bucket_node hash_table[P];

//现在假设hash_table已经初始化好了，insert_new_element()函数目的是把一个新得值插入hash_table中，
//元素插入成功时，函数返回0，否则返回-1，完成函数。

void Init_bucket_node()
{
	for(int i=0; i<P; ++i)
	{
		for(int j=0; j<3; ++j)
		{
			hash_table[i].data[j] = NULL_DATA;
		}
		hash_table[i].next = nullptr;
	}
}

int Insert_new_element(int new_element)
{
	int index = new_element % P;
	bucket_node* insert_node = &hash_table[index];
	bucket_node *prev_node = nullptr;

	while (insert_node != nullptr)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (insert_node->data[i] == NULL_DATA)
			{
				insert_node->data[i] = new_element;
				return 0;
			}
		}
		prev_node = insert_node;
		insert_node = insert_node->next;
	}
	insert_node = (bucket_node*)malloc(sizeof(bucket_node));
	if(insert_node == nullptr)
		return -1;
	for(int i=0; i<3; ++i)
		insert_node->data[i] = NULL_DATA;
	insert_node->next = nullptr;
	insert_node->data[0] = new_element;

	prev_node->next = insert_node;
	return 0;
}
int main()
{
	Init_bucket_node();
	//int array[] = {15,14,21,87,96,293,35,24,149,19,63,16,103,77,5,153,145,356,51,68,705,453 };
	int array[] = {1,8,15,22,29,36,43,50};
	for(int i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		Insert_new_element(array[i]);
	}
	return 0;
}


/*

int Insert_new_element(int new_element)
{
	int index = new_element % P;
	bucket_node* insert_node = &hash_table[index];

	while (insert_node->next != nullptr)
		insert_node = insert_node->next;

	if (insert_node->data[0] == NULL_DATA)
		insert_node->data[0] = new_element;
	else if (insert_node->data[1] == NULL_DATA)
		insert_node->data[1] = new_element;
	else if (insert_node->data[2] == NULL_DATA)
		insert_node->data[2] = new_element;
	else
	{
		insert_node->next = new bucket_node;
		insert_node->next->data[0] = new_element;
		insert_node->next->data[1] = NULL_DATA;
		insert_node->next->data[2] = NULL_DATA;
		insert_node->next->next = nullptr;
	}
	return 0;
}
*/