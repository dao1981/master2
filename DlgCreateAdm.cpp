// DlgCreateAdm.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgCreateAdm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCreateAdm dialog


CDlgCreateAdm::CDlgCreateAdm(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCreateAdm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCreateAdm)
	m_EdPass = _T("");
	//}}AFX_DATA_INIT
}


void CDlgCreateAdm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCreateAdm)
	DDX_Text(pDX, IDC_EDIT2, m_EdPass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCreateAdm, CDialog)
	//{{AFX_MSG_MAP(CDlgCreateAdm)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCreateAdm message handlers
