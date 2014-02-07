#pragma once
#include "afxwin.h"
#include "DlgAccel1.h"
#include "MaskEdit.h"
#include ".\controls\MyLabel.h"

struct CLDTLFormBuffer
{
	int	iScreenPage;
	CString p_strNum[4];
	CString str_p[14][12];
	int		p_iComboIndex[12];
	CLDTLFormBuffer();
};
/*
struct CLDTLFormBuffer
{
	int	iStoredPage;
	CString p_strNum[2];
	CString str_p[14][6];
	int		p_iComboIndex[6];
	CLDTLFormBuffer();
};
*/
// CDlgMsg4624_LDTL dialog

class CDlgMsg4624_LDTL : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg4624_LDTL)

public:
	CDlgMsg4624_LDTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_LDTL();

// Dialog Data
	enum { IDD = IDD_4624_LDTL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	CLDTLFormBuffer m_TlBuffer;
	CLDTLFormBuffer m_BackBuffer;
	afx_msg void OnStnClickedLabs1();

	CMyLabel m_Lab1;
	CMyLabel m_Lab2;
	CMyLabel m_Lab3;
	CMyLabel m_Lab4;
	CMyLabel m_Lab5;

	CMaskEdit m_p[14][6];
	CMaskEdit m_Num[4];
	CComboBox m_c[6];

	CMaskEdit m_FIO1;
	CMaskEdit m_FIO2;
	CButton	  m_8OsButton;

	CButton	  m_bnFio1;
	CButton	  m_bnFio2;

	CButton	  m_ButIz1;
	CButton	  m_ButIz2;
	CButton	  m_ButIz3;
	CButton	  m_ButIz4;
	CButton	  m_ButIz5;
	CButton	  m_ButIz6;

	virtual BOOL OnInitDialog();
protected:
	virtual void OnCancel();
public:
	afx_msg void OnCbnSelchangeCombo23();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnCbnSelchangeCombo_1();
	afx_msg void OnCbnSelchangeCombo_2();
	afx_msg void OnCbnSelchangeCombo_4();
	afx_msg void OnCbnSelchangeCombo_5();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnArrowDown();
	afx_msg void OnArrowUp();
	afx_msg void OnBnClickedButton3();
	void StoreValues(void);
	void DrawBuffer(int page);
public:
	afx_msg void OnBnClickedButton4();
public:
	afx_msg void OnBnClickedButton6();
public:
	afx_msg void OnBnClickedButton7();
public:
	afx_msg void OnBnClickedButton67();
public:
	afx_msg void OnBnClickedButton9();
public:
	afx_msg void OnBnClickedButton25();
public:
	afx_msg void OnEnChangeE130();
};

