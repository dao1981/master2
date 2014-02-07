#pragma once

#include "maskedit.h"
#include "afxwin.h"
#include "DlgAccel1.h"
#include "stdafx.h"
#include "resource.h"
#include "afxcmn.h"
// CDlgMsg4624_Header dialog

class CDlgMsg4624_Header : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg4624_Header)
	char cVagNum32[32];
	SYSTEMTIME stDateRem;
	SYSTEMTIME stDate4624;
public:
	CDlgMsg4624_Header(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_Header();
//	CString m_pVRem[10];
	CWnd *m_pMainTabWnd;
//	CDlgMsg4624_Main *m_pWnd2;
// Dialog Data
	enum { IDD = IDD_4624_HEADER };	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	virtual BOOL OnInitDialog();
	CMaskEdit m_EdRemPR;
	CMaskEdit m_EdKPZ;
	CMaskEdit m_EdVidKorr;
//	CMaskEdit m_EdVRem;
//	CMaskEdit m_DatNeisp;
	CMaskEdit m_EdPTO;
	CMaskEdit m_EdReply;
	CMaskEdit m_DatRem;
	void InitDlgItems(void);
	afx_msg void OnBnClickedButton_OperFIO();
	CMaskEdit m_EdOperFIO;
	CMaskEdit m_EdKodSobst;

//	CMaskEdit m_Dat4624;
//	CMaskEdit m_Hour1;
	CMaskEdit m_Hour2;
//	CMaskEdit m_Min1;
	CMaskEdit m_Min2;
	afx_msg void OnEnChangeEdit_VRem();
//	CEdit m_EdVRemName;
	afx_msg void OnBnClickedButton5();
};
