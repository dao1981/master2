#pragma once
#include "afxwin.h"
#include "maskedit.h"


// CDlgSetupTO dialog

class CDlgSetupTO : public CDialog
{
	DECLARE_DYNAMIC(CDlgSetupTO)

public:
	CDlgSetupTO(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSetupTO();

// Dialog Data
	enum { IDD = IDD_SETUP_TO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_Check1;
	CMaskEdit m_EdName1;
	CMaskEdit m_EdName2;
	CMaskEdit m_EdName3;
	CMaskEdit m_EdAuto1;
	CMaskEdit m_EdAuto2;
	CMaskEdit m_EdAuto3;
	CMaskEdit m_EdAddr1;
	CMaskEdit m_EdAddr2;
	CMaskEdit m_EdAddr3;
	CMaskEdit m_EdPort1;
	CMaskEdit m_EdPort2;
	CMaskEdit m_EdPort3;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	void ReadSetupFiles(void);
	CMaskEdit m_EdPathSnd;
	CMaskEdit m_EdPathRcv;
	CMaskEdit m_EdPathBad;
	CButton m_Check2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCreateDir2();
	afx_msg void OnBnClickedCreateDir3();
};
