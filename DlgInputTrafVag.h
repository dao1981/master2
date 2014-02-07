#pragma once
#include "afxwin.h"
#include "maskedit.h"


// CDlgInputTrafVag dialog

class CDlgInputTrafVag : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputTrafVag)

public:
	CDlgInputTrafVag(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputTrafVag();

// Dialog Data
	enum { IDD = IDD_INPUT_TRAF_VAG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_Check1;
	CButton m_Check2;
	CButton m_Check3;
	CButton m_Check4;
	CButton m_Check5;
	CMaskEdit m_EdNVag;
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	CMaskEdit m_EdESR1;
	CMaskEdit m_EdStan1;
	CMaskEdit m_EdESR2;
	CMaskEdit m_EdStan2;
	CButton m_Radio1;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CButton m_Radio3;
	CButton m_Radio4;
	CButton m_Radio5;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck31();
	afx_msg void OnBnClickedCheck3();
	CButton m_But1;
	CButton m_But2;
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	CButton m_Radio2;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
};
