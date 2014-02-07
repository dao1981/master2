// MaskEdit.cpp : implementation file
//

#include "stdafx.h"
#include "MaskEdit.h"
#include <math.h>
#include ".\maskedit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMaskEdit
DWORD CMaskEdit::dwBuffer = 0;

CMaskEdit::CMaskEdit()
{    
    iMode = 1;
    Prec = 0;
    Scale = 0;
    dwData = 0;
    bGotData = false;
    lpEmpl = NULL;
	lpStrArray = NULL;
	dwMaxLength = 0;
	iActive = 0;
	bColored = FALSE;
//	m_crBkColor = ::GetSysColor(COLOR_3DHILIGHT); // Initializing background color to the system face color.
	m_crBkColor = RGB(255,255,255);
	m_crTextColor = RGB(0,0,0); // Initializing text color to black
	m_brBkgnd.CreateSolidBrush(m_crBkColor); // Creating the Brush Color For the Edit Box Background
	dwFlags = 0;//ME_SCROLL_NORMAL;
	iDontAskForFIO = 0;
	dwStrArraySize = 0;
}

CMaskEdit::~CMaskEdit()
{
    if( iMode == 5 )
    {
        if( lpEmpl )
        {
            delete lpEmpl;
        }
    } else
	if( iMode == 6 )
		delete lpStrArray;
}

BOOL CMaskEdit::EnableWindow( BOOL bEnable )
{
	if( !bEnable ) 
	{		
		SetBkColor( GetSysColor(15) );
	}
	
	return CEdit::EnableWindow( bEnable );
}

void CMaskEdit::SetMode(int iNewMode, BOOL bIsColored, DWORD dwLength)
{
	if( iNewMode == 0 )
	{
		iMode = 0;
		dwMaxLength = dwLength;
	} else
    if( iNewMode == 3 )
    {
        iMode = 3;
        Prec = 2;
        Scale = 4;
    } else
    if( iNewMode == 1 )
    {
        iMode = 1;
    } else
    if( iNewMode == 5 )
    {
        iMode = 5;
        SetData(0);
        if( !lpEmpl )
        {
            lpEmpl = new CEmplArray;
        }
    } else
	if( iNewMode == 6 )
	{
		iMode = 6;
		if( !lpStrArray )
		{
			lpStrArray = new CString[500];
		}
	}
	bColored = bIsColored;
}

int CMaskEdit::InitDate()
{
    if( iMode != 1 && iMode != 3 ) return -1;
    SYSTEMTIME st;
    ZeroMemory(&st, sizeof(st));
    GetLocalTime(&st);
    SetDate(&st);
    RedrawWindow();
    return 0;
}

SYSTEMTIME CMaskEdit::GetAsSystemTime()
{
    SYSTEMTIME st;
    ZeroMemory(&st, sizeof(st));
    GetAsDate(&st);
    return st;
}

BEGIN_MESSAGE_MAP(CMaskEdit, CEdit)
	//{{AFX_MSG_MAP(CMaskEdit)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_CONTROL_REFLECT(EN_KILLFOCUS, OnKillfocus)
	ON_WM_SYSCHAR()
	ON_CONTROL_REFLECT(EN_SETFOCUS, OnSetfocus)
	ON_WM_SETFOCUS()
	ON_WM_MOUSEACTIVATE()
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMaskEdit message handlers

void CMaskEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    int iStart = 0;
    int iEnd = 0;
    int iNum = 0;
    char cNum[8] = "";
    char cText[32] = "";
    GetWindowText(cText, 32);
    GetSel(iStart, iEnd);

    switch ( iMode )
    {
    case 0:
        CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
    break;
    case 1:
        if( nChar == VK_RIGHT )
        {
            if( iStart == 2 )
            {
                sprintf(cNum, "%c%c", cText[0], cText[1]);
                iNum = atoi(cNum);
                if( iNum > 31 || iNum == 0) return;
                sprintf(cNum, "%.2d", iNum);
                strncpy(cText, cNum, 2);
                SetWindowText(cText);
                iStart++;         
            } 
            else
            if( iStart == 5 )
            {
                sprintf(cNum, "%c%c", cText[3], cText[4]);
                iNum = atoi(cNum);
                if( iNum > 12 || iNum == 0) return;
                sprintf(cNum, "%.2d", iNum);
                strncpy(cText + 3, cNum, 2);
                SetWindowText(cText);
                iStart ++;
            } else
            if( iStart > 9 )
            {
                iStart = 0;
            } else
            if( iStart > 5 )
            {
                if( cText[iStart] == ' ' ) return;
                else iStart++;
                if( iStart > 10 ) iStart = 0;
            }
            else    
            {
                iStart++;
            }   
            SetSel(iStart, iStart);
        } else
        if( nChar == VK_LEFT )
        {
            if( iStart == 0 )
            {
                sprintf(cNum, "%c%c", cText[0], cText[1]);
                iNum = atoi(cNum);
                if( iNum > 31 || iNum == 0) return;
                sprintf(cNum, "%.2d", iNum);
                strncpy(cText, cNum, 2);
                SetWindowText(cText);
                iStart = 10;                     
            }
            else
            if( iStart == 6 )
            {
                sprintf(cNum, "%c%c", cText[3], cText[4]);
                iNum = atoi(cNum);
                if( iNum > 12 || iNum == 0) return;
                sprintf(cNum, "%.2d", iNum);
                strncpy(cText + 3, cNum, 2);
                SetWindowText(cText);
                iStart--;
            }
            else
            iStart--;
            SetSel(iStart, iStart);
        }
        if( nChar == VK_BACK )
        {
            if( iStart == 0 ) return;
            if( iStart == 3 || iStart == 6 )
            {
                iStart--;
            } else
            {            
                iStart--;
                cText[iStart] = ' ';
                SetWindowText(cText);            
            }
            SetSel(iStart, iStart);
        }
    break;
    case 2:    
        if( nChar == VK_LEFT )
        {
            if( iStart == 0 ) return;
/*            if( iStart == Prec + 1 )
            {
                iStart -= 2;
            } else*/
                iStart--;
        } else
        if( nChar == VK_RIGHT )
        {
            if( iStart >= Prec + Scale ) return;
            else iStart++;
        } else
        if( nChar == VK_BACK )
        {
            if( iStart == 0 ) return;
            if( iStart == Prec + 1)
            {
                cText[iStart - 2] = ' ';
                iStart -= 2;
            } else
            {
                cText[iStart - 1] = ' ';
                iStart--;
            }
            SetWindowText(cText);
        } else
		if( nChar == VK_DELETE )
		{
			if( iStart >= strlen(cText)) return;
			if( Scale > 0 ) return;
			if( iStart == Prec ) iStart++;
			{
				for( int i=iStart; i < 64 && cText[i]; i++ )
				{
					cText[i] = cText[i+1];
				}
			}
			SetWindowText(cText);
		}
		
        SetSel(iStart, iStart);

    break;
    case 3:
        if( nChar == VK_LEFT )
        {
            if( iStart == 0 ) return;
            iStart--;
            if( iStart == 2 )
            {
                strcpy(cNum, cText + 3);
                if( atoi(cNum) < 1850 ) strcpy(cText + 3, "1850");
                else if( atoi(cNum) > 2050 ) strcpy(cText + 3, "2050");
                SetWindowText(cText);
            }
        } else
        if( nChar == VK_RIGHT )
        {
            if( iStart > Prec + Scale ) return;
            iStart++;
            if( iStart == 3 )
            {
                strncpy(cNum, cText, 2);
                cNum[2] = 0;
                if( atoi(cNum) < 1 ) strncpy(cText, "01",2);
                else if( atoi(cNum) > 12 ) strncpy(cText, "12", 2);
                SetWindowText(cText);
            }
        } else
        if( nChar == VK_BACK )
        {
            if( iStart == 0 ) return;
            if( iStart == Prec + 1)
            {
                cText[iStart - 2] = ' ';
                iStart -= 2;
            } else
            {
                cText[iStart - 1] = ' ';
                iStart--;
            }
            SetWindowText(cText);
        }
        SetSel(iStart, iStart);
    break;
    case 4:
        if( nChar == VK_BACK )
        {
            cText[iStart - 1] = 0;
            SetWindowText(cText);
            SetSel(iStart - 1, iStart - 1);
        }
        if( nChar == VK_DELETE )
        {
            CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
        }
    break;
    case 5:
        if( nChar == VK_F2 )
        {
            if( dwData )
                dwBuffer = dwData;
        } else
        if( nChar == VK_F3 )
        {
             this->SetFamTextByID(dwBuffer);
        }
        if( nChar == VK_BACK )
        {
//            cText[iStart - 1] = 0;
//            SetWindowText(cText);
			if( iStart == 0 ) 
			{
				SetWindowText("");
				SetData(0);
			}
            if( iStart ) SetSel(iStart - 1, strlen(cText));
        }
/*
        if( nChar == VK_DELETE )
        {
            CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
        }
*/
    break;
	case 6:
		if( nChar == VK_BACK )
        {
            cText[iStart - 1] = 0;
            SetWindowText(cText);
            SetSel(iStart - 1, iStart - 1);
        }
        if( nChar == VK_DELETE )
        {
            CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
        }
	break;
	}

