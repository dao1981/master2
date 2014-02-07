#if !defined(AFX_DLGAUTH1_H__FF2F0516_5DA0_4185_9ED6_82244A606F9F__INCLUDED_)
#define AFX_DLGAUTH1_H__FF2F0516_5DA0_4185_9ED6_82244A606F9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAuth1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAuth1 dialog

class CDlgAuth1 : public CDialog
{
// Construction
public:
	CDlgAuth1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAuth1)
	enum { IDD = IDD_DIALOG_AUTH_NAMED };
	CString	m_strName;
	CString	m_strPass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAuth1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAuth1)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGAUTH1_H__FF2F0516_5DA0_4185_9ED6_82244A606F9F__INCLUDED_)
