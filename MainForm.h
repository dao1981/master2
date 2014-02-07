#if !defined(AFX_MAINFORM_H__C8C8E2FD_2B7A_4FDA_B93F_01236AA5C9F3__INCLUDED_)
#define AFX_MAINFORM_H__C8C8E2FD_2B7A_4FDA_B93F_01236AA5C9F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainForm.h : header file
//
#include "DlgAccel1.h"
/////////////////////////////////////////////////////////////////////////////
// CMainForm dialog

class CMainForm : public CDlgWithAccelerators
{
// Construction
public:
	CMainForm(CWnd* pParent = NULL);   // standard constructor
    HICON m_hIcon;
    void OnCancel(); 
    void OnPrintSome();
	BOOL bMsg4624Only;

	char cVagNum32[32];
	SYSTEMTIME stRemDat;

// Dialog Data
	//{{AFX_DATA(CMainForm)
	enum { IDD = IDD_MAIN_WINDOW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainForm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainForm)
	virtual BOOL OnInitDialog();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFORM_H__C8C8E2FD_2B7A_4FDA_B93F_01236AA5C9F3__INCLUDED_)
