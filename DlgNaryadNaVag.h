#pragma once
#include "maskedit.h"


// CDlgNaryadNaVag dialog

class CDlgNaryadNaVag : public CDialog
{
	DECLARE_DYNAMIC(CDlgNaryadNaVag)

public:
	CDlgNaryadNaVag(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgNaryadNaVag();

// Dialog Data
	enum { IDD = IDD_NARYAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat;
	CMaskEdit m_FIO;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
