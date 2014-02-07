#if !defined(AFX_DLGKPIN_H__531A4C09_034A_4DDD_B7E9_197B7E1F81F5__INCLUDED_)
#define AFX_DLGKPIN_H__531A4C09_034A_4DDD_B7E9_197B7E1F81F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgKPin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgKPin dialog

class CDlgKPin : public CDialog
{
// Construction
public:
	CDlgKPin(CWnd* pParent = NULL);   // standard constructor
    BOOL OnInitDialog();
    void    SelPrih();
// Dialog Data
	//{{AFX_DATA(CDlgKPin)
	enum { IDD = IDD_DIALOG_KP_INP1 };
	CButton	m_TwinBn;
	CComboBox	m_Combo1;
	CEdit	m_Edit1;
	UINT	m_iNumKP;
	//}}AFX_DATA
    PASP_KP Pasp; // TZapPasp record
    PRIH_KP Prih; // TZapPrih
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgKPin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgKPin)
	virtual void OnOK();
	afx_msg void OnButton1();    
	afx_msg void OnButton8();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGKPIN_H__531A4C09_034A_4DDD_B7E9_197B7E1F81F5__INCLUDED_)
