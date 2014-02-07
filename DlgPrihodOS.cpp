// DlgPrihodOS.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPrihodOS.h"
#include "DlgSprav1.h"
#include "DlgSpravKdr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPrihodOS dialog


CDlgPrihodOS::CDlgPrihodOS(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgPrihodOS::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPrihodOS)
	//}}AFX_DATA_INIT
    m_Dat1.SetMode(1);
    m_Dat2.SetMode(1);
    m_Dat3.SetMode(3);
    dwIPR = 0;
    dwIPR2 = 0;
    iUpdate = 0;
    dwPriznRas = 0;
    dwGruz = 0;
    ZeroMemory(&st, sizeof(st));
}


void CDlgPrihodOS::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPrihodOS)
	DDX_Control(pDX, IDC_EDIT10, m_EdNPos);
	DDX_Control(pDX, IDC_EDIT6, m_EdNVed);
	DDX_Control(pDX, IDC_EDIT2, m_EdType);
	DDX_Control(pDX, IDC_EDIT1, m_EdNum);
	DDX_Control(pDX, IDC_EDIT9, m_EdKlPr2);
	DDX_Control(pDX, IDC_EDIT11, m_EdFIO);
	DDX_Control(pDX, IDC_EDIT5, m_EdNamePr);
	DDX_Control(pDX, IDC_EDIT4, m_EdKlPr);
	DDX_Control(pDX, IDC_EDIT8, m_Dat3);
	DDX_Control(pDX, IDC_EDIT7, m_Dat2);
	DDX_Control(pDX, IDC_EDIT3, m_Dat1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPrihodOS, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgPrihodOS)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonSelectPr)
	ON_BN_CLICKED(IDC_BUTTON2, OnSelectIzgPr)
	ON_BN_CLICKED(IDC_BUTTON3, OnButtonFIO)
	ON_EN_KILLFOCUS(IDC_EDIT4, OnKillfocusEditKl1)
	ON_EN_KILLFOCUS(IDC_EDIT9, OnKillfocusEditPr2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPrihodOS message handlers

void CDlgPrihodOS::OnButtonSelectPr() 
{
    CDlgSprav1 Dlg;	
    Dlg.iDlgKind = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwIPR = Dlg.ret_dwIPR;
    m_EdKlPr.SetWindowText(Dlg.cKodPr);
    m_EdNamePr.SetWindowText(Dlg.cPrName);
}

void CDlgPrihodOS::OnSelectIzgPr() 
{
	CDlgSprav1 Dlg;	
    Dlg.iDlgKind = 4;
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwIPR2 = Dlg.ret_dwIPR;
    m_EdKlPr2.SetWindowText(Dlg.cKodPr);    
}

void CDlgPrihodOS::OnButtonFIO() 
{
    CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    Dlg.iFilter = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFIO.SetWindowText(Dlg.cFio);
    m_EdFIO.SetData(Dlg.dwFio);
}

BOOL CDlgPrihodOS::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
	m_EdFIO.SetMode(5);
    DBW.FillEmplArray(m_EdFIO.lpEmpl, 1);

    m_EdNum.SetWindowText(strNum);
    m_EdType.SetWindowText(strType);

    FillForm();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgPrihodOS::OnKillfocusEditKl1() 
{
    CString str;
    m_EdKlPr.GetWindowText(str);
    if( str == "" )
    {
        dwIPR = 0;
        return;
    }
    char cText[255] = "";
    char cQ[128] = "";
    long Ind = 0;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwIPR, 4, &Ind);
    DBW.GetData( 7, SQL_C_CHAR, cText, 254, &Ind);
/*    DBW.GetData( 4, SQL_C_BIT, &lbCanForm, 1, &Ind);*/
    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        MessageBox("Введено некорректное клеймо предприятия!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdKlPr.SetWindowText("");
        m_EdNamePr.SetWindowText("");
		m_EdKlPr.SetFocus();
        return;
    }
    m_EdNamePr.SetWindowText(cText);	
}

void CDlgPrihodOS::OnKillfocusEditPr2() 
{
    CString str;
    m_EdKlPr2.GetWindowText(str);
    if( str == "" )
    {
        dwIPR2 = 0;
        return;
    }
    char cText[255] = "";
    char cQ[128] = "";
    long Ind = 0;
    bool lbCanIzgOs = false;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwIPR2, 4, &Ind);
    DBW.GetData( 3, SQL_C_BIT, &lbCanIzgOs, 1, &Ind);
    DBW.GetData( 7, SQL_C_CHAR, cText, 254, &Ind);    
    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR || !lbCanIzgOs )
    {
        MessageBox("Введено некорректное клеймо предприятия изготовления оси!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdKlPr2.SetWindowText("");
		m_EdKlPr2.SetFocus();
        return;
    }
}

