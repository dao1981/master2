// DlgAddKpSmall.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgAddKpSmall.h"
#include "DlgShowTwin.h"
#include "DlgSpravSmp.h"
#include "DlgSprav1.h" 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <sqlext.h>
#include ".\dlgaddkpsmall.h"

extern SQLRETURN    g_sqlret;
extern CMasterApp   theApp;
extern DWORD g_iDep;
/////////////////////////////////////////////////////////////////////////////
// CDlgAddKpSmall dialog


CDlgAddKpSmall::CDlgAddKpSmall(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAddKpSmall::IDD, pParent)
	, m_strTKP(_T(""))
{
	//{{AFX_DATA_INIT(CDlgAddKpSmall)
	m_EditText = _T("");
	//}}AFX_DATA_INIT
	iCreateRecieveMode = 0;
	qwIKP = 0;
	qwIZAP = 0;
	dwGruz = 0;
	bStarted = false;
	cRemont64[0] = 0;
	ZeroMemory(&stDatIzg, sizeof(stDatIzg));
	dwIPrIzg = 0;
	dwNeispID = 0;
	cYearIzg[0] = 0;
	cKlPrIzg[0] = 0;

	dwObod_KP1 = 0;
	dwObod_KP2 = 0;
	dwGreb_KP1 = 0;
	dwGreb_KP2 = 0;
	dProkat_KP1 = 0;
	dProkat_KP2 = 0;
	dDiam_KP1 = 0;
	dDiam_KP2 = 0;
	dwDisk_KP1 = 0;
	dwDisk_KP2 = 0;
}


void CDlgAddKpSmall::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Text(pDX, IDC_EDIT1, m_EditText);
	DDX_Control(pDX, IDC_STAT_REM, m_LabelRem);
	DDX_Control(pDX, IDC_EDIT2, m_EdKod);
	DDX_Control(pDX, IDC_BUTTON1, m_But1);
	DDX_Control(pDX, IDC_EDIT3, m_EdKodName);
	DDX_Control(pDX, IDC_EDIT4, m_EdKlIzg);
	DDX_Control(pDX, IDC_EDIT5, m_EdYear);
	DDX_Control(pDX, IDC_STAT_IZG, m_LabelIzg);
	DDX_Control(pDX, IDC_STAT_YR, m_LabelYr);
	DDX_Control(pDX, IDC_BUTTON2, m_ButKl);
	DDX_Control(pDX, IDC_EDIT6, m_EdObod_KP1);
	DDX_Control(pDX, IDC_EDIT71, m_EdObod_KP2);
	DDX_Control(pDX, IDC_EDIT70, m_EdGreb_KP1);
	DDX_Control(pDX, IDC_EDIT127, m_EdGreb_KP2);
	DDX_Control(pDX, IDC_EDIT69, m_EdProkat_KP1);
	DDX_Control(pDX, IDC_EDIT72, m_EdProkat_KP2);
	DDX_Control(pDX, IDC_EDIT119, m_EdDiam_KP1);
	DDX_Control(pDX, IDC_EDIT136, m_EdDiam_KP2);
	DDX_Control(pDX, IDC_EDIT118, m_EdDisk_KP1);
	DDX_Control(pDX, IDC_EDIT78, m_EdDisk_KP2);
	DDX_Control(pDX, IDC_COMBO2, m_cbTypePodsh);
	DDX_Control(pDX, IDC_COMBO3, m_cbMSteel);
}


BEGIN_MESSAGE_MAP(CDlgAddKpSmall, CDialog)
	//{{AFX_MSG_MAP(CDlgAddKpSmall)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgAddKpSmall::OnBnClickedButton2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAddKpSmall message handlers

