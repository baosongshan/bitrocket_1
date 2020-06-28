#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<functional>
using namespace std;

#include<iostream>
using namespace std;


typedef enum{RED, BLACK} Color_Type;

template<class Type>
class RBTree;

template<class Type>
class rb_iterator;

template<class Type>
class RBTreeNode
{
	friend class RBTree<Type>;
	friend class rb_iterator<Type>;
public:
	RBTreeNode(Type d=Type(), RBTreeNode<Type>*left=nullptr, RBTreeNode<Type>*right=nullptr):
		data(d),leftChild(left),rightChild(right),parent(nullptr),color(RED)
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode<Type> *leftChild;
	RBTreeNode<Type> *rightChild;
	RBTreeNode<Type> *parent;
	Color_Type        color;
};

template<class Type>
class rb_iterator
{
	typedef rb_iterator<Type> self; 
public:
	rb_iterator(RBTreeNode<Type> *p, RBTreeNode<Type> *nil)
		: node(p), NIL(nil)
	{}
public:
	self& operator--();
	self  operator--(int);
	self operator++(int);
	self& operator++()
	{
		if(node->rightChild != NIL)
		{
			node = node->rightChild;
			while(node->leftChild != NIL)
				node = node->leftChild;
		}
		else
		{
			RBTreeNode<Type> *p = node->parent;
			while(node == p->rightChild)
			{
				node = p;
				p = node->parent;
			}
			node = p;
		}
		return *this;
	}
public:
	Type& operator*()const
	{
		return node->data;
	}
	Type* operator->()const
	{
		return &(node->data);
	}
	bool operator!=(const self &it)const
	{
		return node != it.node;
	}
	bool operator==(const self &it)const
	{
		return node == it.node;
	}
private:
	RBTreeNode<Type> *node;
	RBTreeNode<Type> *NIL;
};

template<class Type>
class RBTree
{
public:
	typedef rb_iterator<Type> iterator;
public:
	void set_endnode()
	{
		RBTreeNode<Type> *p = root;
		while(p!=NIL && p->rightChild!=NIL)
			p = p->rightChild;
		p->rightChild = end_node;
	}
public:
	iterator begin()
	{
		RBTreeNode<Type> *p = root;
		while(p!=NIL && p->leftChild != NIL) 
			p = p->leftChild;
		return iterator(p, NIL);
	}
	iterator end()
	{
		return iterator(end_node, NIL);
	}
public:
	size_t size()const
	{
		return size(root) - 1;
	}
protected:
	size_t size(RBTreeNode<Type> *t)const
	{
		if(t == NIL)
			return 0;
		else
			return size(t->leftChild) + size(t->rightChild) + 1;
	}
public:
	RBTree():NIL(_Buynode()),root(NIL),end_node(_Buynode())
	{
		NIL->leftChild = NIL->rightChild = NIL->parent = nullptr;
		NIL->color = BLACK;

		end_node->leftChild = end_node->rightChild  = end_node->parent = NIL;

		root = NIL;
	}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
protected:
	bool Insert(RBTreeNode<Type>*&t, const Type &x);
	bool Remove(RBTreeNode<Type>*&t, const Type &key);
protected:
	void RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
	void LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
	void Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x);
protected:
	RBTreeNode<Type>* _Buynode(const Type &x = Type())
	{
		RBTreeNode<Type> *s = new RBTreeNode<Type>(x);
		s->leftChild = s->rightChild = s->parent = NIL;
		return s;
	}
private:
	RBTreeNode<Type> *root;
	RBTreeNode<Type> *NIL;
	RBTreeNode<Type> *end_node; // 结束节点
};

