#if !defined(AFX_DLGVVODRP_H__3F5E8187_8115_4A10_8D41_903CF75D0998__INCLUDED_)
#define AFX_DLGVVODRP_H__3F5E8187_8115_4A10_8D41_903CF75D0998__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgVvodRP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgVvodRP dialog

class CDlgVvodRP : public CDialog
{
// Construction
public:
	CDlgVvodRP(CWnd* pParent = NULL);   // standard constructor
    DWORD dwIPRPodsh[512];
    DWORD dwIPType[512];
    void DisableCtrls();
    void EnableCtrls();
    void ButtonKN(int Num);
    void EditKNChng(int Num);

    void GetKadr(int Num);
    DWORD dwIPodsh;

    DWORD dwIFamOsm;
    DWORD dwIFamRem;
    DWORD dwIFamMas;
    DWORD dwIFamRol;
    DWORD dwIFamSep;
    DWORD dwIFamKol;
    DWORD dwIFamOsv;

    DWORD dwKN1;
    DWORD dwKN2;
    DWORD dwKN3;
    DWORD dwKN4;

    DWORD dwIPR;
    DWORD dwPType;

    char  cPNum[32];
    char  cDat[32];
    char  cVR[32];

    BOOL  Init;
    __int64 qwIZAP;
// Dialog Data
	//{{AFX_DATA(CDlgVvodRP)
	enum { IDD = IDD_DIALOG_VVOD_RP };
	CButton	m_ButtonReady;
	CButton	m_ButtonOK;
	CButton	m_ButtonFIO7;
	CButton	m_ButtonFIO6;
	CButton	m_ButtonFIO5;
	CButton	m_ButtonFIO4;
	CButton	m_ButtonFIO3;
	CButton	m_ButtonFIO2;
	CButton	m_ButtonFIO1;
	CButton	m_ButtonNK4;
	CButton	m_ButtonNK3;
	CButton	m_ButtonNK2;
	CButton	m_ButtonNK1;
	CComboBox	m_Combo3;
	CEdit	m_EditFIO7;
	CEdit	m_EditFIO6;
	CEdit	m_EditFIO5;
	CEdit	m_EditFIO4;
	CEdit	m_EditFIO3;
	CEdit	m_EditFIO2;
	CEdit	m_EditFIO1;
	CEdit	m_EditNN4;
	CEdit	m_EditNN3;
	CEdit	m_EditNN2;
	CEdit	m_EditNN1;
	CEdit	m_EditKN4;
	CEdit	m_EditKN3;
	CEdit	m_EditKN2;
	CEdit	m_EditKN1;
	CDateTimeCtrl	m_Date3;
	CDateTimeCtrl	m_Date2;
	CDateTimeCtrl	m_Date1;
	CEdit	m_sdatCtr;
	CEdit	m_Edit1;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgVvodRP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgVvodRP)
	virtual BOOL OnInitDialog();
	afx_msg void OnReady();
	afx_msg void OnButtonNK1();
	afx_msg void OnButton6();
	afx_msg void OnButton4();
	afx_msg void OnButton9();
	afx_msg void OnChangeEditKN1();
	afx_msg void OnChangeEditKN2();
	afx_msg void OnChangeEditKN3();
	afx_msg void OnChangeEditKN4();
	afx_msg void OnButtonFIO1();
	afx_msg void OnButtonFIO2();
	afx_msg void OnButtonFIO3();
	afx_msg void OnButtonFIO4();
	afx_msg void OnButtonFIO5();
	afx_msg void OnButtonFIO6();
	afx_msg void OnButtonFIO7();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGVVODRP_H__3F5E8187_8115_4A10_8D41_903CF75D0998__INCLUDED_)
