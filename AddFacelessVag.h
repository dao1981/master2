#pragma once
#include "maskedit.h"


// CAddFacelessVag dialog

class CAddFacelessVag : public CDialog
{
	DECLARE_DYNAMIC(CAddFacelessVag)

public:
	CAddFacelessVag(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAddFacelessVag();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdVag;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CString strNVag;
	DWORD dwBrigadir_ID;
	char cNTL1[32], cNTL2[32];
//	__int64 qwReplaceVagID;
	__int64	qwTlVagID;
	int		iVagPrih;
};
