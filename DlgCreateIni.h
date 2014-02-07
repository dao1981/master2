#if !defined(AFX_DLGCREATEINI_H__3249B7D9_C378_4392_903E_29526BCC396E__INCLUDED_)
#define AFX_DLGCREATEINI_H__3249B7D9_C378_4392_903E_29526BCC396E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCreateIni.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCreateIni dialog

class CDlgCreateIni : public CDialog
{
// Construction
public:
	CDlgCreateIni(CWnd* pParent = NULL);   // standard constructor
    int CheckValid();
// Dialog Data
	//{{AFX_DATA(CDlgCreateIni)
	enum { IDD = IDD_DIALOG_CREATE_INI };
	CEdit	m_EdPass;
	CEdit	m_EdLogin;
	CEdit	m_EdSrv;
	CString	m_strServerName;
	CString	m_strLogin;
	CString	m_strPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCreateIni)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCreateIni)
	virtual void OnOK();
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCREATEINI_H__3249B7D9_C378_4392_903E_29526BCC396E__INCLUDED_)
