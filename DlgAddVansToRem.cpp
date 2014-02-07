// DlgAddVansToRem.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgAddVansToRem.h"
#include ".\dlgaddvanstorem.h"
#include "DlgMsg4624_Main.h"


// CDlgAddVansToRem dialog

IMPLEMENT_DYNAMIC(CDlgAddVansToRem, CDialog)
CDlgAddVansToRem::CDlgAddVansToRem(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAddVansToRem::IDD, pParent)
{
	iNeisp = 0;
}

CDlgAddVansToRem::~CDlgAddVansToRem()
{
}

void CDlgAddVansToRem::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_EDIT1, m_EdMaskVan);
}


BEGIN_MESSAGE_MAP(CDlgAddVansToRem, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON15, OnBnClickedButton_4624)
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEditFind)
END_MESSAGE_MAP()


// CDlgAddVansToRem message handlers


BOOL CDlgAddVansToRem::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB | LVS_EX_CHECKBOXES );

	char cQ[512] = "";
	long Ind = 0;
	char cText[64] = "";
	__int64 qwNum = 0; 
	DWORD	dwNum = 0;
	int iRet = 0;

	m_List.InsertColumn(0, "№ вагона", LVCFMT_LEFT,  100);
	m_List.InsertColumn(1, "Дата обнар.", LVCFMT_LEFT,  100);
	if( !iNeisp ) m_List.InsertColumn(2, "Начало ремонта", LVCFMT_LEFT,  100);
	m_List.InsertColumn(3, "Вид ремонта", LVCFMT_LEFT,  100);

	if( !iNeisp ) sprintf(cQ, "pTov_AddRemVanList %u", g_iDep);
	else 
	{
		sprintf(cQ, "pTov_AddRemVanListNeisp %u", g_iDep);
		SetWindowText("Неисправные вагоны");
	}
		
	DBW.ExecSQL(cQ);
	for( int i = 0; (iRet = DBW.Fetch()) !=SQL_NO_DATA && iRet != SQL_ERROR && i < 32000; i++ )
	{
		m_List.InsertItem(i, "");
		DBW.GetData(1, SQL_C_UBIGINT, &qwNum, 8, &Ind);
		m_List.qwSetItemData(i, qwNum);
		DBW.GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind);
		m_List.SetCheck(i, dwNum);
		m_List.EnableItem(i, !dwNum);
		DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind);
		m_List.SetItemText(i,0,cText);
		DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
		m_List.SetItemText(i,1,cText);

		DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind);
		m_List.SetItemText(i,2,cText);
		if( iNeisp )
		{
			DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind);
			m_List.SetItemText(i,3,cText);
		}
	}
	DBW.CloseCursor();
	return TRUE; 
}

void CDlgAddVansToRem::OnBnClickedOk()
{
	char cQ[255] = "";
	int iCount = m_List.GetItemCount();
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
		if( m_List.isItemEnabled(i) && m_List.GetCheck(i) )
		{			
			sprintf(cQ, "pTov_AddRemVanTov %I64u, %u, %u", m_List.qwGetItemData(i), g_iDep, iNeisp);
			DBW.ExecSQL(cQ);
			DBW.CloseCursor();
		}
	}
	OnOK();
}

void CDlgAddVansToRem::OnBnClickedCheck1()
{
	for( int i=0; i < m_List.GetItemCount(); i++ )
		m_List.SetCheck(i, m_Check1.GetCheck());
}

void CDlgAddVansToRem::OnBnClickedButton_4624()
{
	if( m_List.GetSelectionMark() == -1 ) return;
	CDlgMsg4624_Main *Dlg = new CDlgMsg4624_Main;
//	char cText[640] = "";
	
/*	m_List.GetItemText(m_List.GetSelectionMark(), 1, cText, 64);
	Dlg.stRemDat ;= RusDateToSysDate(cText);*/
	m_List.GetItemText(m_List.GetSelectionMark(), 0, Dlg->cVagNum32, 32);
	Dlg->DoModal();
	delete Dlg;
}
CString sOldText1 = "";
void CDlgAddVansToRem::OnEnChangeEditFind()
{
    CString s1;
    CString s2;
    m_EdMaskVan.GetWindowText(s1);
    if( s1.GetLength() <= 0 )
    {
        m_List.ClearMark();
        return;
    }

    for( int i=0; i < m_List.GetItemCount(); i++ )
    {
        s2 = m_List.GetItemText(i, 0);
        if( s2.Left(s1.GetLength()) == s1 )
        {
//            int x = m_List.SetSelectionMark(i);
			m_List.ClearMark();
            m_List.SetMarkedItem(i);
//            m_List.SetHotCursor(i);
            m_List.EnsureVisible(i, TRUE);
            m_List.RedrawWindow();
            sOldText1 = s1;
            return;
        }
    }
    m_EdMaskVan.GetWindowText(sOldText1);
}
