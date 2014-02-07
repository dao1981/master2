// DlgZapressLog.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgZapressLog.h"
#include ".\dlgzapresslog.h"
#include "DlgSpravKdr.h"

// CDlgZapressLog dialog

IMPLEMENT_DYNAMIC(CDlgZapressLog, CDlgWithAccelerators)
CDlgZapressLog::CDlgZapressLog(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgZapressLog::IDD, pParent)
{
}

CDlgZapressLog::~CDlgZapressLog()
{
}

void CDlgZapressLog::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_EDIT7, m_EdFam);
	DDX_Control(pDX, IDC_EDIT5, m_EdNum);
}


BEGIN_MESSAGE_MAP(CDlgZapressLog, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgZapressLog message handlers

BOOL CDlgZapressLog::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_EdFam.SetMode(5);
	DBW.FillEmplArray(m_EdFam.lpEmpl, 41);
	m_EdNum.QInit(100, 1);
	m_EdNum.SetWindowText("1");
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgZapressLog::OnBnClickedButton1()
{
    CDlgSpravKdr Dlg;
    Dlg.iFilter = 41;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFam.SetData(Dlg.dwFio);
    m_EdFam.SetWindowText(Dlg.cFio);
}

void CDlgZapressLog::OnBnClickedOk()
{
	if( !m_Dat1.isValid() || !m_Dat2.isValid() || m_Dat1.isNull() || m_Dat2.isNull())
	{
		AfxMessageBox("Необходимо указать временной интервал");
		return;
	}
	char cQ[128] = "";
	sprintf(cQ, "pTov_mkcRepHtmRaspres %d, %s, %s, %s, %s",
		g_iDep,
		m_Dat1.GetSQLDate(),
		m_Dat2.GetSQLDate(),
		isNull(m_EdFam.GetData()),
		m_EdNum.GetString(1)
		);
	DBW.DisplayHtmlReport(cQ);
	OnOK();
}
