#pragma once

#include<iostream>
#include<time.h>
#include<windows.h>
#include<conio.h>
using namespace std;

struct Date
{
	int m_year;
	int m_month;
	int m_day;
};
struct Time
{
	int m_hour;
	int m_minute;
	int m_second;
};

class CDateTime;
ostream& operator<<(ostream &out, const CDateTime &dt);
class CDateTime
{
	friend ostream& operator<<(ostream &out, const CDateTime &dt);
public:
	CDateTime();
public:
	CDateTime NextDateTime(int n);
	CDateTime PrevDateTime(int n);
	int GetWeekByYMD(int year, int month, int day); //
public:
	CDateTime operator++(int);
	CDateTime operator--(int);
	CDateTime& operator++();
	CDateTime& operator--();
public:
	CDateTime& operator+=(int n); // 2020 5 31 + 10
	CDateTime& operator-=(int n); 
public:
	int operator-(const CDateTime &dt);
public:
	bool operator==(const CDateTime &dt);
	bool operator!=(const CDateTime &dt);
	bool operator>(const CDateTime &dt);
	bool operator<(const CDateTime &dt);
	bool operator>=(const CDateTime &dt);
	bool operator<=(const CDateTime &dt);
public:
	CDateTime GetCurDateTime();
	void DateTimeShow();

	void DateTimeCalendar();
private:
	Date m_date;
	Time m_time;
};