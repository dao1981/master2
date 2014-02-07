#if !defined(AFX_DLGRAZMGROUP_H__80D4B76A_B373_4716_9CEA_827D74D32940__INCLUDED_)
#define AFX_DLGRAZMGROUP_H__80D4B76A_B373_4716_9CEA_827D74D32940__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRazmGroup.h : header file
//
#include "MaskEdit.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgRazmGroup dialog

class CDlgRazmGroup : public CDialog
{
// Construction
public:
	CDlgRazmGroup(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgRazmGroup)
	enum { IDD = IDD_DIALOG_RAZM_GRP };
	CMaskEdit	m_Dat2;
	CMaskEdit	m_Dat1;
	CMaskEdit	m_EdD2;
	CMaskEdit	m_EdD1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRazmGroup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRazmGroup)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRAZMGROUP_H__80D4B76A_B373_4716_9CEA_827D74D32940__INCLUDED_)
