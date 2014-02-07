// DlgNaryadNaVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgNaryadNaVag.h"
#include ".\dlgnaryadnavag.h"
#include "PrintableDlg.h"

// CDlgNaryadNaVag dialog

IMPLEMENT_DYNAMIC(CDlgNaryadNaVag, CDialog)
CDlgNaryadNaVag::CDlgNaryadNaVag(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNaryadNaVag::IDD, pParent)
{
}

CDlgNaryadNaVag::~CDlgNaryadNaVag()
{
}

void CDlgNaryadNaVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
	DDX_Control(pDX, IDC_EDIT2, m_FIO);
}


BEGIN_MESSAGE_MAP(CDlgNaryadNaVag, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgNaryadNaVag message handlers

BOOL CDlgNaryadNaVag::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Dat.SetMode(1,1);
	m_FIO.SetMode(5,1);
	DBW.FillEmplArray(m_FIO.lpEmpl, 17);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgNaryadNaVag::OnBnClickedOk()
{
	if( !m_Dat.isValid() || m_Dat.isNull() )
	{
		AfxMessageBox("Дата указана некорректно!");
		m_Dat.SetFocus();
		return;
	}
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_GetRepPptVag1520 %u, %s, %s",
		g_iDep,
		m_Dat.GetSQLDate(),
		isNull(m_FIO.GetData()));
	if( Dlg.DoModal() == IDCANCEL ) return;	
	OnOK();
}
