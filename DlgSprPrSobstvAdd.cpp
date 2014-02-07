// DlgSprPrSobstvAdd.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSprPrSobstvAdd.h"
#include "DlgSpravDor.h"
#include "DlgSprav1.h"
#include "DlgSpravSmp.h"

// CDlgSprPrSobstvAdd dialog

IMPLEMENT_DYNAMIC(CDlgSprPrSobstvAdd, CDialog)

CDlgSprPrSobstvAdd::CDlgSprPrSobstvAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSprPrSobstvAdd::IDD, pParent)
{
	dwPrID = 0;
	iDorCount = 0;
	dwIPR_ForOsv = 0;
}

CDlgSprPrSobstvAdd::~CDlgSprPrSobstvAdd()
{
}

void CDlgSprPrSobstvAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_EdName);
	DDX_Control(pDX, IDC_EDIT1, m_EdSName);
	DDX_Control(pDX, IDC_EDIT6, m_EdKodDor);
	DDX_Control(pDX, IDC_EDIT7, m_EdDorName);
	DDX_Control(pDX, IDC_EDIT5, m_EdOKPO);
	DDX_Control(pDX, IDC_EDIT130, m_EdKlPr);
	DDX_Control(pDX, IDC_EDIT120, m_EdLocCode);
}


BEGIN_MESSAGE_MAP(CDlgSprPrSobstvAdd, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgSprPrSobstvAdd::OnBnClickedButton_SelDor)
	ON_BN_CLICKED(IDOK, &CDlgSprPrSobstvAdd::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT6, &CDlgSprPrSobstvAdd::OnEnChangeEditKodDor)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgSprPrSobstvAdd::OnBnClickedButton_SelCl)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgSprPrSobstvAdd::OnBnClickedButton_LocCode)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgSprPrSobstvAdd::OnBnClickedButton_OKPO)
	ON_EN_KILLFOCUS(IDC_EDIT5, &CDlgSprPrSobstvAdd::OnEnKillfocusEdit5)
	ON_BN_CLICKED(IDCANCEL, &CDlgSprPrSobstvAdd::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgSprPrSobstvAdd message handlers

BOOL CDlgSprPrSobstvAdd::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdName.SetMode(0, 1, 60);
	m_EdSName.SetMode(0,1, 50);
	m_EdKodDor.QInit(20, 1);
	m_EdDorName.SetMode(0, 1, 100);
	m_EdOKPO.QInit(80, 1);
	m_EdKlPr.QInit(80, 1);
	m_EdLocCode.QInit(80, 1);

	m_EdDorName.EnableWindow(0);
	char cQ[128] = "";
	long Ind = 0;

	sprintf(cQ, "pTov_GetAllDor");
	DBW.ExecSQL(cQ);
	for (int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && i < 100; i++)
	{
		DBW.GetData(1, SQL_C_CHAR, pDorSpr[i].cCode, 3, &Ind );
		DBW.GetData(2, SQL_C_CHAR, pDorSpr[i].cName, 32, &Ind );
//		DBW.Fetch();
		iDorCount++;
	}
	DBW.CloseCursor();
	

	if( iMode && dwPrID )
	{
		char cText[80] = "";
		sprintf(cQ, "pTov_SobstvPrGet %d", dwPrID );
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(2, SQL_C_CHAR, cText, 80, &Ind);
		if( Ind != -1 ) m_EdName.SetWindowText(cText);
		DBW.GetData(3, SQL_C_CHAR, cText, 80, &Ind);
		if( Ind != -1 ) m_EdSName.SetWindowText(cText);
		DBW.GetData(4, SQL_C_CHAR, cText, 80, &Ind);
		if( Ind != -1 ) m_EdKodDor.SetWindowText(cText);
		DBW.GetData(5, SQL_C_CHAR, cText, 80, &Ind);
		if( Ind != -1 ) m_EdOKPO.SetWindowText(cText);

		DBW.CloseCursor();
	}

	 return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSprPrSobstvAdd::OnBnClickedButton_SelDor()
{
	CDlgSpravDor Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdKodDor.SetWindowText(Dlg.c_cKodDor);
	m_EdDorName.SetWindowText(Dlg.c_cFullName);
}

void CDlgSprPrSobstvAdd::OnBnClickedOk()
{
	
	int iGotDor = 0;
	for( int i=0; i < iDorCount; i++ )
	{
		if( m_EdKodDor.GetString() == (CString)pDorSpr[i].cCode )
		{
			m_EdDorName.SetWindowText( pDorSpr[i].cName );
			iGotDor = 1;
		}
	}

	if( !m_EdKodDor.isNull() && !iGotDor )
	{
		AfxMessageBox("Некорректно указан код дороги!");
		m_EdKodDor.SetFocus();
		return;
	}

	char cQ[228] = "";
	sprintf(cQ, "pTov_SobstvPrWrite %s, %s, %s, %s, %s, %s, %s, %s",
			isNull(dwPrID),
			m_EdName.GetString(1),
			m_EdSName.GetString(1),
			m_EdKodDor.GetString(1),
			m_EdOKPO.GetString(1),
			m_EdKlPr.GetString(1),
			m_EdLocCode.GetString(1),
			isNull(dwIPR_ForOsv)
			);

	DBW.ExecSQL(cQ);
	DBW.CloseCursor();

	OnOK();
}

void CDlgSprPrSobstvAdd::OnEnChangeEditKodDor()
{
	for( int i=0; i < iDorCount; i++ )
	{
		if( m_EdKodDor.GetString() == (CString)pDorSpr[i].cCode )
		{
			m_EdDorName.SetWindowText( pDorSpr[i].cName );
			return;
		}
	}
	m_EdDorName.SetWindowText("");
}

void CDlgSprPrSobstvAdd::OnBnClickedButton_SelCl()
{
	CDlgSprav1 Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;
	char cQ[128] = "";
	char cText[64] = "";
	DWORD dwNum = 0;
	long Ind = 0;

	m_EdKlPr.SetWindowText("");
	m_EdOKPO.SetWindowText("");
	m_EdLocCode.SetWindowText("");
	m_EdName.SetWindowText("");
	m_EdSName.SetWindowText("");
	m_EdDorName.SetWindowText("");
	m_EdKodDor.SetWindowText("");

	sprintf(cQ, "pTov_GetCompletePredpr %s", isNull(Dlg.ret_dwIPR));
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	dwIPR_ForOsv = Dlg.ret_dwIPR;
	DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 ) m_EdKlPr.SetWindowText(cText);
	DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 ) m_EdName.SetWindowText(cText);
	DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 ) m_EdSName.SetWindowText(cText);
	DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 ) m_EdDorName.SetWindowText(cText);
	DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 ) m_EdKodDor.SetWindowText(cText);

	DBW.CloseCursor();


	/*
	m_EdKlPr.SetWindowText(Dlg.cKodPr);
	m_EdName.SetWindowText(Dlg.cPrName);
	m_EdSName.SetWindowText(Dlg.cPrSName);
	dwPrID = Dlg.ret_dwIPR;
	*/
}

