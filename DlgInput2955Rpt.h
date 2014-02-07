#pragma once
#include "maskedit.h"
#include "afxwin.h"
#include "DlgAccel1.h"

// CDlgInput2955Rpt dialog

class CDlgInput2955Rpt : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgInput2955Rpt)

public:
	CDlgInput2955Rpt(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInput2955Rpt();

// Dialog Data
	enum { IDD = IDD_INPUT_2955_RPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	CButton m_Check;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
