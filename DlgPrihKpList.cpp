// DlgPrihKpList.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPrihKpList.h"


// CDlgPrihKpList dialog
extern CString sOldText;

IMPLEMENT_DYNAMIC(CDlgPrihKpList, CDialog)

CDlgPrihKpList::CDlgPrihKpList(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPrihKpList::IDD, pParent)
{
	iModeCheckbox = 0;
	iRetCount = 0;
	iGotHeader = 0;
}

CDlgPrihKpList::~CDlgPrihKpList()
{
}

void CDlgPrihKpList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT1, m_EdMaskKP);

	DDX_Control(pDX, IDC_CHECK1, m_But1);
	DDX_Control(pDX, IDC_CHECK39, m_But2);
	DDX_Control(pDX, IDC_CHECK31, m_But3);
}


BEGIN_MESSAGE_MAP(CDlgPrihKpList, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgPrihKpList::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgPrihKpList::OnEnChangeEditFind)
	ON_BN_CLICKED(IDC_CHECK39, &CDlgPrihKpList::OnBnClickedCheck39)
	ON_BN_CLICKED(IDC_CHECK1, &CDlgPrihKpList::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK31, &CDlgPrihKpList::OnBnClickedCheck31)
END_MESSAGE_MAP()


// CDlgPrihKpList message handlers

BOOL CDlgPrihKpList::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
	m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB );

	if( iModeCheckbox == 1 ) m_List.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB );

	m_But1.SetCheck(1);
	RefreshList();
	sOldText = "";
	return TRUE; 
}

void CDlgPrihKpList::OnBnClickedOk()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 && !iModeCheckbox ) 
	{
		AfxMessageBox("Необходимо выбрать КП!");
		return;
	}
	if( idx != -1 ) qwRetIZap = m_List.qwGetItemData(idx);
	else qwRetIZap = 0;
	if( iModeCheckbox == 1 )
	{
		iRetCount = 0;
		for( int i = 0; i < m_List.GetItemCount(); i++ )
		{
			if( m_List.GetCheck( i ) )
			{
				qwRetIzapList[ iRetCount ] = m_List.qwGetItemData( i );
				iRetCount++;
			}
		}
	}	
	OnOK();
}

void CDlgPrihKpList::OnEnChangeEditFind()
{
    CString s1;
    CString s2;
    m_EdMaskKP.GetWindowText(s1);
    if( s1.GetLength() <= 0 )
    {
        m_List.ClearMark();
        return;
    }
		
    for( int i=0; i < m_List.GetItemCount(); i++ )
    {
        s2 = m_List.GetItemText(i, 1);
        if( s2.Left(s1.GetLength()) == s1 )
        {
//            int x = m_List.SetSelectionMark(i);
			m_List.ClearMark();
            m_List.SetMarkedItem(i);
//            m_List.SetHotCursor(i);
            m_List.EnsureVisible(i, TRUE);
            m_List.RedrawWindow();
            sOldText = s1;
            return;
        }
    }
    m_EdMaskKP.GetWindowText(sOldText);}

void CDlgPrihKpList::OnBnClickedCheck1()
{
//	if( m_But2.GetCheck() ) m_But2.SetCheck( !m_But1.GetCheck() );
//	if( m_But3.GetCheck() ) m_But3.SetCheck( !m_But1.GetCheck() );
	if( !m_But2.GetCheck() && !m_But3.GetCheck() ) { m_But1.SetCheck(1); return; }
	m_But2.SetCheck(0);
	m_But3.SetCheck(0);
	RefreshList();
}

void CDlgPrihKpList::OnBnClickedCheck39()
{
//	if( m_But1.GetCheck() ) m_But1.SetCheck( !m_But2.GetCheck() );
//	if( !m_But2.GetCheck() && !m_But3.GetCheck() ) m_But1.SetCheck(1);
	if( !m_But1.GetCheck() && !m_But3.GetCheck() ) { m_But2.SetCheck(1); return; }
	m_But1.SetCheck(0);
	m_But3.SetCheck(0);
	RefreshList();
}



void CDlgPrihKpList::OnBnClickedCheck31()
{
//	if( m_But1.GetCheck() ) m_But1.SetCheck( !m_But3.GetCheck() );
//	if( !m_But2.GetCheck() && !m_But3.GetCheck() ) m_But1.SetCheck(1);
	if( !m_But1.GetCheck() && !m_But2.GetCheck() ) { m_But3.SetCheck(1); return; }
	m_But1.SetCheck(0);
	m_But2.SetCheck(0);
	RefreshList();
}

void CDlgPrihKpList::RefreshList(void)
{
	char cQ[255] = "";
	DWORD dwCol = 0;
	sprintf(cQ, "pTov_KP_GetPrihodList %u, %u, %u", 
			g_iDep,
			m_But2.GetCheck(),
			m_But3.GetCheck());
	DBW.ExecSQL(cQ);	
	if( !iGotHeader ) {
		DBW.SetListHeader(&m_List);
		iGotHeader = 1;
	}
	DBW.UpdateListByHandle(&m_List, &dwCol, 0, 1);

	DBW.CloseCursor();
}
