// DlgShowTOVKadr.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgShowTOVKadr.h"


// CDlgShowTOVKadr dialog

IMPLEMENT_DYNAMIC(CDlgShowTOVKadr, CDialog)

CDlgShowTOVKadr::CDlgShowTOVKadr(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgShowTOVKadr::IDD, pParent)
{
	dwIFam_Ret = 0;
}

CDlgShowTOVKadr::~CDlgShowTOVKadr()
{
}

void CDlgShowTOVKadr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}


BEGIN_MESSAGE_MAP(CDlgShowTOVKadr, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgShowTOVKadr::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgShowTOVKadr message handlers

BOOL CDlgShowTOVKadr::OnInitDialog()
{
	CDialog::OnInitDialog();
	cFIO[0] = 0;
	cTabN[0] = 0;
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	DWORD dwPos = 0;
	char cQ[255] = "";
	sprintf(cQ, "pTov_mkcGetTovKadr %d", g_iDep);
    DBW.ExecSQL( cQ );
    DBW.SetListHeader(&m_List);
    DBW.UpdateListByHandle(&m_List, &dwPos);
    DBW.CloseCursor();

    m_HeaderCtrl.SetTitleText("Сотрудники АРМ ТОВ");
    m_HeaderCtrl.SetDescText("Выберете сотрудника для добавления в АИС ХЧ.");

	m_HeaderCtrl.SetIconHandle(AfxGetApp()->LoadIcon(IDI_USER));
	m_HeaderCtrl.Init(this);
	m_HeaderCtrl.MoveCtrls(this);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgShowTOVKadr::OnBnClickedOk()
{
	int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    char cText[32] = "";
    char cText1[32] = "";
    char cText2[32] = "";
    m_List.GetItemText(idx, 0, cText2, 32);
    m_List.GetItemText(idx, 1, cText, 32);
//    m_List.GetItemText(idx, 2, cText1, 32);
//    sprintf(cFio, "%s %c.%c.", cText2, cText[0], cText1[0]);
    strcpy(cFIO, cText2);
	strcpy(cTabN, cText);

    dwIFam_Ret = m_List.GetItemData(idx);
	
	OnOK();
}
