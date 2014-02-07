#pragma once
#include "maskedit.h"
#include "afxwin.h"
#include "dlgaccel1.h"
#include "ColoredButton.h"

// CDlgMsg2955 dialog

class CDlgMsg2955 : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg2955)

public:
	CDlgMsg2955(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg2955();

// Dialog Data
	enum { IDD = IDD_MSG_2955 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Ed1;
	CMaskEdit m_Ed2;
	CMaskEdit m_Ed3;
	CMaskEdit m_Ed4;
	CMaskEdit m_Ed5;
	CMaskEdit m_Ed6;
	CMaskEdit m_Ed7;
	CMaskEdit m_Ed8;
	CMaskEdit m_Ed9;
	CMaskEdit m_Ed10;
	CMaskEdit m_Ed11;
	CMaskEdit m_Ed12;
	CMaskEdit m_Ed13;
	CMaskEdit m_Ed14;
	CMaskEdit m_Ed15;
	CMaskEdit m_Ed16;
	CMaskEdit m_Ed17;
	CMaskEdit m_Ed18;
	CMaskEdit m_Ed19;
	CMaskEdit m_Ed20;

	CMaskEdit m_Ed21;
	CMaskEdit m_Ed22;
	CMaskEdit m_Ed23;
	CMaskEdit m_Ed24;
	CMaskEdit m_Ed25;
	CMaskEdit m_Ed26;
	CMaskEdit m_Ed27;
	CMaskEdit m_Ed28;
	CMaskEdit m_Ed29;
	CMaskEdit m_Ed30;
	CMaskEdit m_Ed31;
	CMaskEdit m_Ed32;
	CMaskEdit m_Ed33;
	CMaskEdit m_Ed34;
	CMaskEdit m_Ed35;
	CMaskEdit m_Ed36;
	CMaskEdit m_Ed37;
	CMaskEdit m_Ed38;
	CMaskEdit m_Ed39;
	CMaskEdit m_Ed40;

	CButton m_Check1;

	virtual BOOL OnInitDialog();
	CMaskEdit m_Dat;

	SYSTEMTIME stRptDate;
	__int64 qwIDS;
	CEdit m_Vkm;
	CColoredButton m_bnSost;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton10();
	int StoreMsgToBase(void);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedPrint();

	int iDataFromBD;
public:
	afx_msg void OnBnClickedCheck2();
};
