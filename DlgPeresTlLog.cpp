// DlgPeresTlLog.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPeresTlLog.h"
#include "DlgPeresTlAddPeres.h"

// CDlgPeresTlLog dialog

IMPLEMENT_DYNAMIC(CDlgPeresTlLog, CDialog)

CDlgPeresTlLog::CDlgPeresTlLog(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPeresTlLog::IDD, pParent)
{
	iRecieveMode = 1;
}

CDlgPeresTlLog::~CDlgPeresTlLog()
{
}

void CDlgPeresTlLog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_CHECK2, m_Check1);
	DDX_Control(pDX, IDC_CHECK3, m_Check2);
	DDX_Control(pDX, IDC_CHECK4, m_Check3);
	DDX_Control(pDX, IDC_CHECK5, m_Check4);
	DDX_Control(pDX, IDC_CHECK6, m_Check5);

	DDX_Control(pDX, IDOK, m_ButNew);
	DDX_Control(pDX, IDC_BUTTON6, m_ButDelete);
	DDX_Control(pDX, IDC_BUTTON1, m_ButEdit);
	DDX_Control(pDX, IDC_BUTTON8, m_ButSendRecv);
	DDX_Control(pDX, IDC_BUTTON2, m_Radio2);
	DDX_Control(pDX, IDC_BUTTON5, m_ButSelect);
	DDX_Control(pDX, IDC_BUTTON4, m_ButFam);
	DDX_Control(pDX, IDC_BUTTON3, m_ButPred);

	DDX_Control(pDX, IDC_EDIT8, m_EdFam);
	DDX_Control(pDX, IDC_EDIT6, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT5, m_EdPrName);
	DDX_Control(pDX, IDC_EDIT4, m_EdKlPr);
	DDX_Control(pDX, IDC_EDIT16,m_NVed2);	
	DDX_Control(pDX, IDC_EDIT3, m_NVed1);

	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
}


BEGIN_MESSAGE_MAP(CDlgPeresTlLog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgPeresTlLog::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CDlgPeresTlLog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgPeresTlLog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlgPeresTlLog::OnBnClickedButton_Select)
END_MESSAGE_MAP()


// CDlgPeresTlLog message handlers
extern DWORD g_dwPrID;
BOOL CDlgPeresTlLog::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	m_EdNVag.QInit(80, 1);
	m_EdKlPr.QInit(60, 1);
	m_NVed2.QInit(60, 1);	
	m_NVed1.QInit(60, 1);
    m_EdFam.SetMode(5);
    DBW.FillEmplArray(m_EdFam.lpEmpl, 8);


	long	Ind = 0;

    m_Check1.SetCheck(1);
    SYSTEMTIME st;
    GetLocalTime(&st);

    m_Dat2.SetTime(&st);
    if( st.wMonth == 1 )
    {
        st.wMonth = 12;
        st.wYear--;
    } else
        st.wMonth--;
	if( st.wMonth == 2 && st.wDay > 28)
	{
		st.wDay = 28;
	}
	if( st.wDay == 31 ) st.wDay = 30;
    m_Dat1.SetTime(&st);

    if( iRecieveMode )
    {
        
        b1 = (CButton *)GetDlgItem(IDC_RADIO1);
        b2 = (CButton *)GetDlgItem(IDC_RADIO2);
/*        m_Check4.ModifyStyle(WS_VISIBLE,0);
        b1->ModifyStyle(WS_VISIBLE,0 );
        b2->ModifyStyle(WS_VISIBLE,0 );
        m_EdKl.ModifyStyle(WS_VISIBLE, 0);
		m_EdPrName.EnableWindow(0);*/
        m_ButSendRecv.SetWindowText("Получить");
        this->SetWindowText("Список приходных пересылочных ведомостей");
		m_Check3.SetWindowText("Отправитель:");
    }

    if( iRecieveMode )
    {
		sprintf(cQuery, "pTov_PeresTl_GetLog %d, %d, NULL, %s, %s, NULL, NULL, NULL, NULL, NULL",
			iRecieveMode,
			g_dwPrID,
            m_Dat1.GetSQLDate(), 
            m_Dat2.GetSQLDate());

    } 
    DBW.ExecSQL(cQuery);
    DBW.SetListHeader(&m_List);
