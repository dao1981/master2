// DlgEditDepo.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgEditDepo.h"
#include ".\dlgeditdepo.h"
#include "DlgSpravDor.h"

// CDlgEditDepo dialog

IMPLEMENT_DYNAMIC(CDlgEditDepo, CDlgWithAccelerators)
CDlgEditDepo::CDlgEditDepo(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgEditDepo::IDD, pParent)
{
	dwIPR = 0;
}

CDlgEditDepo::~CDlgEditDepo()
{
}

void CDlgEditDepo::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Cb1);
	DDX_Control(pDX, IDC_COMBO3, m_Cb2);
	DDX_Control(pDX, IDC_COMBO4, m_Cb3);
	DDX_Control(pDX, IDC_EDIT1, m_EdDepoName);
	DDX_Control(pDX, IDC_EDIT2, m_EdDepoSName);
	DDX_Control(pDX, IDC_EDIT3, m_EdKod);
	DDX_Control(pDX, IDC_EDIT16, m_EdKodOtd);
	DDX_Control(pDX, IDC_EDIT116, m_EdKleimo);
	DDX_Control(pDX, IDC_EDIT74, m_EdKodDor);
	DDX_Control(pDX, IDC_EDIT119, m_EdESR);
	DDX_Control(pDX, IDC_EDIT4, m_EdKPNum);
	DDX_Control(pDX, IDC_EDIT5, m_EdPasKP);
	DDX_Control(pDX, IDC_EDIT6, m_EdNeispKP);
	DDX_Control(pDX, IDC_EDIT93, m_EdRevizNum);
	DDX_Control(pDX, IDC_EDIT7, m_EdKPZ);
	DDX_Control(pDX, IDC_EDIT94, m_EdPTO);
	DDX_Control(pDX, IDC_EDIT70, m_EdOtvet);
	DDX_Control(pDX, IDC_EDIT147, m_EdKodS29xx);
	DDX_Control(pDX, IDC_CHECK2, m_CheckAutoPrih);
	DDX_Control(pDX, IDCANCEL, m_Rad1);
	DDX_Control(pDX, IDOK, m_butOK);
}


BEGIN_MESSAGE_MAP(CDlgEditDepo, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButtonSelStan)
END_MESSAGE_MAP()


// CDlgEditDepo message handlers

extern WORD g_iRang;

BOOL CDlgEditDepo::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	if( g_iRang < 3 ) m_butOK.EnableWindow(FALSE);

	CButton *bb;
	bb = (CButton *)GetDlgItem(IDC_RADIO3);
	bb->EnableWindow(FALSE);

	m_Cb1.AddString("Есть");
	m_Cb1.SetItemData(0,1);
	m_Cb1.AddString("Нет");
	m_Cb1.SetItemData(1,0);

	m_Cb2.AddString("Есть");
	m_Cb2.SetItemData(0,1);
	m_Cb2.AddString("Нет");
	m_Cb2.SetItemData(1,0);

	m_Cb3.AddString("Грузовое");
	m_Cb3.SetItemData(0,1);
	m_Cb3.AddString("Пассажирское");
	m_Cb3.SetItemData(1,2);

	m_EdDepoName.bColored = 1;
	m_EdDepoName.iMode = 0;

	m_EdDepoSName.bColored = 1;
	m_EdDepoSName.iMode = 0;

	m_EdKod.QInit(30);
	m_EdKod.bColored = 1;

	m_EdKodOtd.QInit(20);
	m_EdKodOtd.bColored = 1;

	m_EdKleimo.QInit(40);
	m_EdKleimo.bColored = 1;

	m_EdKodDor.QInit(20);
	m_EdKodDor.bColored = 1;

	m_EdESR.QInit(60);
	m_EdESR.bColored = 1;

	m_EdKPNum.QInit(60, 1);

	m_EdPasKP.QInit(60, 1);

	m_EdNeispKP.QInit(60, 1);

	m_EdRevizNum.QInit(60, 1);

	m_EdKPZ.SetMode(0, 1, 17);

	m_EdPTO.QInit(70);
	m_EdPTO.bColored = 1;

	m_EdOtvet.QInit(130, 1);

	m_EdKodS29xx.QInit(40, 1);

	m_Cb1.SetCurSel(0);
	m_Cb2.SetCurSel(0);

	if( g_iRang < 4 ) m_butOK.EnableWindow(0);
