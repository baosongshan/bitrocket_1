#include"bigint.h"

ostream& operator<<(ostream &out, const BigInt &bt)
{
	for(u_long i=bt.size(); i>=1; --i)
		out<<(int)bt[i];
	return out;
}

void BigInt::LoadData(int sz)
{
	srand(time(0));
	for(int i=0; i<sz; ++i)
	{
		push_back(rand() % 10);
	}
}
void BigInt::ShowData()const
{
	for(size_t i=size(); i>0; --i)
		cout<<(int)big[i];
	cout<<endl;
}

void BigInt::push_back(u_char x)
{big.push_back(x);}
size_t BigInt::size()const
{return big.size();}

u_char BigInt::operator[](size_t pos)const
{
	assert(pos>=1 && pos<=size());
	return big[pos];
}

u_char BigInt::AddItem(u_char a, u_char b, u_char &sign)
{
	u_char sum = a + b + sign;
	if(sum >= 10)
	{
		sign = 1;
		sum -= 10;
	}
	else
		sign = 0;
	return sum;
}

void BigInt::Add(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	u_long i, j;
	i = j = 1;
	u_char sum = 0, sign = 0;
	while(i<=bt1.size() && j<=bt2.size())
	{
		sum = AddItem(bt1[i], bt2[j], sign);
		bt.push_back(sum);
		i++;
		j++;
	}
	while(i <= bt1.size())
	{
		sum = AddItem(bt1[i], 0, sign);
		bt.push_back(sum);
		i++;
	}

	while(j <= bt2.size())
	{
		sum = AddItem(0, bt2[j], sign);
		bt.push_back(sum);
		j++;
	}

	if(sign > 0)
		bt.push_back(sign);
}

 void BigInt::Sub(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
 {
	 //if(bt1 < bt2)
	//	 return;
 }