//    DBW.UpdateListByHandle(&m_List);
	RefreshList();
    DBW.CloseCursor();

/*    OnCheck1();
    OnCheck2();
    OnCheck3();
    OnCheck4();
    OnCheck5();
*/
	/*
    if( iRecieveMode )
    {
        m_ButEdit.EnableWindow(FALSE);
    }
	*/
	return TRUE;
}



void CDlgPeresTlLog::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
}


void CDlgPeresTlLog::RefreshList()
{
//    m_List.DeleteAllItems();
	char cText[64] = "";
	long Ind = 0;
	DWORD Pos = 0;
	DBW.UpdateListByHandle(&m_List, &Pos, false, true);
	if( iRecieveMode ) 
	{
		for( int i=0; i < m_List.GetItemCount(); i++ )
		{
			m_List.GetItemText(i, 7, cText, 64);
			if( cText[0] == 'ф' ) m_List.SetItemColor(i, RGB(0,0,0), RGB(255,235,235));
			else
			if( strcmp(cText, "поступила") == 0 ) m_List.SetItemColor(i, RGB(0,0,0), RGB(235,235,255));
			else
			m_List.SetItemColor(i, RGB(0,0,0), RGB(235,255,235));
		}
	} else
	{
		for( int i=0; i < m_List.GetItemCount(); i++ )
		{
			m_List.GetItemText(i, 6, cText, 64);
			if( cText[0] == 'ф' ) m_List.SetItemColor(i, RGB(0,0,0), RGB(255,235,235));
			else
			if( cText[0] == 'о' ) m_List.SetItemColor(i, RGB(0,0,0), RGB(235,235,255));
			else
			m_List.SetItemColor(i, RGB(0,0,0), RGB(235,255,235));
		}
	}
	m_List.RedrawWindow();
}

void CDlgPeresTlLog::OnBnClickedOk()
{
	CDlgPeresTlAddPeres Dlg;
	Dlg.iModeRecieve = 1;
	Dlg.qwIPERES = 0;
	Dlg.DoModal();
//	OnOK();
}


// Корректировка
void CDlgPeresTlLog::OnBnClickedButton1()
{

	int idx = m_List.GetSelectionMark();
	if( idx < 0 ) return;	
	CDlgPeresTlAddPeres Dlg;

	if( iRecieveMode ) 
	{
		Dlg.iModeRecieve = 1;
		Dlg.qwIPERES = m_List.qwGetItemData(idx);
		Dlg.DoModal();
	}
	OnBnClickedButton_Select();

}

void CDlgPeresTlLog::OnBnClickedButton_Select()
{
	char cQ[64] = "";
	
	sprintf(cQuery, "pTov_PeresTl_GetLog %d, %s, %s, %s, %s, %s, %s, %s, %s, %s",
		iRecieveMode,
		isNull(iRecieveMode == 1 ? g_dwPrID : isAble(m_Check3.GetCheck(), m_EdKlPr.GetData())),
		isNull(iRecieveMode == 0 ? g_dwPrID : isAble(m_Check3.GetCheck(), m_EdKlPr.GetData())),
		isAble(m_Check1.GetCheck(), m_Dat1.GetSQLDate()), 
        isAble(m_Check1.GetCheck(), m_Dat2.GetSQLDate()),

		isAble(m_Check2.GetCheck(), m_NVed1.GetString(1)),
		isAble(m_Check2.GetCheck(), m_NVed2.GetString(1)),

		isAble(m_Check4.GetCheck(), b1->GetCheck() ? "1" : "0" ),
		isAble(m_Check4.GetCheck(), m_EdNVag.GetString(1)),
		isAble(m_Check5.GetCheck(), isNull(m_EdFam.GetData()))
		);

	    DBW.ExecSQL(cQuery);
//		DBW.SetListHeader(&m_List);
//    DBW.UpdateListByHandle(&m_List);
		RefreshList();
		DBW.CloseCursor();
}
