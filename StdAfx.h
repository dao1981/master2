// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__CD56AE6E_0676_4F15_AEE1_D1AD8CC5C15B__INCLUDED_)
#define AFX_STDAFX_H__CD56AE6E_0676_4F15_AEE1_D1AD8CC5C15B__INCLUDED_

#define WINVER 0x0501

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <sqlext.h>
#include "DBWire.h"
//#include "..\configure\config.h"
//#include <afxdhtml.h>

struct PRIH_KP
{
    __int64 qwIZAP;
	__int64 qwIKP;
	char	cNKP[32];
	DWORD	dwTKP;
	char	cTKP[32];
    WORD    wITR;
    DWORD   dwTREB_REM;
    WORD    wGruz; // 0 - пассажирск. 1 - груз. 2 - симв. "г" на ободе, 5 -
    WORD    wTd_l, wTd_r,wOb_l,wOb_r,wGr_l,wGr_r,wPod_l,wPod_r,wSred_l,wSred_r;
    double  dPrihDkk_l, dPrihDkk_r, dRashDkk_l, dRashDkk_r;
    char    cPosForPr_KL[32], cPosOsvPr_KL[32], cPeresPr_KL[32], cPeresPr_NAME[64], cIzgPr_KL[32];
//    char    cDatPost[32];
    double  dPr_l, dPr_r;
    DWORD   dwPriznRas;
    DWORD   dwFam, dwRemVagID, dwFamRash;
    char    cFam[32], cFamRash[32];
    char    cNeisp_KL[32], cNeisp_NAME[32];
	DWORD	dwNeisp_ID;
    DWORD   dwNVedPeres;
    DWORD   dwPeresIPR;
	DWORD	dwPosForPr_ID, dwPosOsvPr_ID, dwIzgPr_ID;
    char    cPrihNVag[32];
//    DWORD   dwKneisp;
    SYSTEMTIME stDatIzg; // Изготовление оси
    SYSTEMTIME stDatFor; // Последнее формирование
    SYSTEMTIME stDatOsv; // Последнее освидетельствование
    SYSTEMTIME stDatPost; // Поступления
    SYSTEMTIME dt5; // Ремонт
    SYSTEMTIME dt6; // Монтаж букс
    SYSTEMTIME stDatRash;
	SYSTEMTIME stPeresDat;
	int iSteelType;
	int iParkNum;

	DWORD dwSobstIPRPrih;
	DWORD dwSobstIPRRash;

    PRIH_KP()
    {
		ZeroMemory(this, sizeof(PRIH_KP));
    }
};

struct PASP_KP
{
    char    cTKP[32];
    char    cKLPR[32];
    DWORD   dwTKP;
    __int64 qwIKP;
    char    cNKP[32];
//    char    cIZOS_DAT[32];    
//    char    cPOSFOR_DAT[32];
//    char    cPOSOSV_DAT[32];
    SYSTEMTIME stIZOS_DAT;
    SYSTEMTIME stPOSFOR_DAT;
    SYSTEMTIME stPOSOSV_DAT;
    char    cIzOsPr_KL[32];
    char    cPosForPr_KL[32];
    char    cPosOsvPr_KL[32];
    char    cPL_OS[32];
    char    cRedName[32];
    DWORD   dwRedTypeID;

    DWORD   dwIzOsPr_ID;
	DWORD	dwPosForPr_ID;
	DWORD	dwPosOsvPr_ID;
	WORD	wGruz;
    PASP_KP()
    {
        memset(this, 0, sizeof(PASP_KP));
    }
};

struct PRIHOD_PARAMS
{
    char    cDatPrih1[16];
    char    cDatPrih2[16];
    char    cDatRem1[16];
    char    cDatRem2[16];    
    char    cDatRash1[16];
    char    cDatRash2[16];

    char    cNoRash_8[8];
    char    cNotIsp_8[8];

    char    cTKP_8[8];
    char    cMaskNKP_32[32];
    char    cTypeRemID_8[8];
    char    cVagNumIn[48];      // Подкачены под
    char    cVagNumOut[48];     // Выкачены из-под
    char    cIPRRecieved_8[8];  // Присланы от
    char    cDv_8[8];           // Только двойники
    char    cIzgOsIPr_16[16];

    char    cDatIzgOs1[16];
    char    cDatIzgOs2[16];

    char    cDatPosFor1[16];
    char    cDatPosFor2[16];

    char    cDKK1_16[16];
    char    cDKK2_16[16];

    char    cNeispID_8[8];
    char    cPriznObt_8[8];

	DWORD	dwVagRemPrih;
	DWORD	dwVagRemRash;

	int		iSpis;

