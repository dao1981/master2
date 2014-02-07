#pragma once
#include "afxcmn.h"
#include "DlgMsg4624_Header.h"
#include "DlgMsg4624_KP.h"
#include "DlgMsg4624_LDTL.h"
#include "DlgMsg4624_TLVAG.h"
#include "DlgMsg4624_ZamenaBlTl.h"
#include "DlgMsg4624_BlTl.h"
#include "DlgMsg4624_ZamenaKP.h"
#include "DlgMsg4624_ZamenaLDTL.h"
#include "maskedit.h"
#include "resource.h"
#include "DlgAccel1.h"
// CDlgMsg4624_Main dialog

class CDlgMsg4624_Main : public CDlgWithAccelerators
{
//	DECLARE_DYNAMIC(CDlgMsg4624_Main)	


public:
	CDlgMsg4624_Main(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_Main();

	int	p_iTabOrderIndex[20];
	int	iTabCount;

	char cVagNum32[32];
	char cNVagTl[32];
	__int64 qwIzapRashKP[9];
	SYSTEMTIME stRemDat;
	SYSTEMTIME stDat4624;
	__int64 qwILK;
	__int64 qwIDS;
	DWORD	dwVRem;  // этот вид ремонта настоящий
	DWORD	dwVRem7; 
	int		i8os;
	BOOL	bStarted;
	DWORD	dw_nPhrase;
	HICON	m_hIcon;
	CString m_pVRem[10];
	int		iInfoFromVagPasp;

	int		i2730Pushed;

	char    cKodSobst[4];	

	int iZmKP_Idx;
	int iZmLDTL_Idx;
	int iZmBl_Idx;
	int iBlIdx;
// Dialog Data
	enum { IDD = IDD_4624ALL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTabCtrl m_Tab;

	int		iZamena;

	CDlgMsg4624_Header *m_pDlg_Header;
	CDlgMsg4624_KP *m_pDlg_KP;
	CDlgMsg4624_LDTL *m_pDlg_LDTL;
	CDlgMsg4624_TLVAG *m_pDlgTLVag;
	CDlgMsg4624_BlTl *m_pDlgBlTl;

	CDlgMsg4624_ZamenaKP *m_pDlgZamenaKP;
	CDlgMsg4624_ZamenaBlTl *m_pDlgZamenaBlTl;
	CDlgMsg4624_ZamenaLDTL *m_pDlgZamenaLDTL;
	CWnd *CurWnd;
	CWnd *m_pWndTab[10];
//	afx_msg void OnClose();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CMaskEdit m_EdNLK;
	CMaskEdit m_EdNVag;
	CMaskEdit m_EdVRem;
	CEdit	  m_EdVRemName;
	CStatic	  m_MsgState;
	CButton	  m_bnZamena;
	CButton	  m_bnSend;
	CButton	  m_8OsCheck;
	CButton	  m_ButMsgText;
	CButton	  m_ZeroDataCheck;
	CButton	  m_But2730;
	CButton	  m_ButStore;
	CButton	  m_ButVU36;
	int		  iHidden;

	DWORD dwVkladka, dwErrX, dwErrY;

	CMaskEdit m_DatNeisp;
	CMaskEdit m_Hour1;
	CMaskEdit m_Min1;
	void InitComp(void);
	void FillForms(void);
protected:
	virtual void OnOK();
public:
	afx_msg void OnBnClickedOk();
	int WriteMsgLine(int idx);
	afx_msg void OnBnClickedButton1();
	void InsertZamenaTabs(void);
	void WriteMsgZamenaKP(int idx);
	void WriteMsgZamenaLDTL(int idx);
	void FillZamenaTabs(void);
	void WriteMsgZamenaBlTl(int idx);
	void SetEnabledItemsOfRemCode(DWORD VRem);
	CString GetRazmerScript ();
	afx_msg void OnBnClickedButton_NextTab();
	afx_msg void OnBnClickedButton_PrevTab();
	afx_msg void OnClose();
protected:
	virtual void OnCancel();
public:
//	afx_msg void OnArrowDown();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnDestroy();
	afx_msg void OnEnChangeEdit_VRem();
	void InitTabOrderIndex(void);
	void SetTabsByOrderIndex(void);
	int StoreMsgToBase(void);
	afx_msg void OnBnClicked_ZamenaCheck();
	afx_msg void OnBnClickedCheck_8Os();
	afx_msg void OnBnClickedButton_LvtText();
	void SetEnabledBy8Os(int i8Os);
	void SetErrorEdit(DWORD dwVkladka, DWORD dwErrX, DWORD dwErrY);
	int iPaspPPT;
	afx_msg void OnBnClickedVU36();
	void FillFrom2730(void);
	afx_msg void OnBnClickedButton6();
	void PerenosKPtoZamenKP(int iKpOrder);
	void PerenosKPtoZamenDTL(int iDTLOrder);
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedTEXT4624();
public:	
public:
	void SetIzNalButtons(void);
};
