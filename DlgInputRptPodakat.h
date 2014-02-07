#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgInputRptPodakat dialog

class CDlgInputRptPodakat : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputRptPodakat)

public:
	CDlgInputRptPodakat(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputRptPodakat();

// Dialog Data
	enum { IDD = IDD_INPUT_RPT_PODKAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CMaskEdit m_EdKPNum;
	CMaskEdit m_EdDat;
	CButton m_Rad1;
	CButton m_Rad2;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedOk();
};
