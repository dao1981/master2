#if !defined(AFX_AUTHDLG_H__3C961B57_A108_475B_B672_1114B30B7A1A__INCLUDED_)
#define AFX_AUTHDLG_H__3C961B57_A108_475B_B672_1114B30B7A1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AuthDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAuthDlg dialog

class CAuthDlg : public CDialog
{
// Construction
public:
	CAuthDlg(CWnd* pParent = NULL);   // standard constructor
    HICON m_hIcon;
// Dialog Data
	//{{AFX_DATA(CAuthDlg)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_Edit1;
	CString	m_UserName;
	CString	m_Pass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAuthDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAuthDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTHDLG_H__3C961B57_A108_475B_B672_1114B30B7A1A__INCLUDED_)
