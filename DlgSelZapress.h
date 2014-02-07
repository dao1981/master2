#if !defined(AFX_DLGSELZAPRESS_H__A6AE9DAB_B1B0_43C6_9ED8_FD99BBD64A93__INCLUDED_)
#define AFX_DLGSELZAPRESS_H__A6AE9DAB_B1B0_43C6_9ED8_FD99BBD64A93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSelZapress.h : header file
//
#include "MaskEdit.h"
#include "DlgAccel1.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgSelZapress dialog

class CDlgSelZapress : public CDlgWithAccelerators
{
// Construction
public:
	CDlgSelZapress(CWnd* pParent = NULL);   // standard constructor
    DWORD dwIPR;
// Dialog Data
	//{{AFX_DATA(CDlgSelZapress)
	enum { IDD = IDD_DIALOG_SEL_ZAPRESS };
	CButton	m_But2;
	CButton	m_But1;
	CEdit	m_EdMask;
	CButton	m_c10;
	CButton	m_c9;
	CButton	m_c8;
	CButton	m_c7;
	CButton	m_c6;
	CButton	m_c5;
	CButton	m_c4;
	CButton	m_c3;
	CButton	m_c2;
	CButton	m_c1;
	CEdit	m_EdPrName;
	CEdit	m_EdKl;
	CMaskEdit	m_EdFam;
	CMaskEdit	m_Dat8;
	CMaskEdit	m_Dat7;
	CMaskEdit	m_Dat6;
	CMaskEdit	m_Dat5;
	CMaskEdit	m_Dat4;
	CMaskEdit	m_Dat3;
	CMaskEdit	m_Dat2;
	CMaskEdit	m_Dat1;
	CComboBox	m_Cb1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSelZapress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSelZapress)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton_FAM();
	afx_msg void OnButton_PR();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnCheck6();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	afx_msg void OnCheck9();
	afx_msg void OnCheck10();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSELZAPRESS_H__A6AE9DAB_B1B0_43C6_9ED8_FD99BBD64A93__INCLUDED_)