//	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMaskEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    DWORD dwStyle = GetStyle();
    if( dwStyle & WS_DISABLED ) return;
    int iStart = 0, iStop = 0;
    char cText[64] = "";
    char cNum[5] = "";
    int  iNum = 0;
    DWORD dwNum = 0;
    DWORD dwID = 0;
    char cRez[64] = "";
    int  iLen1 = 0, iLen2 = 0;
    CString strText;

    switch( iMode )
    {
    case 0:
		CEdit::GetWindowText(cText, 64);
		if( !dwMaxLength || strlen(cText) < dwMaxLength || nChar == 8 )
			CEdit::OnChar(nChar, nRepCnt, nFlags);
    break;
    case 1:  //xx.xx.xxxx
        CEdit::GetSel(iStart, iStop);
        CEdit::GetWindowText(cText, 64);
        if( nChar == VK_RIGHT ) //dont work yet
        {
            if( iStart == 1 || iStart == 4 )
            {
                iStart += 2;
            } 
            else
                iStart++;
            SetSel(iStart, iStart);
        }
        if( iStart != 2 && iStart != 5 )
        {
            if( !cText[0] )
            {
                strcpy(cText, "  .  .    ");
                SetWindowText(" .  .    ");
            }
            if( nChar < '0' || nChar > '9' || iStart == 10 ) return;
            // is date is Valid?
            if( iStart == 1 )
            {
                cNum[0] = cText[0];
                cNum[1] = nChar;
                cNum[2] = 0;
                iNum = atoi(cNum);
                if( iNum > 31 || iNum == 0) 
                {
                    return;
                }
            }
            if( iStart == 4 )
            {
                cNum[0] = cText[3];
                cNum[1] = nChar;
                cNum[2] = 0;
                iNum = atoi(cNum);
                if( iNum > 12 || iNum == 0)
                {
                    return;
                }
            }            
            cText[iStart] = nChar;
            SetWindowText(cText);
            if( iStart < 9 )
            {
                iStart++;
                if( iStart == 2 || iStart == 5 ) iStart++;
                CEdit::SetSel(iStart, iStart);
            }
        } 
    break;
    case 2:
        GetSel(iStart, iStop);
        GetWindowText(cText, 64);
        if( nChar == '.' && Scale > 0)
        {
            char cNum64[64] = "";
            strcpy(cNum64, cText);
            cNum64[Prec] = 0;
//            iNum = atoi(cNum64);
            SetSel(Prec+1, Prec+1);
        } else
        {
            if( nChar < '0' || nChar > '9' || iStart == Prec + Scale + 1 ) return;
            if(cText[0] == 0 ) 
            {
                strncpy(cText, "                    ", Prec);
                strncpy(cText + Prec, ".                    ", Scale);
                cText[Prec + Scale + 1] = 0;
            }            
            if( iStart < Prec - 1 ) 
            {
                cText[iStart] = nChar;
                iStart++;
            }
            else
            if( iStart == Prec - 1) 
            {
                cText[iStart] = nChar;
                iStart = Prec + 1;
            }
            else
            if( iStart > Prec && iStart < Prec + Scale + 1 )
            {
                cText[iStart] = nChar;
                iStart++;
            }
            SetWindowText(cText);
            SetSel(iStart, iStart);
        }
    break;
    case 3:
        GetSel(iStart, iStop);
        GetWindowText(cText, 64);
        if( nChar == '.' && Scale > 0)
        {
            char cNum64[64] = "";
            strcpy(cNum64, cText);
            cNum64[Prec] = 0;
//            iNum = atoi(cNum64);
            SetSel(Prec+1, Prec+1);
            int m = atoi(cNum64);
            if( m <= 0 )
            {
                cText[1] = '1';
                SetWindowText(cText);
            } else
            if( m > 12 )
            {
                strncpy(cText, "12", 2);
                SetWindowText(cText);
            }
        } else
        {
            if( nChar < '0' || nChar > '9' || iStart == Prec + Scale + 1 ) return;
            if(cText[0] == 0 ) 
            {
                strncpy(cText, "                    ", Prec);
                strncpy(cText + Prec, ".                    ", Scale);
                cText[Prec + Scale + 1] = 0;
            }
            if( iStart < Prec - 1 ) 
            {
                cText[iStart] = nChar;
                iStart++;
            }
            else
            if( iStart == Prec - 1) //moving m -> y
            {
                cText[iStart] = nChar;
                iStart = Prec + 1;
                strncpy(cNum, cText, 2);
                cNum[2] = 0;
                if( atoi(cNum) < 1 ) strncpy(cText, "01",2);
                else if( atoi(cNum) > 12 ) strncpy(cText, "12", 2);
            }
            else
            if( iStart > Prec && iStart < Prec + Scale + 1 )
            {
                cText[iStart] = nChar;
                iStart++;
            }
            SetWindowText(cText);
            SetSel(iStart, iStart);
        }
    break;
    case 4:
            if( nChar == 8 ) return;
            CEdit::OnChar(nChar, nRepCnt, nFlags);
            if( !lpEmpl )
            {
                return;
            }
            iLen1 = 0, iLen2 = 0;
            iLen1 = GetWindowText(cText, 64);
            cRez[0] = 0;            
            dwID = 0;
            iLen2 = lpEmpl->GetEmployee(cText, cRez, &dwID);
            if( iLen2 )
            {
                SetWindowText(cRez);
                SetSel(iLen1, iLen2);
            }
    break;
    case 5:
            if( nChar == 8 ) return;
//            CEdit::OnChar(nChar, nRepCnt, nFlags);
            if( !lpEmpl )
            {
                return;
            }
            iLen1 = 0, iLen2 = 0;
            iLen1 = GetWindowText(cText, 64);
            CEdit::GetSel(iStart, iStop);
            cText[iStart] = 0;
            sprintf(cText, "%s%c", cText, nChar);
            
            cRez[0] = 0;
            dwID = 0;

            iLen2 = lpEmpl->GetEmployee(cText, cRez, &dwID);
            if( iLen2 )
            {
                SetWindowText(cRez);
                SetSel(iStart+1, strlen(cRez));
                SetData(dwID);
            }
    break;
	case 6:
			if( nChar == 8 ) return;
			if( !lpStrArray ) return;
			iLen1 = 0, iLen2 = 0;
            iLen1 = GetWindowText(cText, 64);
            CEdit::GetSel(iStart, iStop);
            cText[iStart] = 0;
            sprintf(cText, "%s%c", cText, nChar);
            
            cRez[0] = 0;
            for( int i=0; i < dwStrArraySize; i++ )
			{
				if( !strncmp(lpStrArray[i], cText, strlen(cText)) )
				{
					
				}
			}
	break;
    }
}

