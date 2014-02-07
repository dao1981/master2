#pragma once
#include "fastgrid.h"
#include "maskedit.h"
#include "afxwin.h"
#include "NewMenu.h"

// CDlgMsg4624Log dialog

class CDlgMsg4624Log : public CDialog
{
	DECLARE_DYNAMIC(CDlgMsg4624Log)

public:
	CDlgMsg4624Log(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624Log();
	
	char cDat1[12];
	COLORREF p_crColors[16];
// Dialog Data
	enum { IDD = IDD_4624_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CFastGrid m_List;
	afx_msg void OnBnClicked_Select();
	void RefreshList(void);
	CMaskEdit m_Dat1;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonEdit();
	CStatic m_Count1;
	CStatic m_Count2;
	int iMain;
	/*
	VOID CALLBACK TimerRefresh( 
    HWND hwnd,        // handle to window for timer messages 
    UINT message,     // WM_TIMER message 
    UINT idTimer,     // timer identifier 
    DWORD dwTime);*/
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonDelBD();
	afx_msg void OnBnClickedButtonNew4624();
	afx_msg void OnBnClickedButtonVU36();
	afx_msg void OnBnClickedButton497();
	CButton m_CheckSokr;
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemchangingList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemActivateList2(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CButton m_ButDelASOUP;
	CButton m_ButDelBD;
	CButton m_ButVU36;
	CButton m_But497;
	void SetButtonsState(void);
	CButton m_ButEdit;
	afx_msg void OnBnClickedButtonText4624();
	afx_msg void OnMenu4624Zapr2730();
	afx_msg void OnMenu4624_2955();
	afx_msg void OnM46242957();
	afx_msg void OnMenu4624_2956();
	afx_msg void OnMenu4624_2958();
	afx_msg void OnM4624_ZhurnalKompl();
	afx_msg void OnM4624PaspDepo();
	afx_msg void OnN4624Kadr();
	afx_msg void OnM4624KodAsoup();
	afx_msg void OnM4624VagVRem();
	CString strWindowName;
	afx_msg void OnM4624NeispVag();
public:
	afx_msg void OnMnu4624ZamDet();
};