void CDlgPrihodOS::OnOK() 
{
    if( m_Dat1.isNull() )
    {
        MessageBox("Не указана дата поступления!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_Dat1.SetFocus();
        return;
    }
    if( !dwIPR )
    {
        MessageBox("Не указано предприятие откуда поступила ось!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdKlPr.SetFocus();
        return;
    }
    if( m_Dat3.isNull() )
    {
        MessageBox("Не указана дата изготовления оси!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_Dat3.SetFocus();
        return;
    }
    if( !dwIPR2 )
    {
        MessageBox("Не указано предприятие изготовления оси!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdKlPr2.SetFocus();
        return;
    }
    if( !m_EdFIO.GetData() )
    {
        MessageBox("Не указана фамилия принявшего!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdFIO.SetFocus();
        return;
    }
    
    CString cQ;
    CString strNVed, strNPos;
    m_EdNVed.GetWindowText(strNVed);
    m_EdNPos.GetWindowText(strNPos);
    if( !iUpdate )
    cQ.Format("pTov_PrihodOs NULL, NULL, %u, '%s', %u, %s, %u, %s, %s, %u, %s, %s, %u, %u, %u",
        g_iDep,
        strNum,
        dwTKP,
        m_Dat1.GetSQLDate(),
        dwIPR,
        m_Dat2.GetSQLDate(),
        isNull(strNVed),
        dwIPR2,
        m_Dat3.GetSQLDate(),
        isNull(strNPos),
        m_EdFIO.GetData(),
        dwPriznRas,
        dwGruz);
    else
    cQ.Format("pTov_PrihodOs %I64u, %I64u, %u, '%s', %u, %s, %u, %s, %s, %u, %s, %s, %u, %u, %u",
        qwIKP,
        qwIZAP,
        g_iDep,
        strNum,
        dwTKP,
        m_Dat1.GetSQLDate(),
        dwIPR,
        m_Dat2.GetSQLDate(),
        isNull(strNVed),
        dwIPR2,
        m_Dat3.GetSQLDate(),
        isNull(strNPos),
        m_EdFIO.GetData(),
        dwPriznRas,
        dwGruz);

//    AfxMessageBox(cQ);
    
    long Ind = 0;
    int  iNum = 0;
    char cText[64] = "";
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    DBW.GetData(1, SQL_C_SLONG, &iNum, 4, &Ind);
    if( iNum )
    {
        DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
        if( Ind != -1 )
        {
            MessageBox(cText ,"Внимание", MB_OK| MB_ICONINFORMATION);
        }
    } else
    {
        DBW.GetData(2, SQL_C_UBIGINT, &qwIKP, 8, &Ind );
        DBW.GetData(3, SQL_C_UBIGINT, &qwIZAP, 8, &Ind );
        DBW.GetData(4, SQL_C_ULONG, &dwPriznRas, 4, &Ind );
        DBW.GetData(5, SQL_C_ULONG, &dwGruz, 4, &Ind );
    }
    DBW.CloseCursor();
    m_Dat1.GetTime(&st);
	CDlgWithAccelerators::OnOK();
}

int CDlgPrihodOS::FillForm()
{
    CString cQ;
    cQ.Format("pTov_GetPrihodOs %I64u", qwIZAP);
    DBW.ExecSQL(cQ);
    if( (g_sqlret =DBW.Fetch()) == SQL_NO_DATA )
    {
        iUpdate = 0;
        DBW.CloseCursor();
        return -1;
    }
    if( g_sqlret == SQL_ERROR )
    {
        DBW.CloseCursor();
        CDlgWithAccelerators::OnCancel();
        return -1;
    }
    iUpdate = 1;
    long Ind = 0;
    SQL_DATE_STRUCT  sqlDat;
    SYSTEMTIME st;
    DWORD   dwNum = 0;
    char cText[64] = "";

    DBW.GetData(1, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        m_Dat1.SetTime(&st);
    }
    DBW.GetData(2, SQL_C_ULONG, &dwIPR, 4, &Ind);
    if( Ind != -1 )
    {
        DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
        if( Ind != -1 ) m_EdKlPr.SetWindowText(cText);
        DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
        if( Ind != -1 ) m_EdNamePr.SetWindowText(cText);
        DBW.GetData(5, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
        if( Ind != -1 )
        {
            SqlDateToSysTime(sqlDat, &st);
            m_Dat2.SetTime(&st);
        }
        DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
        if( Ind != -1 ) m_EdNVed.SetWindowText(cText); 
    }
    DBW.GetData(7, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        m_Dat3.SetTime(&st);
    }
    DBW.GetData(8, SQL_C_ULONG, &dwIPR2, 4, &Ind);
    DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
    if( Ind != -1 ) m_EdKlPr2.SetWindowText(cText);
    DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
    if( Ind != -1 ) m_EdNPos.SetWindowText(cText);
    DBW.GetData(11, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( Ind != -1 )
    {
        m_EdFIO.SetData(dwNum);
        DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind );
        if( Ind != -1 ) m_EdFIO.SetWindowText(cText);
    }
    DBW.CloseCursor();
    return 0;
}

void CDlgPrihodOS::OnCancel() 
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	
	CDlgWithAccelerators::OnCancel();
}
