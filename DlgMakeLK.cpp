// DlgMakeLK.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMakeLK.h"
#include "DlgMakeLK_KPOrder.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMakeLK dialog


CDlgMakeLK::CDlgMakeLK(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMakeLK::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMakeLK)
	//}}AFX_DATA_INIT
    bGotKPOrder = FALSE;
    dwMasterKP_ID = 0;
    ZeroMemory(p_qwIZAP, sizeof(p_qwIZAP));
    bKPOrderRecorded = 0;
}


void CDlgMakeLK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMakeLK)
	DDX_Control(pDX, IDC_EDIT5, m_Dat1);
	DDX_Control(pDX, IDC_EDIT6, m_Dat2);
	DDX_Control(pDX, IDC_EDIT4, m_Ed2);
	DDX_Control(pDX, IDC_EDIT3, m_EdPrRem);
	DDX_Control(pDX, IDC_EDIT2, m_EdNum);
	DDX_Control(pDX, IDC_EDIT1, m_Ed1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMakeLK, CDialog)
	//{{AFX_MSG_MAP(CDlgMakeLK)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton_KP)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMakeLK message handlers

BOOL CDlgMakeLK::OnInitDialog() 
{
	CDialog::OnInitDialog();
    
    m_Dat1.SetMode(1);
    m_Dat2.SetMode(1);

    CString cQ;
    char cText[64] = "";
    long Ind = 0;
    SQL_DATE_STRUCT  sqlDat;
    SYSTEMTIME st;
    DWORD dwNum = 0;
    cQ.Format("pTov_LK_GetHeader %I64u", qwILK);
    DBW.ExecSQL(cQ);
    DBW.Fetch();    
    DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 ) m_Ed1.SetWindowText(cText);
    DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 ) m_EdNum.SetWindowText(cText);
    DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 ) m_EdPrRem.SetWindowText(cText);
    DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 ) m_Ed2.SetWindowText(cText);
    DBW.GetData(5, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) 
    {
        SqlDateToSysTime(sqlDat, &st);
        m_Dat1.SetTime(&st);
    }
    DBW.GetData(6, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) 
    {
        SqlDateToSysTime(sqlDat, &st);
        m_Dat2.SetTime(&st);
    }
    DBW.GetData(7, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( dwNum )
        iOsCount = 8;
    else
        iOsCount = 4;

    DBW.GetData(8, SQL_C_ULONG, &dwMasterKP_ID, 4, &Ind); 
    dwNum = 0;
    DBW.GetData(9, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( dwNum )
        bKPOrderRecorded = TRUE;

    DBW.CloseCursor();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMakeLK::OnButton_KP() 
{
    CDlgMakeLK_KPOrder Dlg;
    Dlg.qwILK = qwILK;
    Dlg.dwFamID = dwMasterKP_ID;
    Dlg.iOsCount = iOsCount;
    if( Dlg.DoModal() == IDCANCEL ) return;
    bGotKPOrder = TRUE;
    for( int i=0; i < iOsCount; i++ )
    {
        p_qwIZAP[i] = Dlg.p_qwIZAP[i];
    }
    dwMasterKP_ID = Dlg.m_EdFam.GetData();
}

void CDlgMakeLK::OnOK() 
{
    CString cQ, cQ1, cQ2, str, strNVag, strVRem;
    int iOs = 0;
    long Ind = 0;
    char cText[64] = "";
    if( iOsCount == 8 ) iOs = 1;
    m_Ed1.GetWindowText(str);
    if( str == "" )
    {
        AfxMessageBox("Не указан номер листка комплектации",  MB_OK);
        return;
    }
    if( atoi(str) == 0 )
    {
        AfxMessageBox("Номер листка комплектации указан неверно",  MB_OK);
        return;
    }    
    if( !bGotKPOrder && !bKPOrderRecorded ) 
    {
        AfxMessageBox("Не указан порядок КП!", MB_OK);
        return;
    }

    m_EdNum.GetWindowText(strNVag);
    m_Ed2.GetWindowText(strVRem);
    cQ1.Format("pTov_LK_SetHeader %I64u, %s",
                qwILK,
                str);
    /*
                strNVag,
                strVRem,
                m_Dat1.GetSQLDate(),
                m_Dat2.GetSQLDate(),
                iOs,                
                g_iFam);*/
    cQ2.Format("pTov_UpdateLKVag %I64u, '%s', %s, %s, %u, %s, %u, 1 ",
                qwILK,
                strNVag,
                strVRem,
                m_Dat2.GetSQLDate(),
                iOs,
                m_Dat1.GetSQLDate(),
                g_iFam);

    int iRez = 0;
	DBW.ExecSQL(cQ2);
    DBW.Fetch();
    DBW.GetData(1, SQL_C_SLONG, &iRez, 4, &Ind);
	if( iRez )
	{
		DBW.GetData(2, SQL_C_CHAR, cText, 1024, &Ind);
	}
//    DBW.ClearResultSet();
	DBW.CloseCursor();
	DBW.ReallocHandle();

	if( iRez == 1 )
	{
		if( MessageBox(cText, "Внимание!", MB_YESNO ) == IDNO ) return;
	} else
	if( iRez == -1 )
	{
		MessageBox(cText, "Внимание!", MB_OK );
		return;
	}
	if( iRez )
	{
		cQ2.Format("pTov_UpdateLKVag %I64u, '%s', %s, %s, %u, %s, %u, 0 ",
                qwILK,
                strNVag,
                strVRem,
                m_Dat2.GetSQLDate(),
                iOs,
                m_Dat1.GetSQLDate(),
                g_iFam);

                DBW.ExecSQL(cQ2);
				DBW.CloseCursor();
			    DBW.ReallocHandle();
    
		DBW.ExecSQL(cQ1);
		DBW.CloseCursor();
	}
    if( bGotKPOrder )
    {
        cQ.Format("pTov_LKSetKPOrder %I64u, %s, %s, %s, %s, %s, %s, %s, %s, %s",
            qwILK,
            isNull(dwMasterKP_ID),
            isNull(p_qwIZAP[0]),
            isNull(p_qwIZAP[1]),
            isNull(p_qwIZAP[2]),
            isNull(p_qwIZAP[3]),
            isNull(p_qwIZAP[4]),
            isNull(p_qwIZAP[5]),
            isNull(p_qwIZAP[6]),
            isNull(p_qwIZAP[7])
            );
        DBW.ExecSQL(cQ);
        DBW.CloseCursor();
    }
	CDialog::OnOK();
}
