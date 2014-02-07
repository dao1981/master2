#if !defined(AFX_DLGSPRAVKDR_H__91D9E26B_A57E_4538_B196_A427015E9360__INCLUDED_)
#define AFX_DLGSPRAVKDR_H__91D9E26B_A57E_4538_B196_A427015E9360__INCLUDED_
#include "FastGrid.h"
#include "afxwin.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSpravKdr.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSpravKdr dialog

class CDlgSpravKdr : public CDialog
{
// Construction
public:
	CDlgSpravKdr(CWnd* pParent = NULL);   // standard constructor
    int SearchMode;
    char cQuery[64];
    void UpdateListByQuery();
    DWORD dwFam[5000];
    int   DlgMode;
    char  cFio[64];
    DWORD dwFio;
    int   iFilter;
    BOOL  bSortAscending;
    int   nSortedCol;
// Dialog Data
	//{{AFX_DATA(CDlgSpravKdr)
	enum { IDD = IDD_DIALOG_SPRAV_KADR };
	CFastGrid	m_List;
	CButton	m_OK;
	CEdit	m_Edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSpravKdr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSpravKdr)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit1();
	afx_msg void OnRadio1();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnButton2();
	virtual void OnOK();
	afx_msg void OnListHeaderClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CButton m_bn1;
	CButton m_bn2;
	CButton m_bn3;
	CStatic m_Lab;
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSPRAVKDR_H__91D9E26B_A57E_4538_B196_A427015E9360__INCLUDED_)
