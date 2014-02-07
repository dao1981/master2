#include "afxwin.h"
#include "maskedit.h"
#if !defined(AFX_DLGADDKPSMALL_H__5503C061_CDF6_4370_B539_FF446C850772__INCLUDED_)
#define AFX_DLGADDKPSMALL_H__5503C061_CDF6_4370_B539_FF446C850772__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAddKpSmall.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAddKpSmall dialog

class CDlgAddKpSmall : public CDialog
{
// Construction
public:
	CDlgAddKpSmall(CWnd* pParent = NULL);   // standard constructor
    DWORD   dwTKP[255];
    char    cDate[12];
    char    cNumKP[32];
	char	cRemont64[64];
	char	cTKP32[32];
    DWORD     dwTypeKP;
    unsigned __int64 qwIKP;
    unsigned __int64 qwIZAP;
	DWORD	dwIPrIzg;
	SYSTEMTIME stDatIzg;
	char	cYearIzg[8];
	char	cKlPrIzg[16];

	DWORD	dwTPodsh;
	DWORD	dwmSteel;

    DWORD   dwPriznRas;
    DWORD   dwGruz;
	int		iCreateRecieveMode;
	DWORD	dwNeispID;
	bool	bStarted;
	CString m_strNeispName;
// Dialog Data
	//{{AFX_DATA(CDlgAddKpSmall)
	enum { IDD = IDD_DIALOG_SMALL_ADD_KP };
	CEdit	m_Edit1;
	CComboBox	m_Combo1;
	CString	m_EditText;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAddKpSmall)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAddKpSmall)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdKlIzg;
	CStatic m_LabelRem;
	CString m_strTKP;
	afx_msg void OnBnClickedOk();
	CEdit m_EdKod;
	CButton m_But1;
	CEdit m_EdKodName;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton2();
public:
	
	CMaskEdit m_EdYear;
	CStatic m_LabelIzg;
	CStatic m_LabelYr;
	CButton m_ButKl;
	int m_iYearIzg;
	int m_iKlPrIzg;

	CMaskEdit m_EdObod_KP1;
	CMaskEdit m_EdObod_KP2;
	CMaskEdit m_EdGreb_KP1;
	CMaskEdit m_EdGreb_KP2;
	CMaskEdit m_EdProkat_KP1;
	CMaskEdit m_EdProkat_KP2;

	DWORD dwObod_KP1;
	DWORD dwObod_KP2;
	DWORD dwGreb_KP1;
	DWORD dwGreb_KP2;
	double dProkat_KP1;
	double dProkat_KP2;
	double dDiam_KP1;
	double dDiam_KP2;
	DWORD dwDisk_KP1;
	DWORD dwDisk_KP2;

	CMaskEdit m_EdDiam_KP1;
	CMaskEdit m_EdDiam_KP2;
	CMaskEdit m_EdDisk_KP1;
	CMaskEdit m_EdDisk_KP2;
public:
	CComboBox m_cbTypePodsh;
public:
	CComboBox m_cbMSteel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDKPSMALL_H__5503C061_CDF6_4370_B539_FF446C850772__INCLUDED_)
