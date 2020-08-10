#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_

#include"common.h"

template<class Type>
class SeqList
{
public:
	typedef Type&       reference;
	typedef const Type& const_reference;
public:
	SeqList(int sz = SEQLIST_DEFAULT_SIZE);
	SeqList(const SeqList<Type> &st);
	SeqList& operator=(const SeqList<Type> &st);
	~SeqList();
public:
	bool isfull()const;
	bool isempty()const;
public:
	void push_back(const Type &x);
	void push_front(const Type &x);
	void pop_back();
	void pop_front();
	reference front();
	reference back();
	const_reference back()const;
	const_reference front()const;
	size_t size()const;
	void reverse();
	void clear();
	void sort();
	int find(const Type &key);
	void erase(const Type &key);
public:
	reference operator[](int pos);
	const_reference operator[](int pos)const;
public:
	Symbol GetSymbol()const;
	void SetSymbol(Symbol sym);
protected:
	bool _Inc();
private:
	enum {SEQLIST_DEFAULT_SIZE = 20};
private:
	Type * base;
	size_t capacity;
	size_t len;
};

//////////////////////////////////////////////////////////////////////////////////
//顺序表的实现

template<class Type>
Symbol SeqList<Type>::GetSymbol()const
{
	return base[0];
}
template<class Type>
void SeqList<Type>::SetSymbol(Symbol sym)
{
	base[0] = (Type)sym;
}

template<class Type>
bool SeqList<Type>:: _Inc()
{
	Type *new_base;
	try
	{
		new_base = new Type[capacity * 2 + 1];
	}
	catch (bad_alloc &e)
	{
		cout << "Out Of Memory." << endl;
		return false;
	}

	memset(new_base, 0, sizeof(Type)*(capacity * 2 + 1));
	memcpy(new_base, base, sizeof(Type)*(capacity + 1));
	capacity *= 2;

	delete[]base;
	base = new_base;

	return true;
}

template<class Type>
bool SeqList<Type>::isfull()const
{return len >= capacity;}

template<class Type>
bool SeqList<Type>::isempty()const
{return len == 0;}

template<class Type>
SeqList<Type>::SeqList(int sz)
{
	capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
	base = new Type[capacity + 1]; //第一个空间暂时不存储任何数据
	memset(base, 0, sizeof(Type)*(capacity+1));
	len = 0;
}

template<class Type>
SeqList<Type>::SeqList(const SeqList<Type> &st)
{
	capacity = st.capacity;
	base = new Type[sizeof(Type)*(capacity+1)];
	memset(base, 0, sizeof(Type)*(capacity+1));
	memcpy(base, st.base, sizeof(Type)*(st.len+1));
	len = st.len;
}

template<class Type>
SeqList<Type>& SeqList<Type>::operator=(const SeqList<Type> &st)
{
	if(this != &st)
	{
		if(capacity < st.len)
		{
			Type *new_base = new Type[st.capacity+1];
			delete []base;
			base = new_base;
			capacity = st.capacity;
		}
		memcpy(base, st.base, sizeof(Type)*(st.len+1));
		len = st.len;
	}
	return *this;
}

template<class Type>
SeqList<Type>::~SeqList()
{
	delete []base;
	base = NULL;
	capacity = len = 0;
}

template<class Type>
void SeqList<Type>::push_back(const Type &x)
{
	if(isfull() && !_Inc())
		ERR_EXIT("push_back");
	base[++len] = x;
}
template<class Type>
void SeqList<Type>::push_front(const Type &x)
{
	if(isfull() && !_Inc())
		ERR_EXIT("push_front");
	for(size_t i=len; i>=1; --i)
		base[i+1] = base[i];
	base[1] = x;
	len++;
}

template<class Type>
void SeqList<Type>::pop_back()
{
	if(isempty())
		ERR_EXIT("pop_back");
	len--;
}
template<class Type>
void SeqList<Type>::pop_front()
{
	if(isempty())
		ERR_EXIT("pop_front");
	for(size_t i=1; i<len; ++i)
		base[i] = base[i+1];
	len--;
}

template<class Type>
size_t SeqList<Type>::size()const
{return len;}

template<class Type>
typename SeqList<Type>::reference SeqList<Type>::front()
{
	if(isempty())
		ERR_EXIT("front");
	return base[1];
}
template<class Type>
typename SeqList<Type>::reference SeqList<Type>::back()
{
	if(isempty())
		ERR_EXIT("back");
	return base[len];
}

template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::front()const
{
	if(isempty())
		ERR_EXIT("front");
	return base[1];
}
template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::back()const
{
	if(isempty())
		ERR_EXIT("back");
	return base[len];
}

template<class Type>
typename SeqList<Type>::reference SeqList<Type>::operator[](int pos)
{
	assert(pos>=1 && pos<=len);
	return base[pos];
}

template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::operator[](int pos)const
{
	assert(pos>=1 && pos<=len);
	return base[pos];
}

template<class Type>
void SeqList<Type>::reverse()
{
	if(size() <= 1)
		return;
	size_t start = 1, end = len;
	while(start < end)
	{
		Swap(base[start], base[end]);
		start++;
		end--;
	}
}
template<class Type>
void SeqList<Type>:: clear()
{len = 0;}

template<class Type>
void SeqList<Type>::sort()
{
	if(size() <= 1)
		return;
	for(size_t i=0; i<len; ++i)
	{
		for(size_t j=1; j<=len-i-1; ++j)
		{
			if(base[j] > base[j+1])
				Swap(base[j], base[j+1]);
		}
	}
}

template<class Type>
int SeqList<Type>::find(const Type &key)
{
	for(size_t i=1; i<=len; ++i)
	{
		if(base[i] == key)
			return i;
	}
	return -1;
}

template<class Type>
void SeqList<Type>::erase(const Type &key)
{
	int pos = find(key);
	if(pos == -1)
		return;
	for(size_t i=pos; i<=size; ++i)
		base[i] = base[i+1];
	len--;
}

#endif /* _SEQ_LIST_H_ */