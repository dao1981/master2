#if !defined(AFX_DLGKPHISORYINP_H__34F1FE97_0123_479F_AFC1_A013F2E84AF7__INCLUDED_)
#define AFX_DLGKPHISORYINP_H__34F1FE97_0123_479F_AFC1_A013F2E84AF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgKpHisoryInp.h : header file
//
#include "MaskEdit.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgKpHisoryInp dialog

class CDlgKpHisoryInp : public CDialog
{
// Construction
public:
	CDlgKpHisoryInp(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgKpHisoryInp)
	enum { IDD = IDD_DIALOG_HISTORY_KP };
	CMaskEdit	m_Edit;
	CComboBox	m_Combo;
	//}}AFX_DATA
    int     iMode;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgKpHisoryInp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgKpHisoryInp)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSetfocusEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGKPHISORYINP_H__34F1FE97_0123_479F_AFC1_A013F2E84AF7__INCLUDED_)
