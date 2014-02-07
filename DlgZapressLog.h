#pragma once
#include "maskedit.h"
#include "DlgAccel1.h"


// CDlgZapressLog dialog

class CDlgZapressLog : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgZapressLog)

public:
	CDlgZapressLog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgZapressLog();

// Dialog Data
	enum { IDD = IDD_INPUT_RASPRESS_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	CMaskEdit m_EdFam;
	CMaskEdit m_EdNum;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