template<class Type>
bool RBTree<Type>::Insert(RBTreeNode<Type>*&t, const Type &x)
{
	//1 按照bst的规则插入节点
	RBTreeNode<Type> *pr = NIL;
	RBTreeNode<Type> *p = t;
	while(p != NIL)
	{
		if(x == p->data)
			return false;

		pr = p;

		if(x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}

	RBTreeNode<Type> *s = _Buynode(x);
	//链接节点
	if(pr == NIL)
	{
		t = s;
		t->parent = NIL;
	}
	else if(x < pr->data)
		pr->leftChild = s;
	else
		pr->rightChild = s;
	s->parent = pr;

	//2 平衡调整
	Insert_Fixup(t, s);
	return true;
}

template<class Type>
bool RBTree<Type>::Remove(RBTreeNode<Type>*&t, const Type &key)
{
	//留作同学们自行练习
	//1 按照bst的规则删除节点
	//2 调整平衡
}

//右单旋转
template<class Type>
void RBTree<Type>::RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
{
	RBTreeNode<Type> *s = p->leftChild;
	p->leftChild = s->rightChild;
	if(s->rightChild != NIL)
		s->rightChild->parent = p;
	s->parent = p->parent;
	if(p->parent == NIL)
		t = s;
	else if(p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->rightChild = p;
	p->parent = s;
}
//左单旋转
template<class Type>
void RBTree<Type>::LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
{
	RBTreeNode<Type> *s = p->rightChild;
	p->rightChild = s->leftChild;
	if(s->leftChild != NIL)
		s->leftChild->parent = p;
	s->parent = p->parent;
	if(p->parent == NIL)
		t = s;
	else if(p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->leftChild = p;
	p->parent = s;
}

template<class Type>
void RBTree<Type>::Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
{
	while(x->parent->color == RED)
	{
		RBTreeNode<Type> *s; //叔伯节点
		if(x->parent == x->parent->parent->leftChild) //左分支
		{
			s = x->parent->parent->rightChild;

			//状况三、四
			if(s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
				continue;
			}
			//状况二
			if(x == x->parent->rightChild)
			{
				x = x->parent;
				LeftRotate(t, x);
			}
			//状况一
			x->parent->color = BLACK; //p
			x->parent->parent->color = RED; //g
			RightRotate(t, x->parent->parent);
		}
		else //右分支
		{
			s = x->parent->parent->leftChild;
			//状况三、四
			if(s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
				continue;
			}
			//状况二
			if(x == x->parent->leftChild)
			{
				x = x->parent;
				RightRotate(t, x);
			}
			//状况一
			x->parent->color = BLACK;       //P
			x->parent->parent->color = RED; //G
			LeftRotate(t, x->parent->parent);
		}
	}
	t->color = BLACK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
template<class Type>
class Set
{
public:
	typedef Type value_type;
	//typename typedef RBTree<value_type>::iterator iterator;
	typedef rb_iterator<Type> iterator;
public:
	Set()
	{}
public:
	iterator begin()
	{
		return _Tr.begin();
	}
	iterator end()
	{
		return _Tr.end();
	}
	void set_endnode()
	{
		_Tr.set_endnode();
	}
public:
	size_t size()const
	{
		return _Tr.size();
	}
public:
	void insert(const Type &x)
	{
		_Tr.Insert(x);;
	}
	
private:
	RBTree<value_type> _Tr;
};
template<class Type1, class Type2>
class Map
{
public:
	typedef pair<Type1,Type2> value_type;
	typedef rb_iterator<value_type> iterator;
public:
	Map()
	{}
public:
	iterator begin()
	{return _Tr.begin();}
	iterator end()
	{return _Tr.end();}
	void set_endnode()
	{
		_Tr.set_endnode();
	}
public:
	void insert(const value_type &x)
	{
		_Tr.Insert(x);
	}
private:
	RBTree<value_type> _Tr;
};
void main()
{
	pair<int, string> v1 = {1, "Student"};
	pair<int, string> v2 = {3, "Teacher"};
	pair<int, string> v3 = {4, "Bit"};
	pair<int, string> v4 = {2, "Friend"};

	Map<int, string> imap;
	imap.insert(v1);
	imap.insert(v2);
	imap.insert(v3);
	imap.insert(v4);

	imap.set_endnode();

	auto it = imap.begin();
	while(it != imap.end())
	{
		cout<<it->first<<" : "<<it->second<<endl;
		++it;
	}

}

/*
void main()
{
	int ar[] = {4,8,9,0,2,5,1,7}; 
	int n = sizeof(ar) / sizeof(ar[0]);
	Set<int> is;
	for(int i=0; i<n; ++i)
		is.insert(ar[i]);

	is.set_endnode();

	cout<<"size = "<<is.size()<<endl;

	auto it = is.begin();
	while(it != is.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}


/*
void main()
{
	map<int, string> ismap = 
	{{1, "Student"}, {3, "Teacher"}, {4, "Bit"}, {2, "Friend"},
	{1, "Stu"}, {3, "Teacher"}, {4, "Bit"}, {2, "Friend"}};
	for(auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;

	multimap<int, string> multi_ismap = 
	{{1, "Student"}, {3, "Teacher"}, {4, "Bit"}, {2, "Friend"},
	{1, "Stu"}, {3, "Teacher"}, {4, "Bit"}, {2, "Friend"}};
	for(auto &e : multi_ismap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	map<int, string> ismap = {{1, "Student"}, {3, "Teacher"}, {4, "Bit"}, {2, "Friend"}};
	for(auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;

	ismap[1] = "学生";
	ismap[3] = "老师";
	ismap[4] = "比特";
	ismap[2] = "朋友";  //关键值存在则修改数据，若不存在则插入数据

	ismap[5] = "西安";  //5-"西安"
	//ismap.at(5);

	for(auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	map<int, string> ismap = {{1, "Student"}, {3, "Teacher"}, {4, "Bit"}, {2, "Friend"}};
	for(auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;
}


void main()
{
	map<int, string> ismap;
	ismap.insert(make_pair(1, "Student"));
	ismap.insert(make_pair(3, "Teacher"));
	ismap.insert(make_pair(4, "Bit"));
	ismap.insert(make_pair(2, "Friend"));

	for(auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	pair<int, string> v1 = {1, "Student"};
	pair<int, string> v2 = {3, "Teacher"};
	pair<int, string> v3 = {4, "Bit"};
	pair<int, string> v4 = {2, "Friend"};
	
	//pair
	//map<int, string, greater<int>> ismap;
	map<int, string> ismap;
	ismap.insert(v1);
	ismap.insert(v2);
	ismap.insert(v3);
	ismap.insert(v4);

	for(auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	pair<int, string> v1 = {1, "Student"};
	pair<int, string> v2 = {3, "Teacher"};
	pair<int, string> v3 = {4, "Bit"};
	pair<int, string> v4 = {2, "Friend"};
	
	//pair
	//map<int, string, greater<int>> ismap;
	map<int, string> ismap;
	ismap.insert(v1);
	ismap.insert(v2);
	ismap.insert(v3);
	ismap.insert(v4);

	auto it = ismap.begin();
	while(it != ismap.end())
	{
		cout<<it->first<<" : "<<it->second<<endl;
		++it;
	}


}

/*
void main()
{
	set<int> is = {4,8,9,5,0,2,5,5,5,5,5,1,5,5,5,7};
	cout<<"is size = "<<is.count(50)<<endl;
	multiset<int> multi_is = {4,8,9,5,0,2,5,5,5,5,5,1,5,5,5,7};
	cout<<"multi_is size = "<<multi_is.count(5)<<endl;
}

/*
void main()
{
	set<int> is = {4,8,9,0,2,5,1,7};  //传话筒

	//is.erase(5);
	//auto pos = is.begin();
	auto pos = is.find(7);
	//is.erase(pos);
	is.erase(is.begin(), is.end());

	auto it = is.begin();
	while(it != is.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;
}

/*
void main()
{
	set<int> is = {4,8,9,0,2,5,1,7};
	auto it = is.begin();
	while(it != is.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;

	set<int>::iterator it1 = is.begin();
	while(it1 != is.end())
	{
		cout<<*it1<<" ";
		++it1; //it++
	}
	cout<<endl;

	auto rit = is.rbegin();
	while(rit != is.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}

/*
void main()
{
	int ar[] = {4,8,9,0,2,5,1,7};
	int n = sizeof(ar)/sizeof(ar[0]);
	set<int> is;
	for(auto &e : is)
		cout<<e<<" ";
	cout<<endl;
	set<int> is_1(ar, ar+n);
	for(auto &e : is_1)
		cout<<e<<" ";
	cout<<endl;

	vector<int> iv = {4,8,9,0,2,5,1,7};
	set<int> is_2(iv.begin(), iv.end());
	for(auto &e : is_2)
		cout<<e<<" ";
	cout<<endl;

	set<int> is_3 = is_2; //拷贝构造函数
	for(auto &e : is_3)
		cout<<e<<" ";
	cout<<endl;

}

/*
//set 

void main()
{
	set<int> is = {4,8,9,5,0,2,5,5,5,5,5,1,5,5,5,7};
	for(auto &e : is)
		cout<<e<<" ";
	cout<<endl;

	multiset<int> multi_is = {4,8,9,5,0,2,5,5,5,5,5,1,5,5,5,7};
	for(auto &e : multi_is)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	set<int, greater<int>> is = {4,8,9,0,2,5,1,7};
	auto it = is.begin();
	//*it = 100;
	//it = is.erase(it);
	//is.insert(100);
	
	//it = is.begin();

	while(it != is.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	vector<int> iv = {4,8,9,0,2,5,1,7};
	set<int> is;
	for(int e : iv)
		is.insert(e);
	
	//vector
	for(int e : iv)
		cout<<e<<" ";
	cout<<endl;

	for(auto &e : is)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	//值对结构 key-second
	pair<int, string> isv = {1,"abc"}; //int_string value
	cout<<isv.first<<" : "<<isv.second<<endl;
}
*/