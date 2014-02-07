#if !defined(AFX_DLGADDPERES_H__F38A4B1B_871A_41E7_995D_EEDC6AF111F0__INCLUDED_)
#define AFX_DLGADDPERES_H__F38A4B1B_871A_41E7_995D_EEDC6AF111F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAddPeres.h : header file
//
#include "MaskEdit.h"
#include "FastGrid.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgAddPeres dialog
#include "DlgAccel1.h"

class CDlgAddPeres : public CDlgWithAccelerators
{
// Construction
public:
	void GetKpList();
	CDlgAddPeres(CWnd* pParent = NULL);   // standard constructor
    __int64 qwIKP[128];
    __int64 qwIZAP[128];
	SYSTEMTIME stDatIzg[128];
	DWORD		dwIPrIzg[128];
	char	cNKP[128][12];

	DWORD p_dwObod_KP1[128];
	DWORD p_dwObod_KP2[128];
	DWORD p_dwGreb_KP1[128];
	DWORD p_dwGreb_KP2[128];
	double p_dProkat_KP1[128];
	double p_dProkat_KP2[128];
	double p_dDiam_KP1[128];
	double p_dDiam_KP2[128];
	DWORD p_dwDisk_KP1[128];
	DWORD p_dwDisk_KP2[128];
	DWORD p_dwTypePodshASUV[128];
	DWORD p_dwMSteel[128];

    DWORD   dwPriznRas[128];
    DWORD   dwGruz[128];
    DWORD   dwKPCount;
	DWORD	p_dwTKP[128];
	DWORD	p_dwNewTKP[128];
	DWORD	p_dwNeispID[128];
	DWORD	p_dwRemoved[128];
    int     iMode;
    DWORD   dwVedNum;
    char    cVedDate[12];
    SYSTEMTIME stVedDate;
	DWORD	dwFIO_MastRcv;
    DWORD   dwFIO_Mast;
    DWORD   dwFIO_Priem;
    DWORD   dwIPR_Rcv;    // Получатель
    DWORD   dwIPR_Snd;    // Отправитель
    DWORD   dwIPR_Sobst;  // Собственник
    __int64 qwIPeres;
    DWORD   dwOldKPCount;
    int     iHeader;
    int     iOnVag;

    int     iRecieveMode;
	int		iCreateRecieveMode;
	int		iShowAddDelButtons;
    int     DlgStarted;

	CMenu	*m_Menu;
// Dialog Data
	//{{AFX_DATA(CDlgAddPeres)
	enum { IDD = IDD_DIALOG_ED_RP };
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
	CEdit	m_PrSnd;
	CEdit	m_PrSobst;
	CMaskEdit	m_Edit6;
	CMaskEdit	m_Edit5;
	CComboBox	m_Combo1;
	CEdit	m_CountCtrl;
	CFastGrid	m_List;
	CButton	m_Button3;
	CEdit	m_Edit4;
	CEdit	m_Edit3;
	CEdit	m_Edit2;
	CMaskEdit	m_Edit1;
	UINT	m_uiCount;
	UINT	m_Edit1Num;
	int		m_iPrRem;
	CString	m_cVagNum;
	CString	m_Edit4Text;
	CButton	m_ButIzNal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAddPeres)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAddPeres)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnChangeEdit4();
	afx_msg void OnButton2();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnAddVed();
	virtual void OnCancel();
	afx_msg void OnButton_MasterRcv();
	afx_msg void OnButton_GetSobst();
	afx_msg void OnCheck_SelectAll();
	afx_msg void OnButton_PrSender();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMnuPsp();
	virtual BOOL DestroyWindow();
public:
	afx_msg void OnEnChangeEditPrOtpr();
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnBnClickedButton_SelFromNal();
public:
	afx_msg void OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnEnChangeEdit118();
public:
	afx_msg void OnBnClickedButton_ClearSobst();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDPERES_H__F38A4B1B_871A_41E7_995D_EEDC6AF111F0__INCLUDED_)
