// DlgPPT_EditVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPPT_EditVag.h"
#include "DlgSpravKdr.h"

// CDlgPPT_EditVag dialog

IMPLEMENT_DYNAMIC(CDlgPPT_EditVag, CDialog)

CDlgPPT_EditVag::CDlgPPT_EditVag(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPPT_EditVag::IDD, pParent)
{
	qwIZapVag = 0;
}

CDlgPPT_EditVag::~CDlgPPT_EditVag()
{
}

void CDlgPPT_EditVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NVAG, m_LabNVag);
	DDX_Control(pDX, IDC_EDIT1, m_EdDat1067);
	DDX_Control(pDX, IDC_EDIT2, m_EdNTL1);
	DDX_Control(pDX, IDC_EDIT7, m_EdNTL2);
	DDX_Control(pDX, IDC_EDIT5, m_EdFIO1);
	DDX_Control(pDX, IDC_EDIT3, m_EdD);
	DDX_Control(pDX, IDC_EDIT16, m_EdR);
	DDX_Control(pDX, IDC_EDIT116, m_EdDat1520);
	DDX_Control(pDX, IDC_EDIT74, m_EdFIO2);
	DDX_Control(pDX, IDC_BUTTON3, m_bnCancel1520);
	DDX_Control(pDX, IDC_EDIT119, m_EdNVagTL);
	DDX_Control(pDX, IDC_EDIT118, m_EdFio_Sles);
}


BEGIN_MESSAGE_MAP(CDlgPPT_EditVag, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgPPT_EditVag::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgPPT_EditVag::OnBnClickedButtonFIO1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgPPT_EditVag::OnBnClickedButtonFIO2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgPPT_EditVag::OnBnClickedButtonCancel1520)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgPPT_EditVag::OnBnClickedButton_FioSles)
END_MESSAGE_MAP()


// CDlgPPT_EditVag message handlers

