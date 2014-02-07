// DlgRptVU53.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRptVU53.h"
#include "PrintableDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRptVU53 dialog


CDlgRptVU53::CDlgRptVU53(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRptVU53::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRptVU53)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgRptVU53::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRptVU53)
	DDX_Control(pDX, IDC_CHECK38, m_Bn3);
	DDX_Control(pDX, IDC_CHECK31, m_Bn2);
	DDX_Control(pDX, IDC_CHECK1, m_Bn1);
	DDX_Control(pDX, IDC_DATETIMEPICKER16, m_Dt6);
	DDX_Control(pDX, IDC_DATETIMEPICKER8, m_Dt5);
	DDX_Control(pDX, IDC_DATETIMEPICKER10, m_Dt4);
	DDX_Control(pDX, IDC_DATETIMEPICKER6, m_Dt3);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_Dt2);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Dt1);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_CHECK2, m_CheckSokr);
}


BEGIN_MESSAGE_MAP(CDlgRptVU53, CDialog)
	//{{AFX_MSG_MAP(CDlgRptVU53)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK31, OnCheck31)
	ON_BN_CLICKED(IDC_CHECK38, OnCheck38)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CDlgRptVU53::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRptVU53 message handlers

void CDlgRptVU53::OnCheck1() 
{
    if(m_Bn1.GetCheck())
    {
        m_Dt1.EnableWindow(TRUE);
        m_Dt2.EnableWindow(TRUE);
    }
    else
    {
        m_Dt1.EnableWindow(FALSE);
        m_Dt2.EnableWindow(FALSE);
    }
}

void CDlgRptVU53::OnCheck31() 
{
    if(m_Bn2.GetCheck())
    {
        m_Dt3.EnableWindow(TRUE);
        m_Dt4.EnableWindow(TRUE);
    }
    else
    {
        m_Dt3.EnableWindow(FALSE);
        m_Dt4.EnableWindow(FALSE);
    }
}

void CDlgRptVU53::OnCheck38() 
{
    if(m_Bn3.GetCheck())
    {
        m_Dt5.EnableWindow(TRUE);
        m_Dt6.EnableWindow(TRUE);
    }
    else
    {
        m_Dt5.EnableWindow(FALSE);
        m_Dt6.EnableWindow(FALSE);
    }	
}

BOOL CDlgRptVU53::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_Dt1.EnableWindow(FALSE);
    m_Dt2.EnableWindow(FALSE);
    m_Dt3.EnableWindow(FALSE);
    m_Dt4.EnableWindow(FALSE);
    m_Dt5.EnableWindow(FALSE);
    m_Dt6.EnableWindow(FALSE);
	return TRUE;
}

void CDlgRptVU53::OnOK() 
{
    SYSTEMTIME t1;
    char c_d1[18] = "", c_d2[18] = "", c_d3[18] = "", c_d4[18] = "", c_d5[18] = "", c_d6[18] = "";
    char cQ[512] = "";
    ZeroMemory(&t1, sizeof(SYSTEMTIME));

    if( m_Bn1.GetCheck() )
    {
        m_Dt1.GetTime(&t1);
		t1.wMilliseconds = 0;
        DateToSql(t1, c_d1);
		ZeroMemory(&t1, sizeof(t1));
        m_Dt2.GetTime(&t1);
		t1.wMilliseconds = 0;
        DateToSql(t1, c_d2);
    }
    else
    {
        strcpy(c_d1, "NULL");
        strcpy(c_d2, "NULL");
    }
    if( m_Bn2.GetCheck() )
    {
        m_Dt3.GetTime(&t1);
		t1.wMilliseconds = 0;
        DateToSql(t1, c_d3);
        m_Dt4.GetTime(&t1);
		t1.wMilliseconds = 0;
        DateToSql(t1, c_d4);
    }
    else
    {
        strcpy(c_d3, "NULL");
        strcpy(c_d4, "NULL");
    }
    if( m_Bn3.GetCheck() )
    {
        m_Dt5.GetTime(&t1); t1.wMilliseconds = 0;
        DateToSql(t1, c_d5); 
        m_Dt6.GetTime(&t1); t1.wMilliseconds = 0;
        DateToSql(t1, c_d6);
    }
    else
    {
        strcpy(c_d5, "NULL");
        strcpy(c_d6, "NULL");
    }
	if( !m_CheckSokr.GetCheck() )
	{
		sprintf(cQ, "pTov_MKCReportVU53 %s, %s, %s, %s, %s, %s, %u", 
				c_d1, 
				c_d2, 
				c_d3, 
				c_d4, 
				c_d5, 
				c_d6,
				g_iDep);
	} else
	{
		sprintf(cQ, "pTov_MKCReportVU53S %s, %s, %s, %s, %s, %s, %u", 
				c_d1, 
				c_d2, 
				c_d3, 
				c_d4, 
				c_d5, 
				c_d6,
				g_iDep);
	}
//    AfxMessageBox(cQ);
    CPrintableDlg Dlg;
    strcpy(Dlg.cQ, cQ);
    Dlg.m_bCheck1 = true;
    Dlg.m_bCheck2 = true;
    if( Dlg.DoModal() == IDCANCEL ) return;
	CDialog::OnOK();
//    MessageBox("Passed ... OK", "SQL", MB_OK);
}

void CDlgRptVU53::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
