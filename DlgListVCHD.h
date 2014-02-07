#if !defined(AFX_DLGLISTVCHD_H__04C51956_13D0_4CCC_8C20_EA9CA168A3B7__INCLUDED_)
#define AFX_DLGLISTVCHD_H__04C51956_13D0_4CCC_8C20_EA9CA168A3B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgListVCHD.h : header file
//
#include "FastGrid.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgListVCHD dialog

class CDlgListVCHD : public CDialog
{
// Construction
public:
	CDlgListVCHD(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgListVCHD)
	enum { IDD = IDD_DIALOG_LIST_VCHD };
	CFastGrid	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgListVCHD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgListVCHD)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton_ListDiag();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLISTVCHD_H__04C51956_13D0_4CCC_8C20_EA9CA168A3B7__INCLUDED_)
