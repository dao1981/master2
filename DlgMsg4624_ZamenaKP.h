#pragma once
#include "maskedit.h"
#include "DlgAccel1.h"
#include "./controls/MyLabel.h"
// CDlgMsg4624_ZamenaKP dialog

class CDlgMsg4624_ZamenaKP : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg4624_ZamenaKP)

public:
	CDlgMsg4624_ZamenaKP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_ZamenaKP();

// Dialog Data
	enum { IDD = IDD_4624_ZAMENA_KP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_p[14][8];
	virtual BOOL OnInitDialog();
	CMaskEdit m_FIO1;
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
	CMyLabel m_Lab13;

	CButton  m_bnFio;

	CComboBox m_pTKP[8];
protected:
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnBnClickedButton_FIO1();
	afx_msg void OnArrowDown();
	afx_msg void OnArrowUp();
};
