#pragma once
#include "maskedit.h"


// CDlgInputNVag dialog

class CDlgInputNVag : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputNVag)

public:
	CDlgInputNVag(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputNVag();

// Dialog Data
	enum { IDD = IDD_INPUT_NVAG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdNVag;
	CString strNVag;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
