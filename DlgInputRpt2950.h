#pragma once
#include "afxwin.h"
#include "maskedit.h"


// CDlgInputRpt2950 dialog

class CDlgInputRpt2950 : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputRpt2950)

public:
	CDlgInputRpt2950(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputRpt2950();

// Dialog Data
	enum { IDD = IDD_INPUT_RPT_2950 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_Cb1;
	CButton m_Cb2;
	CMaskEdit m_Dat;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedOk();
};
