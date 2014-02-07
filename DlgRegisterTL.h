#pragma once
#include "afxwin.h"
#include "maskedit.h"
#include "DlgAccel1.h"

// CDlgRegisterTL dialog

class CDlgRegisterTL : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgRegisterTL)

public:
	CDlgRegisterTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgRegisterTL();
	__int64	qwTL_ID;
	DWORD   dwDefIPR;
	char	cDefKLPR[32];
	char	cDefPrName[64];

	DWORD	dwSender_IPR;
	DWORD	dwRamaIzg1_IPR;
	DWORD	dwRamaIzg2_IPR;
	DWORD	dwBalka_IPR;
	DWORD	dwKP1_IPR;
	DWORD	dwKP2_IPR;
	DWORD	dwMesto_IPR;
	__int64	qwITNB;
	__int64	qwITBR;
	__int64 qwITL;

	char	cTlNum[32];
	int		iMode;
	
	int		iSomeAdded;
// Dialog Data
	enum { IDD = IDD_REG_TL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_Cb_LR_1;
	CComboBox m_Cb_LR_2;
	CComboBox m_Cb_LR_3;
	CComboBox m_Cb_LR_4;
	void InitForm(void);
	CComboBox m_Cb_TKP1;
	CComboBox m_Cb_TKP2;
	CMaskEdit m_DatPrih;
	afx_msg void OnBnClickedBut_SelectSender();
	CEdit m_EdSenderKl;
	CEdit m_EdSenderName;
	CMaskEdit m_EdFioMast;
	afx_msg void OnBnClickedBut_SelectMaster();
	afx_msg void OnCbnSelchangeCb_LR1();
	afx_msg void OnCbnSelchangeCb_LR2();
	afx_msg void OnCbnSelchangeCb_LR3();
	afx_msg void OnCbnSelchangeCb_LR4();
	afx_msg void OnBnClickedBut_SelectIzgRama1();
	CEdit m_EdRamaIzgKl;
	CEdit m_EdRamaIzgName;
	afx_msg void OnBnClickedBut_SelectIzgRama2();
	CEdit m_EdRamaIzg2Kl;
	CEdit m_EdRamaIzg2Name;
	afx_msg void OnBnClickedBut_SelectBalkaPr();
	CEdit m_EdBalkaIzgKl;
	CEdit m_EdBalkaIzgName;
	afx_msg void OnBnClickedBut_SelectIzgKp1();
	CEdit m_EdKP1IzgKl;
	CEdit m_EdKP1IzgName;
	CEdit m_EdKP2IzgKl;
	CEdit m_EdKP2IzgName;
	afx_msg void OnBnClickedBut_SelectIzgKP2();
	afx_msg void OnBnClickedBu_SelectMesto();
	CEdit m_EdMestoKl;
	CEdit m_EdMestoName;
	CMaskEdit m_DatKP1;
	CMaskEdit m_DatKP2;
	afx_msg void OnBnClickedOk();
	CEdit m_EdNTL;
	CEdit m_EdProbeg;
	CEdit m_EdNBR1;
	CEdit m_EdNBR2;
	CEdit m_EdYear1;
	CEdit m_EdYear2;
	CEdit m_EdNNB;
	CEdit m_EdYear3;
	CEdit m_EdNKP1;
	CEdit m_EdNKP2;
	CMaskEdit m_DatKompl;
	void ResetForm(void);
	afx_msg void OnBnClickedButton_AddToBase();
	int WriteData(char *cNewNTL = NULL, __int64 *qw_NewITL = 0 , __int64 *qw_NewITBR = 0, __int64 *qwNewITNB = 0);
};
