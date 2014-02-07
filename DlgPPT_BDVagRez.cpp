// DlgPPT_BDVagRez.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPPT_BDVagRez.h"
#include "DlgPPT_EditVag.h"
#include "PrintableDlg.h"
#include "DlgMsg4624_Main.h"

// CDlgPPT_BDVagRez dialog
extern CMasterApp theApp;
extern CString g_strASOUPTeleName;

IMPLEMENT_DYNAMIC(CDlgPPT_BDVagRez, CDialog)

CDlgPPT_BDVagRez::CDlgPPT_BDVagRez(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPPT_BDVagRez::IDD, pParent)
{
	sOldText = "";
}

CDlgPPT_BDVagRez::~CDlgPPT_BDVagRez()
{
}

void CDlgPPT_BDVagRez::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_STATIC_COUNT, m_LabCount);
	DDX_Control(pDX, IDC_EDIT1, m_EdMaskVan);
}


BEGIN_MESSAGE_MAP(CDlgPPT_BDVagRez, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgPPT_BDVagRez::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgPPT_BDVagRez::OnBnClickedButtonCancel1520)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgPPT_BDVagRez::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgPPT_BDVagRez::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgPPT_BDVagRez::OnBnClickedButtonReport)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgPPT_BDVagRez::OnBnClickedButton4624)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlgPPT_BDVagRez::OnBnClickedButtonZapr2730)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlgPPT_BDVagRez::OnBnClickedButtonPokaz2730)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlgPPT_BDVagRez::OnBnClickedButton_2612)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlgPPT_BDVagRez::OnBnClickedButton_Show2612)
END_MESSAGE_MAP()


// CDlgPPT_BDVagRez message handlers

BOOL CDlgPPT_BDVagRez::OnInitDialog()
{
	CDialog::OnInitDialog();

	DWORD col = 0;
	DBW.ExecSQL(cQ);
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
	m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB );
	DBW.SetListHeader(&m_List); 
	DBW.UpdateListByHandle(&m_List, &col, 0, 1);
	DWORD cnt = m_List.GetItemCount();
	char cText[64] = "";
	itoa(cnt, cText, 10);
	m_LabCount.SetWindowText(cText);
	return TRUE;  
}

void CDlgPPT_BDVagRez::RefreshList()
{
	DWORD col = 0;
	int idx = m_List.GetSelectionMark();
	m_List.DeleteAllItems();
	DBW.ExecSQL(cQ);
	DBW.UpdateListByHandle(&m_List, &col, 0, 1);
	DBW.CloseCursor();
	if( idx > -1 ) 
	{
		m_List.SetSelectionMark(idx);
		m_List.EnsureVisible(idx, 1);
	}
	DWORD cnt = m_List.GetItemCount();
	char cText[64] = "";
	itoa(cnt, cText, 10);
	m_LabCount.SetWindowText(isNull(cText));
}

void CDlgPPT_BDVagRez::OnBnClickedOk()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	CDlgPPT_EditVag Dlg;
	Dlg.qwIZapVag = m_List.qwGetItemData(idx);
	if( Dlg.DoModal() == IDOK )
	{
		RefreshList();
	}
	m_List.SetMarkedItem(idx, 1);
	m_List.EnsureVisible(idx, 1);
//	OnOK();
}

void CDlgPPT_BDVagRez::OnBnClickedButtonCancel1520()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	if( MessageBox("Вы действительно хотите отменить подкатку тележек 1520 под вагон?", "Внимание!", MB_YESNO ) == IDNO )
		return;
	char cQ[64] = "";
	sprintf( cQ, "pTov_ppt_Cancel1520 %I64u",  m_List.qwGetItemData(idx) );
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	RefreshList();
}

void CDlgPPT_BDVagRez::OnBnClickedButton3() // удалить вагон
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	if( MessageBox("Вы действительно хотите удалить данные о подкатке тележки 1067 под вагон?", "Внимание!", MB_YESNO ) == IDNO )
		return;
	char cQ1[128] = "";
	sprintf(cQ1, "pTov_pptDelVagPkt %I64u", m_List.qwGetItemData(idx));
	DBW.ExecSQL(cQ1);
	DBW.CloseCursor();

	RefreshList();
}

void CDlgPPT_BDVagRez::OnEnChangeEdit1()
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
            sOldText = s1;
            return;
        }
    }
    m_EdMaskVan.GetWindowText(sOldText);
}

void CDlgPPT_BDVagRez::OnBnClickedButtonReport()
{
	CPrintableDlg Dlg;
    sprintf(Dlg.cQ, cQReport);
    Dlg.m_bCheck1 = true;
    Dlg.m_bCheck2 = true;
    Dlg.DoModal();

}
extern int g_iNoHideRemVag4624;
void CDlgPPT_BDVagRez::OnBnClickedButton4624()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	
	CString strNVag = m_List.GetItemText(idx, 0);
	CDlgMsg4624_Main Dlg;
	
	Dlg.dwVRem = 72;

	strncpy(Dlg.cVagNum32, strNVag, 9);
	char cDat[16] = "";
	m_List.GetItemText( idx, 7, cDat, 15 );
	if( cDat[0] == 0 )
	{
		AfxMessageBox("Невозможно передать 4624, т.к. нет операции подкадки тележки 1520!");
		return;
	}
//	g_iNoHideRemVag4624 = 0;
	Dlg.stDat4624 = RusDateToSysDate(cDat);
	Dlg.DoModal();

}
extern int g_i2730ReqMessage;

void CDlgPPT_BDVagRez::OnBnClickedButtonZapr2730()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	CString strNVag = m_List.GetItemText(idx, 0);

	if( g_strASOUPTeleName )
	{
		CString strMess;
		if( g_i2730ReqMessage == 4618) strMess.Format("(: 4618 2730: %s:)", strNVag );
		else strMess.Format("(: 4628 2730: %s:)", strNVag );
		theApp.SendTeleMessage(strMess, CString("2730_") + strNVag);
	}
}

void CDlgPPT_BDVagRez::OnBnClickedButtonPokaz2730()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	
	CString strNVag = m_List.GetItemText(idx, 0);

	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_GetVU36ByNVag '%s', 1, 0", strNVag );
	Dlg.DoModal();
}

void CDlgPPT_BDVagRez::OnBnClickedButton_2612()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	CString strNVag = m_List.GetItemText(idx, 0);

	if( g_strASOUPTeleName )
	{
		CString strMess;
		/*
		if( g_i2730ReqMessage == 4618) strMess.Format("(: 4618 2730: %s:)", strNVag );
		else 
		*/
		strMess.Format("(: 4618 2612: %s:)", strNVag );
		theApp.SendTeleMessage(strMess, CString("2612_") + strNVag);
	}
}

void CDlgPPT_BDVagRez::OnBnClickedButton_Show2612()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	
	CString strNVag = m_List.GetItemText(idx, 0);

	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTHP_SelTexMaket '%s', 2612", strNVag );
	Dlg.DoModal();
}
