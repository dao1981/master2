#if !defined(AFX_DLGDISPLRP_H__9158B15D_A4C9_40DC_BB91_BB71CBC760E9__INCLUDED_)
#define AFX_DLGDISPLRP_H__9158B15D_A4C9_40DC_BB91_BB71CBC760E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDisplRP.h : header file
//
#include "FastGrid.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgDisplRP dialog

class CDlgDisplRP : public CDialog
{
// Construction
public:
	CDlgDisplRP(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDisplRP)
	enum { IDD = IDD_DIALOG_RPSHOW };
	CFastGrid	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDisplRP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDisplRP)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeZap();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDISPLRP_H__9158B15D_A4C9_40DC_BB91_BB71CBC760E9__INCLUDED_)