BOOL CDlgAddKpSmall::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_EdKlIzg.QInit(80,1);
	m_EdYear.QInit(40, 1);

	m_EdObod_KP1.QInit(20, 1);
	m_EdObod_KP2.QInit(20, 1);
	m_EdGreb_KP1.QInit(20, 1);
	m_EdGreb_KP2.QInit(20, 1);
	m_EdProkat_KP1.QInit(11, 1);
	m_EdProkat_KP2.QInit(11, 1);
	m_EdDiam_KP1.QInit(31, 1);
	m_EdDiam_KP2.QInit(31, 1);
	m_EdDisk_KP1.QInit(20, 1);
	m_EdDisk_KP2.QInit(20, 1);

	char cText[64] = "";
    long Ind = 0;
    DBW.ExecSQL("pTov_GetTKP");
    for(WORD i=0; (g_sqlret = DBW.Fetch())!= SQL_NO_DATA &&
          g_sqlret != SQL_ERROR; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwTKP[i], 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Combo1.AddString(cText);
		m_Combo1.SetItemData(i, dwTKP[i]);
    }
    DBW.CloseCursor();
    m_Combo1.SetCurSel(0);
	if( iCreateRecieveMode )
	{
//		DBW.FillComboWithRepairsKP(&m_Combo2);
		m_EdKodName.ModifyStyle(0, WS_DISABLED);
	} else
	{
//		m_Combo2.ModifyStyle(WS_VISIBLE, 0);
		m_LabelRem.ModifyStyle(WS_VISIBLE, 0);
		m_EdKod.ModifyStyle(WS_VISIBLE, 0);
		m_EdKodName.ModifyStyle(WS_VISIBLE, 0);
		m_But1.ModifyStyle(WS_VISIBLE, 0);

		m_LabelIzg.ModifyStyle(WS_VISIBLE, 0);
		m_LabelYr.ModifyStyle(WS_VISIBLE, 0);
		m_ButKl.ModifyStyle(WS_VISIBLE, 0);
		m_EdKlIzg.ModifyStyle(WS_VISIBLE, 0);
		m_EdYear.ModifyStyle(WS_VISIBLE, 0);
	}
	bStarted = 1;
	return TRUE;
}

void CDlgAddKpSmall::OnOK() 
{
    char cQ[64] = "";
//    char cText[32];
	char cNKP[33] = "";
	long Ind = 0;
	DWORD dwNum = 0;
    if( !m_Edit1.GetWindowText(cNKP, 32) )
	{
		MessageBox("Не указан номер колесной пары!", "Внимание", MB_OK);
		return;
	}
    strcpy(cNumKP, cNKP);
    dwTypeKP = dwTKP[m_Combo1.GetCurSel()];
	
	if( !iCreateRecieveMode )
	{
		sprintf(cQ, "pTov_GetKPByNum '%s', %u, '%s', %u",
				cNKP,
				dwTypeKP,
				cDate,
				g_iDep);
		DBW.ExecSQL(cQ);
		if((g_sqlret = DBW.Fetch()) == SQL_NO_DATA )
		{
			AfxMessageBox("Не зарегистрирован приход данной КП или дата прихода КП позже чем дата пересылочной ведомости.\nПовторите ввод!");
			DBW.CloseCursor();
			return;
		}
		if(g_sqlret == SQL_ERROR)
		{
			AfxMessageBox("Ошибка SQL!");
		}		
		DBW.GetData( 1, SQL_C_UBIGINT, &qwIKP, 8, &Ind);
		DBW.GetData( 2, SQL_C_UBIGINT, &qwIZAP, 8, &Ind);
		DBW.GetData( 3, SQL_C_ULONG, &dwPriznRas, 4, &Ind);
		DBW.GetData( 4, SQL_C_ULONG, &dwGruz, 4, &Ind);
		DBW.GetData( 5, SQL_C_CHAR, cRemont64, 64, &Ind);
		
		mgSQLGetSysDate( 6, &stDatIzg, &Ind );
		DBW.GetData( 7, SQL_C_ULONG, &dwIPrIzg, 4, &Ind );
		DBW.GetData( 8, SQL_C_ULONG, &dwTypeKP, 4, &Ind );
		DBW.GetData( 9, SQL_C_CHAR, cKlPrIzg, 10, &Ind);
		DBW.GetData( 10, SQL_C_CHAR, cYearIzg, 6, &Ind);


		DBW.CloseCursor();
	} else
	{
		if( !m_EdKlIzg.isNull() )
		{
			int dwNum = 0;
			sprintf(cQ, "pTov_GetPrByKl %s", m_EdKlIzg.GetString(1));
			DBW.ExecSQL(cQ);
			DBW.Fetch();
			DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
			m_EdKlIzg.SetData( dwNum );
			dwIPrIzg = dwNum;
			DBW.CloseCursor();
			if( !Ind || Ind == -1 )
			{
				AfxMessageBox("Указанный производитель КП отсутствует в справочнике!");
				m_EdKlIzg.SetFocus();
				return;
			}
		}
		
		sprintf(cQ, "pTov_GetKPCountByNKP '%s', %u", cNKP, m_Combo1.GetItemData(m_Combo1.GetCurSel()));
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
		DBW.CloseCursor();

		if( dwNum == 1 )
		{
			sprintf(cQ, "pTov_GetKPByNumForPrih '%s', %u, '%s', %u",
					cNKP,
					dwTypeKP,
					cDate,
					g_iDep);
			DBW.ExecSQL(cQ);
			DBW.Fetch();
			qwIKP=0;
			qwIZAP=0;
			dwGruz = 0;
			long Ind = 0;
			DBW.GetData( 1, SQL_C_UBIGINT, &qwIKP, 8, &Ind );
			DBW.GetData( 2, SQL_C_UBIGINT, &qwIZAP, 8, &Ind );
			DBW.GetData( 3, SQL_C_ULONG, &dwPriznRas, 4, &Ind );
			DBW.GetData( 4, SQL_C_ULONG, &dwGruz, 4, &Ind );
			DBW.GetData( 5, SQL_C_CHAR, cRemont64, 64, &Ind );
			mgSQLGetSysDate( 6, &stDatIzg, &Ind );
			DBW.GetData( 7, SQL_C_ULONG, &dwIPrIzg, 4, &Ind );
			DBW.GetData( 8, SQL_C_ULONG, &dwTypeKP, 4, &Ind );
			DBW.CloseCursor();
			if( qwIZAP )
			{
				AfxMessageBox("Уже зарегистрирован приход этой КП!");
				return;
			}
		} /*else
		if( dwNum > 1 )
		{
			CDlgShowTwin	Dlg;
			Dlg.dwTKP = m_Combo1.GetItemData(m_Combo1.GetCurSel());
			strcpy(Dlg.cNKP, cNKP);
			if( Dlg.DoModal() == IDCANCEL ) return;
			qwIKP = Dlg.qwIKP;
			m_Combo1.GetWindowText(m_strTKP);
		}*/
		m_iYearIzg = m_EdYear.GetAsDWord();
		m_iKlPrIzg = m_EdKlIzg.GetAsDWord();

		dwObod_KP1 = m_EdObod_KP1.GetAsDWord();
		dwObod_KP2 = m_EdObod_KP2.GetAsDWord();
		dwGreb_KP1 = m_EdGreb_KP1.GetAsDWord();
		dwGreb_KP2 = m_EdGreb_KP2.GetAsDWord();
		dProkat_KP1 = m_EdProkat_KP1.GetAsDouble();
		dProkat_KP2 = m_EdProkat_KP2.GetAsDouble();
		dDiam_KP1 = m_EdDiam_KP1.GetAsDouble();
		dDiam_KP2 = m_EdDiam_KP2.GetAsDouble();
		dwDisk_KP1 = m_EdDisk_KP1.GetAsDWord();
		dwDisk_KP2 = m_EdDisk_KP2.GetAsDWord();
	}
	if( !m_EdKlIzg.isNull() )
		strcpy( cKlPrIzg, m_EdKlIzg.GetAsString() );
	else cKlPrIzg[0] = 0;
	if( !m_EdYear.isNull() )
		strcpy( cYearIzg,m_EdYear.GetAsString() );
	else cYearIzg[0] = 0;
	m_Combo1.GetWindowText(m_strTKP);
	stDatIzg.wYear = m_EdYear.GetAsDWord();
	stDatIzg.wMonth = 1;
	stDatIzg.wDay = 1;
	dwIPrIzg = m_EdKlIzg.GetData();
	m_EdKodName.GetWindowText(m_strNeispName);

	dwTPodsh = m_cbTypePodsh.GetCurSel() + 1;
//	if( dwTPodsh == -1 ) dwTPodsh = 99;
	dwmSteel = m_cbMSteel.GetCurSel() + 1;
//	if( dwmSteel == -1 ) dwmSteel = 99;

	CDialog::OnOK();
}

