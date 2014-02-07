////////////////////////////////////////////////////////////////
// MSDN -- May 2000
//
// If this code works, it was written by Paul DiLascia.
// If not, I don't know who wrote it.
// Compiles with Visual C++ 6.0, runs on Windows 98 and probably NT too.
//
// CDlgWithAccelerators is a general-purpose class that adds
// accelerators to CDialog.
//
#include "stdafx.h"
#include "dlgaccel1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HACCEL CDlgWithAccelerators::m_hAccel; // accelerator table

BEGIN_MESSAGE_MAP(CDlgWithAccelerators,CNewDialog)
	//{{AFX_MSG_MAP(CEnterkeyApp)
    ON_COMMAND(ID_MY_ENTER, OnMyEnter)
    ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
    ON_COMMAND(ID_ARROW_UP, OnArrowUp)
//    ON_MESSAGE(DM_GETDEFID, OnGetDefID) // not used
    //}}AFX_MSG
END_MESSAGE_MAP()

////////////////
// do-nothing ctors and dtor
//
IMPLEMENT_DYNAMIC(CDlgWithAccelerators, CNewDialog)
CDlgWithAccelerators::CDlgWithAccelerators(LPCTSTR lpszTemplateName,
	CWnd* pParentWnd) : CNewDialog(lpszTemplateName, pParentWnd)
{
}

CDlgWithAccelerators::CDlgWithAccelerators(UINT nIDTemplate,
	CWnd* pParentWnd) : CNewDialog(nIDTemplate, pParentWnd)
{
}

CDlgWithAccelerators::~CDlgWithAccelerators()
{
}

//////////////////
// Pre-translate message: translate keystrokes using acclerator table. 
//
BOOL CDlgWithAccelerators::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST) {
		HACCEL hAccel = m_hAccel;
		if (hAccel && ::TranslateAccelerator(m_hWnd, hAccel, pMsg))
			return TRUE;
	}
	return CNewDialog::PreTranslateMessage(pMsg);
}

//////////////////
// Initialize dialog: load accelerators
//
HANDLE haccel;
BOOL CDlgWithAccelerators::OnInitDialog()
{
	BOOL bRet = CNewDialog::OnInitDialog();

	// Load dialog's accelerators
/*
    char *s = new char[20];
    strcpy(s, "IDD_DLG11");*/

//    m_lpszTemplateName = s;
    //AfxGetResourceHandle()
//    HINSTANCE h = AfxGetResourceHandle();
    if( !m_hAccel )
    {
        m_hAccel = LoadAccelerators(AfxGetInstanceHandle(),
		     m_lpszTemplateName); // use same resource name as dialog
		if( !m_hAccel )
		{
			char cc[32] = "";
			itoa(GetLastError(), cc, 10);
			AfxMessageBox(cc);
		}
//        ASSERT(m_hAccel);
    }
	return bRet;
}

LRESULT CDlgWithAccelerators::OnGetDefID(WPARAM wp, LPARAM lp)
{
//    AfxMessageBox("Yo!");
	TRACE(_T("CDlgWithAccelerators::OnGetDefID\n"));
    CWnd* pW = GetFocus();
/*    CRuntimeClass *c = pW->GetRuntimeClass();
    if( c->m_lpszClassName != "CButton" )
	    return MAKELONG(0,DC_HASDEFID);*/
    return CNewDialog::GetDefID();
}

void CDlgWithAccelerators::OnMyEnter()
{
	CWnd* pWndNext = GetNextDlgTabItem(GetFocus());
	if (pWndNext) 
    {
		pWndNext->SetFocus();
	}
}

void CDlgWithAccelerators::OnArrowDown()
{    
	CWnd* pWndNext = GetNextDlgTabItem(GetFocus());
	if (pWndNext) 
    {
		pWndNext->SetFocus();
	}   
}

void CDlgWithAccelerators::OnArrowUp()
{
	CWnd* pWndNext = GetNextDlgTabItem(GetFocus(), TRUE);
	if (pWndNext) 
    {
		pWndNext->SetFocus();
	}
}
