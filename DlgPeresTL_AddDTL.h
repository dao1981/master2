#pragma once
#include "maskedit.h"


// CDlgPeresTL_AddDTL dialog

class CDlgPeresTL_AddDTL : public CDialog
{
	DECLARE_DYNAMIC(CDlgPeresTL_AddDTL)

public:
	CDlgPeresTL_AddDTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPeresTL_AddDTL();

	int DlgStarted;
	int iTypeDTL; //0 - Боковая Рама, 1 - Надрессорная балка
// Dialog Data
	enum { IDD = IDD_PERES_TL_ADD_DTL };

	 char	cDTlNum[20];
	 char	cYear[6];
	 DWORD	dwIPR;
	 char	cKlPr[16];
	 char	cPrName[40];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	CMaskEdit m_EdNDtl;
	CMaskEdit m_EdDat;
	CMaskEdit m_EdKlPr;
	CMaskEdit m_EdPrName;
	afx_msg void OnBnClickedButtonSelPr();
	afx_msg void OnEnChangeEditKLPR();
public:
	afx_msg void OnBnClickedOk();

};
