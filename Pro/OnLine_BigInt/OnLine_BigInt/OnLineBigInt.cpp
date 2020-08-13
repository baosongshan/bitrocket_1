#include<vld.h>
#include"bigint.h"

int QuickPow(int a, int n)
{
	int base = a;
	int res = 1;
	while(n)
	{
		if(n & 1)
			res *= base;
		base *= base;
		n>>=1;
	}
	return res;
}

void main()
{
	cout<<QuickPow(2, 1100)<<endl;
}

/*
void main()
{
	//1 支持负数运算
	BigInt bt(-123);
	cout<<"bt = "<<bt<<endl;

	//2 支持256进制存储 用于节省空间

	//3
}

/*
typedef enum{ADD, SUB, MUL, DIV, MOD} OPER;

void Data_Handler(BigInt &bt, BigInt &bt1, BigInt &bt2, OPER &op)
{
	bt.clear();
	bt1.clear();
	bt2.clear();

	//m=41431&n=41431&cmd=1
	//std::string data = getenv("QUREY_STRING");
	std::string data = "m=41431&n=41431&cmd=1";

	//解析bt1
	int pos = data.find('=');
	const char *p = data.c_str() + pos + 1;
	while(*p>='0' && *p<='9')
	{
		bt1.push_front(*p-'0');
		p++;
	}

	//解析bt2
	pos = data.find('=', pos+1);
	p = data.c_str() + pos + 1;
	while(*p>='0' && *p<='9')
	{
		bt2.push_front(*p-'0');
		p++;
	}

	//解析操作符
	pos = data.find('=', pos+1);
	p = data.c_str() + pos + 1;
	if(*p == '1')
		op = ADD;
	if(*p == '2')
		op = SUB;
	if(*p == '3')
		op = MUL;
	if(*p == '4')
		op = DIV;
	
}


void main()
{
	BigInt bt, bt1, bt2;
	OPER op;
	Data_Handler(bt, bt1, bt2, op);
	cout<<"bt1 = "<<bt1<<endl;
	cout<<"bt2 = "<<bt2<<endl;
	cout<<"cmd = "<<op<<endl;
}

/*
void main()
{
	//BigInt bt, bt1(796), bt2(4);
	BigInt bt, bt1, bt2;
	bt1.LoadData(3);

	cout<<"bt1 = "<<bt1<<endl;

	Sleep(1000);
	bt2.LoadData(6);
	cout<<"bt2 = "<<bt2<<endl;

	clock_t start = clock();
	bt = bt1 + bt2;
	clock_t end = clock();

	cout<<"time:"<<(end-start)<<endl;
	cout<<"bt  = "<<bt<<endl;
}

/*
void main()
{
	//BigInt bt, bt1(796), bt2(4);
	BigInt bt, bt1, bt2;
	bt1.LoadData(3);

	cout<<"bt1 = "<<bt1<<endl;

	Sleep(1000);
	bt2.LoadData(6);
	cout<<"bt2 = "<<bt2<<endl;

	clock_t start = clock();
	//BigInt::Add(bt, bt1, bt2);
	//BigInt::Sub(bt, bt1, bt2);
	//BigInt::Mul(bt, bt1, bt2);
	//BigInt::Div(bt, bt1, bt2);
	//BigInt::Mod(bt, bt1, bt2);
	//BigInt::Square(bt, bt1);
	BigInt::Pow(bt, bt1, bt2);
	clock_t end = clock();

	cout<<"time:"<<(end-start)<<endl;
	cout<<"bt  = "<<bt<<endl;
}

/*
void Test_SeqList()
{
	SeqList<unsigned int> list;
	for(int i=1; i<=10; ++i)
		list.push_back(i);

	for(int i=1; i<=10; ++i)
		cout<<list[i]<<" ";
	cout<<endl;

	list.push_front(20);
	list.push_front(30);

	for(int i=1; i<=list.size(); ++i)
		cout<<list[i]<<" ";
	cout<<endl;

	list.pop_back();
	list.pop_front();
	for(int i=1; i<=list.size(); ++i)
		cout<<list[i]<<" ";
	cout<<endl;

	cout<<"back = "<<list.back()<<endl;
	cout<<"front = "<<list.front()<<endl;

	//list.reverse();
	list.sort();
	for(int i=1; i<=list.size(); ++i)
		cout<<list[i]<<" ";
	cout<<endl;

}

void main()
{
	Test_SeqList();
}
*/