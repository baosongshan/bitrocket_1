#include<vld.h>
#include"bigint.h"

void main()
{
	//BigInt bt, bt1(123), bt2(23);
	BigInt bt, bt1, bt2;
	bt1.LoadData(10);

	cout<<"bt1 = "<<bt1<<endl;

	Sleep(1000);
	bt2.LoadData(2);
	cout<<"bt2 = "<<bt2<<endl;

	//BigInt::Add(bt, bt1, bt2);
	//BigInt::Sub(bt, bt1, bt2);
	//BigInt::Mul(bt, bt1, bt2);
	//BigInt::Div(bt, bt1, bt2);

	bt = bt1 + bt2;
	bt = bt1 - bt2;
	bt = bt1 * bt2;
	bt = bt1 / bt2;
	bt1 += bt2;


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