// stdafx.cpp : source file that includes just the standard includes
//	master.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

void SqlDateToSysTime(SQL_DATE_STRUCT src, SYSTEMTIME *dst)
{
    if( dst == NULL ) return;
    memset(dst, 0, sizeof(SYSTEMTIME));
    dst->wDay = src.day;
    dst->wMonth = src.month;
    dst->wYear = src.year;
}

void DateToStrRus(SYSTEMTIME st, char *ct)
{
	
	sprintf(ct, "%.2d-%.2d-%.4d", st.wDay, st.wMonth, st.wYear);
}

void DateToSql(SYSTEMTIME st, char *ct)
{
    if( !ct ) return;
	if( st.wYear > 1800 )
		if( !st.wMilliseconds )
		{
			sprintf(ct, "'%.4d%.2d%.2d'",  st.wYear, st.wMonth, st.wDay);
		} else
			sprintf(ct, "'%.4d%.2d%.2d %.2d:%.2d'",  
					st.wYear, 
					st.wMonth, 
					st.wDay,
					st.wHour,
					st.wMinute);

	else
		strcpy(ct, "NULL");
}

void DateToStr(SYSTEMTIME st, char *ct)
{
    if( !gs_DateFmt )
        sprintf(ct, "%.2d-%.2d-%.4d", st.wDay, st.wMonth, st.wYear);
    else
        sprintf(ct, "%.2d-%.2d-%.4d", st.wMonth, st.wDay, st.wYear);
}

int SysDateCmp(SYSTEMTIME t1, SYSTEMTIME t2) //(t1 > t2 ? 1:-1
{
    if( t1.wYear > t2.wYear ) return 1;
    if( t1.wYear < t2.wYear ) return -1;
    if( t1.wMonth > t2.wMonth ) return 1;
    if( t1.wMonth < t2.wMonth ) return -1;
    if( t1.wDay > t2.wDay ) return 1;
    if( t1.wDay < t2.wDay ) return -1;
	if( t1.wHour > t2.wHour ) return 1;
	if( t1.wHour < t2.wHour ) return -1;
    if( t1.wMinute > t2.wMinute ) return 1;
	if( t1.wMinute < t2.wMinute ) return -1;

	return 0;
}

long mgSQLGetSysDate(int iCol, SYSTEMTIME *tm, long *Ind = NULL)
{
		long Ind1 = 0;
		SQL_TIMESTAMP_STRUCT ts;
		ZeroMemory(&ts, sizeof(ts));
		DBW.GetData(iCol, SQL_C_TYPE_TIMESTAMP, &ts, sizeof(ts), &Ind1);
		if( Ind1 != -1 ) 
		{
			tm->wYear = ts.year;
			tm->wMonth = ts.month;
			tm->wDay = ts.day;
			tm->wHour = ts.hour;
			tm->wMinute = ts.minute;
			tm->wSecond = ts.second;
		}
/*
	SQL_DATE_STRUCT date;
    long Ind1 = 0;
    DBW.GetData(iCol, SQL_C_TYPE_DATE, &date, sizeof(SQL_DATE_STRUCT), &Ind1);
    if( Ind ) *Ind = Ind1;
    if( Ind1 != -1 )
    {
        SqlDateToSysTime(date, tm);
	}
*/
	if ( Ind ) *Ind = Ind1;
    return Ind1;

}

CString DateToSQL(SYSTEMTIME st)
{
    if( st.wMonth < 0 || st.wMonth > 12 || st.wDay < 0 || st.wDay > 31 ||
		st.wYear < 1800 || st.wYear > 2050 || st.wHour > 24 || st.wMinute > 60)
        return "NULL";
    CString ct;
	if( !st.wMilliseconds  )
	{
		ct.Format("'%.4d%.2d%.2d'",  st.wYear, st.wMonth, st.wDay);
	} else
	{
		if( st.wMinute < 61 && st.wHour < 25 )
			ct.Format("'%.4d%.2d%.2d %.2d:%.2d'",  st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute);
	}
	if( ct == "00000000" || ct == "00000000 00:00") return "NULL";
    return ct;

}

CString StrDateToSQL(char *c, BOOL bWithNull)
{
    CString s;
    if( bWithNull )
    {
        if( c[0] == 0 ) return "NULL";
        s.Format("'%.4s%.2s%.2s'",
                 c + 6,
                 c + 3,
                 c);
       
    } else
        s.Format("%.4s%.2s%.2s",
                 c + 6,
                 c + 3,
                 c);
    return s;
}

SYSTEMTIME RusDateToSysDate(char *t)
{
    SYSTEMTIME st;
    ZeroMemory(&st, sizeof(SYSTEMTIME));
    if( !t ) return st;
	char tt[100] = "";
	strncpy(tt, t, 99);

    tt[10] = 0;
    char *token;
    tt[2] = '.';
    tt[5] = '.';
    token = strtok(tt, ".");
    st.wDay = atoi(token);
    token = strtok( NULL, ".");
    st.wMonth = atoi(token);
    token = strtok( NULL, ".");
    st.wYear = atoi(token);
    return st;

}

CString isNull(DWORD Val)
{
    CString s;
    if( Val ) s.Format("%u", Val);
    else s = "NULL";
    return s;
}

CString isNull(double Val)
{
    CString s;
    if( Val ) s.Format("%f", Val);
    else s = "NULL";
    return s;
}

CString isNull(WORD Val)
{
    CString s;
    if( Val ) s.Format("%u", Val);
    else s = "NULL";
    return s;
}

CString isNull(__int64 Val)
{
    CString s;
    if( Val ) s.Format("%I64u", Val);
    else s = "NULL";
    return s;
}

CString isNull(CString Val)
{
    CString s;
    if( Val == "" || Val == "NULL")
    {
        s = "NULL";
    } else
        s.Format("'%s'", Val);
    return s;
}

int VanNumberIsValid(CString strNum)
{
//    return 1;

    int iLen = strNum.GetLength();

    if( iLen != 8 ) return 0;

    int summ = 0, k = 0;
    for( int i = 0; i < 8; i++ )
    {
        k = strNum[i] - '0';
        k = (strNum[i] - '0') * (((i + 1) % 2) + 1);
        summ += k/10 + k%10;
    }
    if( (summ % 10) == 0 ) return 1;

    return 0;
}

CString dwtostr_null(DWORD dwNum)
{
	if( !dwNum ) return "NULL";
	char c[32] = "";
	_ultoa(dwNum, c, 10);
	return c;
}

CString dbltostr_null(double dNum)
{
	if( !dNum ) return "NULL";
	char c[32] = "";
	sprintf(c, "%f", dNum);
	return c;
}

CString isAble(int Check, CString str)
{
    if( !Check ) return "NULL";
    return str;
}

DWORD isAble(int Check, DWORD dwNum )
{
    if( !Check ) return 0;
    return dwNum;
}

int SetComboBoxItemByID( CComboBox *b, DWORD iID )
{
	if( !b ) return 0;
	for( int i=0; i < b->GetCount(); i++ )
	{
		if( b->GetItemData(i) == iID )
		{
			b->SetCurSel(i);
			return 1;
		}
	}
	b->SetCurSel( -1 );
	return 0;
}