int CMaskEdit::GetAsDate(SYSTEMTIME *dest)
{
    ZeroMemory(dest, sizeof(SYSTEMTIME));
    char cText[64] = "";
    char cNum[16] = "";
    int  iNum = 0;
    GetWindowText(cText, 32);
    if( iMode == 1 )
    {
        strncpy(cNum, cText, 2);
        cNum[2] = 0;
        iNum = atoi(cNum);
        if( iNum > 31 || !iNum ) return -1;
        dest->wDay = iNum;
        strncpy(cNum, cText + 3, 2);
        iNum = atoi(cNum);
        if( iNum > 12 || !iNum) return -2;
        dest->wMonth = iNum;
        strncpy(cNum, cText + 6, 4);
        cNum[5] =0;
        iNum = atoi(cNum);
		if( cNum[0] && iNum < 100 )
		{
			if( iNum < 30 ) dest->wYear = 2000 + iNum;
			else dest->wYear = 1900 + iNum;
		} else
			if( iNum < 1817 || iNum > 2045 || !iNum) return -3;
			else dest->wYear = iNum;
    } else
    if( iMode == 3 )
    {
        if(!cText[0]) return 0;
		if( !cText[5] )
		{
				if( atoi(cText + 3) <= 10  )
				{
					cText[5] = cText[3]; cText[6] = cText[4]; cText[3] = '2'; cText[4] = '0'; cText[7] = 0;
				} else
				if( atoi(cText + 3) < 100  )
				{
					cText[5] = cText[3]; cText[6] = cText[4]; cText[3] = '1'; cText[4] = '9'; cText[7] = 0;
				}
		}
        dest->wDay = 1;
        strncpy(cNum, cText, 2);
        cNum[2] = 0;
        iNum = atoi(cNum);
        if( iNum > 12 || iNum < 1) return -2;
        dest->wMonth = iNum;
        strncpy(cNum, cText + 3, 4);
        cNum[5] =0;
        iNum = atoi(cNum);
		if( cNum[0] && iNum < 100 )
		{
			if( iNum < 30 ) dest->wYear = 2000 + iNum;
			else dest->wYear = 1900 + iNum;
		} else
			if( iNum < 1850 || iNum > 2050 || !iNum) return -3;
			else dest->wYear = iNum;
    }
    return 0;
}

