#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgInputRptPrihodTL dialog

class CDlgInputRptPrihodTL : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputRptPrihodTL)

public:
	CDlgInputRptPrihodTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputRptPrihodTL();

// Dialog Data
	enum { IDD = IDD_INPUT_REP_PRIHTL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	CMaskEdit m_EdNVag;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheck1();
	CButton m_Check1;
	CButton m_Check2;
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedOk();
};
