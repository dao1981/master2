// DlgRptInputZhurnKompl.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRptInputZhurnKompl.h"
#include ".\dlgrptinputzhurnkompl.h"


// CDlgRptInputZhurnKompl dialog

IMPLEMENT_DYNAMIC(CDlgRptInputZhurnKompl, CDialog)
CDlgRptInputZhurnKompl::CDlgRptInputZhurnKompl(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRptInputZhurnKompl::IDD, pParent)
{
}

CDlgRptInputZhurnKompl::~CDlgRptInputZhurnKompl()
{
}

void CDlgRptInputZhurnKompl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdDat1);
	DDX_Control(pDX, IDC_EDIT2, m_EdDat2);
	DDX_Control(pDX, IDC_EDIT7, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT5, m_EdDat3);
	DDX_Control(pDX, IDC_EDIT6, m_EdDat4);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_RADIO3, m_Rad1);
	DDX_Control(pDX, IDC_RADIO2, m_Rad2);
}


BEGIN_MESSAGE_MAP(CDlgRptInputZhurnKompl, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO3, OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnBnClickedRadio2)
END_MESSAGE_MAP()


// CDlgRptInputZhurnKompl message handlers

BOOL CDlgRptInputZhurnKompl::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdNVag.QInit(80,1);
	m_EdDat1.SetMode(1, 1);
	m_EdDat2.SetMode(1, 1);

	m_HeaderCtrl.SetTitleText("Журнал комплектации");
	m_HeaderCtrl.SetDescText("Журнал контроля комплектации грузовых вагонов на пунктах текущего отцепочного ремонта.");
	
	m_HeaderCtrl.SetIconHandle(AfxGetApp()->LoadIcon(IDI_USER1));
	m_HeaderCtrl.SetIconOffset(10);
	
	m_HeaderCtrl.Init(this);
	m_HeaderCtrl.MoveCtrls(this);

	OnBnClickedRadio2();

	m_EdDat3.InitDate();
	m_EdDat4.InitDate();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgRptInputZhurnKompl::OnBnClickedOk()
{
	if( ( ( m_Rad1.GetCheck() && m_EdDat1.isNull() && m_EdDat2.isNull() ) ||
		( m_Rad2.GetCheck() && m_EdDat3.isNull() && m_EdDat4.isNull() ) ) &&
		m_EdNVag.isNull() )
	{
		AfxMessageBox("Необходимо заполнить хотя бы одно поле!", MB_OK);
		return;
	}
	char cQ[128] = "";

	if( m_Rad1.GetCheck() )
	{
		sprintf(cQ, "pTov_mkcRepHtm4624pto %d, %s, %s, %s, 0, %d",
				g_iDep,
				m_EdDat1.GetSQLDate(),
				m_EdDat2.GetSQLDate(),
				m_EdNVag.GetAsString(),
				m_Check1.GetCheck());
	} else
	{
		sprintf(cQ, "pTov_mkcRepHtm4624pto %d, %s, %s, %s, 1, %d",
				g_iDep,
				m_EdDat3.GetSQLDate(),
				m_EdDat4.GetSQLDate(),
				m_EdNVag.GetAsString(),
				m_Check1.GetCheck());

	}
	DBW.DisplayHtmlReport(cQ);
	OnOK();
}

void CDlgRptInputZhurnKompl::OnBnClickedRadio1()
{	
	m_Rad1.SetCheck(1);
	m_Rad2.SetCheck(0);	

	m_EdDat1.EnableWindow();
	m_EdDat2.EnableWindow();
	m_EdDat3.EnableWindow(0);
	m_EdDat4.EnableWindow(0);

}

void CDlgRptInputZhurnKompl::OnBnClickedRadio2()
{
	m_Rad2.SetCheck(1);
	m_Rad1.SetCheck(0);

	m_EdDat1.EnableWindow(0);
	m_EdDat2.EnableWindow(0);
	m_EdDat3.EnableWindow();
	m_EdDat4.EnableWindow();
}