bool CMaskEdit::isValid()
{
    char cText[64] = "";
    char cNum[16] = "";
    int  iNum = 0;
    int  i = 0;
    GetWindowText(cText, 64);    
    switch (iMode)
    {
    case 0:
        return true;
    case 1:
        strncpy(cNum, cText, 2);
        cNum[2] = 0;
        iNum = atoi(cNum);
        if( iNum > 31 || !iNum ) return false;
        strncpy(cNum, cText + 3, 2);
        iNum = atoi(cNum);
        if( iNum > 12 || !iNum) return false;
        strncpy(cNum, cText + 6, 4);
        cNum[5] =0;
        iNum = atoi(cNum);
        if(  ((iNum < 1817 && iNum > 99 ) || iNum > 2045) || !cNum[0]) return false;
    break;
    case 2:
        if( !cText[0] ) return true;
        for( i=0; i < 64 && cText[i]; )
        {
            if( cText[i] == ' ' ) 
            {
                for(int j=i; j < 64 && cText[j]; j++ ) cText[j] = cText[j+1];
            } else i++;
        }
        for( i=0; i < 64 && cText[i]; i++ )
        {
            if( (cText[i] < '0' || cText[i] > '9') && cText[i] !='.' ) return false;
            if( cText[i] == '.' ) iNum++;
            if(iNum > 1 ) return false;
        }
    break;
    case 3:
        if( !cText[0] ) return false;
        for( i=0; i < 64 && cText[i]; )
        {
            if( cText[i] == ' ' ) 
            {
                for(int j=i; j < 64 && cText[j]; j++ ) cText[j] = cText[j+1];
            } else i++;
        }
        int mm = 0, yy = 0;
        for( i=0; i < 64 && cText[i]; i++ )
        {
            if( (cText[i] < '0' || cText[i] > '9') && cText[i] !='.' ) return false;
            if( cText[i] == '.' ) iNum++;
            if( iNum > 1 ) return false;
            if( !iNum && cText[i] != '.')
            {
                mm = (mm * 10) + (cText[i] - 48);
            } else
            if( iNum && cText[i] != '.' )
            {
                yy = (yy * 10) + (cText[i] - 48);
            }
        }
        if( mm > 12 || mm < 1 ) return false;
		if( yy > 40 && yy < 100 ) yy += 1900;
		if( yy >= 0 && yy < 10 ) yy += 2000;
        if( yy > 2050 || yy < 1850 ) return false;
    break;
//date mm.yyyy must
    }
    return true;
}

CString CMaskEdit::GetString(BOOL bWithNULL)
{
    char s[128] = "";
    int ret = GetAsString(s);
	CString str;
	if( bWithNULL )
		if( s[0] == 0 || !strcmp("NULL", s) )
			str = "NULL";
		else
			str = (CString)'\'' + s + '\'';
    else
		str = s;
    return str;
}

CString CMaskEdit::GetSQLDate()
{
    char cText[32];
    CString str;
    SYSTEMTIME st;
    if(iMode == 1 || iMode == 3 )
    {
        if( isNull() || !isValid() || GetAsDate(&st)) return "NULL";
        DateToSql(st, cText);
        return cText;
    }
    return "NULL";
}

int CMaskEdit::SetAbsValue(double dV)
{
    if( dV < 0 )
        SetValue(-dV);
    else
        SetValue(dV);
    return 0;
}

int CMaskEdit::SetAbsMaxValue(double dV1, double dV2)
{
    if( dV1 < 0 ) dV1 = -dV1;
    if( dV2 < 0 ) dV2 = -dV2;
    SetValue(max(dV1, dV2));
    return 0;
}

bool CMaskEdit::isNull()
{
    char cText[64] = "";
    GetWindowText(cText, 64);
    int i = 0;
    switch(iMode)
    {
    case 1:
        for( i=0; i < 64 && cText[i]; )
        {
            if( cText[i] == ' ' || cText[i] == '.') 
            {
                for(int j=i; j < 64 && cText[j]; j++ ) cText[j] = cText[j+1];
            } else i++;
        }
        if( !strcmp(cText, ".") ) return true;
        if( cText[0] == 0 ) return true;
    case 2:
    case 3:
        for( i=0; i < 64 && cText[i]; )
        {
            if( cText[i] == ' ' ) 
            {
                for(int j=i; j < 64 && cText[j]; j++ ) cText[j] = cText[j+1];
            } else i++;
        }
        if( !strcmp(cText, ".") ) return true;
        if( cText[0] == 0 ) return true;
    break;
    default: return false;
    }
    return false;
}

