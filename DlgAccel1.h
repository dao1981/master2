#include "stdafx.h"
#if !defined(DLG_ACCEL_INCLUDED)
#define DLG_ACCEL_INCLUDED

#include "resource.h"
#include "NewMenu.h"

//////////////////
// Generic dialog-that-uses-accelerators.
//
class CDlgWithAccelerators : public CNewDialog {
	DECLARE_DYNAMIC(CDlgWithAccelerators);
public:
	CDlgWithAccelerators(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	CDlgWithAccelerators(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	~CDlgWithAccelerators();
//    enum { IDD = IDD_DLG11 };
protected:
	static HACCEL m_hAccel; // accelerator table

    // Add some enter override here
    afx_msg LRESULT OnGetDefID(WPARAM wp, LPARAM lp);
    void OnMyEnter();
    void OnArrowDown();
    void OnArrowUp();

	// MFC overrides
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
};

#endif
