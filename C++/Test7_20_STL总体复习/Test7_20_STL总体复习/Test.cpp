#include<iostream>
#include<list>
#include<vector>
#include<set>
#include<deque>
#include<algorithm>
#include<numeric>
#include<functional>
using namespace std;

void  main()
{
	vector<int> v1{ 4, 1, 8, 0, 5,  9, 3, 7,2, 6 };
	list<int>   v2{ 4, 1, 8, 0, 5,  9, 3, 7,2, 6 };
	deque<int>  v3{ 4, 1, 8, 0, 5,  9, 3, 7,2, 6 };
	set<int>    v4{ 4, 1, 8, 0, 5,  9, 3, 7,2, 6 };

	auto it1 = find(v1.begin(), v1.end(), 9);
	auto it2 = find(v2.begin(), v2.end(), 9);
	auto it3 = find(v3.begin(), v3.end(), 9);
	auto it4 = find(v4.begin(), v4.end(), 9);
}

/*
void  main()
{
	vector<int> v = {1,2,3};
	sort(v.begin(), v.end());

	do
	{
		cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	}while(next_permutation(v.begin(), v.end()));

	cout<<"======================================"<<endl;

	sort(v.begin(), v.end(), greater<int>()); //3 2 1
	do
	{
		cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	}while(prev_permutation(v.begin(), v.end()));
}

/*
void  main()
{
	vector<int> v{ 4, 1, 8, 0, 5, 5,5, 9, 3,5, 7, 5,5,2, 6 };  //sort
	for (auto &e : v)
		cout << e << " ";
	cout << endl;

	sort(v.begin(), v.end()); //交换 选择 插入 快排

	for (auto &e : v)
		cout << e << " ";
	cout << endl;

	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end());

	for (auto &e : v)
		cout << e << " ";
	cout << endl;
}

/*
//map  set --> key
void main()
{
	set<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto &e : v)
		cout << e << " ";
	cout << endl;

	reverse(v.begin(), v.end());

	for (auto &e : v)
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	vector<int> v{0,1,2,3,4,5,6,7,8,9};
	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;

	reverse(v.begin(), v.end());

	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;



}

/*
bool isOdd(int x)
{
	return (x % 2 == 1); //0   1
}

void main()
{
	vector<int> v{0,1,2,3,4,5,6,7,8,9};
	auto pos = partition(v.begin(), v.end(), isOdd);

	for(auto it=v.begin(); it!=pos; ++it)
		cout<<*it<<" ";
	cout<<endl;

	for(auto it=pos; it!=v.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;
}

/*
void  main()
{
	vector<int> v1{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };
	//             first         mid         last
	partial_sort(v1.begin(), v1.begin()+3, v1.end(), greater<int>());

	for(int i=0; i<3; ++i)
		cout<<v1[i]<<" ";
	cout<<endl;
}

/*
void main()
{
	list<int> v1 = {1,9,5,7,3};
	vector<int> v2 = {2,8,10,4,6};

	//vector<int> v(v1.size() + v2.size());
	//merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

	v1.sort();
	sort(v2.begin(), v2.end());

	int ar[10] = {0};
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), ar);

	for(auto &e : ar)
		cout<<e<<" ";
	cout<<endl;

}

/*
void main()
{
	vector<int> v1 = {1,9,5,7,3};
	vector<int> v2 = {2,8,10,4,6};

	//vector<int> v(v1.size() + v2.size());
	//merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int ar[10] = {0};
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), ar);

	for(auto &e : ar)
		cout<<e<<" ";
	cout<<endl;

}


/*
void main()
{
	vector<int> v1 = {1,3,5,7,9};
	vector<int> v2 = {2,4,6,8,10};

	//vector<int> v(v1.size() + v2.size());
	//merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

	int ar[10] = {0};
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), ar);

	for(auto &e : ar)
		cout<<e<<" ";
	cout<<endl;

}


/*
void main()
{
	cout<<max(10, 20)<<endl;
	cout<<min(10, 20)<<endl;
}

/*
bool Greater3(int x)
{
	return x > 3;
}

void main()
{
	vector<int> v2{0,1,2,3,4,5,6,7,8,9,11,13};

	auto rit = find(v2.begin(), v2.end(), 9);
	if(rit != v2.end())
		cout<<"rit = "<<*rit<<endl;
	else
		cout<<"没有这个数据."<<endl;

	rit = find_if(v2.begin(), v2.end(), Greater3);
	if(rit != v2.end())
		cout<<"rit = "<<*rit<<endl;
	else
		cout<<"没有这个数据."<<endl;
}

/*
//奇数的个数
bool isOdd(int x)
{
	return (x % 2 == 1); //0   1
}

bool Greater3(int x)
{
	return x > 3;
}

struct less5
{
	bool operator()(int x)
	{
		return x < 5;
	}
};

void main()
{
	vector<int> v1{ 10, 20, 30, 30, 20, 10, 10, 20, 10, 10};
	cout<<"10 count = "<<count(v1.begin(), v1.end(), 10)<<endl;

	vector<int> v2{0,1,2,3,4,5,6,7,8,9,11,13};
	cout<<"odd count = "<<count_if(v2.begin(), v2.end(), isOdd)<<endl;
	cout<<">3 count = "<<count_if(v2.begin(), v2.end(), Greater3)<<endl;
	cout<<"<5 count = "<<count_if(v2.begin(), v2.end(), less5())<<endl;
}

/*
int Mul2(int x, int y)
{
	return x + 2 * y;
}


void main()
{
	vector<int> iv{1,2,3,4,5,6,7,8,9,10};
	int sum1 = accumulate(iv.begin(), iv.end(), 0);
	cout<<"sum1 = "<<sum1<<endl;

	int sum2 = accumulate(iv.begin(), iv.end(), 0, Mul2);
	cout<<"sum2 = "<<sum2<<endl;
}

/*
struct Mul2
{
	int operator()(int x, int y)
	{
		return x + 2 * y;
	}
};


void main()
{
	vector<int> iv{1,2,3,4,5,6,7,8,9,10};
	int sum1 = accumulate(iv.begin(), iv.end(), 0);
	cout<<"sum1 = "<<sum1<<endl;

	int sum2 = accumulate(iv.begin(), iv.end(), 0, Mul2());
	cout<<"sum2 = "<<sum2<<endl;
}

/*
void main()
{
	vector<int> iv{1,2,3,4,5,6,7,8,9,10};
	int sum = 0;
	for(auto &e : iv)
		sum += e;
	cout<<"sum = "<<sum<<endl;

	auto pos = find(iv.begin(), iv.end(), 6);
	int sum1 = accumulate(iv.begin(), pos, 100);
	cout<<"sum1 = "<<sum1<<endl;
}

/*
class Test
{};
void main()
{
	list<int> mylist;
	list<double> youlist;
	list<Test> hilist;
}
*/