#if !defined(AFX_DLGDBREMSELECT_H__193E30CC_28AD_419A_9221_1948A5423528__INCLUDED_)
#define AFX_DLGDBREMSELECT_H__193E30CC_28AD_419A_9221_1948A5423528__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDBRemSelect.h : header file
//
#include "MaskEdit.h"
#include "DlgAccel1.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgDBRemSelect dialog

class CDlgDBRemSelect : public CDlgWithAccelerators
{
// Construction
public:
	CDlgDBRemSelect(CWnd* pParent = NULL);   // standard constructor
    void EnableCtrls(BOOL State);
    DWORD dwTKP[64];
    DWORD dwRemKP[64];
    DWORD dwNeisp;
    DWORD dwPRPost_ID;
    DWORD dwPRRash_ID;
// Dialog Data
	//{{AFX_DATA(CDlgDBRemSelect)
	enum { IDD = IDD_DIALOG_SEL_KP_REM };
	CComboBox	m_Combo7;
	CComboBox	m_Combo6;
	CButton	m_Check15;
	CButton	m_Check14;
	CButton	m_ButPr2;
	CButton	m_Check13;
	CEdit	m_EdPrName2;
	CEdit	m_EdPrKl2;
	CButton	m_ButPr;
	CButton	m_Check12;
	CEdit	m_EdPrName;
	CEdit	m_EdPrKl;
	CMaskEdit	m_Dt6;
	CMaskEdit	m_Dt5;
	CMaskEdit	m_Dt4;
	CMaskEdit	m_Dt3;
	CMaskEdit	m_Dt2;
	CMaskEdit	m_Dt1;
	CEdit	m_Edit4;
	CEdit	m_Edit3;
	CButton	m_Check4;
	CButton	m_Button1;
	CComboBox	m_Combo5;
	CComboBox	m_Combo4;
	CComboBox	m_Combo3;
	CComboBox	m_Combo2;
	CEdit	m_Edit2;
	CEdit	m_Edit1;
	CComboBox	m_Combo1;
	CButton	m_Check11;
	CButton	m_Check10;
	CButton	m_Check9;
	CButton	m_Check8;
	CButton	m_Check7;
	CButton	m_Check6;
	CButton	m_Check5;
	CButton	m_Check3;
	CButton	m_Check2;
	CButton	m_Check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDBRemSelect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDBRemSelect)
	afx_msg void OnButton4();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnCheck6();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	afx_msg void OnCheck9();
	afx_msg void OnCheck10();
	afx_msg void OnCheck11();
	virtual void OnOK();
	afx_msg void OnButtonPr();
	afx_msg void OnCheck12();
	afx_msg void OnKillfocusEditKlPr();
	afx_msg void OnButton8();
	afx_msg void OnKillfocusEditPr2();
	afx_msg void OnCheck13();
	afx_msg void OnCheck14();
	afx_msg void OnCheck15();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDBREMSELECT_H__193E30CC_28AD_419A_9221_1948A5423528__INCLUDED_)
