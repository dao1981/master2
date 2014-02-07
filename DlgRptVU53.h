#include "afxwin.h"
#if !defined(AFX_DLGRPTVU53_H__FD66AA19_8F3F_4886_AE62_940C3CE42D95__INCLUDED_)
#define AFX_DLGRPTVU53_H__FD66AA19_8F3F_4886_AE62_940C3CE42D95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRptVU53.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRptVU53 dialog

class CDlgRptVU53 : public CDialog
{
// Construction
public:
	CDlgRptVU53(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgRptVU53)
	enum { IDD = IDD_DIALOG_RPT_VU53 };
	CButton	m_Bn3;
	CButton	m_Bn2;
	CButton	m_Bn1;
	CDateTimeCtrl	m_Dt6;
	CDateTimeCtrl	m_Dt5;
	CDateTimeCtrl	m_Dt4;
	CDateTimeCtrl	m_Dt3;
	CDateTimeCtrl	m_Dt2;
	CDateTimeCtrl	m_Dt1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRptVU53)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRptVU53)
	afx_msg void OnCheck1();
	afx_msg void OnCheck31();
	afx_msg void OnCheck38();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	CButton m_CheckSokr;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRPTVU53_H__FD66AA19_8F3F_4886_AE62_940C3CE42D95__INCLUDED_)
