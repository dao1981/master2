#pragma once
#include "MaskEdit.h"
#include "FastGrid.h"

// CDlgPeresTlAddPeres dialog

struct CDetailTL
{
	int	 iGridIndex;
	__int64 qwIZapDTL;
	int iTypeDTL;
	char cNum[12];
	char cYear[6];
	char cKlPr[16];
	char cPrName[60];
	DWORD dwIRP;
	CDetailTL() { ZeroMemory(this,sizeof(CDetailTL)); }
};

struct 	CDTlDel
{
	__int64 qwIZapDTL;
	int iTypeDTL;
};


class CDlgPeresTlAddPeres : public CDialog
{
	DECLARE_DYNAMIC(CDlgPeresTlAddPeres)

public:

	__int64 qwIPERES;
	int iModeRecieve;
//	int iNewVed; //1 - создаем новую ведомость 

	int WriteData();
	void RefreshList();
	CDlgPeresTlAddPeres(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPeresTlAddPeres();

	CDetailTL pBR[50];
	CDetailTL pNB[50];
	int iBRCount;
	int iNBCount;

	CDTlDel pDelDTl[100];
	int iDelCount;

	DWORD dwIPR_Rcv;
	int DlgStarted;
	DWORD dwFIO_Mast;
	DWORD dwFIO_Priem;
	DWORD dwIPR_Snd;
	DWORD dwIPR_Sobst;

	CButton	m_But2;
	CButton	m_ButMaterRcv;
	CButton	m_ButSobst;
	CButton	m_ButRcv;
	CButton m_ButMastLow;
	CButton m_ButPriemLow;
	CButton m_ButAddKP;
	CMaskEdit	m_Date1;
	CButton	m_CheckAll;
	CMaskEdit	m_EdMasterRcv;
	CMaskEdit	m_DatRcv;
	CEdit	m_EdPrSobst;
	CEdit	m_EdPrSnd;
	CMaskEdit	m_PrSnd;
	CMaskEdit	m_PrSobst;
	CMaskEdit	m_Edit6;
	CMaskEdit	m_EdFamSnd;
	CComboBox	m_Combo1;
	CEdit	m_CountCtrl;
	CFastGrid	m_List;
	CButton	m_Button3;
	CMaskEdit	m_Edit4;
	CMaskEdit	m_EdKlPrRcv;
	CMaskEdit	m_EdNVag;
	CMaskEdit	m_Edit1;
	UINT	m_uiCount;
	UINT	m_Edit1Num;
	int		m_iPrRem;
	CString	m_cVagNum;
	CString	m_Edit4Text;
// Dialog Data
	enum { IDD = IDD_PERES_TL_ADD_PERES };

	afx_msg void OnButton1();
	afx_msg void OnChangeEdit4();
	afx_msg void OnButton2();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
//	afx_msg void OnAddVed();
//	virtual void OnCancel();
	afx_msg void OnButton_MasterRcv();
	afx_msg void OnButton_GetSobst();
	afx_msg void OnCheck_SelectAll();
	afx_msg void OnButton_PrSender();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAddNB();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEditPrSender();
	afx_msg void OnBnClickedButton3();
};
