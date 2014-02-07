// DlgSelKPType.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSelKPType.h"


// CDlgSelKPType dialog

IMPLEMENT_DYNAMIC(CDlgSelKPType, CDialog)

CDlgSelKPType::CDlgSelKPType(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSelKPType::IDD, pParent)
{
	dwITKP = 0;
}

CDlgSelKPType::~CDlgSelKPType()
{
}

void CDlgSelKPType::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_STATICX, m_LabNKP);
}


BEGIN_MESSAGE_MAP(CDlgSelKPType, CDialog)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CDlgSelKPType::OnNMDblclkList1)
	ON_BN_CLICKED(IDOK, &CDlgSelKPType::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgSelKPType message handlers

BOOL CDlgSelKPType::OnInitDialog()
{
	CDialog::OnInitDialog();
	dwITKP = 0;

	m_List.ModifyStyle(0, LVS_NOCOLUMNHEADER | LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD | LVS_SINGLESEL, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB );

	m_List.InsertColumn(0, "ТИП КП", LVCFMT_RIGHT, 190);

	char cQ[123] = "pTov_GetTKP";
	long Ind = 0;
	char cText[64] = "";
	SQLRETURN sqlret;

	DWORD dwNum = 0;

	DBW.ExecSQL( cQ );
	for( int i=0; (sqlret = DBW.Fetch()) != SQL_NO_DATA && sqlret != SQL_ERROR; i++ )
    {
        DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
        DBW.GetData(2, SQL_C_CHAR, cText, 32, &Ind);
		
		m_List.InsertItem(i, cText);
		m_List.SetItemData(i, dwNum );

    }
    DBW.CloseCursor();   

	m_LabNKP.SetWindowText( strNKP );

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSelKPType::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	OnBnClickedOk();
}

void CDlgSelKPType::OnBnClickedOk()
{
	int idx = m_List.GetSelectionMark();

	if( idx == -1 )
	{
		AfxMessageBox("Необходимо выбрать тип КП из списка!");
		return;
	}
	
	dwITKP = m_List.GetItemData( idx );
	strTKP = m_List.GetItemText( idx, 0 );

	OnOK();
}
