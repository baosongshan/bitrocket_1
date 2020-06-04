#include"CDateTime.h"

#define ESC 0x1B

void HideCursor()
{
	CONSOLE_CURSOR_INFO  cursor_info = {100, 0};
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor_info);
}
void ShowCursor()
{
	CONSOLE_CURSOR_INFO  cursor_info = {10, 1};
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor_info);
}

ostream& operator<<(ostream &out, const CDateTime &dt)
{
	out<<dt.m_date.m_year<<"年"<<dt.m_date.m_month<<"月"<<dt.m_date.m_day<<"日 ";
	cout<<dt.m_time.m_hour<<"时"<<dt.m_time.m_minute<<"分"<<dt.m_time.m_second<<"秒";
	return out;
}

CDateTime::CDateTime()
{
	m_date.m_year = 1;
	m_date.m_month = 1;
	m_date.m_day = 1;

	m_time.m_hour = 0;
	m_time.m_minute = 0;
	m_time.m_second = 0;
}

CDateTime::CDateTime(int year, int month, int day)
{
	m_date.m_year = year;
	m_date.m_month = month;
	m_date.m_day = day;

	time_t te;
	time(&te);
	struct tm *ptm = localtime(&te);
	m_time.m_hour = ptm->tm_hour;
	m_time.m_minute = ptm->tm_min;
	m_time.m_second = ptm->tm_sec;
}

CDateTime CDateTime::GetCurDateTime()
{
	time_t te;
	time(&te);
	struct tm *ptm = localtime(&te);

	CDateTime tmp;

	tmp.m_date.m_year = ptm->tm_year + 1900;
	tmp.m_date.m_month = ptm->tm_mon + 1;
	tmp.m_date.m_day = ptm->tm_mday;

	tmp.m_time.m_hour = ptm->tm_hour;
	tmp.m_time.m_minute = ptm->tm_min;
	tmp.m_time.m_second = ptm->tm_sec;

	return tmp;
}

void CDateTime::DateTimeShow()
{
	HideCursor();
	CDateTime tmp;
	while(1)
	{
		if(_kbhit())
		{
			int val = getch();
			if(val == ESC)
				break;
		}
		tmp = GetCurDateTime();
		cout<<tmp;
		Sleep(1000);
		system("cls");
	}
	ShowCursor();
}

bool CDateTime::IsLeap(int year)
{
	return (year%4==0&&year%100!=0) ||(year%400==0);
}

int CDateTime::GetMonthDays(int year, int month)
{
	int days[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month==2 && IsLeap(year))
		return days[0];
	return days[month];
}

int CDateTime::GetWeekByYMD(int year, int month, int day)
{
	int D = 0;
	for(int i=1; i<month; ++i)
	{
		D += GetMonthDays(year, i);
	}
	D += day;

	//蔡勒公式
	int x = (year-1)+(year-1)/4 - (year-1)/100 +(year-1)/400 + D;
	return x % 7;
}

CDateTime CDateTime::NextDateTime(int n)
{
	int year = m_date.m_year;
	int month = m_date.m_month;
	int day = m_date.m_day;

	int mday = GetMonthDays(year, month);

	while(day+n > mday)
	{
		month++;
		if(month > 12)
		{
			year++;
			month = 1;
		}
		n -= mday;
		mday = GetMonthDays(year, month);
	}

	day += n;
	return CDateTime(year, month, day);
}

void CDateTime::DateTimeCalendar(int year, int month)
{
	cout<<year<<"年"<<month<<"月"<<endl;
	char* title[] = {"一","二","三","四","五","六","日"};
	for(int i=0; i<7; ++i)
		printf("%-5s", title[i]);
	cout<<endl;

	int mdays = GetMonthDays(year, month);
	int week = GetWeekByYMD(year, month, 1);
	if(week == 0)
		week = 7;
	for(int i=0; i<week-1; ++i)
	{
		printf("%-5s"," ");
	}
	for(int i=1; i<=mdays; ++i)
	{
		printf("%-5d", i);
		if((i+week-1) % 7 == 0)
		{
			cout<<endl<<endl;
		}
	}
	cout<<endl;
}