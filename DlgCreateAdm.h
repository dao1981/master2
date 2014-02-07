#if !defined(AFX_DLGCREATEADM_H__FCF1C1A8_3A8A_40F2_9B82_D3A0691410BF__INCLUDED_)
#define AFX_DLGCREATEADM_H__FCF1C1A8_3A8A_40F2_9B82_D3A0691410BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCreateAdm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCreateAdm dialog

class CDlgCreateAdm : public CDialog
{
// Construction
public:
	CDlgCreateAdm(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCreateAdm)
	enum { IDD = IDD_DIALOG_CREATE_ADM };
	CString	m_EdPass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCreateAdm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCreateAdm)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCREATEADM_H__FCF1C1A8_3A8A_40F2_9B82_D3A0691410BF__INCLUDED_)
