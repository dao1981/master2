// DBWire.h: interface for the CDBWire class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBWIRE_H__3DA846B5_68FA_4DDD_846E_144669D677AF__INCLUDED_)
#define AFX_DBWIRE_H__3DA846B5_68FA_4DDD_846E_144669D677AF__INCLUDED_

#include "EmplArray.h"
#include "FastGrid.h"
#include "stdAfx.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct PRIH_KP;
struct PASP_KP;

#define MsgCheckExistsInstance  "ClientTovCheckExistsPlease"
#define MsgSendViaTele "ClientTovSendMyMessagePlease"

class CDBWire  
{
public:
	void WriteServerDebug(CString Q);
	void FillComboWithSmazkaType(CComboBox *cb);
	void FillComboWithOsRezRepairs(CComboBox *cb);
	void FillComboWithProfessions(CComboBox *cb);
	int GetGlobalOption(CString OptionName, int *Value);
	int GetDepoName(DWORD dwID, CString &Name, CString &SName, DWORD &DepoType, DWORD &dwGruzPas);
	CString GetFIOByID(DWORD dwID);
	int GetPaspKP(__int64 qwIKP, PASP_KP *psp);
	int WritePrihodKP(PRIH_KP *p, PASP_KP *psp, BOOL bShowMessage = FALSE, __int64 qwILK = 0);
	int WritePrihodKP(PRIH_KP *p, BOOL bShowMessage = FALSE, __int64 qwILK = 0);
	int LoadPrihdKP(PRIH_KP *p, __int64 qwIZap );
	int GetPrihodKP(__int64 IZap, PRIH_KP *p);
	CString GetNeispKlByID(DWORD dwID);
	int ClearResultSet();
	int ExecProc(CString cQuery, int &RetValue);
	int Connect( CString Server, CString Login, CString Pass);
	int FillEmplArray(CEmplArray *lpArr, int iFilter);
	int FillComboWithTRemVag(CComboBox *cb);
	int FillComboWithTPR(CComboBox *cb);
	void SetListHeader(CListCtrl *m_List);
	void CloseCursor();
	SQLRETURN GetData(SQLUSMALLINT Col, SQLSMALLINT Type, SQLPOINTER Buf, SQLINTEGER BufLen, SQLINTEGER *Ind);
	SQLRETURN Fetch();
	long DisplaySQLError();
	int UpdateListByHandle(CFastGrid *m_List, DWORD *IDPos = NULL, bool bHoldColLength = false, bool b_QWData = false);
	int ReallocHandle();
	int Disconnect();
	int WriteLog(char *s, int Level = 0, int WriteTime = 1);
	int Connect(CString ConnectString);
	int ExecSQL(CString cQuery);

	int FillComboWithTKP(CComboBox *cb);
	CString GetTKPNameByID(DWORD dwITKP);
	CDBWire();
	virtual ~CDBWire();

/* отрпавка сообщений через ТОВ */
	int MsgIDCheckExistsInstance, MsgIDSendViaTele;
	int initTovSendMessage();
	int SendMessageToTov(CString strMessage);
	int SendMessageToDst(CString strMessage, CString src, CString dst);

    SQLRETURN    sqlret;
private:
    SQLHENV      h_env;
    SQLHDBC      h_dbc;
    SQLHSTMT     h_sqlstmt;
    SQLSMALLINT  cb_ConnStrOut;
	
public:
	CString		strConnStr;
	int FillComboWithRepairsKP(CComboBox * cb);
	int DisplayHtmlReport(CString cQ);
	int GetGlobalOption(CString OptionName, CString *strValue);
	int iConnecting;
public:
	int ExecSQLRzv(char * cQ);
};

#endif // !defined(AFX_DBWIRE_H__3DA846B5_68FA_4DDD_846E_144669D677AF__INCLUDED_)
