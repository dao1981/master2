#pragma once
#include "afxwin.h"
#include "maskedit.h"


// CDlgPPT_EditVag dialog

class CDlgPPT_EditVag : public CDialog
{
	DECLARE_DYNAMIC(CDlgPPT_EditVag)

public:
	CDlgPPT_EditVag(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPPT_EditVag();

// Dialog Data
	enum { IDD = IDD_PPT_EDIT_VAGTL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	__int64 qwIZapVag;
	char cNVag[10];

	CStatic m_LabNVag;
	CMaskEdit m_EdDat1067;
	CMaskEdit m_EdNTL1;
	CMaskEdit m_EdNTL2;
	CMaskEdit m_EdFIO1;
	CMaskEdit m_EdD;
	CMaskEdit m_EdR;
	CMaskEdit m_EdDat1520;
	CMaskEdit m_EdFIO2;
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedButtonFIO1();
public:
	afx_msg void OnBnClickedButtonFIO2();
public:
	afx_msg void OnBnClickedButtonCancel1520();
public:
	CButton m_bnCancel1520;
public:
	CMaskEdit m_EdNVagTL;
public:
	CMaskEdit m_EdFio_Sles;
public:
	afx_msg void OnBnClickedButton_FioSles();
};
