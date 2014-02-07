#pragma once
#include "maskedit.h"
#include "fastgrid.h"
#include "DlgAccel1.h"


// CDlgPPTSendToRem dialog

class CDlgPPTSendToRem : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgPPTSendToRem)

public:
	CDlgPPTSendToRem(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPPTSendToRem();

// Dialog Data
	enum { IDD = IDD_PPS_SENT_TO_REM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CMaskEdit m_Dat1;
	CMaskEdit m_FIO1;
	CMaskEdit m_EdTlNum;
	afx_msg void OnBnClickedButton_FIO1();
	CFastGrid m_List;
	afx_msg void OnBnClickedButton_AddTl();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton_remove();
protected:
	virtual void OnCancel();
};
