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
	BigInt(long value = 0);
public:
	void LoadData(int sz);
	void ShowData()const;
	void SetSymbol(Symbol sym);
	Symbol GetSymbol()const;
public:
	u_char back()const;
	void push_back(u_char x);
	void push_front(u_char x);
	void pop_back();
	size_t size()const;
	void clear();
public:
	static u_char AddItem(u_char a, u_char b, u_char &sign);
	static void Add(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static u_char SubItem(u_char a, u_char b, u_char &sign);
	static void Sub(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static void MulItem(BigInt &bt, const BigInt &bt1, u_char x);
	static void MoveAdd(BigInt &bt, const BigInt &bt1, u_long offset);
	static void Mul(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static void Div(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static void Mod(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static void Square(BigInt &bt, const BigInt &bt1);
	static void Pow(BigInt &bt, const BigInt &bt1, const BigInt &bt2); // bt = bt1^bt2
	static void PowMod(BigInt &bt, const BigInt &bt1, const BigInt &bt2, const BigInt &bt3); //RSA bt = bt1^bt2 % bt3
public:
	static void clear_head_zero(BigInt &bt);
public:
	u_char& operator[](size_t pos);
	u_char operator[](size_t pos)const;
public:
	BigInt& operator++();
	BigInt  operator++(int);
	BigInt& operator--();
	BigInt  operator--(int);
public:
	BigInt operator+(const BigInt &bt);
	BigInt operator-(const BigInt &bt);
	BigInt operator*(const BigInt &bt);
	BigInt operator/(const BigInt &bt);
	BigInt operator%(const BigInt &bt);
public:
	BigInt& operator+=(const BigInt &bt);
	BigInt& operator-=(const BigInt &bt);
	BigInt& operator*=(const BigInt &bt);
	BigInt& operator/=(const BigInt &bt);
	BigInt& operator%=(const BigInt &bt);
public:
	BigInt operator>>(u_long i); // bt >> 5
	BigInt operator<<(u_long i); 
	BigInt& operator>>=(u_long i); 
	BigInt& operator<<=(u_long i); 
public:
	bool operator<(const BigInt &bt)const;
	bool operator>=(const BigInt &bt)const;
	bool operator>(const BigInt &bt)const;
	bool operator<=(const BigInt &bt)const;
	bool operator==(const BigInt &bt)const;
	bool operator!=(const BigInt &bt)const;
private:
	SeqList<u_char> big;

	//vector<u_char> big;
};

#endif /* _BIGINT_H_ */