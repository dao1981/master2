#if !defined(AFX_DLGMAKELK_SEND_H__C7396369_C253_4CE5_843F_E57233B301B0__INCLUDED_)
#define AFX_DLGMAKELK_SEND_H__C7396369_C253_4CE5_843F_E57233B301B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMakeLK_Send.h : header file
//
#include "Maskedit.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMakeLK_Send dialog

class CDlgMakeLK_Send : public CDialog
{
// Construction
public:
	CDlgMakeLK_Send(CWnd* pParent = NULL);   // standard constructor
    __int64 qwILK;
// Dialog Data
	//{{AFX_DATA(CDlgMakeLK_Send)
	enum { IDD = IDD_DIALOG_MKLK_SEND };
	CEdit	m_EdFam2;
	CMaskEdit	m_EdFam1;
	CEdit	m_EdVag;
	CEdit	m_EdNum;
	CString	m_LNum;
	CString	m_VagNum;
	CString	m_Oper;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMakeLK_Send)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMakeLK_Send)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonKdr();
	afx_msg void OnButton_MessageText();
	afx_msg void OnSend();
	afx_msg void OnButton_LK_view();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMAKELK_SEND_H__C7396369_C253_4CE5_843F_E57233B301B0__INCLUDED_)
