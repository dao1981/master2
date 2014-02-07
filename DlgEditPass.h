#if !defined(AFX_DLGEDITPASS_H__AA3FF340_0DD5_4598_8302_B8F598A305BB__INCLUDED_)
#define AFX_DLGEDITPASS_H__AA3FF340_0DD5_4598_8302_B8F598A305BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgEditPass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgEditPass dialog

class CDlgEditPass : public CDialog
{
// Construction
public:
	CDlgEditPass(CWnd* pParent = NULL);   // standard constructor
    int Mode;
	int iRang;
	int iFam;
	BOOL bRangWasChanged;
// Dialog Data
	//{{AFX_DATA(CDlgEditPass)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_Edit1;
	UINT	m_iRang;
	CString	m_cPass1;
	CString	m_cPass2;
	CString	m_cUser;
	//}}AFX_DATA

	char cOldRang[10];
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgEditPass)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgEditPass)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit5();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEDITPASS_H__AA3FF340_0DD5_4598_8302_B8F598A305BB__INCLUDED_)
