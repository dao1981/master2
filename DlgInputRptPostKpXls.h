#pragma once
#include "maskedit.h"


// CDlgInputRptPostKpXls dialog

class CDlgInputRptPostKpXls : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputRptPostKpXls)

public:
	CDlgInputRptPostKpXls(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputRptPostKpXls();

// Dialog Data
	enum { IDD = IDD_INPUT_RPT_POST_KP_XLS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdDat;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	char cDat[16];
};
