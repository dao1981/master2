#pragma once
#include "afxcmn.h"
#include "DlgRashodTl.h"
#include "afxwin.h"
#include "maskedit.h"
#include "dlgaccel1.h"

// CDlgRashodTl_Main dialog

class CDlgRashodTl_Main : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgRashodTl_Main)

public:
	CDlgRashodTl_Main(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgRashodTl_Main();

// Dialog Data
	enum { IDD = IDD_RASHOD_TL_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	__int64 qwILK;
	__int64 qwIDS;
	int i8Os;

	int iLoaded;

	int SaveData();

	virtual BOOL OnInitDialog();
	CTabCtrl m_Tab;
	CDlgRashodTl m_RashodTab[2];
/*	CDlgRashodTl m_RashodTab2;
	CDlgRashodTl m_RashodTab3;
	CDlgRashodTl m_RashodTab4;*/
	CWnd *CurWnd;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit71();
//	CComboBox m_Cb1;
	CMaskEdit m_EdNVag;
	CMaskEdit m_EdYrVag;
	CMaskEdit m_DatRem1;
/*	CMaskEdit m_EdHHRem1;
	CMaskEdit m_EdMMRem1;*/
	CMaskEdit m_DatRem2;
/*	CMaskEdit m_EdHHRem2;
	CMaskEdit m_EdMMRem2;*/
	CMaskEdit m_DatPodk;
	CMaskEdit m_EdFam;
	CMaskEdit m_EdVRem;

	CMaskEdit m_EdFam1;
	CMaskEdit m_EdFam2;
	CMaskEdit m_EdFam3;
	CMaskEdit m_EdFam4;
	CButton m_bnSendToAsld;
	DWORD dwVRem4624;
	void GetIPR( CMaskEdit *);

	SYSTEMTIME stDatPostRem;
	afx_msg void OnBnClickedFam();
	afx_msg void OnBnClickedButtonFillFrom4624();
	void FillForm(void);
	afx_msg void OnBnClickedOk();
	afx_msg void OnSendToASUV();
};
