#pragma once
#include "afxwin.h"
#include "DlgAccel1.h"
#include "maskedit.h"
#include ".\controls\MyLabel.h"

// CDlgMsg4624_KP dialog

class CDlgMsg4624_KP : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg4624_KP)

public:
	CDlgMsg4624_KP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_KP();

// Dialog Data
	enum { IDD = IDD_4624_KP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	CDlgMsg4624_Main *pMainDlg;
	CMyLabel m_Lab1;
	CMyLabel m_Lab2;
	CMyLabel m_Lab3;
	CMyLabel m_Lab4;
	CMyLabel m_Lab6;
	CMyLabel m_Lab7;
	CMyLabel m_Lab8;
	CMyLabel m_Lab9;
	CMyLabel m_Lab10;
	CMyLabel m_Lab11;
	CMyLabel m_Lab12;
	afx_msg void OnBnClickedCancel();
	void OnCancel(void);
	void SetIzNal( int idx );
	afx_msg void OnBnClickedButton_FIO1();
	void SetObod( int idx );
	void SetGreb( int idx );

	CMaskEdit m_p[14][9];

	CMaskEdit m_EdFIO1;
	CMaskEdit m_EdFIO2;

	CButton m_bnFio1;
	CButton m_bnFio2;

	CButton m_lpButIz[8];
	CButton m_lpButIzNal[8];


	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnArrowDown();
	afx_msg void OnArrowUp();
	afx_msg void OnBnClickedButtonIZ1();
	afx_msg void OnBnClickedButtonIZ2();
	afx_msg void OnBnClickedButtonIZ3();
	afx_msg void OnBnClickedButtonIZ4();
	afx_msg void OnBnClickedButtonIZ5();
	afx_msg void OnBnClickedButtonIZ6();
	afx_msg void OnBnClickedButtonIZ7();
	afx_msg void OnBnClickedButtonIZ8();
public:
	afx_msg void OnBnClickedButtonIzNal1();
public:
	afx_msg void OnBnClickedButtonIzNal2();
public:
	afx_msg void OnBnClickedButtonIzNal3();
public:
	afx_msg void OnBnClickedButtonIzNal4();
public:
	afx_msg void OnBnClickedButtonIzNal5();
public:
	afx_msg void OnBnClickedButtonIzNal6();
public:
	afx_msg void OnBnClickedButtonIzNal7();
public:
	afx_msg void OnBnClickedButtonIzNal8();
public:
	afx_msg void OnEnKillfocus70();
public:
	afx_msg void OnEnChange70();
public:
	afx_msg void OnEnChange71();
public:
	afx_msg void OnEnChange72();
public:
	afx_msg void OnEnChange73();
public:
	afx_msg void OnEnChange74();
public:
	afx_msg void OnEnChange75();
public:
	afx_msg void OnEnChange76();
public:
	afx_msg void OnEnChange77();
public:
	afx_msg void OnEnChange80();
};
