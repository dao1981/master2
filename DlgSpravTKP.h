#if !defined(AFX_DLGSPRAVTKP_H__8FB129C0_A609_42A1_BD64_5E197E6C78AA__INCLUDED_)
#define AFX_DLGSPRAVTKP_H__8FB129C0_A609_42A1_BD64_5E197E6C78AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSpravTKP.h : header file
//
#include "DlgEditKP.h"
#include "afxwin.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgSpravTKP dialog

class CDlgSpravTKP : public CDialog
{
// Construction
public:
	CDlgSpravTKP(CWnd* pParent = NULL);   // standard constructor
    int DlgMode;
    char cQuery[1024];
    void UpdateListByQuery();
    void InitEditForm(CDlgEditKP *Dlg);
    void RefreshList();
// Dialog Data
	//{{AFX_DATA(CDlgSpravTKP)
	enum { IDD = IDD_DIALOG_SPRAV_TKP };
	CFastGrid	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSpravTKP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSpravTKP)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CButton but1;
	CButton but2;
	CButton but3;
	CStatic m_Lab;
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSPRAVTKP_H__8FB129C0_A609_42A1_BD64_5E197E6C78AA__INCLUDED_)
