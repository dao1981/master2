#pragma once
#include "maskedit.h"


struct CDoroga
{
	char cCode[5];
	char cName[64];
};

// CDlgSprPrSobstvAdd dialog

class CDlgSprPrSobstvAdd : public CDialog
{
	DECLARE_DYNAMIC(CDlgSprPrSobstvAdd)

public:
	CDoroga pDorSpr[100];
	int iDorCount;

	CDlgSprPrSobstvAdd(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSprPrSobstvAdd();
	int iMode; //0 - добавляем, 1 - редактируем
	DWORD dwPrID;
	DWORD dwIPR_ForOsv;
// Dialog Data
	enum { IDD = IDD_SPR_SOBSTV_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdName;
public:
	CMaskEdit m_EdSName;
public:
	CMaskEdit m_EdKodDor;
public:
	CMaskEdit m_EdDorName;
public:
	CMaskEdit m_EdOKPO;
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedButton_SelDor();
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnEnChangeEditKodDor();
public:
	afx_msg void OnBnClickedButton_SelCl();
public:
	CMaskEdit m_EdKlPr;
public:
	CMaskEdit m_EdLocCode;
public:
	afx_msg void OnBnClickedButton_LocCode();
public:
	afx_msg void OnBnClickedButton_OKPO();
public:
	afx_msg void OnEnKillfocusEdit5();
public:
	afx_msg void OnBnClickedCancel();
};
