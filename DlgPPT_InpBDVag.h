#pragma once
#include "maskedit.h"
#include "afxwin.h"
#include "DlgPPT_BDVagRez.h"

// CDlgPPT_InpBDVag dialog

class CDlgPPT_InpBDVag : public CDialog
{
	DECLARE_DYNAMIC(CDlgPPT_InpBDVag)

public:
	CDlgPPT_InpBDVag(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPPT_InpBDVag();

// Dialog Data
	enum { IDD = IDD_PPT_SEL_BDVAG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	CMaskEdit m_EdNVag;
public:
	CMaskEdit m_EdNTL;
public:
	CMaskEdit m_EdDat1067;
public:
	CMaskEdit m_EdDat1520;
public:
	afx_msg void OnBnClickedOk();
public:
	CButton m_cbNVag;
public:
	CButton m_cbNTL;
public:
	CButton m_cbDat1067;
public:
	CButton m_cbDat1520;
public:
	afx_msg void OnBnClickedCheck1();
public:
	afx_msg void OnBnClickedCheck2();
public:
	afx_msg void OnBnClickedCheck3();
public:
	afx_msg void OnBnClickedCheck4();
public:
	CMaskEdit m_EdDat1067_2;
public:
	CMaskEdit m_EdDat1520_2;
public:
	CMaskEdit m_EdFIO_Sles;
public:
	CButton m_ButSles;
public:
	afx_msg void OnBnClickedCheck5();
public:
	CButton m_CheckSles;
public:
	afx_msg void OnBnClickedButton_FioSles();
};
