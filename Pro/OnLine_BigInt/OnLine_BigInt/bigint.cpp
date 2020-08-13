#include"bigint.h"

ostream& operator<<(ostream &out, const BigInt &bt)
{
	if(bt.GetSymbol() == NEGATIVE)
		out<<"-";
	for(u_long i=bt.size(); i>=1; --i)
		out<<(int)bt[i];
	return out;
}

void BigInt::SetSymbol(Symbol sym)
{
	big.SetSymbol(sym);
}
Symbol BigInt::GetSymbol()const
{
	return big.GetSymbol();
}

BigInt::BigInt(long value) //123
{
	if(value == 0)
		push_back(0);

	if(value < 0)
		SetSymbol(NEGATIVE);
	value = abs(value);

	while(value)
	{
		push_back(value % 10);  // % 256  0~255
		value /= 10;            // /= 256 
	}
}

/////////////////////////////////////////////////////////////////
void BigInt::LoadData(int sz)
{
	clear();
	srand(time(0));
	for(int i=0; i<sz; ++i)
	{
		u_char val = rand() % 10;
		while(i==sz-1 && val==0)   //解决头部出现0的情况
		{
			val = rand() %10;
		}
		push_back(val);
	}
	clear_head_zero(*this);
}

void BigInt::ShowData()const
{
	for(size_t i=size(); i>0; --i)
		cout<<(int)big[i];
	cout<<endl;
}


u_char BigInt::back()const
{return big.back();}
void BigInt::push_back(u_char x)
{big.push_back(x);}
void BigInt::push_front(u_char x)
{big.push_front(x);}
void BigInt::pop_back()
{big.pop_back();}
size_t BigInt::size()const
{return big.size();}
void BigInt::clear()
{big.clear();}

u_char& BigInt::operator[](size_t pos)
{
	assert(pos>=1 && pos<=size());
	return big[pos];
}

u_char BigInt::operator[](size_t pos)const
{
	assert(pos>=1 && pos<=size());
	return big[pos];
}

