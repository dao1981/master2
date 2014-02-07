#if !defined(AFX_DLGEDRSN_H__5AB03ADB_6067_401E_85DF_96575D8CF387__INCLUDED_)
#define AFX_DLGEDRSN_H__5AB03ADB_6067_401E_85DF_96575D8CF387__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgEdRsn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgEdRsn dialog

class CDlgEdRsn : public CDialog
{
// Construction
public:
	CDlgEdRsn(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgEdRsn)
	enum { IDD = IDD_DIALOG_NCI_ED };
	CStatic	m_nText;
	CEdit	m_Edit;
	CString	m_Text;
	CString	m_osnTitle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgEdRsn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgEdRsn)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEDRSN_H__5AB03ADB_6067_401E_85DF_96575D8CF387__INCLUDED_)
