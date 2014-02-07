#pragma once
#include "d:\develop\master2\controls\mylabel.h"
#include "maskedit.h"
#include "dlgaccel1.h"
#include "ColoredButton.h"

// CDlgMsg2958 dialog

class CDlgMsg2958 : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg2958)

public:
	CDlgMsg2958(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg2958();

// Dialog Data
	enum { IDD = IDD_MSG_2958 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	__int64 qwIDS;
	CColoredButton bnSost;
	int m_iShowKP;
	SYSTEMTIME stDat;
	CMyLabel m_Lab1;
	CMaskEdit m_Ed[18][9];
	CEdit m_Ed1[18][9];
	virtual BOOL OnInitDialog();
	CMaskEdit m_EdPr;
	CMaskEdit m_Dat;
	afx_msg void OnBnClickedOk();
	void FillForm(void);
	afx_msg void OnEnChangeEd10();
	afx_msg void OnBnClickedButton2();
	int StoreToBase(void);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton_Report();
	afx_msg void OnBnClickedCancel();
};