// Get DATA
	CButton *b[3];
	b[0] = (CButton *)GetDlgItem(IDC_RADIO1);
	b[1] = (CButton *)GetDlgItem(IDC_RADIO2);
	b[2] = (CButton *)GetDlgItem(IDC_RADIO3);
	char cQ[512] = "";
	char cText[64] = "";
	long Ind = 0;
	DWORD dwNum = 0;
	sprintf(cQ, "pTov_PaspDepoSel %u", g_iDep);
	DBW.ExecSQL(cQ);
	g_sqlret = DBW.Fetch();
	if( g_sqlret != SQL_NO_DATA && g_sqlret != SQL_ERROR )
	{
		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdDepoName.SetWindowText(cText);
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdDepoSName.SetWindowText(cText);
		DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_Cb3.SetCurSel(dwNum - 1);

		DBW.GetData(4, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
		{
			b[dwNum - 1]->SetCheck(1);
		}
		DBW.GetData(5, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
		{
			m_Cb1.SetCurSel(!dwNum);
		}
		DBW.GetData(6, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
		{
			m_Cb2.SetCurSel(!dwNum);
		}
		DBW.GetData(7, SQL_C_ULONG, &dwIPR, 4, &Ind );
		DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdKleimo.SetWindowText(cText);

		DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdKodDor.SetWindowText(cText);

		DBW.GetData(11, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdESR.SetWindowText(cText);

		DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdKod.SetWindowText(cText);


		DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdKodOtd.SetWindowText(cText);

		DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdKPNum.SetWindowText(cText);

		DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdPasKP.SetWindowText(cText);

		DBW.GetData(17, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdNeispKP.SetWindowText(cText);

		DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdRevizNum.SetWindowText(cText);

		DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdKPZ.SetWindowText(cText);

		DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdPTO.SetWindowText(cText);

		DBW.GetData(21, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdOtvet.SetWindowText(cText);

		DBW.GetData(22, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdKodS29xx.SetWindowText(cText);

		dwNum = 0;
		DBW.GetData(23, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
		{
			m_CheckAutoPrih.SetCheck(dwNum);
		}

		DBW.CloseCursor();
		return TRUE;
	}
	DBW.WriteLog("Ошибка получения информации о депо из БД");
	OnCancel();
	



	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgEditDepo::OnBnClickedOk()
{
	char cQ[600] = "";
	CButton *b[3];
	int iTDep = 0;
	b[0] = (CButton *)GetDlgItem(IDC_RADIO1);
	b[1] = (CButton *)GetDlgItem(IDC_RADIO2);
	b[2] = (CButton *)GetDlgItem(IDC_RADIO3);

	if( b[0]->GetCheck() ) iTDep = 1;
	else
	if( b[1]->GetCheck() ) iTDep = 2;
	else
		iTDep = 3;

	char cb1[6] = "", cb2[6] = "", cb3[6] = "";

	if( m_Cb1.GetCurSel() == -1 ) strcpy(cb1, "NULL");
	else itoa( m_Cb1.GetItemData(m_Cb1.GetCurSel()),cb1,10);

	if( m_Cb2.GetCurSel() == -1 ) strcpy(cb2, "NULL");
	else itoa( m_Cb2.GetItemData(m_Cb2.GetCurSel()),cb2,10);

	if( m_Cb3.GetCurSel() == -1 ) strcpy(cb3, "NULL");
	else itoa( m_Cb3.GetItemData(m_Cb3.GetCurSel()),cb3,10);

	if( m_EdKleimo.isNull() ) 
	{
		AfxMessageBox("Необходимо указать клеймо предприятия!");
		m_EdKleimo.SetFocus();
		return;
	}
	if( m_EdKodDor.isNull() ) 
	{
		AfxMessageBox("Необходимо указать код дороги!");
		m_EdKodDor.SetFocus();
		return;
	}
	if( m_EdESR.isNull() ) 
	{
		AfxMessageBox("Необходимо указать код станции!");
		m_EdESR.SetFocus();
		return;
	}
	sprintf( cQ, "pTov_PaspDepoIns %u, %s, %s, %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u",
			 g_iDep,
			 isNull(m_EdDepoName.GetAsString()),
			 isNull(m_EdDepoSName.GetAsString()),
			 cb3,
			 iTDep,
			 cb1,
			 cb2,
			 isNull(dwIPR),
			 m_EdKleimo.GetString(1),
			 m_EdKodDor.GetString(1),
			 m_EdESR.GetString(1),
			 m_EdKod.GetString(1),
			 m_EdKodOtd.GetString(1),
			 m_EdKPNum.GetString(),
			 m_EdPasKP.GetString(),
			 m_EdNeispKP.GetString(),
			 m_EdRevizNum.GetString(),
			 isNull(m_EdKPZ.GetString()),
			 isNull(m_EdPTO.GetString()),
			 isNull(m_EdOtvet.GetString()),
			 isNull(m_EdKodS29xx.GetString()),
			 m_CheckAutoPrih.GetCheck()
			 );
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	OnOK();
}

void CDlgEditDepo::OnBnClickedCancel()
{
	OnCancel();
}

void CDlgEditDepo::OnBnClickedButtonSelStan()
{
	if( m_EdKodDor.isNull() )
	{
		AfxMessageBox("Сначала необходимо указать код дороги!");
		m_EdKodDor.SetFocus();
		return;
	}
	CDlgSpravDor Dlg;
    Dlg.DlgMode = 1;
    m_EdKodDor.GetWindowText(Dlg.c_cDor, 4);
    if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdESR.SetWindowText(Dlg.c_cKodDor);
}
