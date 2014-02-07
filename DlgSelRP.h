#if !defined(AFX_DLGSELRP_H__6B8D9A8C_9173_444C_83AA_3DBF9B0AC920__INCLUDED_)
#define AFX_DLGSELRP_H__6B8D9A8C_9173_444C_83AA_3DBF9B0AC920__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSelRP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSelRP dialog

class CDlgSelRP : public CDialog
{
// Construction
public:
	CDlgSelRP(CWnd* pParent = NULL);   // standard constructor
    DWORD dwIdPr[256];
    DWORD dwIdTypeRP[256];
// Dialog Data
	//{{AFX_DATA(CDlgSelRP)
	enum { IDD = IDD_DIALOG_DBRP };
	CButton	m_Button1;
	CEdit	m_Edit2;
	CEdit	m_Edit1;
	CDateTimeCtrl	m_dt4;
	CComboBox	m_Combo0;
	CDateTimeCtrl	m_dt3;
	CDateTimeCtrl	m_dt2;
	CDateTimeCtrl	m_dt1;
	CButton	m_Check4;
	CButton	m_Check3;
	CButton	m_Check2;
	CButton	m_Check1;
	CButton	m_Check6;
	CButton	m_Check5;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	BOOL	m_c1;
	BOOL	m_c2;
	BOOL	m_c3;
	BOOL	m_c4;
	BOOL	m_c5;
	BOOL	m_c6;
	CTime	m_d1;
	CTime	m_d2;
	CTime	m_d3;
	CTime	m_d4;
	int		m_cb0;
	CString	m_ed1;
	CString	m_ed2;
	int		m_cb1;
	int		m_cb2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSelRP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSelRP)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnButton3();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck11();
	afx_msg void OnCheck21();
	afx_msg void OnChangeEdit46();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSELRP_H__6B8D9A8C_9173_444C_83AA_3DBF9B0AC920__INCLUDED_)
