#include<iostream>
using namespace std;


typedef enum{RED, BLACK} Color_Type;

template<class Type>
class RBTree;

template<class Type>
class RBTreeNode
{
	friend class RBTree<Type>;
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
class RBTree
{
public:
	RBTree():NIL(_Buynode()),root(NIL)
	{
		NIL->leftChild = NIL->rightChild = NIL->parent = nullptr;
		NIL->color = BLACK;
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

int main()
{
	int ar[] = {10, 7, 8, 15, 5, 6, 11, 13, 12};
	int n = sizeof(ar) / sizeof(ar[0]);
	RBTree<int> rb;
	for(int i=0; i<n; ++i)
		rb.Insert(ar[i]);
	return 0;
}
