// EmplArray.cpp: implementation of the CEmplArray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "master.h"
#include "EmplArray.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEmplArray::CEmplArray()
{
    iCount = 0;
}

CEmplArray::~CEmplArray()
{

}

int rustrcmp(char *s1d, char *s2d, int iLen)
{
    char s1[255]="", s2[255]="";
    strcpy(s1, s1d);
    strcpy(s2, s2d);
    for( int i=0; s1[i] && s2[i] && i < iLen; i++ )
    {
        if( s1[i] >= 'à' && s1[i] <= 'ÿ') s1[i] -= 32;
        if( s2[i] >= 'à' && s2[i] <= 'ÿ') s2[i] -= 32;
    }
    return strnicmp(s1, s2, iLen);
}

int CEmplArray::GetEmployee(char *cFilter, char *cDestFam, DWORD *dwDestID)
{
    if( !cFilter[0] ) return 0;
    int iLen = strlen(cFilter);
    for( int i=0; i < iCount; i++ )
    {
        if( rustrcmp( cFilter, Empl[i].cFIO, iLen ) ) continue;
        else
        {
            *dwDestID = Empl[i].iID;
            strcpy(cDestFam, Empl[i].cFIO);
            return strlen(cDestFam);
        }
    }
    return 0;
}

int CEmplArray::AddEmployee(int iID, char *cFIO, DWORD dwTab)
{
    if( iID <= 0 || !cFIO[0]) return -1;
    if( iCount >= 3000 ) return -2;

    strcpy(Empl[iCount].cFIO, cFIO);
    Empl[iCount].iID = iID;
    Empl[iCount].dwTabNumber = dwTab;

    iCount++;
    return 0;
}

int CEmplArray::GetIDbyFIO(char *cFIO)
{
    for( int i=0; i < iCount; i++ )
        if( rustrcmp(cFIO, Empl[i].cFIO, 64 ) == 0) return Empl[i].iID;
    return 0;
}

DWORD CEmplArray::GetTabNumByID(int iID)
{
    for( int i=0; i < iCount; i++ )
        if( Empl[i].iID == iID ) return Empl[i].dwTabNumber;
    return 0;
}

void CEmplArray::Clear()
{
    iCount = 0;
}

CString CEmplArray::GetFamByID(DWORD dwID)
{
    for( int i=0; i < iCount; i++ )
        if( (unsigned)Empl[i].iID == dwID ) return Empl[i].cFIO ;
	return "";
}
