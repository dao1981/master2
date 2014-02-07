#if !defined(AFX_PRINTERSELECTDLG_H__057789F1_E6DF_4559_ADE5_C6DB7DA6F54D__INCLUDED_)
#define AFX_PRINTERSELECTDLG_H__057789F1_E6DF_4559_ADE5_C6DB7DA6F54D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrinterSelectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrinterSelectDlg dialog

class CPrinterSelectDlg : public CDialog
{
// Construction
public:
	CPrinterSelectDlg(CWnd* pParent = NULL);   // standard constructor
    BOOL m_bPrintersPresent;
// Dialog Data
	//{{AFX_DATA(CPrinterSelectDlg)
	enum { IDD = IDD_DIALOG_PRINTER_SELECT };
	CComboBox	m_Cb;
	CString	m_PrinterName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrinterSelectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrinterSelectDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTERSELECTDLG_H__057789F1_E6DF_4559_ADE5_C6DB7DA6F54D__INCLUDED_)