void BigInt::clear_head_zero(BigInt &bt)
{
	if(bt == 0)
		return;
	while(bt.back() == 0)
	{
		bt.pop_back();
		if(bt == 0)
			return;
	}
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
	bt.clear();
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

u_char BigInt::SubItem(u_char a, u_char b, u_char &sign)
{
	u_char sub;
	if(a >= b + sign)
	{
		sub = a - b - sign;
		sign = 0;
	}
	else
	{
		sub = (a+10) - b - sign;
		sign = 1;
	}
	return sub;
}

void BigInt::Sub(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	if(bt1 < bt2)
		return;
	else if(bt1 == bt2)
		bt = 0;

	bt.clear();

	u_long i, j;
	i = j = 1;
	u_char sub, sign = 0;
	while(i<=bt1.size() && j<=bt2.size())
	{
		sub = SubItem(bt1[i], bt2[j], sign);
		bt.push_back(sub);
		i++;
		j++;
	}
	while(i <= bt1.size())
	{
		sub = SubItem(bt1[i], 0, sign);
		bt.push_back(sub);
		i++;
	}
}

void BigInt::MulItem(BigInt &bt, const BigInt &bt1, u_char x)
{
	u_long i = 1;
	u_char res, sign = 0;
	while(i <= bt1.size())
	{
		res = x * bt1[i] + sign;
		sign = res / 10;  
		res %= 10;        
		bt.push_back(res);
		i++;
	}
	if(sign > 0)
		bt.push_back(sign);
}
void BigInt::MoveAdd(BigInt &bt, const BigInt &bt1, u_long offset)
{
	u_long i = offset;
	u_long j = 1;
	u_char sign = 0;
	while(i<=bt.size() && j<=bt1.size())
	{
		bt[i] = AddItem(bt[i], bt1[j], sign);
		i++;
		j++;
	}
	while(sign>0 && i<=bt.size())
	{
		bt[i] = AddItem(bt[i], 0, sign);
		i++;
	}
	while(j <= bt1.size())
	{
		u_char sum = AddItem(0, bt1[j], sign);
		bt.push_back(sum);
		j++;
	}
	if(sign > 0)
		bt.push_back(sign);
}

void BigInt::Mul(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	if(bt1==0 || bt2==0)
	{
		bt = 0;
		return;
	}

	BigInt res_table[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for(u_long i=1; i<=bt2.size(); ++i)
	{
		if(bt2[i]!=0 && res_table[bt2[i]]==0)
		{
			res_table[bt2[i]].clear();
			MulItem(res_table[bt2[i]], bt1, bt2[i]);
		}
		MoveAdd(bt, res_table[bt2[i]], i);
	}
}

/*
void BigInt::Mul(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	BigInt tmp;
	tmp.clear();
	for(u_long i=1; i<=bt2.size(); ++i)
	{
		MulItem(tmp, bt1, bt2[i]);
		MoveAdd(bt, tmp, i);
		tmp.clear();
	}
}


void BigInt::Mul(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	//先制作结果表
	BigInt res_table[10];
	for(u_char i=1; i<=9; ++i)
	{
		res_table[i].clear();
		MulItem(res_table[i], bt1, i);
	}

	for(u_long i=1; i<=bt2.size(); ++i)
		MoveAdd(bt, res_table[bt2[i]], i);
}
*/

void BigInt::Div(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	bt.clear();
	if(bt1 < bt2)
		bt = 0;
	else if(bt1 == bt2)
		bt = 1;
	else
	{

		u_long bt1_len = bt1.size();
		u_long bt2_len = bt2.size();
		int k = bt1_len - bt2_len;

		BigInt tmp;
		tmp.clear();
		for(u_long i=1; i<=bt2.size(); ++i)
			tmp.push_back(bt1[i+k]);

		while(k >= 0)
		{
			u_char div = 0;
			while(tmp >= bt2)
			{
				tmp -= bt2;
				div++;
				clear_head_zero(tmp);
			}
			bt.push_front(div);   // 6 0
			if(k > 0)
			{
				tmp.push_front(bt1[k]);
				clear_head_zero(tmp);
			}
			--k;
		}
		clear_head_zero(bt);
	}
}

void BigInt::Mod(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	bt.clear();
	if(bt1 < bt2)
		bt = bt1;
	else if(bt1 == bt2)
		bt = 0;
	else
	{

		u_long bt1_len = bt1.size();
		u_long bt2_len = bt2.size();
		int k = bt1_len - bt2_len;

		BigInt tmp;
		tmp.clear();
		for(u_long i=1; i<=bt2.size(); ++i)
			tmp.push_back(bt1[i+k]);

		while(k >= 0)
		{
			while(tmp >= bt2)
			{
				tmp -= bt2;
				clear_head_zero(tmp);
			}
			if(k > 0)
			{
				tmp.push_front(bt1[k]);
				clear_head_zero(tmp);
			}
			--k;
		}

		bt = tmp;

		clear_head_zero(bt);
	}
}

void BigInt::Square(BigInt &bt, const BigInt &bt1)
{
	BigInt::Mul(bt, bt1, bt1);
}

//幂的快速求解法
void BigInt::Pow(BigInt &bt, const BigInt &bt1, const BigInt &bt2) //2^3 = 2*2*2
{
	bt = 1;
	for(BigInt i=0; i<bt2; ++i)
		bt *= bt1;
}

///////////////////////////////////////////////////////////////////////////////
BigInt& BigInt::operator++()
{
	u_long i = 1;
	u_char sign = 1;
	while(sign>0 && i<=size())
	{
		(*this)[i] = AddItem((*this)[i], 0, sign);
		i++;
	}
	if(sign > 0)
		push_back(sign);
	return *this;
}

BigInt  BigInt::operator++(int)
{
	BigInt tmp = *this;
	++*this;
	return tmp;
}

BigInt& BigInt::operator--()
{
	u_long i = 1;
	u_char sign = 1;
	while(sign>0 && i<=size())
	{
		(*this)[i] = SubItem((*this)[i], 0, sign);
		i++;
	}
	clear_head_zero(*this);
	return *this;
}
BigInt  BigInt::operator--(int)
{
	BigInt tmp = *this;
	--*this;
	return tmp;
}

BigInt& BigInt::operator+=(const BigInt &bt)
{
	u_long i, j;
	i = j = 1;
	u_char sign = 0;
	while(i<=size() && j<=bt.size())
	{
		(*this)[i] = AddItem((*this)[i], bt[j], sign);
		i++;
		j++;
	}
	while(sign>0 && i<=size())
	{
		(*this)[i] = AddItem((*this)[i], 0, sign);
		i++;
	}
	while(j <= bt.size())
	{
		u_char sum = AddItem(0, bt[j], sign);
		push_back(sum);
		j++;
	}
	if(sign > 0)
		push_back(sign);

	return *this;
}

BigInt& BigInt::operator-=(const BigInt &bt)
{
	u_long i, j;
	i = j = 1;
	u_char sign = 0;
	while(i<=size() && j<=bt.size())
	{
		(*this)[i] = SubItem((*this)[i], bt[j], sign);
		i++;
		j++;
	}
	while(sign > 0)
	{
		(*this)[i] = SubItem((*this)[i], 0, sign);
		i++;
	}
	return *this;
}

BigInt& BigInt::operator*=(const BigInt &bt)
{
	BigInt tmp;
	BigInt::Mul(tmp, *this, bt);
	*this = tmp;
	return *this;
}
BigInt& BigInt::operator/=(const BigInt &bt)
{
	BigInt tmp;
	BigInt::Div(tmp, *this, bt);
	*this = tmp;
	return *this;
}
BigInt& BigInt::operator%=(const BigInt &bt)
{
	BigInt tmp;
	BigInt::Mod(tmp, *this, bt);
	*this = tmp;
	return *this;
}

BigInt BigInt::operator+(const BigInt &bt)
{
	BigInt tmp;
	BigInt::Add(tmp, *this, bt);
	return tmp;
}
BigInt BigInt::operator-(const BigInt &bt)
{
	BigInt tmp;
	BigInt::Sub(tmp, *this, bt);
	return tmp;
}
BigInt BigInt::operator*(const BigInt &bt)
{
	BigInt tmp;
	BigInt::Mul(tmp, *this, bt);
	return tmp;
}
BigInt BigInt::operator/(const BigInt &bt)
{
	BigInt tmp;
	BigInt::Div(tmp, *this, bt);
	return tmp;
}
BigInt BigInt::operator%(const BigInt &bt)
{
	BigInt tmp;
	BigInt::Mod(tmp, *this, bt);
	return tmp;
}

//////////////////////////////////////////////////////////////////////////////
bool BigInt::operator<(const BigInt &bt)const
{
	if(size() < bt.size())
		return true;
	else if(size() > bt.size())
		return false;

	for(u_long i=bt.size(); i>=1; --i)
	{
		if((*this)[i] > bt[i])
			return false;
		else if(big[i] < bt[i])
			return true;
	}
	return false;
}

bool BigInt::operator>=(const BigInt &bt)const
{
	return !(*this < bt);
}

bool BigInt::operator>(const BigInt &bt)const
{
	if(size() > bt.size())
		return true;
	else if(size() < bt.size())
		return false;

	for(u_long i=bt.size(); i>=1; --i)
	{
		if((*this)[i] > bt[i])
			return true;
		else if(big[i] < bt[i])
			return false;
	}
	return false;
}
bool BigInt::operator<=(const BigInt &bt)const
{
	return !(*this > bt);
}

bool BigInt::operator==(const BigInt &bt)const
{
	if(size() != bt.size())
		return false;

	for(u_long i=1; i<=bt.size(); ++i)
	{
		if((*this)[i] != bt[i])
			return false;
	}
	return true;
}

bool BigInt::operator!=(const BigInt &bt)const
{
	return !(*this == bt);
}
