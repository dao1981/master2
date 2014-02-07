#pragma once
#include "maskedit.h"


// CDlgInputDate dialog

class CDlgInputDate : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputDate)

public:
	CDlgInputDate(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputDate();
	SYSTEMTIME stDate;
	char cSQLDate[26];

// Dialog Data
	enum { IDD = IDD_INPUT_DATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdDate;
public:
	afx_msg void OnBnClickedOk();
public:
	virtual BOOL OnInitDialog();
};
