#pragma once
#include "afxcmn.h"
#include "DlgMsg2957_1.h"
#include "DlgMsg2957_2.h"
#include "maskedit.h"
#include "afxwin.h"
#include "ColoredButton.h"

// CDlgMsg2957Main dialog

class CDlgMsg2957Main : public CDialog
{
	DECLARE_DYNAMIC(CDlgMsg2957Main)

public:
	CDlgMsg2957Main(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg2957Main();

// Dialog Data
	enum { IDD = IDD_MSG2957 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	CDlgMsg2957_1 Tab1;
	CDlgMsg2957_2 Tab2;

	SYSTEMTIME stDate;
	int iFromKpBase;
	__int64 qwIDS;
	CWnd *CurWnd;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CMaskEdit m_Dat;
	CMaskEdit m_EdPr;
	void FillForm(void);
	CColoredButton m_BnSost;
	afx_msg void OnBnClickedOk();
	void StoreMessageToBase(void);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	void CalcSum(void);
};
