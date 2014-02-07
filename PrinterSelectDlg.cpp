// PrinterSelectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "PrinterSelectDlg.h"
#include "winspool.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrinterSelectDlg dialog


CPrinterSelectDlg::CPrinterSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrinterSelectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrinterSelectDlg)
	m_PrinterName = _T("");
	//}}AFX_DATA_INIT
}


void CPrinterSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrinterSelectDlg)
	DDX_Control(pDX, IDC_COMBO1, m_Cb);
	DDX_CBString(pDX, IDC_COMBO1, m_PrinterName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrinterSelectDlg, CDialog)
	//{{AFX_MSG_MAP(CPrinterSelectDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrinterSelectDlg message handlers

BOOL CPrinterSelectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
    PRINTER_INFO_2 prnInfo[32];
    DWORD num = 0, nPrn = 0;
    BOOL F = EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_REMOTE, "", 2, (unsigned char *)prnInfo, sizeof(PRINTER_INFO_2)*32, &num, &nPrn);
    if( !nPrn )
    {
        AfxMessageBox("¬ системе не обнаружено ни одного принтера!");
        m_bPrintersPresent = FALSE;
        CDialog::OnCancel();
        return FALSE;
    }
    for( DWORD i=0; i < nPrn; i++ )
    {
        m_Cb.AddString(prnInfo[i].pPrinterName);
    }
    m_bPrintersPresent = TRUE;
    m_Cb.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