void CDlgSprPrSobstvAdd::OnBnClickedButton_LocCode()
{
	CDlgSpravSmp Dlg;
	Dlg.DlgMode = 400;
	if( Dlg.DoModal() == IDCANCEL ) return;


	m_EdKlPr.SetWindowText("");
	m_EdOKPO.SetWindowText("");
	m_EdLocCode.SetWindowText("");
	m_EdName.SetWindowText("");
	m_EdSName.SetWindowText("");
	m_EdDorName.SetWindowText("");
	m_EdKodDor.SetWindowText("");

	m_EdOKPO.SetWindowText(Dlg.c_retText);
	m_EdName.SetWindowText(Dlg.c_retText2);
	m_EdSName.SetWindowText(Dlg.c_retText2);
	m_EdLocCode.SetWindowText(Dlg.cRet);


}

void CDlgSprPrSobstvAdd::OnBnClickedButton_OKPO()
{
	CDlgSpravSmp Dlg;
	Dlg.DlgMode = 401;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdKlPr.SetWindowText("");
	m_EdOKPO.SetWindowText("");
	m_EdLocCode.SetWindowText("");
	m_EdName.SetWindowText("");
	m_EdSName.SetWindowText("");
	m_EdDorName.SetWindowText("");
	m_EdKodDor.SetWindowText("");


	m_EdOKPO.SetWindowText(Dlg.cRet);
	m_EdName.SetWindowText(Dlg.c_retText);
	m_EdSName.SetWindowText(Dlg.c_retText2);

//	m_EdLocCode.SetWindowText(Dlg.c_retText2);
}

void CDlgSprPrSobstvAdd::OnEnKillfocusEdit5()
{
//	AfxMessageBox("er");
}

void CDlgSprPrSobstvAdd::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
