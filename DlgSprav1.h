#if !defined(AFX_DLGSPRAV1_H__59C51358_F397_4125_B77F_7044EB8B725C__INCLUDED_)
#define AFX_DLGSPRAV1_H__59C51358_F397_4125_B77F_7044EB8B725C__INCLUDED_

#include "FastGrid.h"
#include "afxwin.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSprav1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSprav1 dialog

class CDlgSprav1 : public CDialog
{
// Construction
public:
	CDlgSprav1(CWnd* pParent = NULL);   // standard constructor
    void UpdateListByHandle();
    char cKodPr[32];
    char cPrName[64];
    int iDlgMode;
    int iDlgKind;
    DWORD ret_dwIPR;
    char cTypePr[32];
    char cOldText[64];
	char cPrSName[64];
// Dialog Data
	//{{AFX_DATA(CDlgSprav1)
	enum { IDD = IDD_DIALOG_SPRAV1 };
	CFastGrid	m_List;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	CEdit	m_Edit1;
	CString	m_Edit1Text;
	int		m_Combo2Index;
	CString	m_RecCount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSprav1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSprav1)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnChangeEdit1();
	afx_msg void OnSelchangeCombo2();
	virtual void OnOK();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnListItemHeaderClick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CButton m_Lab;
	CButton m_But1;
	CButton m_But2;
	CButton m_But3;
	CStatic m_Labb;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSPRAV1_H__59C51358_F397_4125_B77F_7044EB8B725C__INCLUDED_)
