#if !defined(AFX_DLGDBOSSELECT_H__2A77FBDE_A9E5_4AD6_AD4A_4E44916BC633__INCLUDED_)
#define AFX_DLGDBOSSELECT_H__2A77FBDE_A9E5_4AD6_AD4A_4E44916BC633__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDBOsSelect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDBOsSelect dialog

class CDlgDBOsSelect : public CDialog
{
// Construction
public:
	CDlgDBOsSelect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDBOsSelect)
	enum { IDD = IDD_DIALOG_BDOS };
	CButton	m_Bn2;
	CEdit	m_Ed4;
	CEdit	m_Ed3;
	CEdit	m_Ed2;
	CButton	m_Bn1;
	CEdit	m_Ed1;
	CComboBox	m_Combo1;
	CButton	m_Chk4;
	CButton	m_Chk7;
	CButton	m_Chk6;
	CButton	m_Chk5;
	CButton	m_Chk3;
	CButton	m_Chk2;
	CButton	m_Chk1;
	CDateTimeCtrl	m_Dt7;
	CDateTimeCtrl	m_Dt8;
	CDateTimeCtrl	m_Dt6;
	CDateTimeCtrl	m_Dt5;
	CDateTimeCtrl	m_Dt4;
	CDateTimeCtrl	m_Dt3;
	CDateTimeCtrl	m_Dt2;
	CDateTimeCtrl	m_Dt1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDBOsSelect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDBOsSelect)
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnButton3();
	afx_msg void OnCheck5();
	afx_msg void OnButton1();
	afx_msg void OnCheck6();
	afx_msg void OnCheck7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDBOSSELECT_H__2A77FBDE_A9E5_4AD6_AD4A_4E44916BC633__INCLUDED_)
