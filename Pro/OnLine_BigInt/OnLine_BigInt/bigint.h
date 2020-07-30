#ifndef _BIGINT_H_
#define _BIGINT_H_

#include"seqlist.h"

class BigInt;
ostream& operator<<(ostream &out, const BigInt &bt);

//大整数运算类
class BigInt
{
	friend ostream& operator<<(ostream &out, const BigInt &bt);
public:
	void LoadData(int sz);
	void ShowData()const;
public:
	void push_back(u_char x);
	size_t size()const;
public:
	static u_char AddItem(u_char a, u_char b, u_char &sign);
	static void Add(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static void Sub(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static void Mul(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static void Div(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static void Mod(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
public:
	u_char operator[](size_t pos)const;
public:
	bool operator<(const BigInt &bt)const;
	bool operator>=(const BigInt &bt)const;
	bool operator>(const BigInt &bt)const;
	bool operator<=(const BigInt &bt)const;
	bool operator==(const BigInt &bt)const;
	bool operator!=(const BigInt &bt)const;
private:
	SeqList<u_char> big;
};

#endif /* _BIGINT_H_ */