BOOL CDlgPPT_EditVag::OnInitDialog()
{
	CDialog::OnInitDialog();

	CFont *pOldFont = NULL;
	CFont boldfont;

	CFont *font = m_LabNVag.GetDC()->GetCurrentFont();
	if (font)
	{
		LOGFONT lf;
		font->GetLogFont(&lf);
		lf.lfWeight = FW_BOLD;
		boldfont.CreateFontIndirect(&lf);
		pOldFont =  m_LabNVag.GetDC()->SelectObject(&boldfont);
	}
	if (pOldFont) m_LabNVag.GetDC()->SelectObject(pOldFont);


	m_EdDat1067.SetMode(1, 1);
	m_EdNTL1.QInit(100, 1);
	m_EdNTL2.QInit(100, 1);
	m_EdFIO1.SetMode(5);
	DBW.FillEmplArray(m_EdFIO1.lpEmpl, 17);
	m_EdD.QInit(50, 1);
	m_EdR.QInit(50, 1);
	m_EdDat1520.SetMode(1, 1);
	m_EdFIO2.SetMode(5);
	m_EdNVagTL.QInit(80);
	DBW.FillEmplArray(m_EdFIO2.lpEmpl, 17);

	m_EdFio_Sles.SetMode(5);
	DBW.FillEmplArray(m_EdFio_Sles.lpEmpl, 0);



	char cQ[128] = "";
	char cText[64] = "";
	DWORD dwNum = 0;
	long Ind = 0;
	SYSTEMTIME tm;

	sprintf( cQ, "pTov_ppt_GetVagData %I64u", qwIZapVag );
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) 
	{
		m_LabNVag.SetWindowText(cText);
		strncpy(cNVag, cText, 9);
	}
	mgSQLGetSysDate(3, &tm, &Ind);
	if( Ind != -1 ) m_EdDat1067.SetTime(&tm);

	DBW.GetData( 4, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != - 1 ) m_EdNTL1.SetValue(dwNum);
	DBW.GetData( 5, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != - 1 ) m_EdNTL2.SetValue(dwNum);

	DBW.GetData( 6, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != - 1 ) 
	{
		m_EdFIO1.SetData(dwNum);
		DBW.GetData( 7, SQL_C_CHAR, cText, 64, &Ind );
		m_EdFIO1.SetWindowText(cText);
	}
	DBW.GetData( 8, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != - 1 ) m_EdD.SetValue(dwNum);
	DBW.GetData( 9, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != - 1 ) m_EdR.SetValue(dwNum);

	mgSQLGetSysDate(10, &tm, &Ind);
	if( Ind != -1 ) m_EdDat1520.SetTime(&tm);

	DBW.GetData( 11, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != - 1 ) 
	{
		m_EdFIO2.SetData(dwNum);
		DBW.GetData( 12, SQL_C_CHAR, cText, 64, &Ind );
		m_EdFIO2.SetWindowText(cText);
	}
	DBW.GetData( 13, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdNVagTL.SetWindowText(cText);

	DBW.GetData( 14, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != - 1 ) 
	{
		m_EdFio_Sles.SetData(dwNum);
		DBW.GetData( 15, SQL_C_CHAR, cText, 64, &Ind );
		m_EdFio_Sles.SetWindowText(cText);
	}



	DBW.CloseCursor();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgPPT_EditVag::OnBnClickedOk()
{
	char cQ[128] = "";
	int		iCode = 0;
	char	cMsg[255] = "";
	char	cMess[255] = "";
	long	Ind = 0;

// проверим номер первой тележки

	sprintf(cQ, "pTov_ppt_CheckTlNum %s, %s", m_EdNTL1.GetString(1), m_EdDat1067.GetSQLDate());
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SLONG, &iCode, 4, &Ind);
	DBW.GetData(2, SQL_C_CHAR, cMsg, 255, &Ind);
	if( iCode == -1 )
	{
		m_EdNTL1.SetFocus();
		AfxMessageBox(cMsg);		
		return;
	} else
	if( iCode == 1 && strcmp(cMsg, cNVag) )
	{
		m_EdNTL1.SetFocus();
		sprintf( cMess, "Данная тележка (1) была подкачена под вагон № %s!", cMsg );				
		AfxMessageBox( cMess );
		return;
	}

	DBW.CloseCursor();
// проверим номер второй тележки

	sprintf(cQ, "pTov_ppt_CheckTlNum %s", m_EdNTL2.GetString(1), m_EdDat1067.GetSQLDate());
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SLONG, &iCode, 4, &Ind);
	DBW.GetData(2, SQL_C_CHAR, cMsg, 255, &Ind);
	if( iCode == -1 )
	{
		AfxMessageBox(cMsg);
		m_EdNTL2.SetFocus();
		return;
	} else
	if( iCode == 1 && strcmp(cMsg, cNVag) )
	{
		sprintf( cMess, "Данная тележка (2) была подкачена под вагон № %s!", cMsg );
		m_EdNTL2.SetFocus();
		AfxMessageBox( cMess );		
		return;
	}
	__int64 qwIZapVagTL = 0;
	if( !m_EdNVagTL.isNull() )
	{
		sprintf(cQ, "pTov_pptGetIzapPTVag %s", m_EdNVagTL.GetString(1));
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData( 1, SQL_C_UBIGINT, &qwIZapVagTL, 8, &Ind );
		DBW.CloseCursor();
		if( Ind == -1 || !qwIZapVagTL )
		{
			AfxMessageBox("Нет данных по тележкам указанного вагона!");
			m_EdNVagTL.SetFocus();
			return;
		}
	}

	sprintf(cQ, "pTov_ppt_SaveVag %I64u, %d, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
			qwIZapVag,
			g_iDep,
			m_EdDat1067.GetSQLDate(),
			m_EdNTL1.GetString(1),
			m_EdNTL2.GetString(1),
			isNull(m_EdFIO1.GetData()),
			isNull(m_EdD.GetAsDWord()),
			isNull(m_EdR.GetAsDWord()),
			m_EdDat1520.GetSQLDate(),
			isNull(m_EdFIO2.GetData()),
			isNull(qwIZapVagTL),
			isNull(m_EdFio_Sles.GetData())
			);
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	OnOK();
}

void CDlgPPT_EditVag::OnBnClickedButtonFIO1()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 17;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFIO1.SetData(Dlg.dwFio);
	m_EdFIO1.SetWindowText(Dlg.cFio);
}

void CDlgPPT_EditVag::OnBnClickedButtonFIO2()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 17;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFIO2.SetData(Dlg.dwFio);
	m_EdFIO2.SetWindowText(Dlg.cFio);
}

void CDlgPPT_EditVag::OnBnClickedButtonCancel1520()
{
	/*
	char cQ[64] = "";
	sprintf( cQ, "pTov_ppt_Cancel1520 %I64u", qwIZapVag );
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	m_EdDat1520.EnableWindow(0);
	m_EdFIO2.EnableWindow(0);
	m_bnCancel1520.EnableWindow(0);*/
	m_EdDat1520.SetWindowText("");
	m_EdFIO2.SetWindowText("");
	m_EdFIO2.SetData(0);
	m_EdFio_Sles.SetWindowText("");
	m_EdFio_Sles.SetData(0);
	

}

void CDlgPPT_EditVag::OnBnClickedButton_FioSles()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 0;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFio_Sles.SetData(Dlg.dwFio);
	m_EdFio_Sles.SetWindowText(Dlg.cFio);
}
