#include"CDateTime.h"

void main()
{
	CDateTime dt;
	dt.DateTimeCalendar(2020, 8);
}

/*
void main()
{
	CDateTime dt;
	//dt.DateTimeShow();
	dt = dt.GetCurDateTime();
	cout<<dt<<endl;

	//2020 6 2 + 100
	CDateTime dt1 = dt.NextDateTime(100);
	cout<<dt1<<endl;

	//cout<<dt.GetWeekByYMD(2020, 2, 30)<<endl;

	//dt.DateTimeShow();
	//dt.DateTimeCalendar();

	//dt.NextDateTime(100);
	//dt.PrevDateTime(100);
	//dt++;  //++dt;
	//dt--;  //--dt;
}
*/