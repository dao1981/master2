#if !defined(AFX_DLGKPVVOD1_H__9EF1D40C_2DB0_457A_BD0F_780F029755E0__INCLUDED_)
#define AFX_DLGKPVVOD1_H__9EF1D40C_2DB0_457A_BD0F_780F029755E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgKpVvod1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgKpVvod1 dialog
#include "MaskEdit.h"
#include "DialogHeader.h"
#include "afxwin.h"
#include "DlgAccel1.h"

class CDlgKpVvod1 : public CDlgWithAccelerators
{
// Construction
public:
	CDialogHeader m_HeaderCtrl;
	CDlgKpVvod1(CWnd* pParent = NULL);   // standard constructor
    PASP_KP Pasp; // TZapPasp record
    PRIH_KP Prih; // TZapPrih
    DWORD idKPType[64];
    char cNumKP[32];
	int iGotKPfromSelKP;
	int iReadyState;
    DWORD dwTypeKP;
    void SelPrih();
    __int64 qwIKP;
	__int64 qwIZap;
    int     iFo;
    int     iZp;
    bool    ClearFlag;
    void    DisableBtns();
    void    SetButtons(__int64);
	void	UpdateFieldsByIZap( __int64 z );
// Dialog Data
	//{{AFX_DATA(CDlgKpVvod1)
	enum { IDD = IDD_DIALOG_KP_VVOD1 };
	CButton	m_ButObmer;
	CButton	m_ButMont;
	CButton	m_ButRem;
	CButton	m_ButZapr;
	CButton	m_ButRash;
//	CEdit	m_Hint;
	CButton	m_ButTwin;
	CButton	m_ButPrihod2;
	CButton	m_ButPrihod;
	CButton m_ButReady;
	CComboBox	m_Combo1;
	CMaskEdit	m_edKpNum;
	CMaskEdit	m_edYearIzg;
	CMaskEdit	m_edKlPrIzg;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgKpVvod1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgKpVvod1)
	afx_msg void OnReady();
	afx_msg void OnButton8();
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton5();
	afx_msg void OnChangeEditNKP();
	afx_msg void OnSelchangeComboTKP();
	afx_msg void OnButton2();
	afx_msg void OnButtonRemont();
	afx_msg void OnButtonMntBuks();
	afx_msg void OnButtonZapress();
	afx_msg void OnBnPrihodOS();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton_PaspKP();
public:
	afx_msg void OnBnClickedButton_SelectKP();
public:
	CButton m_butVybrat;
public:
	CButton m_butExit;
public:
	CButton m_butPasp;
public:
	afx_msg void OnBnClicked_SelKlIzg();
public:
	afx_msg void OnEnChangeEdit7();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGKPVVOD1_H__9EF1D40C_2DB0_457A_BD0F_780F029755E0__INCLUDED_)