int CMaskEdit::GetAsString(char *s)
{
    char cText[64] = "";
    CString cs = "";
    int  i = 0;
    int iNum = 0;
	int mm = 0, yy = 0;
    GetWindowText(cText, 64);
    if( cText[0] == 0 || !isValid())
    {
        strcpy( s, "NULL" );
        return 1;
    }
    switch (iMode)
    {
    case 1:
        sprintf(s, "%.2s-%.2s-%.4s", cText, cText + 3, cText + 6);
    break;
    case 2:
        for( i=0; i < 64 && cText[i]; )
        {
            if( cText[i] == ' ' ) 
            {
                for(int j=i; j < 64 && cText[j]; j++ ) cText[j] = cText[j+1];
            } else i++;
        }
        if( !strcmp(cText, ".") || !cText[0] ) 
        {
            strcpy( s, "NULL" );
            return 0;
        }
        if(cText[strlen(cText) - 1] == '.')
        {
            strcat(cText, "0");
        }
        sprintf(s, "%s", cText);
    break;
    case 3:
        if( !cText[0] ) return -1;
        for( i=0; i < 64 && cText[i]; )
        {
            if( cText[i] == ' ' ) 
            {
                for(int j=i; j < 64 && cText[j]; j++ ) cText[j] = cText[j+1];
            } else i++;
        }        
        for( i=0; i < 64 && cText[i]; i++ )
        {
			if( !cText[5] )
			{
				if( atoi(cText + 3) <= 10  )
				{
					cText[5] = cText[3]; cText[6] = cText[4]; cText[3] = '2'; cText[4] = '0'; cText[7] = 0;
				} else
				if( atoi(cText + 3) < 100  )
				{
					cText[5] = cText[3]; cText[6] = cText[4]; cText[3] = '1'; cText[4] = '9'; cText[7] = 0;
				}
			}
            if( (cText[i] < '0' || cText[i] > '9') && cText[i] !='.' ) return -1;
            if( cText[i] == '.' ) iNum++;
            if( iNum > 1 ) return -1;
            if( !iNum && cText[i] != '.')
            {
                mm = (mm * 10) + (cText[i]-48);
            } else
            if( iNum && cText[i] != '.' )
            {
                yy = (yy * 10) + (cText[i]-48);
            }
        }
        sprintf(s, "01-%.2d-%.4d", mm, yy);
    break;
	case 0:
		strcpy(s, cText);
		return 0;
		break;
    }    
    return 0;
}

int CMaskEdit::SetDate(SYSTEMTIME *t)
{
    char cText[16] = "";
    if( iMode == 1 )
    {
        if( t->wDay > 31 || 
            t->wDay < 1 ||
            t->wMonth > 12 ||
            t->wMonth < 1 ||
            t->wYear > 2045 ||
            t->wYear < 1870 )
        {
            return -1;
            SetWindowText("  .  .    ");
        }
        sprintf(cText, "%.2d.%.2d.%.4d",
                t->wDay,
                t->wMonth,
                t->wYear );
    } else
    if( iMode == 3 )
    {
        if( t->wMonth > 12 ||
            t->wMonth < 1 ||
            t->wYear > 2045 ||
            t->wYear < 1870 )
        {            
            SetWindowText("  .    ");
            return -1;
        }
        sprintf(cText, "%.2d.%.4d",
                t->wMonth,
                t->wYear );
    }
    SetWindowText(cText);
    return 0;
}

int CMaskEdit::SetTime(SYSTEMTIME *t)
{
    SetDate(t);
    return 0;
}

void CMaskEdit::GetTime(SYSTEMTIME *st)
{
    if( !isValid() ) return;
    ZeroMemory(st, sizeof(st));
    char cNum[8] = "";
    char cText[64] = "";
    GetWindowText(cText, 32);
    if( iMode == 1 )
    {
        strncpy(cNum, cText, 2);
        cNum[2] = 0;
        st->wDay = atoi(cNum);
        strncpy(cNum, cText+3, 2);
        cNum[2] = 0;
        st->wMonth = atoi(cNum);
        strncpy(cNum, cText+6, 4);
        cNum[4] = 0;
        st->wYear = atoi(cNum);
		if( st->wYear < 100 )
		{
			if( st->wYear < 30 )
				st->wYear += 2000;
			else
				st->wYear += 1900;
		}
    }
    else
    if( iMode == 3 )
    {
			if( !cText[5] )
			{
				if( atoi(cText + 3) <= 10  )
				{
					cText[5] = cText[3]; cText[6] = cText[4]; cText[3] = '2'; cText[4] = '0'; cText[7] = 0;
				} else
				if( atoi(cText + 3) < 100  )
				{
					cText[5] = cText[3]; cText[6] = cText[4]; cText[3] = '1'; cText[4] = '9'; cText[7] = 0;
				}
			}
        strncpy(cNum, cText, 2);
        cNum[2] = 0;
        st->wDay = 1;
        st->wMonth = atoi(cNum);
        st->wYear = atoi(cText + 3);
//        st->wYear = atoi(cNum);
		if( st->wYear < 100 )
		{
			if( st->wYear < 30 )
				st->wYear += 2000;
			else
				st->wYear += 1900;
		}
	}
}

