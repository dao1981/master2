#pragma once
#include "fastgrid.h"
#include "afxwin.h"


// CDlgBDSelectRezDTL dialog

class CDlgBDSelectRezDTL : public CDialog
{
	DECLARE_DYNAMIC(CDlgBDSelectRezDTL)

public:
	CDlgBDSelectRezDTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgBDSelectRezDTL();

// Dialog Data
	enum { IDD = IDD_SELECT_REZ_DTL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CFastGrid m_List;
	bool bGotHeader;
	char	cQ[1024];
	CFont	*Font;
	void RefreshList(void);
	CStatic m_lbRecCount;	
	afx_msg void OnBnClickedButton_Delete();
	int iDetailID; //0-боковая рама, 1-надрессорная балка, 2-соединит.балка
};
