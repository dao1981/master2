#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CInputNVagObezl4624 dialog

class CInputNVagObezl4624 : public CDialog
{
	DECLARE_DYNAMIC(CInputNVagObezl4624)

public:
	CInputNVagObezl4624(CWnd* pParent = NULL);   // standard constructor
	virtual ~CInputNVagObezl4624();

// Dialog Data
	enum { IDD = IDD_NVAG_OBEZL4624 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdNVag;
	virtual BOOL OnInitDialog();
	CButton m_Check;
	afx_msg void OnBnClickedOk();
	BOOL bDatFromPasp;
	char cNVag32[32];
};
