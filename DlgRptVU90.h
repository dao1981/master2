#include "maskedit.h"
#if !defined(AFX_DLGRPTVU90_H__DD7FA09B_EC73_4C29_AD02_BA8FFF581F16__INCLUDED_)
#define AFX_DLGRPTVU90_H__DD7FA09B_EC73_4C29_AD02_BA8FFF581F16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRptVU90.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRptVU90 dialog

class CDlgRptVU90 : public CDialog
{
// Construction
public:
	CDlgRptVU90(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgRptVU90)
	enum { IDD = IDD_DIALOG_RPT_VU90 };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRptVU90)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRptVU90)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
public:
	CMaskEdit m_Dat1;
public:
	CMaskEdit m_Dat2;
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRPTVU90_H__DD7FA09B_EC73_4C29_AD02_BA8FFF581F16__INCLUDED_)
