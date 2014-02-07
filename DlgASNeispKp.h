#if !defined(AFX_DLGASNEISPKP_H__7711A521_A4EE_4E31_8DBB_34CC6CDA04F8__INCLUDED_)
#define AFX_DLGASNEISPKP_H__7711A521_A4EE_4E31_8DBB_34CC6CDA04F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgASNeispKp.h : header file
//

#include "DlgAccel1.h"
#include "MaskEdit.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgASNeispKp dialog

class CDlgASNeispKp : public CDlgWithAccelerators
{
// Construction
public:
	DWORD dwKNeisp;
	CDlgASNeispKp(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgASNeispKp)
	enum { IDD = IDD_DIALOG_SPRAV_NEISP_KP };
	CMaskEdit	m_Dat2;
	CMaskEdit	m_Dat1;
	CEdit	m_EdNeisp;
	CEdit	m_EdKNeisp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgASNeispKp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgASNeispKp)
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGASNEISPKP_H__7711A521_A4EE_4E31_8DBB_34CC6CDA04F8__INCLUDED_)
