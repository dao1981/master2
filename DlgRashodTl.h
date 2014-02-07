#pragma once
#include ".\controls\MyLabel.h"
#include "afxwin.h"
#include "maskedit.h"
#include "dlgaccel1.h"

// CDlgRashodTl dialog

class CDlgRashodTl : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgRashodTl)

public:
	CDlgRashodTl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgRashodTl();

// Dialog Data
	enum { IDD = IDD_RASHOD_TL };

	CMyLabel m_Lab1;
	CMyLabel m_Lab2;
	CMyLabel m_Lab3;
	CMyLabel m_Lab4;
	CMyLabel m_Lab5;
	CMyLabel m_Lab6;
	CMyLabel m_Lab7;
	CMyLabel m_Lab8;
	CMyLabel m_Lab9;
	CMyLabel m_Lab10;
	CMyLabel m_Lab11;
	CMyLabel m_Lab12;
	CMyLabel m_Lab13;
	CMyLabel m_Lab14;
	CMyLabel m_Lab15;
	CMyLabel m_Lab16;
	CMyLabel m_Lab17;
	CStatic m_Lab18;
	CStatic m_Lab19;
	CStatic m_Lab20;
	CMyLabel m_Lab21;

	CStatic m_Lab22;
	CStatic m_Lab23;
	CStatic m_Lab24;
	CStatic m_Lab25;

	int iNeedBalka;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
protected:
	virtual void OnCancel();
	virtual void OnOK();
public:
	void SetBalkaState(int Visible);
	virtual BOOL OnInitDialog();
/*	CStatic m_n1;
	CStatic m_n2;
	CStatic m_n3;
	CStatic m_n4;*/
	CStatic m_bevel1;
//	CStatic m_bevel2;
	CMaskEdit m_Edb1;
	CMaskEdit m_Edb2;
	CMaskEdit m_Edb3;
	CMaskEdit m_Edb4;

	CMaskEdit m_EdBR1[16];
	CMaskEdit m_EdBR2[16];
	CMaskEdit m_EdNB1[9];
	CMaskEdit m_EdNB2[9];
	CMaskEdit m_EdTV1[14];
	CMaskEdit m_EdTV2[14];

	void OnMyEnter();
	int FillTLDataByNum(CString strNumTL, int iPos);

/*	CMaskEdit m_EdBR1;
	CMaskEdit m_EdBR2;
	CMaskEdit m_EdBR3;
	CMaskEdit m_EdBR4;
	CMaskEdit m_EdBR5;
	CMaskEdit m_EdBR6;
	CMaskEdit m_EdBR7;
	CMaskEdit m_EdBR8;
	CMaskEdit m_EdBR9;
	CMaskEdit m_EdBR10;
	CMaskEdit m_EdBR11;
	CMaskEdit m_EdBR12;
	CMaskEdit m_EdBR13;
	CMaskEdit m_EdBR14;
	CMaskEdit m_EdBR15;
	CMaskEdit m_EdBR16;
	CMaskEdit m_EdNB1;
	CMaskEdit m_EdNB2;
	CMaskEdit m_EdNB3;
	CMaskEdit m_EdNB4;
	CMaskEdit m_EdNB5;
	CMaskEdit m_EdNB6;
	CMaskEdit m_EdNB7;
	CMaskEdit m_EdNB8;
	CMaskEdit m_EdNB9;
	CMaskEdit m_EdTV1;
	CMaskEdit m_EdTV2;
	CMaskEdit m_EdTV3;
	CMaskEdit m_EdTV4;
	CMaskEdit m_EdTV5;
	CMaskEdit m_EdTV6;
	CMaskEdit m_EdTV7;

	CMaskEdit m_EdTV8;
	CMaskEdit m_EdTV9;
	CMaskEdit m_EdTV10;
	CMaskEdit m_EdTV11;
	CMaskEdit m_EdTV12;
	CMaskEdit m_EdTV13;
	CMaskEdit m_EdTV14;*/
	afx_msg void OnStnClickedLab21();
	CMaskEdit m_EdNum1;
	CMaskEdit m_EdNum2;
//	afx_msg void OnEnKillfocusEd1();
//	afx_msg void OnEnSetfocusEd1();
	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};
