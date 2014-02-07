// DlgMsg4624_Header.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_Header.h"
#include ".\dlgmsg4624_header.h"
#include "DlgSpravKdr.h"
#include "DlgMsg4624_Main.h"


// CDlgMsg4624_Header dialog

IMPLEMENT_DYNAMIC(CDlgMsg4624_Header, CDlgWithAccelerators)
CDlgMsg4624_Header::CDlgMsg4624_Header(CWnd* pParent)
	: CDlgWithAccelerators(CDlgMsg4624_Header::IDD, pParent)
{
	ZeroMemory(&stDateRem, sizeof(stDateRem));
	ZeroMemory(cVagNum32, sizeof(cVagNum32));
}

CDlgMsg4624_Header::~CDlgMsg4624_Header()
{
}

void CDlgMsg4624_Header::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, m_EdRemPR);
	DDX_Control(pDX, IDC_EDIT2, m_EdKPZ);
	DDX_Control(pDX, IDC_EDIT6, m_EdVidKorr);
//	DDX_Control(pDX, IDC_EDIT16, m_EdVRem);
//	DDX_Control(pDX, IDC_EDIT93, m_DatNeisp);
	DDX_Control(pDX, IDC_EDIT5, m_EdPTO);
	DDX_Control(pDX, IDC_EDIT7, m_EdReply);
	DDX_Control(pDX, IDC_EDIT4, m_DatRem);
	DDX_Control(pDX, IDC_EDIT9, m_EdOperFIO);
	DDX_Control(pDX, IDC_EDIT1, m_EdKodSobst);
//	DDX_Control(pDX, IDC_EDIT127, m_Dat4624);
	
//	DDX_Control(pDX, IDC_EDIT73, m_Hour1);
	DDX_Control(pDX, IDC_EDIT120, m_Hour2);
//	DDX_Control(pDX, IDC_EDIT16, m_Min1);
	DDX_Control(pDX, IDC_EDIT72, m_Min2);
//	DDX_Control(pDX, IDC_EDIT8, m_EdVRemName);
}


BEGIN_MESSAGE_MAP(CDlgMsg4624_Header, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton_OperFIO)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedButton5)
END_MESSAGE_MAP()


// CDlgMsg4624_Header message handlers

void CDlgMsg4624_Header::OnOK()
{
	return;
//	CDialog::OnOK();
}

void CDlgMsg4624_Header::OnCancel()
{
	return;
//	CDialog::OnCancel();
}

extern CString toStr(DWORD dwNum);

BOOL CDlgMsg4624_Header::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();
	InitDlgItems();
/*	m_DatRem.SetTime(&stDateRem);
	m_Hour1.SetWindowText(toStr(stDateRem.wHour));
	m_Min1.SetWindowText(toStr(stDateRem.wMinute));

	m_DatNeisp.SetTime(&stDate4624); 
	m_Hour2.SetWindowText(toStr(stDate4624.wHour));
	m_Min2.SetWindowText(toStr(stDate4624.wMinute));
*/
/*
	m_pVRem[1] = "Деповский ремонт";
	m_pVRem[2] = "Капитальный ремонт";
	m_pVRem[3] = "Текущий ремонт ТР без замены деталей";
	m_pVRem[4] = "Текущий ремонт ТР2 без замены деталей";
	m_pVRem[5] = "Постройка";
	m_pVRem[6] = "Текущий ремонт ТР с заменой деталей";
	m_pVRem[7] = "Текущий ремонт ТР2 с заменой деталей";
*/
	m_EdKodSobst.SetWindowText("20");
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg4624_Header::InitDlgItems(void)
{
	m_EdRemPR.QInit(50, 1);
	m_EdKPZ.SetMode(0, 1, 17);
	m_EdVidKorr.QInit(50,1);
//	m_EdVRem.QInit(20,1);
//	m_DatNeisp.bColored = 1;
	m_EdPTO.QInit(40,1);
	m_EdReply.SetMode(0, 1, 13);
	m_DatRem.bColored = 1;
	m_EdKodSobst.QInit(50,1);
	
//	m_Dat4624.bColored = 1;
//	m_Hour1.QInit(20, 1);
	m_Hour2.QInit(20, 1);
//	m_Min1.QInit(20, 1);
	m_Min2.QInit(20, 1);

//	m_EdVRemName.ModifyStyle(0, WS_DISABLED);
}

void CDlgMsg4624_Header::OnBnClickedButton_OperFIO()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 32;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdOperFIO.SetData(Dlg.dwFio);
	m_EdOperFIO.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_Header::OnEnChangeEdit_VRem()
{
/*	char cText[64] = "";
	m_EdVRem.GetWindowText(cText, 64);
	int index = 0;
	int r = 0;
	index = atoi(cText);
	if( index != 39 && index != 49 && index > 5 ) 
	{
		m_EdVRemName.SetWindowText("");
		return;
	}
	r = index;
	if( index == 39 ) index = 6;
	if( index == 49 ) index = 7;
	m_EdVRemName.SetWindowText(m_pVRem[index]);

	CDlgMsg4624_Main *dlg = (CDlgMsg4624_Main *)m_pMainTabWnd;
	if( !dlg->bStarted ) return;
	dlg->dwVRem = r;
	if( index == 6 || index == 7 )
		dlg->InsertZamenaTabs();
	else
	{
		if( dlg->m_Tab.GetItemCount() > 5 )
		{
			dlg->m_Tab.DeleteItem(5);
			dlg->m_Tab.DeleteItem(5);
			dlg->m_Tab.DeleteItem(5);
		}
	}
	dlg->SetEnabledItemsOfRemCode(dlg->dwVRem);
//	dlg->RedrawWindow();
	m_EdVRem.SetFocus();
/*	if( (index == 6 || index == 7) m_pWnd2->m_Tab.GetItemCount() < 5 ) 
		m_pWnd2->InsertZamenaTabs();*/
	
}
void CDlgMsg4624_Header::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
}
