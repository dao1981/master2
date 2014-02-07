#if !defined(AFX_DLGOLDKPLIST_H__2696D117_5C3A_44AB_A29B_9083FE60D128__INCLUDED_)
#define AFX_DLGOLDKPLIST_H__2696D117_5C3A_44AB_A29B_9083FE60D128__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOldKPList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgOldKPList dialog

class CDlgOldKPList : public CDialog
{
// Construction
public:
	__int64 qwILK;
	CDlgOldKPList(CWnd* pParent = NULL);   // standard constructor
	__int64 p_qwIKP[16];
	int		iIKPCount;

	__int64 p_qwInitIZAP[16];
    __int64 p_qwIZAP[16];
    __int64 p_qwRetIZAP[16];
    DWORD   p_dwPriznRas[16];
    DWORD   p_dwGruz[16];
	int		iInitCount;

    int     iMode;
// Dialog Data
	//{{AFX_DATA(CDlgOldKPList)
	enum { IDD = IDD_DIALOG_VAG_PREV_PRIH };
	CFastGrid	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOldKPList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgOldKPList)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOLDKPLIST_H__2696D117_5C3A_44AB_A29B_9083FE60D128__INCLUDED_)
