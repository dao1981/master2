// master.h : main header file for the MASTER application
//

#if !defined(AFX_MASTER_H__F1EBDD01_1590_4796_A147_C0453F9D4C28__INCLUDED_)
#define AFX_MASTER_H__F1EBDD01_1590_4796_A147_C0453F9D4C28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include <sqltypes.h>
/////////////////////////////////////////////////////////////////////////////
// CMasterApp:
// See master.cpp for the implementation of this class
//
#define MAXBUFLEN   255

class CMasterApp : public CWinApp
{
private:
        //CSingleDocTemplate* m_pTemplate; //Doc for printing
public:
	CMasterApp();
	int DispatchPeresVedMsg(char *);
	int DispatchSetPeresVedStatus(char *);
	DWORD GetIPRByKL(char cKlPr[8]);
    int CheckAuth(const char *UserName, const char *Password);
    int ConnectDB();
    int DisconnectDB();
	void LoadMsgAnswerFromFile(void);
	int ProcessMsgAnswer(char * strAnswer);	
//    BOOL m_bPrintPreview;
//    void PrintPreview();

    HICON m_hIcon;
//    DWORD UpdateListByGlobalHandle(CListCtrl *);
    void SetListHeaderByGlobalHandle(CListCtrl *);
//    SQLHSTMT ExecSQL(char *cQuery);
    long DisplaySQLError(SQLHSTMT h_cst);
    BOOL LoadMasterIni();
    BOOL LoadSQLGlobalConfig();
    void WriteLog(char *, int Level = 0, int WriteDate = 1);
    void ReallocHandle();
    int CheckFirstStart();
	void Dos2Win(unsigned char * cLine, int len);
	void Win2Dos(char * cLine, int len);
    void SetPrintOrientation(int mode);	

	void SendTeleMessage(CString strMess, CString strPref = "");
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMasterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMasterApp)
	afx_msg void OnAppAbout();
	afx_msg void OnMenuitemAlterPass();
	afx_msg void OnMenuitemInpKP();
	afx_msg void OnMenuitem32786();
	afx_msg void OnMenuitem32793();
	afx_msg void OnMenuitem32789();
	afx_msg void OnMenuitem32787();
	afx_msg void OnMenuitem32785();
	afx_msg void OnMenuitem32794();
	afx_msg void OnMenuitem32795();
	afx_msg void OnMenuitem32788();
	afx_msg void OnMenuitem32775();
	afx_msg void OnMenuitem32778();
	afx_msg void OnMenuitem32772();
	afx_msg void OnMenuitem32796();
	afx_msg void OnMenuitem32779();
	afx_msg void OnMenuitem32780();
	afx_msg void OnVU53();
	afx_msg void OnMenuitem32782();
	afx_msg void OnVU93();
	afx_msg void OnMenuVU90();
	afx_msg void OnMenuitem32802();
	afx_msg void OnMenuitem32781();
	afx_msg void OnMenuitemMkPaspByNKP();
	afx_msg void OnSendVagClick();
	afx_msg void OnMenuitemAnalitSprav_NeispKP();
	afx_msg void OnMenuitemRazmGrp();
	afx_msg void OnMenuitemHistoryKp1();
	afx_msg void OnMenuitemVu36();
	afx_msg void OnMenuitemVU54();
	afx_msg void OnMenuitemSelectOs();
	afx_msg void OnMenuitemPodkatReport();
	afx_msg void OnMenuitem_ZapressLog();
	afx_msg void OnMenuitemPr_AllList();
	afx_msg void OnMenuitem_PrOsv();
	afx_msg void OnMenuitem_PrTl();
	afx_msg void OnMenu_PoluchenieKp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMenuSelectDepo();
	afx_msg void OnMenuBdTl();
	afx_msg void OnMenuRegTl();
	afx_msg void OnMenuBdTl1089();
	afx_msg void OnMenu_Podkat1069();
	afx_msg void OnMenu_Podkat1520();
	afx_msg void OnMnu_Msg4624();
	afx_msg void OnMnuEdPaspDepo();	
	afx_msg void On4624SendLog();
	afx_msg void OnMnuPprSendToRem();	
	virtual int ExitInstance();
	afx_msg void OnMnuNaltl();
	afx_msg void OnMnuPasptl();	
	afx_msg void OnMenuPodachaVag();
	afx_msg void OnMnuNaltl1520();
	afx_msg void OnMenuTrfrVans();
	afx_msg void OnMnuSprOpervag();
	afx_msg void OnVagonNaKolee1067();
	afx_msg void OnMnuAsoupErr();
	afx_msg void OnMnuPpt4624();
	afx_msg void OnMnuPptSpravPerest();
	afx_msg void OnArhOperVag();
	afx_msg void OnMnuVo2();
	afx_msg void OnMnu2955();
	afx_msg void OnMnuMsg2958();
	afx_msg void OnMnuMsg2956();
	afx_msg void OnMnuMsg2957();
	afx_msg void OnMnuRpt2955();
	afx_msg void OnMnuRemDefektBr();
	afx_msg void OnMnuRemDefektNb();
	afx_msg void OnMnuRemDefektSb();
	afx_msg void OnMnuRaspress();
	afx_msg void OnMnuRaspressLog();
	afx_msg void OnMnuQuery2730();
	afx_msg void OnMnu2956Svod();
	afx_msg void OnMnuSetupMess();
	afx_msg void OnMnuRpt2950();
	afx_msg void OnMnuRpt2956();
	afx_msg void OnMnuRptVo7();
	afx_msg void OnMnuObezlVag();
	afx_msg void OnMnuSetupCommon();
	void RotateLog(void);
	afx_msg void OnMnuSprPodkat();
	int CheckClientUpdate(void);
	afx_msg void OnMnuZhurnKomplekt();
	afx_msg void OnMnuDbBr();
	afx_msg void OnMnuDbNb();
	afx_msg void OnMenuObnovlenie();
	afx_msg void OnMnuRptPrihTl();
public:
	afx_msg void OnMnuPeresTlRcv();
public:
	afx_msg void OnMnuVu54Podr();
public:
	afx_msg void OnMenuPptBdVag();
public:
	afx_msg void OnMnuPptPerestVag1520();
public:
	afx_msg void OnMnuExport_PaspKP();
public:
	afx_msg void OnMnuSprSobstv();
public:
	afx_msg void OnMnuSpravZamDet();
	afx_msg void OnMnuSprPostKpXls();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MASTER_H__F1EBDD01_1590_4796_A147_C0453F9D4C28__INCLUDED_)
