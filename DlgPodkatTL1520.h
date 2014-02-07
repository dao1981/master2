#pragma once
#include "fastgrid.h"
#include "afxwin.h"
#include "maskedit.h"


// CDlgPodkatTL1520 dialog

struct VAG_LIST1520
{
	__int64 qwVagID;
	char	cNVag32[32];
	char	cPos1[32];
	char	cPos2[32];
	char	cDatPodk16[16];
	char	cNTL1[32];
	char	cNTL2[32];
	char	cFIO64[64];
	char	cTlVag[32];
	__int64	qwTlVagID;
	int		iPrihVag;
	char	cFIO64_Sles[64];
	DWORD	iFam_Sles;
	VAG_LIST1520()
	{
		ZeroMemory(this, sizeof(VAG_LIST1520));
	}
};

class CDlgPodkatTL1520 : public CDialog
{
	DECLARE_DYNAMIC(CDlgPodkatTL1520)

public:
	CDlgPodkatTL1520(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPodkatTL1520();
	int	iGotHeader;
	VAG_LIST1520 pVagList[128];
	
//	__int64 p_qwIZapExchVag[128];	
//	int iExchVagCount;


	int	iVagCount;
// Dialog Data
	enum { IDD = IDD_PODKAT_TL1520 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked_AddVag();
	CFastGrid m_List;
	CEdit m_EdNVag;
	CMaskEdit m_EdESR;
	CMaskEdit m_EdPark;
	CMaskEdit m_EdWay;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClicked_OK();
	afx_msg void OnBnClickedButton_DeleteVan();
	afx_msg void OnBnClickedCancel_Naryad();
	afx_msg void OnBnClickedButton_VagOnPPT();
	afx_msg void OnBnClickedButton_FIO();
	CMaskEdit m_EdFIO;
	CMaskEdit m_Dat;
	void RefreshList(void);
protected:
	virtual void OnCancel();
public:
	afx_msg void OnEnChangeEdit3();
public:
	afx_msg void OnBnClickedButton_Slesar();
public:
	CMaskEdit m_EdFIO2;
};
