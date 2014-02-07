#pragma once
#include "afxwin.h"
#include "maskedit.h"


// CDlgSetupCommon dialog

class CDlgSetupCommon : public CDialog
{
	DECLARE_DYNAMIC(CDlgSetupCommon)

public:
	CDlgSetupCommon(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSetupCommon();	
// Dialog Data
	enum { IDD = IDD_SETUP_COMMON };
	int m_iNeedDowngrade;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_CheckSqlDbg;
	CButton m_CheckSilentCancel;
	
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CButton m_Check3;
	CMaskEdit m_EdDays;
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck1();
	CMaskEdit m_EdLogDir;
	afx_msg void OnBnClickedButtonReverseUpgr();	
	CButton m_CheckAlerts;
};
