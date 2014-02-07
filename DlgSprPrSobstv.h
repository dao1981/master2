#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgSprPrSobstv dialog

class CDlgSprPrSobstv : public CDialog
{
	DECLARE_DYNAMIC(CDlgSprPrSobstv)

public:
	CDlgSprPrSobstv(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSprPrSobstv();
	int iGotHeader;
	int iNeedOKButton;
	char cPrName[80];
	char cKlPr[64];
	char cOKPO[64];
	DWORD dwSobstID;

// Dialog Data
	enum { IDD = IDD_SPR_PRSOBST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_ButAdd;
	CButton m_ButEdit;
	CButton m_ButDel;
	virtual BOOL OnInitDialog();
	void RefreshList(void);
	CFastGrid m_List;
	afx_msg void OnBnClickedAddPr();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedOk2();
	CButton m_ButOK;
public:
	afx_msg void OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