    PRIHOD_PARAMS()
    {
        ZeroMemory(this, sizeof(PRIHOD_PARAMS));
        strcpy(cDatPrih1, "NULL");
        strcpy(cDatPrih2, "NULL");
        strcpy(cDatRem1, "NULL");
        strcpy(cDatRem2, "NULL");
        strcpy(cDatRash1, "NULL");
        strcpy(cDatRash2, "NULL");
        strcpy(cNoRash_8, "NULL");
        strcpy(cNotIsp_8, "NULL");

        strcpy(cTKP_8, "NULL");
        strcpy(cMaskNKP_32, "NULL");
        strcpy(cTypeRemID_8, "NULL");
        strcpy(cVagNumIn, "NULL");
        strcpy(cVagNumOut, "NULL");
        strcpy(cIPRRecieved_8, "NULL");
        strcpy(cDv_8, "NULL");
        strcpy(cIzgOsIPr_16, "NULL");
        strcpy(cDatIzgOs1, "NULL");
        strcpy(cDatIzgOs2, "NULL");
        strcpy(cDatPosFor1, "NULL");
        strcpy(cDatPosFor2, "NULL");
        strcpy(cDKK1_16, "NULL");
        strcpy(cDKK2_16, "NULL");
        strcpy(cNeispID_8, "NULL");
        strcpy(cPriznObt_8, "NULL");
    }
};

struct PRIHOD_TL
{
	__int64		qwTl_ID; 

	int			dwRightGoesFirst;

	char		cRL_Num32[32]; // Номер левой боковой рамы
	DWORD		dwRL_IPR; //ИД предприятия изготовителя левой боковой рамы
	DWORD		dwRL_Year; // Год изготовления левой боковой рамы
	DWORD		dwRL_Defect; // Дефект левой боковой рамы
	DWORD		dwRL_VRem; // Вид ремонта левой боковой рамы

	char		cRR_Num32[32]; // Номер правой боковой рамы
	DWORD		dwRR_IPR; //ИД предприятия изготовителя правой боковой рамы
	DWORD		dwRR_Year; // Год изготовления правой боковой рамы
	DWORD		dwRR_Defect; // Дефект правой боковой рамы
	DWORD		dwRR_VRem; // Вид ремонта правой боковой рамы

	char		cB_Num32[32]; //Номер надрессорной балки
	DWORD		dwB_IPR; // Год изготовления надрессорной балки
	DWORD		dwB_Year; // Год изготовления надрессорной балки
	DWORD		dwB_Defect; // Дефект надрессорной балки
	DWORD		dwB_VRem; // Вид ремонта надрессорной балки

	DWORD		dwPosition1;
	DWORD		dwPosition2;

	char		cUslNum32[32];
	PRIHOD_TL()
	{
		ZeroMemory(this, sizeof(PRIHOD_TL));
	}
};

struct KP_ID
{
	char cNKP[32];
	char cKlPr[32];
	SYSTEMTIME stDatIzg;
	KP_ID()
	{
		ZeroMemory(this, sizeof(KP_ID));
	}
};

void SqlDateToSysTime(SQL_DATE_STRUCT, SYSTEMTIME *);
void DateToStrRus(SYSTEMTIME, char *);
void DateToStr(SYSTEMTIME, char *);
int  SysDateCmp(SYSTEMTIME, SYSTEMTIME); // rez = st1 - st2
CString DateToSQL(SYSTEMTIME st);
void DateToSql(SYSTEMTIME st, char *ct);
long mgSQLGetSysDate(int iCol, SYSTEMTIME *tm, long *);
SYSTEMTIME RusDateToSysDate(char *t);


CString dwtostr_null(DWORD dwNum);
CString dbltostr_null(double dNum);
CString isNull(DWORD Val);
CString isNull(WORD Val);
CString isNull(double Val);
CString isNull(__int64 Val);
CString isNull(CString Val);

CString StrDateToSQL(char *, BOOL bWithNull = FALSE);

CString isAble(int Check, CString str);
DWORD isAble(int Check, DWORD dwNum );
int SetComboBoxItemByID( CComboBox *b, DWORD iID );

int VanNumberIsValid(CString strNum);
void ShowMsg( CString s );

extern SQLRETURN    g_sqlret;

extern BOOL  g_bSecret;

extern BYTE  gs_DateFmt;
extern DWORD g_iDep;
extern DWORD g_iFam;
extern DWORD g_dwTypeDep;
extern CString g_conf_strMessagePath;
extern CString g_strDepoName;
extern CString g_strDepoSName;
extern int g_conf_User_Name_On_Login;
extern int g_iAutoOK;
extern CDBWire DBW;
extern CDBWire DBWrez;
extern int g_iGotRezervDBW;
extern DWORD g_dwDepoGruzPas;

extern int g_iVersion;
extern int g_iSubVersion;
extern int g_iBuildVersion;
extern int g_conf_MessageOnCancel;
extern long Ind;
extern char cQ[600];

//extern CConfig cfg;

#define LOG_WRITE 0
#define LOG_INFO  1
#define LOG_ERROR 2

//#define INIT_FROM_
#define INIT_FROM_GIVEN_SIMPLE 2
#define INIT_FROM_GIVEN 3
#define INIT_FROM_DB 4
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__CD56AE6E_0676_4F15_AEE1_D1AD8CC5C15B__INCLUDED_)
