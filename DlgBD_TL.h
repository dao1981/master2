#pragma once
#include "afxwin.h"
#include "maskedit.h"

// CDlgBD_TL dialog

class CDlgBD_TL : public CDialog
{
	DECLARE_DYNAMIC(CDlgBD_TL)

public:
	CDlgBD_TL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgBD_TL();

// Dialog Data
	enum { IDD = IDD_BD_PRIH_TL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	CButton m_Cb1;
	CButton m_Cb2;
	CButton m_Cb3;
	CButton m_Cb4;
	CButton m_Cb5;
	CButton m_Cb6;
	CButton m_Cb7;
	CComboBox m_Combo1;
	CComboBox m_Combo2;
	CEdit m_VagNum1;
	CEdit m_VagNum2;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck31();
	afx_msg void OnBnClickedCheck39();
	afx_msg void OnBnClickedCheck40();
	afx_msg void OnBnClickedCheck38();
	afx_msg void OnBnClickedCheck35();
	afx_msg void OnBnClickedCheck42();
	CButton m_Cb8;
	CEdit m_EdUslNum;
	afx_msg void OnBnClickedCheck41();
	afx_msg void OnBnClickedOk();
	CMaskEdit m_Dat11;
	CMaskEdit m_Dat22;
};
