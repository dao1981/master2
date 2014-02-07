#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgInputRpt2956 dialog

class CDlgInputRpt2956 : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputRpt2956)

public:
	CDlgInputRpt2956(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputRpt2956();

// Dialog Data
	enum { IDD = IDD_INPUT_RPT_2956 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat;
	CButton m_Check1;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
