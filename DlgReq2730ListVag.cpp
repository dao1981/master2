// DlgReq2730ListVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgReq2730ListVag.h"
#include ".\dlgreq2730listvag.h"

extern CMasterApp theApp;

// CDlgReq2730ListVag dialog

IMPLEMENT_DYNAMIC(CDlgReq2730ListVag, CDialog)
CDlgReq2730ListVag::CDlgReq2730ListVag(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgReq2730ListVag::IDD, pParent)
{
}

CDlgReq2730ListVag::~CDlgReq2730ListVag()
{
}

void CDlgReq2730ListVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	m_List.InsertColumn(0, "Номер вагона", LVCFMT_LEFT, 100);
}


BEGIN_MESSAGE_MAP(CDlgReq2730ListVag, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButtonDelete)
END_MESSAGE_MAP()


// CDlgReq2730ListVag message handlers

BOOL CDlgReq2730ListVag::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdNVag.QInit(100, 1);
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );    

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgReq2730ListVag::OnBnClickedButton1()
{
	if( m_EdNVag.isNull() )
	{
		AfxMessageBox("Необходимо указать номер вагона");
		return;
	}
	char cText1[64] = "";
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
		m_List.GetItemText( i, 0, cText1, 64);
		if( !strcmp(cText1, m_EdNVag.GetString()) )
		{
			AfxMessageBox("Указанный вагон уже есть в списке!");
			return;
		}
	}
	m_List.InsertItem(m_List.GetItemCount(), m_EdNVag.GetString());
	m_EdNVag.SetWindowText("");
}
extern int g_i2730ReqMessage;
void CDlgReq2730ListVag::OnBnClickedOk()
{
	
	if( m_List.GetItemCount() < 0 ) return;
	char cVagNum32[32] = "";
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
		m_List.GetItemText(i, 0, cVagNum32, 32 );
		if( g_i2730ReqMessage == 4618) theApp.SendTeleMessage(CString("(: 4618 2730: ") + (CString)cVagNum32 + ":)", CString("2730_") + cVagNum32);
		else theApp.SendTeleMessage(CString("(: 4628 2730: ") + (CString)cVagNum32 + ":)", CString("2730_") + cVagNum32);
	}

	OnOK();
}

void CDlgReq2730ListVag::OnBnClickedButtonDelete()
{
	if( m_List.GetSelectionMark() < 0 ) return;
	m_List.DeleteItem(m_List.GetSelectionMark());
}
