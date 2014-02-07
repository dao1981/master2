// DlgRptVU90.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRptVU90.h"
#include "PrintableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRptVU90 dialog


CDlgRptVU90::CDlgRptVU90(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRptVU90::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRptVU90)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_Dat1.iMode = 1;
    m_Dat2.iMode = 1;
}


void CDlgRptVU90::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRptVU90)
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
}


BEGIN_MESSAGE_MAP(CDlgRptVU90, CDialog)
	//{{AFX_MSG_MAP(CDlgRptVU90)
	//}}AFX_MSG_MAP
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDOK, &CDlgRptVU90::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRptVU90 message handlers

void CDlgRptVU90::OnOK() 
{
    char cQ[128] = "";
    SYSTEMTIME t1;
    ZeroMemory(&t1, sizeof(t1));    
    char d1[16] = "", d2[16] = "";

	if (!m_Dat1.isValid ())
	{
		MessageBox ("¬ведите начальную дату корректно");
		return;
	}

	m_Dat1.GetTime(&t1);
	t1.wMilliseconds = 0;
	DateToSql(t1, d1);

	if (m_Dat2.isValid ())
	{
		m_Dat2.GetTime(&t1);
		t1.wMilliseconds = 0;
		DateToSql(t1, d2);
	}
	else
		if (m_Dat2.isNull ())
		{
			strcpy(d2, "NULL");
		}
		else
		{
			MessageBox ("¬ведите конечную дату корректно или оставьте поле пустым");
			return;
		}

	sprintf(cQ, "pTov_mkcReportVU90 %d, %s, %s", g_iDep, d1, d2);

    CPrintableDlg Dlg;
    Dlg.m_bCheck1 = false;
    Dlg.m_bCheck2 = true;
    strcpy(Dlg.cQ, cQ);

    Dlg.DoModal();

	CDialog::OnOK();
}

BOOL CDlgRptVU90::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_Dat1.InitDate();
    m_Dat2.InitDate();
	m_Dat1.EnableWindow();
	m_Dat2.EnableWindow();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CDlgRptVU90::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == VK_RETURN)
	{
		if (GetFocus ()->m_hWnd == m_Dat1.m_hWnd)
		{
			m_Dat2.SetFocus ();
		}
		else
			if (GetFocus ()->m_hWnd == m_Dat2.m_hWnd)
			{
				OnOK ();
			}
	}

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDlgRptVU90::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
