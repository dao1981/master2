// DlgPerestRept.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPerestRept.h"
#include ".\dlgperestrept.h"


// CDlgPerestRept dialog

IMPLEMENT_DYNAMIC(CDlgPerestRept, CDlgWithAccelerators)
CDlgPerestRept::CDlgPerestRept(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgPerestRept::IDD, pParent)
{
	iCheck = 0;
}

CDlgPerestRept::~CDlgPerestRept()
{
}

void CDlgPerestRept::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
}


BEGIN_MESSAGE_MAP(CDlgPerestRept, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgPerestRept message handlers

BOOL CDlgPerestRept::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_Dat1.SetMode(1, 1);
	m_Dat2.SetMode(1, 1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgPerestRept::OnBnClickedOk()
{
	if( m_Dat1.isNull() || !m_Dat1.isValid() )
	{
		AfxMessageBox("Необходимо указать интервал дат!");
		m_Dat1.SetFocus();
		return;
	}

	if( m_Dat2.isNull() || !m_Dat2.isValid() )
	{
		AfxMessageBox("Необходимо указать интервал дат!");
		m_Dat2.SetFocus();
		return;
	}

	d1 = m_Dat1.GetSQLDate();
	d2 = m_Dat2.GetSQLDate();
	iCheck = m_Check.GetCheck();
	OnOK();
}
