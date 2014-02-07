#pragma once
#include "MaskEdit.h"
#include ".\controls\MyLabel.h"
#include "afxwin.h"
#include "DlgAccel1.h"

// CDlgPrihodTL2 dialog

class CDlgPrihodTL2 : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgPrihodTL2)

public:
	CDlgPrihodTL2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPrihodTL2();

// Dialog Data
	enum { IDD = IDD_PRIHOD_TL2 };

	CMyLabel m_Lab1;
	__int64 qwILK;
	__int64	qwIDS;
	DWORD dwVRem;
	SYSTEMTIME stDatPostVRem;
	SYSTEMTIME stDatVyhIzRem;
	int i8Os;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_p[9][12];
	CComboBox m_c[12];
	CComboBox m_c2[12];
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	void FillForm(void);
	CMaskEdit m_EdNVag;
	CEdit m_EdVidRem;
	CMaskEdit m_EdDatPost;
	CMaskEdit m_EdDatVyhRem;
	CMaskEdit m_EdDatVykatki;
	CMaskEdit m_EdFamMast;
	CButton m_bnFrom2730;
	CButton m_bnOK;
	CButton m_bnCancel;
	CButton m_bnReport;
	CButton m_bnSendToAsld;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnCbnSelchangeCombo5();
	afx_msg void OnCbnSelchangeCombo7();
	afx_msg void OnCbnSelchangeCombo8();
	afx_msg void OnCbnSelchangeCombo10();
	afx_msg void OnCbnSelchangeCombo11();
	afx_msg void OnBnClickedButtonFill2730();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton38();
	afx_msg void OnBnClickedButton43();
	afx_msg void OnBnClickedButton33();
	afx_msg void OnBnClickedButton34();
	afx_msg void OnBnClickedButton44();
	afx_msg void OnBnClickedButton51();
	afx_msg void OnBnClickedButton52();
	afx_msg void OnBnClickedButton53();
	afx_msg void OnBnClickedButton54();
	afx_msg void OnBnClickedButton55();
	afx_msg void OnBnClickedButton56();
	afx_msg void OnBnClickedSendAsld();
	void SetPr(int RowIndex);
	void SetAllIPR(void);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnKillfocusE10();
	afx_msg void OnBnClickedButtonReport();
	int SaveData();
};
