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