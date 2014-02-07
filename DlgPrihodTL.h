#pragma once
#include "afxwin.h"


// CDlgPrihodTL dialog

class CDlgPrihodTL : public CDialog
{
	DECLARE_DYNAMIC(CDlgPrihodTL)

public:
	CDlgPrihodTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPrihodTL();

	DWORD dwRamaLeft_IPR;
	DWORD dwRamaRight_IPR;
	DWORD dwBalka_IPR;

	DWORD dwDefect_RL;
	DWORD dwDefect_RR;
	DWORD dwDefect_B;
	PRIHOD_TL	PrihodTl;
// Dialog Data
	enum { IDD = IDD_PRIHOD_TL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void InitComponents(void);
	afx_msg void OnBnClickedButton1();
	CEdit m_EdKl1;
	CEdit m_EdPrName1;
	CEdit m_EdRL_Num;
	CEdit m_EdRR_Num;
	CEdit m_EdRL_Year;
	CEdit m_EdRR_Year;
	CComboBox m_CbRL_Rem;
	CComboBox m_CbRR_Rem;
	CEdit m_EdB_Num;
	CEdit m_EdB_Year;
	CComboBox m_CbB_Rem;
	CEdit m_EdPos1;
	CEdit m_EdPos2;
	CEdit m_EdUslNum;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton_PrRamaRight();
	CEdit m_EdKl2;
	CEdit m_EdPrName2;
	CEdit m_EdKl3;
	CEdit m_EdPrName3;
	afx_msg void OnBnClickedButton_PrBalka();
	afx_msg void OnBnClickedButton_DefectRL();
	afx_msg void OnBnClickedButton_DefectRR();
	afx_msg void OnBnClickedButton_DefectB();
	CComboBox m_CbL;
	CComboBox m_CbR;
	afx_msg void OnCbnSelchangeComboL();
	afx_msg void OnCbnSelchangeComboR();
};
