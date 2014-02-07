#if !defined(AFX_DLGPROBTIN_H__620EF0B9_B030_4D6A_9E75_EF0F6ED1939C__INCLUDED_)
#define AFX_DLGPROBTIN_H__620EF0B9_B030_4D6A_9E75_EF0F6ED1939C__INCLUDED_
#include "MaskEdit.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPrObtIn.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CDlgPrObtIn dialog

class CDlgPrObtIn : public CDialog
{
// Construction
public:
	CDlgPrObtIn(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPrObtIn)
	enum { IDD = IDD_DIALOG_PROBTIN };
	CMaskEdit	m_Date2;
	CMaskEdit	m_Date1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPrObtIn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPrObtIn)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROBTIN_H__620EF0B9_B030_4D6A_9E75_EF0F6ED1939C__INCLUDED_)