double CMaskEdit::GetAsDouble()
{
    if( iMode != 2 ) return 0.0;
    char cText[64] = "";
    GetWindowText(cText, 64);
    int len = strlen(cText);
    for( int i=0; i < len; i++ )
    {
        if( cText[i] == ' ' )
        {
            cText[i] = cText[i + 1];
            cText[i + 1] = ' ';
        }
    }
//    SetWindowText(cText);
    return atof(cText);
}

int CMaskEdit::SetValue(DWORD dwValue)
{
    char cText[32] = "";
    _ltoa(dwValue, cText, 10);
    SetWindowText(cText);
    return 0;
}

int CMaskEdit::SetValue(double dValue)
{
    char cText[64] = "";
    char cRez[64] = "";
    char cBuf[64] = "";
    sprintf(cText, "%f", dValue);
    int i = 0;
    int len = strlen(cText);
    for (; i < len && cText[i] != '.'; i++);

    cText[i + Scale + 1] = 0;

    for(i = 0; i < len && cText[i] !='.'; i++ );

    if( i < Prec )
    {
        for( int j=0; j < Prec - i; j++ )
            cRez[j] = ' ';
        strcpy(cRez+(Prec - i), cText);
    } else
        strcpy(cRez, cText);

    SetWindowText(cRez);
    
    return 0;
}

void CMaskEdit::QInit(int Style, BOOL bStyleColored)
{
	bColored = bStyleColored;
    iMode = 2;
    Scale = Style % 10;
    Prec = Style / 10;
/*
    switch (Style)
    {
    case 33:        
        Scale = 3;
        Prec = 3;
    break;
    case 12:
        Scale = 2;
        Prec = 1;
    break;
    case 13:
        Scale = 3;
        Prec = 1;
    break;
    case 22:
        Scale = Prec = 2;
    break;
    case 32:
        Prec = 3;
        Scale = 2;        
    break;
    case 30:
        Prec = 3;
        Scale = 0;
    break;
    case 20:
        Prec = 2;
        Scale = 0;
    break;
    case 31:
        Prec = 3;
        Scale = 1;        
    break;
    }
*/
}
int CMaskEdit::SetData(DWORD dwNum)
{
    dwData = dwNum;
    bGotData = true;
    return 0;
}

DWORD CMaskEdit::GetData()
{
    return dwData;
}
/*
int CMaskEdit::SetValue(double dValue)
{
    char cText[32] = "";
    char *lpcBuff = NULL;
    char cRez[32] = "";
    int  Count = 0;
    int Sign = 0;
    lpcBuff = _fcvt( dValue, Scale, &Count, &Sign );
// if (Count > Prec ) Do some error check
    if( Count == -1 )
    {
        strcpy(cRez, "0.");
        strncpy(cRez + 2, lpcBuff, Scale);
        cRez[Scale] = 0;
//        sprintf( cRez, "0.%s", lpcBuff);
    } else
    {
        strncpy(cRez, lpcBuff, Prec);
        cRez[Prec] = 0;
        sprintf( cRez, "%s.%s", cRez, lpcBuff + Prec );
    }
    SetWindowText(cRez);
    return 0;
}
*/

CString CMaskEdit::GetDataAsString(BOOL ZeroAsNull)
{
    CString str;
    if( ZeroAsNull && !dwData )
    {
        str = "NULL";
    } else
        str.Format("%u", dwData);
    return str;
}

