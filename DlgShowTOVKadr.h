#pragma once
#include "fastgrid.h"
#include "dialogheader.h"

// CDlgShowTOVKadr dialog

class CDlgShowTOVKadr : public CDialog
{
	DECLARE_DYNAMIC(CDlgShowTOVKadr)

public:
	CDlgShowTOVKadr(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgShowTOVKadr();

// Dialog Data
	enum { IDD = IDD_TOV_EMPLOYEES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CFastGrid m_List;
	DWORD dwIFam_Ret;
	char cFIO[64];
	char cTabN[64];
	CDialogHeader m_HeaderCtrl;
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedOk();
};
