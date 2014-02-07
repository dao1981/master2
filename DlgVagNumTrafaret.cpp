// DlgVagNumTrafaret.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgVagNumTrafaret.h"
#include ".\dlgvagnumtrafaret.h"


// CDlgVagNumTrafaret dialog

IMPLEMENT_DYNAMIC(CDlgVagNumTrafaret, CDlgWithAccelerators)
CDlgVagNumTrafaret::CDlgVagNumTrafaret(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgVagNumTrafaret::IDD, pParent)
{
}

CDlgVagNumTrafaret::~CDlgVagNumTrafaret()
{
}

void CDlgVagNumTrafaret::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdDom);
	DDX_Control(pDX, IDC_EDIT2, m_EdRow);
}


BEGIN_MESSAGE_MAP(CDlgVagNumTrafaret, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgVagNumTrafaret message handlers

void CDlgVagNumTrafaret::PreInitDialog()
{
	CDlgWithAccelerators::PreInitDialog();
	m_EdDom.QInit(20, 1);
	m_EdRow.QInit(10, 1);
}

void CDlgVagNumTrafaret::OnOK()
{
	if( !m_EdDom.GetWindowTextLength() )
	{
		AfxMessageBox("Необходимо ввести номер домкрата");
		return;
	}

	wRow = (WORD)m_EdRow.GetAsDWord();
	wDomkrat = (WORD)m_EdDom.GetAsDWord();

	CDlgWithAccelerators::OnOK();
}

void CDlgVagNumTrafaret::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