void CMaskEdit::OnKillfocus() 
{
	if( bColored )SetBkColor(RGB(255,255,255));
    char    cText[64];
    DWORD   dwID = 0;
    int     iLen = 0;
    char    cRez[64];
	iActive = 0;
    GetWindowText(cText, 64);


    switch( iMode )
    {
    case 5:
        if( !lpEmpl || !cText[0] ) 
        {
            SetData(0);
            break;
        }
        iLen = lpEmpl->GetEmployee(cText, cRez, &dwID);
        if( !iLen )
        {
            MessageBox("Фамилия указана не верно!", "Внимание", MB_OK);
            SetWindowText("");
            SetFocus();
			iActive = 1;
//            LPMSG lpMsg;
        }
        else
        {
            SetData(dwID);
        }
    break;
    case 4:
		if( iDontAskForFIO ) return;
        dwID = lpEmpl->GetIDbyFIO(cText);
/*
        strupr(cText);

        for( int i=0; cText[i] && i < 255; i++ )
            if( cText[i] >= 'а' && cText[i] <= 'я' ) cText[i] -= 32;
        for( i=1; cText[i] != ' ' && cText[i] && i < 255; i++ )
        {
            if( cText[i] >= 'А' && cText[i] <= 'Я' ) cText[i] += 32;
        }
        m_Edit1.SetWindowText(cText);
*/    
        if( dwID )
        {
            char cMess[1024] = "";
            sprintf(cMess, "В глобальном списке сотрудников уже есть сотрудник с ФИО \"%s\".\nДобавить его в список сотрудников МКЦ?", cText);
			int x = MessageBox(cMess, "Внимание", MB_YESNO);// == IDYES
            if( x == IDYES )
            {
                SetData(dwID);
                /*
                itoa(EmplArr.GetTabNumByID(id), cText, 10);
                m_Edit4.EnableWindow(FALSE);
                m_Edit5.SetWindowText(cText);
                m_Edit4.SetFocus();
                */
            }
            else
                SetData(0);
        }
    break;
    }
}

void CMaskEdit::OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CEdit::OnSysChar(nChar, nRepCnt, nFlags);
}

int CMaskEdit::SetFamTextByID(int dwIFAM)
{
	if( iMode != 5 || !lpEmpl ) return -1;
    CString s = lpEmpl->GetFamByID((unsigned)dwIFAM);
    if( s != "" )
    {
	    SetWindowText(s);
        SetData(dwIFAM);
        return 1;
    }
	return 0;
	
}

void CMaskEdit::OnSetfocus() 
{
	iActive = 1;
	if( iMode == 3 )
	{
		CEdit::SetSel(0,0);
	}	
}

void CMaskEdit::OnSetFocus(CWnd* pOldWnd) 
{
	CEdit::OnSetFocus(pOldWnd);
	if( iMode == 3 )
	{
		CEdit::SetSel(0,0);
	}
//	if( bColored ) SetBkColor(RGB(255,250,213)); //Желтый
	if( bColored ) SetBkColor(RGB(210,244,255));
//	CEdit::OnSetFocus(pOldWnd);
}

int CMaskEdit::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message) 
{
	int x = CEdit::OnMouseActivate(pDesktopWnd, nHitTest, message);
	CEdit::SetSel(0,10);
	return x;
}

CString CMaskEdit::GetAsString()
{
    char cText[64] = "";
    if( iMode == 2 || iMode == 0 )
    {
        GetAsString(cText);
        return cText;
    }
    return "'No compatible mode found!'";
    
}

void CMaskEdit::SetDate(SQL_DATE_STRUCT Dat)
{
	SYSTEMTIME st;
	SqlDateToSysTime(Dat, &st);
	SetDate(&st);
}

void CMaskEdit::SetTextColor(COLORREF crColor)
{
	m_crTextColor = crColor;
}

void CMaskEdit::SetBkColor(COLORREF crColor)
{
	m_crBkColor = crColor; // Passing the value passed by the dialog to the member varaible for Backgound Color
	m_brBkgnd.DeleteObject(); // Deleting any Previous Brush Colors if any existed.
	m_brBkgnd.CreateSolidBrush(crColor); // Creating the Brush Color For the Edit Box Background
	RedrawWindow();
}

HBRUSH CMaskEdit::CtlColor(CDC * pDC, UINT nCtlColor)
{
	if (!bColored /*|| this->GetStyle() & WS_DISABLED*/) return NULL;
	HBRUSH hbr;
	hbr = (HBRUSH)m_brBkgnd; // Passing a Handle to the Brush
	pDC->SetBkColor(m_crBkColor); // Setting the Color of the Text Background to the one passed by the Dialog
	pDC->SetTextColor(m_crTextColor); // Setting the Text Color to the one Passed by the Dialog

	if (nCtlColor)       // To get rid of compiler warning
      nCtlColor += 0;

	return hbr;

}

CString CMaskEdit::GetText(void)
{
	CString s;
	GetWindowText(s);
	s.Trim(' ');
	return s;
}

DWORD CMaskEdit::GetAsDWord(void)
{
//	if( iMode != 2 ) return 0;
    char cText[64] = "";
    GetWindowText(cText, 64);
//    SetWindowText(cText);
    return (DWORD)atol(cText);
}
