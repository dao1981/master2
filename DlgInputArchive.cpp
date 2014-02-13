// DlgInputArchive.cpp: файл реализации
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputArchive.h"
#include "afxdialogex.h"
#include "DlgBDSelectRezTL.h"

// диалоговое окно CDlgInputArchive

IMPLEMENT_DYNAMIC(CDlgInputArchive, CDialog)

CDlgInputArchive::CDlgInputArchive(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputArchive::IDD, pParent)
{

}

CDlgInputArchive::~CDlgInputArchive()
{
}

void CDlgInputArchive::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT71, m_EdNumTL);
	DDX_Control(pDX, IDC_EDIT7, m_EdNumNB);
	DDX_Control(pDX, IDC_EDIT3, m_EdNumBR);
	DDX_Control(pDX, IDC_EDIT93, m_EdDat1);
	DDX_Control(pDX, IDC_EDIT94, m_EdDat2);
}


BEGIN_MESSAGE_MAP(CDlgInputArchive, CDialog)
	ON_BN_CLICKED(IDC_CHECK41, &CDlgInputArchive::OnBnClickedCheckNTL)
	ON_BN_CLICKED(IDC_CHECK3, &CDlgInputArchive::OnBnClickedCheckNNB)
	ON_BN_CLICKED(IDC_CHECK2, &CDlgInputArchive::OnBnClickedCheckNBR)
	ON_BN_CLICKED(IDC_CHECK42, &CDlgInputArchive::OnBnClickedCheckDatRem)
	ON_BN_CLICKED(IDOK, &CDlgInputArchive::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений CDlgInputArchive


void CDlgInputArchive::OnBnClickedCheckNTL()
{
	m_EdNumTL.EnableWindow(!m_EdNumTL.IsWindowEnabled());
	if(m_EdNumTL.IsWindowEnabled()) m_EdNumTL.SetFocus();
}


void CDlgInputArchive::OnBnClickedCheckNNB()
{
	m_EdNumNB.EnableWindow(!m_EdNumNB.IsWindowEnabled());
	if(m_EdNumNB.IsWindowEnabled()) m_EdNumNB.SetFocus();
}


void CDlgInputArchive::OnBnClickedCheckNBR()
{
	m_EdNumBR.EnableWindow(!m_EdNumBR.IsWindowEnabled());
	if(m_EdNumBR.IsWindowEnabled()) m_EdNumBR.SetFocus();

}


void CDlgInputArchive::OnBnClickedCheckDatRem()
{
	m_EdDat1.EnableWindow(!m_EdDat1.IsWindowEnabled());
	m_EdDat2.EnableWindow(!m_EdDat2.IsWindowEnabled());
	if(m_EdDat1.IsWindowEnabled()) m_EdDat1.SetFocus();
}


void CDlgInputArchive::OnBnClickedOk()
{
	CDlgBDSelectRezTL Dlg;
	Dlg.iNewProc = 1;
	sprintf(Dlg.cQ, "pTov_BDTL1067Arx %d, %s, %s, %s, %s, %s",
		g_iDep,
		isAble(m_EdDat1.IsWindowEnabled(), m_EdDat1.GetSQLDate()),
		isAble(m_EdDat2.IsWindowEnabled(), m_EdDat2.GetSQLDate()),
		isAble(m_EdNumTL.IsWindowEnabled(), isNull(m_EdNumTL.GetAsString())),
		isAble(m_EdNumNB.IsWindowEnabled(), isNull(m_EdNumNB.GetAsString())),
		isAble(m_EdNumBR.IsWindowEnabled(), isNull(m_EdNumBR.GetAsString()))
		);
	Dlg.DoModal();
	CDialog::OnOK();
}


BOOL CDlgInputArchive::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdNumTL.QInit(100,1);
	m_EdNumNB.QInit(100,1);
	m_EdNumBR.QInit(100,1);
	m_EdDat1.SetMode(1,1);
	m_EdDat2.SetMode(1,1);

	m_EdNumTL.EnableWindow(0);
	m_EdNumNB.EnableWindow(0);
	m_EdNumBR.EnableWindow(0);
	m_EdDat1.EnableWindow(0);
	m_EdDat2.EnableWindow(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}
