// DlgKpHisoryInp.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgKpHisoryInp.h"
#include "DlgBDSelectRez.h"
#include "PrintableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgKpHisoryInp dialog

extern CMasterApp theApp;
CDlgKpHisoryInp::CDlgKpHisoryInp(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgKpHisoryInp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgKpHisoryInp)
	//}}AFX_DATA_INIT
    iMode = 0;
}


void CDlgKpHisoryInp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgKpHisoryInp)
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgKpHisoryInp, CDialog)
	//{{AFX_MSG_MAP(CDlgKpHisoryInp)
	ON_EN_SETFOCUS(IDC_EDIT1, OnSetfocusEdit1)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, &CDlgKpHisoryInp::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CDlgKpHisoryInp::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgKpHisoryInp message handlers

BOOL CDlgKpHisoryInp::OnInitDialog() 
{
	CDialog::OnInitDialog();
    DBW.FillComboWithTKP(&m_Combo);
	if( !iMode ) m_Edit.SetMode(0, 1, 10);
	else m_Edit.QInit(100,1);
    m_Combo.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgKpHisoryInp::OnOK() 
{
	CDlgBDSelectRez Dlg;
    CString str;
    m_Edit.GetWindowText(str);
    Dlg.iMode = 1;
    if( this->iMode == 0)
    {
        sprintf(Dlg.cQ, "pTov_HistoryKP '%s', %u", str, m_Combo.GetItemData(m_Combo.GetCurSel()));
        if( Dlg.DoModal() == IDCANCEL ) return;
    } else
	if( iMode == 1 )
    {
        CPrintableDlg Dlg1;
        sprintf(Dlg1.cQ, "pTov_mkPaspByNKP '%s', %u", str, m_Combo.GetItemData(m_Combo.GetCurSel()));
        Dlg1.m_bCheck1 = false;
        Dlg1.m_bCheck2 = true;
        if( Dlg1.DoModal() == IDCANCEL ) return;
    } else
	{
        CPrintableDlg Dlg1;
        sprintf(Dlg1.cQ, "pTov_mkcReportHistoryKP '%s', %u", str, m_Combo.GetItemData(m_Combo.GetCurSel()));
        Dlg1.m_bCheck1 = false;
        Dlg1.m_bCheck2 = true;
        if( Dlg1.DoModal() == IDCANCEL ) return;
	}
	CDialog::OnOK();
}

void CDlgKpHisoryInp::OnSetfocusEdit1() 
{
    m_Edit.SetWindowText("");
}

void CDlgKpHisoryInp::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CDlgKpHisoryInp::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
