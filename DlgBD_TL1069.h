#pragma once
#include "afxwin.h"
#include "maskedit.h"
#include "DlgAccel1.h"

// CDlgBD_TL1069 dialog

class CDlgBD_TL1069 : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgBD_TL1069)

public:
	CDlgBD_TL1069(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgBD_TL1069();

// Dialog Data
	enum { IDD = IDD_BD_TL1069 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_Check1;
	CButton m_Check2;
	CButton m_Check3;
	CButton m_Check4;
	CButton m_Check5;
	CButton m_Check6;
	CButton m_Check7;
	CButton m_Check8;
	CButton m_Check9;
	CButton m_Check10;
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	CMaskEdit m_Dat3;
	CMaskEdit m_Dat4;
	CMaskEdit m_Dat5;
	CMaskEdit m_Dat6;
	CEdit m_EdVag1;
	CEdit m_EdVag2;
	CEdit m_EdInvNum;
	CEdit m_EdProbeg1;
	CEdit m_EdProbeg2;
	CEdit m_EdBokRamNum;
	CEdit m_EdNadrBalkNum;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck32();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedOk();
};
