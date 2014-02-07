#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgInput_VO7 dialog

class CDlgInput_VO7 : public CDialog
{
	DECLARE_DYNAMIC(CDlgInput_VO7)

public:
	CDlgInput_VO7(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInput_VO7();

// Dialog Data
	enum { IDD = IDD_INPUT_RPT_VO7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat;
	CButton m_Cb1;
	CButton m_Cb2;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
