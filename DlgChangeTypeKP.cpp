// DlgChangeTypeKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgChangeTypeKP.h"


// CDlgChangeTypeKP dialog

IMPLEMENT_DYNAMIC(CDlgChangeTypeKP, CDialog)

CDlgChangeTypeKP::CDlgChangeTypeKP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChangeTypeKP::IDD, pParent)
{
	dwNewTypeKP = 0;
}

CDlgChangeTypeKP::~CDlgChangeTypeKP()
{
}

void CDlgChangeTypeKP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
}


BEGIN_MESSAGE_MAP(CDlgChangeTypeKP, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgChangeTypeKP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgChangeTypeKP message handlers

BOOL CDlgChangeTypeKP::OnInitDialog()
{
	CDialog::OnInitDialog();

	DBW.FillComboWithTKP(&m_Combo);
	for( int i=0; i < m_Combo.GetCount(); i++ )
		if( m_Combo.GetItemData(i) == dwNewTypeKP ) m_Combo.SetCurSel(i);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgChangeTypeKP::OnBnClickedOk()
{
	int idx = m_Combo.GetCurSel();
	if( idx < 0 ) return;

	if( m_Combo.GetItemData(idx) == 100 )
	{
		AfxMessageBox("Необходимо указать определенный тип КП!");
		return;
	}
	dwNewTypeKP = m_Combo.GetItemData(idx);
	m_Combo.GetWindowText(cNewTypeName, 64);
	OnOK();
}
