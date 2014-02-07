#include "afxwin.h"
#if !defined(AFX_DLGRPTVU36M_H__DCDE3728_EF7C_42DC_85BC_91A16C4353AB__INCLUDED_)
#define AFX_DLGRPTVU36M_H__DCDE3728_EF7C_42DC_85BC_91A16C4353AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRptVU36M.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgRptVU36M dialog

class DlgRptVU36M : public CDialog
{
// Construction
public:
	DlgRptVU36M(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgRptVU36M)
	enum { IDD = IDD_DIALOG_RPT_VU36M };
	CEdit	m_Ed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgRptVU36M)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgRptVU36M)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CButton m_Check;
	CButton m_Radio1;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRPTVU36M_H__DCDE3728_EF7C_42DC_85BC_91A16C4353AB__INCLUDED_)
