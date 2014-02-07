#pragma once
#include "maskedit.h"
#include "afxwin.h"
#include "DlgAccel1.h"
#include "ColoredButton.h"
// CDlgMsg2956 dialog

class CDlgMsg2956 : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg2956)

public:
	CDlgMsg2956(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg2956();

// Dialog Data
	enum { IDD = IDD_MSG_2956 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Ed[17];
	CMaskEdit m_Edt[4];

	CMaskEdit m_Ed2[17];
	CMaskEdit m_Edt2[4];
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

	SYSTEMTIME stDate;
	int	iFromKpBase;
	CMaskEdit m_Dat;
	CMaskEdit m_EdVKM;
	__int64 qwIDS;
	CColoredButton m_But;
	afx_msg void OnBnClickedButton2();
	int WriteMessageToBase(void);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonReport();
};
