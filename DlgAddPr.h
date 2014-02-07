#if !defined(AFX_DLGADDPR_H__0669E9C4_B9A9_40C6_94EC_FBB3FA8AB74A__INCLUDED_)
#define AFX_DLGADDPR_H__0669E9C4_B9A9_40C6_94EC_FBB3FA8AB74A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAddPr.h : header file
//

#include "DlgAccel1.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgAddPr dialog

class CDlgAddPr : public CDlgWithAccelerators
{
// Construction
public:
	CDlgAddPr(CWnd* pParent = NULL);   // standard constructor
    DWORD   dwDor;
//    DWORD dwStan;
//    char  cType[32];
    int     iMode;
    DWORD   dwID;
    DWORD   dwTypePr;
    bool    bNeedStamp;
    bool    bNeedCode;
    bool    bNeedDoroga;
    bool    bNeedStan;
// Dialog Data
	//{{AFX_DATA(CDlgAddPr)
	enum { IDD = IDD_DIALOG_ADD_PR };
	CButton	m_Check1;
	CButton	m_Check2;
	CButton m_bOK;
	CEdit	m_Edit4;
	CEdit	m_Edit3;
	CEdit	m_Edit2;
	CEdit	m_Edit1;
	CComboBox	m_Combo;
	CButton	m_Button3;
	CEdit	m_Edit9;
	CEdit	m_Edit8;
	CEdit	m_Edit7;
	CEdit	m_Edit6;
	CEdit	m_Edit5;
	CString	m_Edit1Text;
	CString	m_Edit2Text;
	CString	m_Edit3Text;
	CString	m_Edit4text;
	CString	m_Edit5Text;
	CString	m_Edit6Text;
	CString	m_Edit8Text;
	CString	m_Edit9Text;
	CString	m_Edit7Text;
	BOOL	m_bCheck1;
	BOOL	m_bCheck2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAddPr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAddPr)
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnChangeEdit5();
	afx_msg void OnChangeEdit8();
	afx_msg void OnChangeCombo1();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDPR_H__0669E9C4_B9A9_40C6_94EC_FBB3FA8AB74A__INCLUDED_)