void CDlgAddKpSmall::OnBnClickedOk()
{

	OnOK();
}

void CDlgAddKpSmall::OnBnClickedButton1()
{
    CDlgSpravSmp Dlg;
    Dlg.Style = 1;
    Dlg.DlgMode = 111;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdKod.SetWindowText(Dlg.cRet);
	m_EdKodName.SetWindowText(Dlg.c_retText3);
	dwNeispID = Dlg.dwRet;
    char st[32] = "";

}

void CDlgAddKpSmall::OnEnChangeEdit2()
{
    if( !bStarted ) return;
    char cQ[64]="";
    char cText[64]="";
    m_EdKod.GetWindowText(cText, 64);
    m_EdKodName.SetWindowText("");
    sprintf( cQ, "pTov_GetTKP 2, '%s'", cText );
    DBW.ExecSQL(cQ);
    if( (g_sqlret=DBW.Fetch()) == SQL_NO_DATA &&
         g_sqlret == SQL_ERROR ) 
    {
        DBW.CloseCursor();
		dwNeispID = 0;
        return;
    }
    long Ind = 0;
    cText[0] = 0;
    DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind);
    DBW.GetData( 2, SQL_C_SLONG, &dwNeispID, 4, &Ind);
    m_EdKodName.SetWindowText(cText);
    DBW.CloseCursor();
}

void CDlgAddKpSmall::OnBnClickedButton2()
{
	CDlgSprav1 Dlg;
    Dlg.iDlgKind = 4;
    if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdKlIzg.SetWindowText(Dlg.cKodPr);
	m_EdKlIzg.SetData(Dlg.ret_dwIPR);
}
