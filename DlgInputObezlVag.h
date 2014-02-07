#pragma once
#include "afxwin.h"
#include "maskedit.h"


// CDlgInputObezlVag dialog

class CDlgInputObezlVag : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputObezlVag)

public:
	CDlgInputObezlVag(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputObezlVag();

// Dialog Data
	enum { IDD = IDD_INPUT_OBEZL_VAG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_Cb1;
	CButton m_Cb2;
	CMaskEdit m_EdNVag;
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedCheck1();
	CButton m_C1;
	CButton m_C2;
	afx_msg void OnBnClickedCheck31();
};
