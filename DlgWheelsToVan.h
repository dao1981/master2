#if !defined(AFX_DLGWHEELSTOVAN_H__682926F6_770A_4647_884D_200BD0D48BDC__INCLUDED_)
#define AFX_DLGWHEELSTOVAN_H__682926F6_770A_4647_884D_200BD0D48BDC__INCLUDED_

#include "MaskEdit.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgWheelsToVan.h : header file
//
#include "FastGrid.h"
#include "DlgAccel1.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgWheelsToVan dialog

class CDlgWheelsToVan : public CDlgWithAccelerators
{
// Construction
public:
	void RemoveFromRemoved(__int64 qwIZAP);
	int SelPrih(__int64 qwIKP, PASP_KP &, PRIH_KP &, int &iFo, int &iZp);
	int RefreshKPList();
	int IniKPList();
	CDlgWheelsToVan(CWnd* pParent = NULL);   // standard constructor
    __int64   qwLKID;

	int bFromPTO;

    DWORD   dwMaxKPCount;

    DWORD   dwTKP;
//    CString strNKP;
    __int64 p_qwIZAP;

    PRIH_KP p_ErasedPrih[16];
    PASP_KP p_ErasedPasp[16];
    DWORD   dwErasedCount;

    __int64 p_qwEditedIZAP[16];
    DWORD   dwEditedCount;

    BOOL    bListEnabled[16];

    PRIH_KP pPrih[16];
    PASP_KP pPasp[16];

	DWORD	dwNeedUpdate[16];

    int     p_iFo[16];
    int     p_iZp[16];

    bool    p_bGotPasp[16];
    char    cVagDate[16];
    char    cVagDatRem[16];
    DWORD   dwKPNum;
    DWORD   dwKPInitNum;
	DWORD	dwVRemVag_ID;

	CString m_DatRemInStr;
	CString m_DatRemOutStr;

    CMenu   *m_Menu;

    int iMode; // 0 - Приход, 1 - Расход

	__int64 qwILK;
// Dialog Data
	//{{AFX_DATA(CDlgWheelsToVan)
	enum { IDD = IDD_DIALOG_KP_TO_VAG };
	CEdit	m_Lbl;
	CButton	m_ButWas;
	CMaskEdit	m_DatRemOut;
	CMaskEdit	m_DatRemIn;
	CFastGrid	m_List;
	CButton	m_ButAddKP;
	CMaskEdit	m_Dat;
	CMaskEdit	m_EdFam;
	CEdit	m_NKP;
	CComboBox	m_cb;
	CString	m_nVag;
	CString	m_vRem;
	//}}AFX_DATA
	CMaskEdit m_EdVRem;
	CEdit m_EdNVag;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgWheelsToVan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgWheelsToVan)
	afx_msg void OnAddKP();
	virtual BOOL OnInitDialog();
	afx_msg void OnFamButClick();
	afx_msg void OnAddToBase();
	afx_msg void OnOldKPListClick();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuKpPasp();
	afx_msg void OnMenuKpRemove();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:	
	afx_msg void OnMenuRashodKp();
	afx_msg void OnMenuRazmerKp();
	afx_msg void OnMenuPrihodKp();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGWHEELSTOVAN_H__682926F6_770A_4647_884D_200BD0D48BDC__INCLUDED_)
