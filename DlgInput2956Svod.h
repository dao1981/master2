#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgInput2956Svod dialog

class CDlgInput2956Svod : public CDialog
{
	DECLARE_DYNAMIC(CDlgInput2956Svod)

public:
	CDlgInput2956Svod(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInput2956Svod();

// Dialog Data
	enum { IDD = IDD_INPUT_2956_SVOD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdMonth;
	virtual BOOL OnInitDialog();
	CButton m_Cb1;
	CButton m_Cb2;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedOk();
};
