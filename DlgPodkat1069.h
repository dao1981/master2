#pragma once
#include "maskedit.h"
#include "afxwin.h"
#include "DlgAccel1.h"

// CDlgPodkat1069 dialog

class CDlgPodkat1069 : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgPodkat1069)
public:
	int iTLReplaceMode;
	char cNTL1[32], cNTL2[32];
	int	iMode;
	__int64 qwPTVag_ID;
	SYSTEMTIME stDat;
	DWORD	dwBrigadir_ID;
	char cNVag[32];
	SYSTEMTIME stOldPktDate;
	CDlgPodkat1069(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPodkat1069();
	int	dwGot2730;
// Dialog Data
	enum { IDD = IDD_SEL_PODKAT_TL_1069 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdNVag;
	CMaskEdit m_EdDat;
	CMaskEdit m_EdFIO;
	CMaskEdit m_EdNTL1;
	CMaskEdit m_EdNTL2;
	CMaskEdit m_EdPos1;
	CMaskEdit m_EdPos2;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton_Brigadir();
	afx_msg void OnBnClickedOk();
	CButton m_Check2730;
	CButton m_Check2612;

	CButton m_ButTl1;
	CButton m_ButTl2;
protected:
	virtual void OnCancel();
};
