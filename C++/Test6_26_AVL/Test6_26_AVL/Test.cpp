#include<iostream>
#include<stack>
using namespace std;

template<class Type>
class AVLTree;

//avl node
template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode(Type d=Type(), AVLNode<Type>*left=nullptr, AVLNode<Type>*right=nullptr)
		: data(d), leftChild(left),rightChild(right),bf(0)
	{}
	~AVLNode()
	{}
private:
	Type data;
	AVLNode<Type> *leftChild;
	AVLNode<Type> *rightChild;
	int            bf; //平衡因子
};

//avl tree
template<class Type>
class AVLTree
{
public:
	AVLTree() :root(nullptr)
	{}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
protected:
	bool Insert(AVLNode<Type> *&t, const Type &x);
	bool Remove(AVLNode<Type> *&t, const Type &key);
	void RotateR(AVLNode<Type> *&ptr);
	void RotateLR(AVLNode<Type> *&ptr);
	void RotateL(AVLNode<Type> *&ptr);
	void RotateRL(AVLNode<Type> *&ptr);
private:
	AVLNode<Type> *root;
};

//1 调整平衡  2更改bf
template<class Type>
void AVLTree<Type>::RotateR(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subR = ptr;
	ptr = subR->leftChild;

	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;

	ptr->bf = subR->bf = 0;
}

template<class Type>
void AVLTree<Type>::RotateLR(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subL = ptr->leftChild;
	AVLNode<Type> *subR = ptr;
	ptr = subL->rightChild;

	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	//更新 subL->bf
	if(ptr->bf <= 0)
		subL->bf = 0;
	else
		subL->bf = -1;

	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	//更新 subR->bf
	if(ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;

	ptr->bf = 0;
}

template<class Type>
void AVLTree<Type>::RotateL(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subL = ptr;
	ptr = subL->rightChild;
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;

	ptr->bf = subL->bf = 0;
}

template<class Type>
void AVLTree<Type>::RotateRL(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subL = ptr;
	AVLNode<Type> *subR =ptr->rightChild;
	ptr = subR->leftChild;

	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	//更新subR->bf
	if(ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;

	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	//更新subL->bf
	if(ptr->bf == 1)
		subL->bf = -1;
	else
		subL->bf = 0;

	ptr->bf = 0;
}

template<class Type>
bool AVLTree<Type>::Insert(AVLNode<Type> *&t, const Type &x)
{
	//1 按照BST的规则插入节点
	AVLNode<Type> *pr = nullptr;
	AVLNode<Type> *p = t;

	stack<AVLNode<Type>*> st;

	while(p != nullptr)
	{
		//用于查找x的插入位置
		if(x == p->data)
			return false;

		pr = p;
		st.push(pr);

		if(x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	p = new AVLNode<Type>(x);
	if(pr == nullptr)
	{
		t = p;
		return true;
	}

	//链接新建节点
	if(x < pr->data)
		pr->leftChild = p;
	else
		pr->rightChild = p;

	//2 如果发生不平衡，需要调整平衡
	while(!st.empty())
	{
		pr = st.top();
		st.pop();
		if(p == pr->leftChild)
			pr->bf--;
		else
			pr->bf++;

		if(pr->bf == 0)
			break;
		if(pr->bf==1 || pr->bf==-1) // |bf| == 1 向上回溯
			p = pr;
		else
		{
			//|bf| == 2 发生不平衡 调整平衡
			if(p == pr->leftChild) //左分支
			{
				if(p->bf < 0)    //     /
				{
					RotateR(pr);
					//cout<<"RotateR."<<endl;
				}
				else            //     <
				{
					RotateLR(pr);
					//cout<<"RotateLR."<<endl;
				}	
			}
			else  //右分支
			{
				if(p->bf > 0)    //   \ 
				{
					RotateL(pr);
					//cout<<"RotateL."<<endl;
				}
				else             //   > 
				{
					RotateRL(pr);
					//cout<<"RotateRL."<<endl;
				}	
			}
			break;
		}
	}

	//重新链接
	if(st.empty())
		t = pr;
	else
	{
		AVLNode<Type> *ppr = st.top();
		if(ppr->data > pr->data)
			ppr->leftChild = pr;
		else
			ppr->rightChild = pr;
	}

	return true;
}

template<class Type>
bool AVLTree<Type>::Remove(AVLNode<Type> *&t, const Type &key)
{
	//1 按照bst的规则找到节点并删除

	//2 删除节点后，若发生不平衡，需要重新调整并更新bf
}

void main()
{
	int ar[] = {9,26,16,3,7,11,18,14,15};
	int n = sizeof(ar) / sizeof(ar[0]);

	AVLTree<int> avl;
	for(int i=0; i<n; ++i)
		avl.Insert(ar[i]);
}