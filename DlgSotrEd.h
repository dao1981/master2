#if !defined(AFX_DLGSOTRED_H__1058C7E4_96AC_4762_8BD7_D7462039BCCE__INCLUDED_)
#define AFX_DLGSOTRED_H__1058C7E4_96AC_4762_8BD7_D7462039BCCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSotrEd.h : header file
//
#include "EmplArray.h"
#include "MaskEdit.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgSotrEd dialog

class CDlgSotrEd : public CDialog
{
// Construction
public:
	CDlgSotrEd(CWnd* pParent = NULL);   // standard constructor
    ~CDlgSotrEd();
    char mcPass[30];
    BYTE miRang;
    int  Mode;
    DWORD id;
    CEmplArray EmplArr;
    DWORD ret_dwProfID;
// Dialog Data
	//{{AFX_DATA(CDlgSotrEd)
	enum { IDD = IDD_DIALOG_SOTR_ED };
	CComboBox	m_Combo;
	CMaskEdit	m_Edit1;
	CButton	m_Check1;
	CEdit	m_Edit5;
	CEdit	m_Edit4;
	BOOL	m_cbPRKP;
	BOOL	m_cbPZMKP;
	BOOL	m_cbPDSH;
	BOOL	m_cbPDPO;
	BOOL	m_cbPDVK;
	BOOL	m_cbPDSO;
	BOOL	m_cbPDSP;
	BOOL	m_cbPDD;
	BOOL	m_cbPDO;
	BOOL	m_cbPDG;
	BOOL	m_cbPDROL;
	BOOL	m_cbPDSEP;
	BOOL	m_cbPDNK;
	BOOL	m_cbPOSV;
	BOOL	m_cbPMB;
	BOOL	m_cbSL1;
	BOOL	m_cbSL2;
	BOOL	m_cbPOTK;
	BOOL	m_cbPOP;
	BOOL	m_cbPRP;
	BOOL	m_cbPKP;
	BOOL	m_cbOTP;
	BOOL	m_cbPVPV;
	BOOL	m_cbMRP;
	BOOL	m_cbORED;
	BOOL	m_cbRRED;
	BOOL	m_cbMRED;
	BOOL	m_cbZKP;
	BOOL	m_cbBZKP;
	CString	m_Edit1Text;
	CString	m_Edit5Text;
	CString	m_Edit4Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSotrEd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSotrEd)
	virtual void OnOK();
	afx_msg void OnCheck30();
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEdit1();
	afx_msg void OnSetfocusTabNum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSOTRED_H__1058C7E4_96AC_4762_8BD7_D7462039BCCE__INCLUDED_)
