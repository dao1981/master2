#pragma once
#include "maskedit.h"
#include "afxwin.h"
#include "fastgrid.h"
#include "dlgaccel1.h"

// CDlgProkatTL1069 dialog

class CDlgProkatTL1069 : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgProkatTL1069)

public:
	int	iGotHeader;
	char cQ[512];
	CDlgProkatTL1069(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgProkatTL1069();

// Dialog Data
	enum { IDD = IDD_PODKAT_TL1069 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClicked_Select();
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	CEdit m_EdVagNum;
	void RefreshList(void);
	CFastGrid m_List;
	afx_msg void OnBnClickedButton_PPTVans();
	CEdit m_EdESR;
	CEdit m_EdPark;
	CEdit m_EdWay;
	CButton m_Check1;
	CButton m_Check2;
	afx_msg void OnBnClickedButton_AddVag();
	afx_msg void OnBnClickedButton_EditVag();
	CMaskEdit m_Dat;
	CMaskEdit m_EdFIO;
	afx_msg void OnBnClickedButton_FIO();
	CStatic m_LabelCount;
	afx_msg void OnBnClickedButton4();
};
