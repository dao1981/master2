#if !defined(AFX_DLGSELECTOS_H__635D7A5F_303C_42F8_B3F0_F854CE2D6CB7__INCLUDED_)
#define AFX_DLGSELECTOS_H__635D7A5F_303C_42F8_B3F0_F854CE2D6CB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSelectOS.h : header file
//
#include "MaskEdit.h"
#include "DlgAccel1.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgSelectOS dialog

class CDlgSelectOS : public CDlgWithAccelerators
{
// Construction
public:
	CDlgSelectOS(CWnd* pParent = NULL);   // standard constructor
    DWORD dwPrIzg;
    DWORD dwPrPeres;
// Dialog Data
	//{{AFX_DATA(CDlgSelectOS)
	enum { IDD = IDD_DIALOG_SEL_OS };
	CButton	m_c10;
	CButton	m_But2;
	CButton	m_But1;
	CButton	m_c6;
	CButton	m_c9;
	CButton	m_c8;
	CButton	m_c7;
	CButton	m_c5;
	CButton	m_c4;
	CButton	m_c3;
	CButton	m_c2;
	CButton	m_c1;
	CEdit	m_EdMask;
	CMaskEdit	m_Dat8;
	CMaskEdit	m_Dat7;
	CEdit	m_EdIzgPrName;
	CEdit	m_EdIzgKl;
	CComboBox	m_Combo1;
	CEdit	m_EdPeresPrName;
	CEdit	m_EdPeresKl;
	CMaskEdit	m_Dat6;
	CMaskEdit	m_Dat5;
	CMaskEdit	m_Dat4;
	CMaskEdit	m_Dat3;
	CMaskEdit	m_Dat2;
	CMaskEdit	m_Dat1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSelectOS)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSelectOS)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
    afx_msg void OnCheck5();
	afx_msg void OnCheck6();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	afx_msg void OnCheck9();
	afx_msg void OnCheck10();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnKillfocusEdit3();
	afx_msg void OnKillfocusEdit9();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSELECTOS_H__635D7A5F_303C_42F8_B3F0_F854CE2D6CB7__INCLUDED_)
