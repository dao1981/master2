#if !defined(AFX_DLGDBKPSELECT_H__4EA55314_51F4_4866_89B5_673A54C56001__INCLUDED_)
#define AFX_DLGDBKPSELECT_H__4EA55314_51F4_4866_89B5_673A54C56001__INCLUDED_

#include "MaskEdit.h"
#include "DlgAccel1.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDBKPSelect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDBKPSelect dialog


class CDlgDBKPSelect : public CDlgWithAccelerators
{
// Construction
public:
	CDlgDBKPSelect(CWnd* pParent = NULL);   // standard constructor
    DWORD dwTKP[64];
    DWORD dwRemKP[64];
    DWORD dwPeresIPR;
    DWORD dwOsIPR;
    DWORD dwNeisp;

	int	iSelectCount;
    void EnableCtrls(BOOL State=TRUE);
// Dialog Data
	//{{AFX_DATA(CDlgDBKPSelect)
	enum { IDD = IDD_DIALOG_SEL_KP_PRIH };
	CMaskEdit	m_Dt6;
	CMaskEdit	m_Dt5;
	CMaskEdit	m_Dt4;
	CMaskEdit	m_Dt3;
	CMaskEdit	m_Dt2;
	CMaskEdit	m_Dt1;
	CMaskEdit	m_Dt10;
	CMaskEdit	m_Dt9;
	CMaskEdit	m_Dt8;
	CMaskEdit	m_Dt7;
	CEdit	m_Edit9;
	CEdit	m_Edit8;
	CComboBox	m_Combo3;
	CButton	m_Button4;
	CEdit	m_Edit10;
	CButton	m_Button1;
	CButton	m_Button2;
	CEdit	m_Edit7;
	CButton	m_Check9;
	CComboBox	m_Combo2;
	CEdit	m_Edit6;
	CEdit	m_Edit5;
	CButton	m_Check16;
	CButton	m_Check15;
	CButton	m_Check14;
	CButton	m_Check12;
	CButton	m_Check11;
	CButton	m_Check10;
	CEdit	m_Edit4;
	CEdit	m_Edit3;
	CEdit	m_Edit2;
	CEdit	m_Edit1;
	CComboBox	m_Combo1;
	CButton	m_Check8;
	CButton	m_Check7;
	CButton	m_Check6;
	CButton	m_Check5;
	CButton	m_Check4;
	CButton	m_Check3;
	CButton	m_Check2;
	CButton	m_Check1;
	CButton	m_CheckSpis;
	//}}AFX_DATA
	CComboBox	m_ComboRem1;
	CComboBox	m_ComboRem2;
	CMaskEdit m_EdSobst;
	CButton m_ButSobst;
	CButton m_Check17;

	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDBKPSelect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDBKPSelect)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton4();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnCheck6();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	afx_msg void OnCheck10();
	afx_msg void OnCheck11();
	afx_msg void OnCheck12();
	afx_msg void OnCheck13();
	afx_msg void OnCheck14();
	afx_msg void OnCheck15();
	afx_msg void OnCheck16();
	afx_msg void OnCheck17();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton7();
public:
	afx_msg void OnBnClickedButton_Sobst();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDBKPSELECT_H__4EA55314_51F4_4866_89B5_673A54C56001__INCLUDED_)
