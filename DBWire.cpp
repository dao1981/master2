// DBWire.cpp: implementation of the CDBWire class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "master.h"
#include "DBWire.h"
#include "FastGrid.h"
#include ".\dbwire.h"
#include "DlgConnectServ.h"
#include ".\master.h"
#include ".\telecom\teleI.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern int gs_EnableServerDebug;
extern CString g_strDepoKl;
extern DWORD g_dwPrID;
extern char	g_cDepESR[16];
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDBWire::CDBWire()
{
    h_env = SQL_NULL_HENV;
    h_dbc = SQL_NULL_HDBC;
    h_sqlstmt = SQL_NULL_HSTMT;   

	MsgIDCheckExistsInstance = 0;
	MsgIDSendViaTele = 0;
	iConnecting = 0;
}


extern CMasterApp theApp;
extern int g_iStandAlone;

CDBWire::~CDBWire()
{

}

int CDBWire::initTovSendMessage()
{
	if( g_iStandAlone ) return 1;
	WriteLog("initTovSendMessage");
	HANDLE MutexHandle;

	MsgIDCheckExistsInstance = RegisterWindowMessage(MsgCheckExistsInstance);
	MsgIDSendViaTele = RegisterWindowMessage(MsgSendViaTele);
	MutexHandle = CreateMutex(NULL,false,MsgCheckExistsInstance);
	
	if( !MutexHandle )
	{
		WriteLog("MutexHandle is NULL");
		return -1;
	}
	WriteLog("ok");
	return 0;
}

int CDBWire::SendMessageToTov(CString strMessage)
{
	if( g_iStandAlone ) 
	{
		WriteLog("!stand alone");
		return 1;
	}
	WriteLog("SendMessageToTov");

	WriteLog((char*)strMessage.GetString());


	CString msg = strMessage;
	HANDLE MutexHandle, HM;
	LPVOID pMsg;
	while(1)
	{
		MutexHandle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, MsgCheckExistsInstance);
		if( !MutexHandle )
		{
			if( AfxMessageBox("Не могу передать сообщение. Возможно ТОВ не запущен", 							   
							  MB_RETRYCANCEL) == IDRETRY)
			{
				WriteLog("error on OpenMutex");
				continue;
			}
		} // Клиент существует - передаем сообщение

		HM = CreateFileMapping((HANDLE)-1, NULL,PAGE_READWRITE,0,msg.GetLength() + 1,MsgSendViaTele);
		if( !HM )
		{
			WriteLog("error on CreateFileMapping (HM is NULL)");
		}
		pMsg = MapViewOfFile(HM,FILE_MAP_WRITE,0,0,0);
		sprintf( (char *)pMsg, "\t\t%s", strMessage );

		PostMessage(HWND_BROADCAST,MsgIDSendViaTele,0,0);
		UnmapViewOfFile(pMsg);
		CloseHandle(MutexHandle);
		WriteLog("done");
		break;
	}
	return 0;
}

int CDBWire::SendMessageToDst(CString strMessage, CString src, CString dst)
{
	if( g_iStandAlone ) 
	{
		WriteLog("!stand alone");
		return 1;
	}

	WriteLog((char*)("SendMessageToDst: from " + src + " to " + dst).GetString ());

	WriteLog((char*)strMessage.GetString());


	CString msg = strMessage;
	HANDLE MutexHandle, HM;
	LPVOID pMsg;
	while(1)
	{
		MutexHandle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, MsgCheckExistsInstance);
		if( !MutexHandle )
		{
			if( AfxMessageBox("Не могу передать сообщение. Возможно ТОВ не запущен", 							   
							  MB_RETRYCANCEL) == IDRETRY)
			{
				WriteLog("error on OpenMutex");
				continue;
			}
		} // Клиент существует - передаем сообщение

		HM = CreateFileMapping((HANDLE)-1, NULL,PAGE_READWRITE,0,msg.GetLength() + 1,MsgSendViaTele);
		if( !HM )
		{
			WriteLog("error on CreateFileMapping (HM is NULL)");
		}
		pMsg = MapViewOfFile(HM,FILE_MAP_WRITE,0,0,0);
		sprintf( (char *)pMsg, "%s\t%s\t%s", src, dst, strMessage);

		PostMessage(HWND_BROADCAST,MsgIDSendViaTele,0,0);
		UnmapViewOfFile(pMsg);
		CloseHandle(MutexHandle);
		WriteLog("done");
		break;
	}
	return 0;
}


int CDBWire::FillComboWithTKP(CComboBox *cb)
{
    if( !cb ) return -1;
    long    Ind = 0;
    DWORD   dwNum = 0;
    char    cText[32] = "";
    ExecSQL("pTov_GetTKP");
    for( int i=0; (sqlret = Fetch()) != SQL_NO_DATA && sqlret != SQL_ERROR; i++ )
    {
        GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
        GetData(2, SQL_C_CHAR, cText, 32, &Ind);
        cb->AddString(cText);
        cb->SetItemData(i, dwNum);
    }
    CloseCursor();   
    return 0;
}

int CDBWire::ExecSQL(CString cQuery)
{
    if( cQuery == "" )
    {
        AfxMessageBox("Empty query were passed");
    }
    WriteServerDebug(cQuery);
    char cQ[10024] = "";
    strcpy((char *)cQ, (LPCSTR)cQuery);
    WriteLog(cQ);

    sqlret = SQLExecDirect(h_sqlstmt, (unsigned char *)cQ, strlen(cQuery));
    WriteLog(" + ");
    if( sqlret == SQL_ERROR )
    {
        WriteLog("Failed", 2, 0);
        if( DisplaySQLError() == 24 )
        {
            WriteLog("Trying to reallocate DB handle", 0, 0);
            SQLRETURN rRet;
            SQLFreeHandle(SQL_HANDLE_STMT, h_sqlstmt);
            rRet = SQLAllocHandle( SQL_HANDLE_STMT,
                          h_dbc,
                          &h_sqlstmt );
            if( rRet == SQL_ERROR )
            {
                WriteLog("Falied to Allocate DB handle", 2, 0);
            }
            else
                WriteLog("Handle Allocated", 1, 0);            
                WriteLog("Trying to execute last query again", 0, 0);
                sqlret = SQLExecDirect(h_sqlstmt, (unsigned char *)cQ, strlen(cQuery));
                WriteLog(cQ);
                if( sqlret == SQL_ERROR )
                {
                    WriteLog("Failed", 2, 0);
                    DisplaySQLError();                    
                } else
                    WriteLog("OK", 1, 0);
                return 0;
        } else
		{
			Disconnect();
			if( Connect(strConnStr) == -1 )
			{
				CDlgConnectServ Dlg;
				if( Dlg.DoModal() == IDCANCEL ) return -1;
			}
			sqlret = SQLExecDirect(h_sqlstmt, (unsigned char *)cQ, strlen(cQuery));
                WriteLog(cQ);
                if( sqlret == SQL_ERROR )
                {
                    WriteLog("Failed", 2, 0);
                    DisplaySQLError();   
					return -1;
                } else
                    WriteLog("OK", 1, 0);
                return 0;
		}
    } else
        WriteLog("OK",1 ,0);
    return 0;
}

int CDBWire::Connect(CString ConnectString)
{
	iConnecting = 1;
	strConnStr = ConnectString;
   RETCODE retcode;
   SQLCHAR cStringIn[1024] = "";
   SQLCHAR cStringOut[1024] = "";
   strcpy((char *)cStringIn, (LPCSTR)ConnectString);
   char s[1024] = "";
  
//   sprintf(s, "Using string: %s", ConnectString);
//   WriteLog(s, 3);

   retcode = SQLAllocHandle (SQL_HANDLE_ENV, NULL, &h_env);
   retcode = SQLSetEnvAttr(h_env, SQL_ATTR_ODBC_VERSION,
                     (SQLPOINTER)SQL_OV_ODBC3,
                     SQL_IS_INTEGER);
   retcode = SQLAllocHandle(SQL_HANDLE_DBC, h_env, &h_dbc);
   retcode = SQLDriverConnect(h_dbc,
                  NULL,
                  cStringIn,
                  SQL_NTS,
                  cStringOut,
                  MAXBUFLEN,
                  &cb_ConnStrOut,
                  SQL_DRIVER_NOPROMPT);

   unsigned char SQLState[6];
   long          iDiag = 0;
   short         iTextLength = 0;
   unsigned char pcMessage[512] = "";
   char cMess[1024] = "";
   RETCODE rc1 = 0;
   for( int x = 0 ;(rc1 = SQLGetDiagRec(SQL_HANDLE_DBC, 
                        h_dbc, 
                        x, 
                        SQLState, 
                        &iDiag,  
                        pcMessage,
                        512,
                        &iTextLength)) != SQL_NO_DATA && x < 16; x++)
   {
        sprintf(cMess, "%s\n%s", cMess, pcMessage );
   }
   if ( (retcode != SQL_SUCCESS) && 
      (retcode != SQL_SUCCESS_WITH_INFO) ) 
   {
//        DisplaySQLError(h_sqlstmt);
       WriteLog(cMess, 2, 0);
	   iConnecting = 0;
       return -1;
   }
   WriteLog(cMess, 1, 0);

   SQLAllocHandle( SQL_HANDLE_STMT,
                      h_dbc,
                      &h_sqlstmt );
   SQLSetConnectOption(h_dbc, SQL_CURSOR_TYPE, SQL_CURSOR_STATIC);
   SQLSetConnectOption(h_dbc, SQL_AUTOCOMMIT, SQL_AUTOCOMMIT_ON);

   iConnecting = 0;
   return 0;
}

int CDBWire::WriteLog(char *s, int Level, int WriteTime)
{
    theApp.WriteLog(s, Level, WriteTime);
    return 0;
}

int CDBWire::Disconnect()
{
   SQLDisconnect(h_dbc);
   SQLFreeHandle(SQL_HANDLE_DBC, h_dbc);
   SQLFreeHandle(SQL_HANDLE_ENV, h_env);
   return 0;    
}

int CDBWire::ReallocHandle()
{
    SQLFreeHandle(SQL_HANDLE_STMT, h_sqlstmt);
    SQLAllocHandle(SQL_HANDLE_STMT,
                       h_dbc,
                       &h_sqlstmt );
    return 0;
}

int CDBWire::UpdateListByHandle(CFastGrid *m_List, DWORD *IDPos, bool bHoldColLength, bool b_QWData)
{
    DWORD dwCount = 0;
//    SQL_NUMERIC_STRUCT nsNum;
    SQLHDESC h_desc = NULL;
    char  cText[512] = "";
    DWORD  dwNum = 0;
    long  lNum = 0;
    long  Ind = 0;
//    long a, b;
    char  cRez[512] = "";
    char cType[64]="";
    m_List->DeleteAllItems();
    BYTE    ColVisible[255];
    memset(&ColVisible, 1, sizeof(BYTE));
    SQLColAttribute(h_sqlstmt, 0, SQL_DESC_COUNT, NULL, 0, NULL, &dwCount);
    for( WORD v=0; v < dwCount; v++ )
    {
        SQLColAttribute(h_sqlstmt, v + 1, SQL_DESC_NAME, cText, 64, NULL, NULL);
        if( cText[0] == '-' ) ColVisible[v]=0;
        else ColVisible[v] = 1;

    }
    int iCW[128];
    memset(&iCW, 0, sizeof(iCW));
    int iSW = 0;
//    int a, b, nsNum;
    BOOL ColFlag = FALSE;
    WORD ColCount=0;
	DWORD dwRecordCount = 0;
    __int64 qwNum = 0;
    for(DWORD j=0; (sqlret = SQLFetch(h_sqlstmt)) != SQL_NO_DATA && sqlret != SQL_ERROR && j < 32000; j++ )
    {
        ColFlag = FALSE;
        ColCount = 0;
//        m_List->InsertItem(LVIF_TEXT | LVIF_STATE, j, "", 0, LVIS_SELECTED, 0, 0);
        m_List->InsertItem(j, "");
        dwRecordCount++;
        for( WORD i=0; i < dwCount; i++ )
        {
            if( IDPos && i == *IDPos )
            {   
                if( !b_QWData )
                {
                    SQLGetData(h_sqlstmt, i + 1, SQL_C_ULONG, &dwNum, 4, &Ind);
                    m_List->SetItemData(j, dwNum);
                } 
                else 
                {
                    SQLGetData(h_sqlstmt, i + 1, SQL_C_UBIGINT, &qwNum, 4, &Ind);
                    if( Ind != -1 ) m_List->qwSetItemData(j, qwNum);
					else m_List->qwSetItemData(j, 0);
                }
            }

            if( !ColVisible[i] ) continue;
            SQLColAttribute(h_sqlstmt, i + 1, SQL_DESC_TYPE_NAME, cRez, 64, NULL, NULL);
            SQLColAttribute(h_sqlstmt, i + 1, SQL_DESC_TYPE, NULL, 0, NULL, &dwNum);
            sprintf(cType, " %s (%d) ", cRez, dwNum);
            
            cText[0] = 0;
			if( dwNum == 9 )// datetime
            {
                SQL_DATE_STRUCT date;
                SQLGetData(h_sqlstmt, i + 1, SQL_C_TYPE_DATE, &date, sizeof(SQL_DATE_STRUCT), &Ind);
                if(Ind != -1 ) sprintf(cText, "%.2d-%.2d-%.4d", date.day, date.month, date.year);
            } else
				SQLGetData(h_sqlstmt, i + 1, SQL_C_CHAR, cText, 128, &Ind);
            //(IDPos && *IDPos >= 512) && 
/*
            if( (DWORD)(i + 1) == dwCount )
            {
                m_List->SetItemData(j, atoi(cText));
            }
*/
            if( Ind != -1 ) 
            {
                m_List->SetItemText(j, ColCount, cText);
            }
            if(iCW[ColCount] < (iSW = m_List->GetStringWidth(cText))) iCW[ColCount]=iSW;
            ColCount++;
        }
    }
    DWORD dwListStyle = 0;
    dwListStyle = m_List->GetExStyle();
    
    bool f = false;    
    bool f1 = false;
    if( dwListStyle && LVS_EX_CHECKBOXES ) f1 = true;
    if( !bHoldColLength )
    {
        for(WORD i=0; i < dwCount; i++ ) 
        {
            if( iCW[i] == 0 ) continue;
            if( f1 && !f )
            {
                iCW[i] += 11;
            }
            f = 0;
            m_List->SetColumnWidth(i, iCW[i]+15);
        }
    }
	return dwRecordCount;
}

long CDBWire::DisplaySQLError()
{
    if( g_bSecret ) return 0;
    SQLRETURN rc2=0;
    SQLSMALLINT i, MsgLen;
    SQLCHAR SQLState[6], Msg[SQL_MAX_MESSAGE_LENGTH];
    SQLINTEGER NativeError;
    long Ret = 0;
    i = 1;
    char cText[2048] = "";
    while ((rc2 = SQLGetDiagRec(SQL_HANDLE_STMT, h_sqlstmt, i, SQLState, &NativeError,
        Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA && i < 16) 
    {
        sprintf(cText, "%s[%s]-[%d]-[%s]\n",cText, SQLState,NativeError,Msg);
        if( !Ret && !strcmp((char *)SQLState, "24000")) Ret = 24;
        WriteLog(cText, LOG_ERROR);
		if( strstr(cText, "TCP/IP Sockets") == NULL )
			MessageBox(NULL, cText, "SQL Error Display", MB_OK);
        i++;
    }
    return Ret;
}

SQLRETURN CDBWire::Fetch()
{
    return SQLFetch(h_sqlstmt);
}

SQLRETURN CDBWire::GetData(SQLUSMALLINT Col, SQLSMALLINT Type, SQLPOINTER Buf, SQLINTEGER BufLen, SQLINTEGER *Ind)
{
//    if( !Ind ) return SQL_ERROR;
    return SQLGetData(h_sqlstmt, Col, Type, Buf, BufLen, Ind);
}

void CDBWire::CloseCursor()
{
    SQLCloseCursor(h_sqlstmt);
}

void CDBWire::SetListHeader(CListCtrl *m_List)
{
    DWORD dwCount = 0;
    char  cName[64] = "";
    SQLColAttribute(h_sqlstmt, 0, SQL_DESC_COUNT, NULL, 0, NULL, &dwCount);
    for( WORD i=0; i < dwCount; i++ )
    {
        SQLColAttribute(h_sqlstmt, i + 1, SQL_DESC_NAME, cName, 64, NULL, NULL);
        if( cName[0] != '-' ) m_List->InsertColumn(i, cName, LVCFMT_LEFT,  100, -1);
    }
}

int CDBWire::FillComboWithTPR(CComboBox *cb)
{
    ExecSQL("pTov_GetAllTypesPR");
    char cText[32] = "";
    long Ind = 0;
    DWORD dwNum = 0;
    for( WORD i=0; (g_sqlret = Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 512; i++ )
    {
        SQLGetData(h_sqlstmt, 1, SQL_C_ULONG, &dwNum, 4, &Ind);        
        SQLGetData(h_sqlstmt, 2, SQL_C_CHAR, cText, 15, &Ind);
        if( Ind != -1 ) cb->AddString(cText);
        cb->SetItemData(i, dwNum);
    }
    CloseCursor();
    return 0;
}

int CDBWire::FillComboWithTRemVag(CComboBox *cb)
{
    ExecSQL("pTov_GetTypeRemVag");
    char cText[32] = "";
    long Ind = 0;
    DWORD dwNum = 0;
    for( WORD i=0; (g_sqlret = Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 512; i++ )
    {
        SQLGetData(h_sqlstmt, 1, SQL_C_ULONG, &dwNum, 4, &Ind);        
        SQLGetData(h_sqlstmt, 2, SQL_C_CHAR, cText, 15, &Ind);
        if( Ind != -1 ) cb->AddString(cText);
        cb->SetItemData(i, dwNum);
    }
    CloseCursor();
    return 0;
}

int CDBWire::FillEmplArray(CEmplArray *lpArr, int iFilter)
{
    CString strQ;
    long    Ind = 0;
    char    cText[64] = "";
    DWORD   dwNum = 0;
    strQ.Format("pTov_GetAllEmployee 0, null, %d, %u", iFilter, g_iDep);
    ExecSQL(strQ);
    lpArr->Clear();
    for( int i=0; (g_sqlret = SQLFetch(h_sqlstmt)) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 3000; i++ )
    {
        SQLGetData(h_sqlstmt, 1, SQL_C_ULONG, &dwNum, 4, &Ind);
        SQLGetData(h_sqlstmt, 2, SQL_C_CHAR, cText, 64, &Ind);
//        SQLGetData(h_sqlstmt, 4, SQL_C_ULONG, &dwNum, 4, &Ind);
        lpArr->AddEmployee(dwNum, cText, 0);
    }
    SQLCloseCursor(h_sqlstmt);
    return 0;
}

int CDBWire::Connect(CString Server, CString Login, CString Pass)
{
    char ConnStrIn[512] = "";
    sprintf((char *)ConnStrIn, "DRIVER={SQL Server};SERVER=%.64s;"\
             "UID=%.64s;PWD=%.64s;DATABASE=kcmod;",
              Server,
              Login,
              Pass);
    return Connect(ConnStrIn);
}

int CDBWire::ExecProc(CString cQuery, int &RetValue)
{
//    int RetValue = 0;
    SDWORD cbRetValue = 0;

    if( cQuery == "" )
    {
        AfxMessageBox("EXEC PROC: Empty query were passed");
    }
    WriteServerDebug(cQuery);
    char cQ[1024] = "";
    char cText[64] = "";
    strcpy((char *)cQ, (LPCSTR)cQuery);
    sprintf(cQ, "{? = call %s }", cQuery);
    WriteLog(cQ);

    sqlret = SQLBindParameter(h_sqlstmt, 1, SQL_PARAM_OUTPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &RetValue, 0, &cbRetValue);

    sqlret = SQLExecDirect(h_sqlstmt, (unsigned char *)cQ, SQL_NTS);
   
    if( sqlret == SQL_ERROR )
    {
        WriteLog("Failed", 2, 0);
        if( DisplaySQLError() == 24 )
        {
            WriteLog("EXEC PROC: Trying to reallocate DB handle", 0, 0);
            SQLRETURN rRet;
            SQLFreeHandle(SQL_HANDLE_STMT, h_sqlstmt);
            rRet = SQLAllocHandle( SQL_HANDLE_STMT,
                          h_dbc,
                          &h_sqlstmt );
            if( rRet == SQL_ERROR )
            {
                WriteLog("EXEC PROC: Falied to Allocate DB handle", 2, 0);
            }
            else
                WriteLog("EXEC PROC: Handle Allocated", 1, 0);            
                WriteLog("EXEC PROC: Trying to execute last query again", 0, 0);
                sqlret = SQLExecDirect(h_sqlstmt, (unsigned char *)cQ, strlen(cQuery));
                WriteLog(cQ);
                if( sqlret == SQL_ERROR )
                {
                    WriteLog("Failed", 2, 0);
                    DisplaySQLError();                    
                } else
                {
                    WriteLog("OK", 1, 0);
                }
                return RetValue;
        }
    } else
    {
        WriteLog("OK", 1, 0);
    }
    return RetValue;
}

int CDBWire::ClearResultSet()
{
    while ( ( sqlret = SQLMoreResults(h_sqlstmt) ) != SQL_NO_DATA );
    return 0;
}

CString CDBWire::GetNeispKlByID(DWORD dwID)
{
	long Ind;
	DWORD dwNum = 0;
	char cText[64] = "";

	ExecSQL("pTov_GetNeispKP");
	while( (sqlret = SQLFetch(h_sqlstmt)) != SQL_NO_DATA )
	{
		SQLGetData(h_sqlstmt, 1, SQL_C_CHAR, &cText, 64, &Ind);
		SQLGetData(h_sqlstmt, 5, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 && dwNum == dwID )
		{
			SQLCloseCursor(h_sqlstmt);
			return cText;
		}
	}
	SQLCloseCursor(h_sqlstmt);
	return "";

}

int CDBWire::GetPrihodKP(__int64 IZap, PRIH_KP *p)
{
	if( !p || !IZap ) return -1;

	char cQ[64] = "";
	long Ind = 0;
	SQL_DATE_STRUCT  sqlDat;
//    SYSTEMTIME       sysTime;
    DWORD dwNum = 0;

	sprintf(cQ, "pTov_GetKPData %I64u", IZap);
	ExecSQL(cQ);
	if( (sqlret = SQLFetch(h_sqlstmt)) == SQL_NO_DATA ) return -1;

	SQLGetData(h_sqlstmt, 1, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if(Ind != -1 ) SqlDateToSysTime(sqlDat, &p->stDatPost);
	SQLGetData(h_sqlstmt, 2, SQL_C_USHORT, &p->wGruz, 2, &Ind);
	SQLGetData(h_sqlstmt, 3, SQL_C_USHORT, &p->wITR, 2, &Ind);
	SQLGetData(h_sqlstmt, 4, SQL_C_CHAR, &p->cPrihNVag, 32, &Ind);
	SQLGetData(h_sqlstmt, 5, SQL_C_CHAR, &p->cPeresPr_NAME, 32, &Ind);
	SQLGetData(h_sqlstmt, 6, SQL_C_CHAR, p->cPeresPr_KL, 32, &Ind);	
	SQLGetData(h_sqlstmt, 7, SQL_C_ULONG, &p->dwPeresIPR, 4, &Ind);
	SQLGetData(h_sqlstmt, 8, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &p->stPeresDat);

	SQLGetData(h_sqlstmt, 9, SQL_C_ULONG, &p->dwNVedPeres, 4, &Ind);
	SQLGetData(h_sqlstmt,11, SQL_C_USHORT, &p->wTd_l, 2, &Ind);
	SQLGetData(h_sqlstmt,12, SQL_C_USHORT, &p->wTd_r, 2, &Ind);
	SQLGetData(h_sqlstmt,13, SQL_C_DOUBLE, &p->dPrihDkk_l, sizeof(SQL_C_DOUBLE), &Ind);
	SQLGetData(h_sqlstmt,14, SQL_C_DOUBLE, &p->dPrihDkk_r, sizeof(SQL_C_DOUBLE), &Ind);
	SQLGetData(h_sqlstmt,15, SQL_C_CHAR, p->cPosForPr_KL, 32, &Ind);
	SQLGetData(h_sqlstmt,16, SQL_C_ULONG, &p->dwPosForPr_ID, 4, &Ind);
	SQLGetData(h_sqlstmt,17, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &p->stDatFor);
	SQLGetData(h_sqlstmt,18, SQL_C_CHAR, p->cPosOsvPr_KL, 32, &Ind);
	SQLGetData(h_sqlstmt,19, SQL_C_ULONG, &p->dwPosOsvPr_ID, 4, &Ind);
	SQLGetData(h_sqlstmt,20, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &p->stDatOsv);
	SQLGetData(h_sqlstmt,21, SQL_C_ULONG, &p->dwNeisp_ID, 4, &Ind);
	SQLGetData(h_sqlstmt,22, SQL_C_CHAR, p->cNeisp_KL, 32, &Ind);
	SQLGetData(h_sqlstmt,23, SQL_C_CHAR, p->cNeisp_NAME, 32, &Ind);
	SQLGetData(h_sqlstmt,24, SQL_C_ULONG, &p->dwTREB_REM, 4, &Ind);
	SQLGetData(h_sqlstmt,25, SQL_C_ULONG, &p->dwFam, 4, &Ind);
	SQLGetData(h_sqlstmt,26, SQL_C_ULONG, &p->dwRemVagID, 4, &Ind);
    SQLGetData(h_sqlstmt,27, SQL_C_ULONG, &p->dwPriznRas, 4, &Ind);
	SQLGetData(h_sqlstmt,28, SQL_C_ULONG, &p->iSteelType, 4, &Ind);
	SQLGetData(h_sqlstmt,29, SQL_C_ULONG, &p->iParkNum, 4, &Ind);
	SQLGetData(h_sqlstmt,30, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);	
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &p->dt6);
	SQLGetData(h_sqlstmt,31, SQL_C_ULONG, &p->dwSobstIPRPrih, 4, &Ind);



//    SQLGetData(h_sqlstmt,20, SQL_C_ULONG, &psp->dwTKP, 4, &Ind);

	CloseCursor();
	return 0;
}

int CDBWire::WritePrihodKP(PRIH_KP *p, PASP_KP *psp, BOOL bShowMessage, __int64 qwILK)
{
	char cQ[1024] = "";
	char cIKP[32] = "";
	char cIZAP[32] = "";
	char cDate[32] = "", /*cGpParam[32] = "",*/ cParams[32] = "", cIzOsPr_ID[32] = "", cPosForPr_ID[16] = "",
		 cPosOsvPr_ID[32] = "", cTypeRedID[32] = "", cTD_r[8] = "", cTD_l[8] = "", cDkk_r[8] = "",
		 cDkk_l[8] = "", cNeispID[16] = "", cTrebRemID[16] = "";

	if( psp->qwIKP == 0 ) strcpy(cIKP, "NULL");
	else _i64toa(psp->qwIKP, cIKP, 10);

	if( p->qwIZAP == 0 ) strcpy(cIZAP, "NULL");
	else _i64toa(p->qwIZAP, cIZAP, 10);

//	itoa(p->wGruz, cGpParam, 10);

	if( p->cPrihNVag[0] )
	{
		sprintf(cParams, "'%s'", p->cPrihNVag);
		if( p->dwRemVagID )
		{
			sprintf(cParams, "%s, %u",cParams, p->dwRemVagID);
		} else
			strcat(cParams, ", NULL");
		strcat(cParams, ", NULL, NULL, NULL");
	} else
	{
		char cnv[32] = "";
		if( p->dwNVedPeres ) itoa(p->dwNVedPeres, cnv, 10);
		else strcpy(cnv, "NULL");
		
		sprintf(cParams, "NULL, NULL, %u, %s, %s", p->dwPeresIPR, DateToSQL(p->stPeresDat), cnv);
	}

	sprintf(cQ, "pTov_PrihodKP %s, %s, %u, '%s', %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %d, %s",
		//															    ^cIzOsPr
			isNull(psp->qwIKP),
			isNull(p->qwIZAP),
			g_iDep,
			psp->cNKP,
			psp->dwTKP,
			DateToSQL(p->stDatPost),
			isNull(p->wGruz),
			cParams,
			dwtostr_null(psp->dwIzOsPr_ID),
			DateToSQL(p->stDatIzg),
			dwtostr_null(p->dwPosForPr_ID),
			DateToSQL(p->stDatFor),
			dwtostr_null(p->dwPosOsvPr_ID),
			DateToSQL(p->stDatOsv),
			dwtostr_null(p->wITR),
			dwtostr_null(p->wTd_r),
			dwtostr_null(p->wTd_l),
			dbltostr_null(p->dPrihDkk_r),
			dbltostr_null(p->dPrihDkk_l),
			dwtostr_null(p->dwNeisp_ID),
			dwtostr_null(p->dwTREB_REM),
			isNull(p->dwFam),
			p->dwPriznRas,
            isNull(qwILK),
			p->iSteelType,
			dwtostr_null((DWORD)p->iParkNum)
			);
	char cMess[512] = "";
	long Ind = 0;
    WriteServerDebug(cQ);
	ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cMess, 512, &Ind);

	if( !_atoi64(cMess) )
	{
		if( bShowMessage )
			MessageBox(NULL, cMess ,"Внимание", MB_OK | MB_ICONINFORMATION);	
		
		DBW.CloseCursor();
		DBW.ReallocHandle();
		return -1;	
	} else
	{
		psp->qwIKP = _atoi64(cMess);
		DBW.GetData(2, SQL_C_UBIGINT, &p->qwIZAP, 8, &Ind );
		DBW.GetData(3, SQL_C_ULONG, &p->dwPriznRas, 4, &Ind );
	}
	DBW.CloseCursor();
	return 0;

}

int CDBWire::LoadPrihdKP(PRIH_KP *p, __int64 qwIZap )
{
	if( !qwIZap ) return -1;
	ZeroMemory(p, sizeof(PRIH_KP));
	char cQ[1024] = "";
	SQL_DATE_STRUCT  sqlDat;
	sprintf(cQ, "pTov_KP_LoadPrihodKP %s", isNull( qwIZap ));
	DBW.ExecSQL(cQ);
	DBW.Fetch();
/*
	DBW.GetData(1, SQL_C_UBIGINT, &p->qwIZAP, 8, &Ind );
	DBW.GetData(2, SQL_C_UBIGINT, &p->qwIKP, 8, &Ind );
//	DBW.GetData(3, SQL_C_UBIGINT, &p->qwIKP, 8, &Ind ); // IDEP пропустим
	DBW.GetData(4, SQL_C_CHAR, p->cNKP, 24, &Ind );
	DBW.GetData(5, SQL_C_ULONG, &p->dwTKP, 4, &Ind );
	DBW.GetData(6, SQL_C_CHAR, p->cTKP, 24, &Ind );
	DBW.GetData(7, SQL_C_CHAR, p->cIzgPr_KL, 24, &Ind ); 
//	DBW.GetData(8, SQL_C_CHAR, p->cIzgPr_NAME, 24, &Ind ); 
	DBW.GetData(9, SQL_C_CHAR, &p->dwIzgPr_ID, 24, &Ind ); 
	mgSQLGetSysDate(10, &p->stDatIzg, &Ind);
	mgSQLGetSysDate(11, &p->stDatPost, &Ind);
	DBW.GetData(12, SQL_C_CHAR, p->cPrihNVag, 9, &Ind ); 
	DBW.GetData(13, SQL_C_ULONG, &p->dwRemVagID, 4, &Ind ); 
	DBW.GetData(14, SQL_C_ULONG, &p->dwPeresIPR, 4, &Ind ); 
	DBW.GetData(15, SQL_C_CHAR, p->cPeresPr_KL, 9, &Ind ); 
	DBW.GetData(16, SQL_C_CHAR, p->cPeresPr_NAME, 32, &Ind ); 
	mgSQLGetSysDate(17, p->stPeresDat, &Ind);
	DBW.GetData(18, SQL_C_ULONG, &p->dwNVedPeres, 4, &Ind ); 
	DBW.GetData(19, SQL_C_UINT, &p->wITR, 2, &Ind );
	DBW.GetData(20, SQL_C_UINT, &p->wTd_r, 2, &Ind );
	DBW.GetData(21, SQL_C_UINT, &p->wTd_l, 2, &Ind );
*/

	p->qwIZAP = qwIZap;
	SQLGetData(h_sqlstmt, 1, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if(Ind != -1 ) SqlDateToSysTime(sqlDat, &p->stDatPost);
	SQLGetData(h_sqlstmt, 2, SQL_C_USHORT, &p->wGruz, 2, &Ind);
	SQLGetData(h_sqlstmt, 3, SQL_C_USHORT, &p->wITR, 2, &Ind);
	SQLGetData(h_sqlstmt, 4, SQL_C_CHAR, &p->cPrihNVag, 32, &Ind);
	SQLGetData(h_sqlstmt, 5, SQL_C_CHAR, &p->cPeresPr_NAME, 32, &Ind);
	SQLGetData(h_sqlstmt, 6, SQL_C_CHAR, p->cPeresPr_KL, 32, &Ind);	
	SQLGetData(h_sqlstmt, 7, SQL_C_ULONG, &p->dwPeresIPR, 4, &Ind);
	SQLGetData(h_sqlstmt, 8, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &p->stPeresDat);

	SQLGetData(h_sqlstmt, 9, SQL_C_ULONG, &p->dwNVedPeres, 4, &Ind);
	SQLGetData(h_sqlstmt,11, SQL_C_USHORT, &p->wTd_l, 2, &Ind);
	SQLGetData(h_sqlstmt,12, SQL_C_USHORT, &p->wTd_r, 2, &Ind);
	SQLGetData(h_sqlstmt,13, SQL_C_DOUBLE, &p->dPrihDkk_l, sizeof(SQL_C_DOUBLE), &Ind);
	SQLGetData(h_sqlstmt,14, SQL_C_DOUBLE, &p->dPrihDkk_r, sizeof(SQL_C_DOUBLE), &Ind);
	SQLGetData(h_sqlstmt,15, SQL_C_CHAR, p->cPosForPr_KL, 32, &Ind);
	SQLGetData(h_sqlstmt,16, SQL_C_ULONG, &p->dwPosForPr_ID, 4, &Ind);
	SQLGetData(h_sqlstmt,17, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &p->stDatFor);
	SQLGetData(h_sqlstmt,18, SQL_C_CHAR, p->cPosOsvPr_KL, 32, &Ind);
	SQLGetData(h_sqlstmt,19, SQL_C_ULONG, &p->dwPosOsvPr_ID, 4, &Ind);
	SQLGetData(h_sqlstmt,20, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &p->stDatOsv);
	SQLGetData(h_sqlstmt,21, SQL_C_ULONG, &p->dwNeisp_ID, 4, &Ind);
	SQLGetData(h_sqlstmt,22, SQL_C_CHAR, p->cNeisp_KL, 32, &Ind);
	SQLGetData(h_sqlstmt,23, SQL_C_CHAR, p->cNeisp_NAME, 32, &Ind);
	SQLGetData(h_sqlstmt,24, SQL_C_ULONG, &p->dwTREB_REM, 4, &Ind);
	SQLGetData(h_sqlstmt,25, SQL_C_ULONG, &p->dwFam, 4, &Ind);
	SQLGetData(h_sqlstmt,26, SQL_C_ULONG, &p->dwRemVagID, 4, &Ind);
    SQLGetData(h_sqlstmt,27, SQL_C_ULONG, &p->dwPriznRas, 4, &Ind);
	SQLGetData(h_sqlstmt,28, SQL_C_ULONG, &p->iSteelType, 4, &Ind);
	SQLGetData(h_sqlstmt,29, SQL_C_ULONG, &p->iParkNum, 4, &Ind);
	SQLGetData(h_sqlstmt,30, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);	
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &p->dt6);
	SQLGetData(h_sqlstmt,31, SQL_C_ULONG, &p->dwSobstIPRPrih, 4, &Ind);

	DBW.GetData(32, SQL_C_CHAR, p->cNKP, 24, &Ind );
	DBW.GetData(33, SQL_C_ULONG, &p->dwTKP, 4, &Ind );
	DBW.GetData(34, SQL_C_CHAR, p->cTKP, 24, &Ind );

	DBW.GetData(35, SQL_C_CHAR, p->cIzgPr_KL, 24, &Ind ); 
//	DBW.GetData(36, SQL_C_CHAR, p->cIzgPr_NAME, 24, &Ind ); 
	DBW.GetData(37, SQL_C_CHAR, &p->dwIzgPr_ID, 24, &Ind ); 
	mgSQLGetSysDate(38, &p->stDatIzg, &Ind);

	SQLGetData(h_sqlstmt,39, SQL_C_DOUBLE, &p->dRashDkk_l, sizeof(SQL_C_DOUBLE), &Ind);
	SQLGetData(h_sqlstmt,40, SQL_C_DOUBLE, &p->dRashDkk_r, sizeof(SQL_C_DOUBLE), &Ind);

	SQLGetData(h_sqlstmt,41, SQL_C_ULONG, &p->wOb_l, 4, &Ind);
	SQLGetData(h_sqlstmt,42, SQL_C_ULONG, &p->wOb_r, 4, &Ind);

	SQLGetData(h_sqlstmt,43, SQL_C_ULONG, &p->wGr_l, 4, &Ind);
	SQLGetData(h_sqlstmt,44, SQL_C_ULONG, &p->wGr_r, 4, &Ind);

	SQLGetData(h_sqlstmt,45, SQL_C_DOUBLE, &p->dPr_l, sizeof(SQL_C_DOUBLE), &Ind);
	SQLGetData(h_sqlstmt,46, SQL_C_DOUBLE, &p->dPr_r, sizeof(SQL_C_DOUBLE), &Ind);


	CloseCursor();
	









	DBW.CloseCursor();
	return 0;
}

int CDBWire::WritePrihodKP(PRIH_KP *p, BOOL bShowMessage, __int64 qwILK)
{
		char cQ[1024] = "";
		char cMess[512] = "";

		sprintf(cQ, "pTov_KP_WritePrihod %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s,  %s, %s, %s, %s, %s, %s, %s, %s",
				isNull( p->qwIZAP ), //isNull(qwIZap),
				g_iDep,
				isNull(p->cNKP),
				isNull(p->dwTKP),
				isNull(p->cIzgPr_KL),
				DateToSQL( p->stDatIzg ), //  m_DatIzg.GetSQLDate(),
				isNull( p->wGruz ), // cGruzPas,
				DateToSQL( p->stDatPost ),
				isNull( p->cPrihNVag ),
				isNull( p->dwRemVagID ),
				isNull( p->dwPeresIPR ),
				DateToSQL( p->stPeresDat ),
				isNull( p->dwNVedPeres ),
				isNull( p->wITR ),
				isNull( p->wTd_r ),
				isNull( p->wTd_l ),
				isNull( p->dPrihDkk_r ),
				isNull( p->dPrihDkk_l ),
				DateToSQL( p->stDatFor ), // m_DatFor.GetSQLDate(),
				isNull( p->cPosForPr_KL),
				DateToSQL( p->stDatOsv ),
				isNull( p->cPosOsvPr_KL ),
				isNull( (DWORD)p->iSteelType ),

				isNull( p->dwNeisp_ID ),
				isNull( p->dwTREB_REM ),
				isNull( p->dwFam ),
				isNull( (DWORD) p->iParkNum ),
				isNull( p->dwSobstIPRPrih ),
				isNull( p->wOb_r ),
				isNull( p->wGr_r ),
				isNull( p->dPr_r ),

				isNull( p->wOb_l ),
				isNull( p->wGr_l ),
				isNull( p->dPr_l ),
				isNull( p->dwPriznRas ),
				isNull( qwILK ),
				"NULL", //IPeres,
				isNull( p->dRashDkk_l ),
				isNull( p->dRashDkk_r )
				);

	ExecSQL(cQ);
	Fetch();
	GetData(1, SQL_C_CHAR, cMess, 512, &Ind);

	if( !_atoi64(cMess) && cMess[0] && cMess[0] != '0')
	{
		if( bShowMessage )
			MessageBox(NULL, cMess ,"Внимание", MB_OK | MB_ICONINFORMATION);	
		
		CloseCursor();
		ReallocHandle();
		return -1;	
	} else
	{
		p->qwIKP = _atoi64(cMess);
		GetData(2, SQL_C_UBIGINT, &p->qwIZAP, 8, &Ind );
		GetData(3, SQL_C_ULONG, &p->dwPriznRas, 4, &Ind );
	}
	CloseCursor();
	return 0;}

int CDBWire::GetPaspKP(__int64 qwIKP, PASP_KP *psp)
{
	if( !psp || !qwIKP ) return -1;
	char cQ[64] = "";
	long Ind = 0;
	SQL_DATE_STRUCT  sqlDat;
//    SYSTEMTIME       sysTime;
	sprintf(cQ, "pTov_GetKPByIKP2 %I64u", qwIKP);
	ExecSQL(cQ);
	if( (sqlret = SQLFetch(h_sqlstmt)) == SQL_NO_DATA ) return -1;

	SQLGetData(h_sqlstmt, 1, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &psp->stIZOS_DAT);
	SQLGetData(h_sqlstmt, 2, SQL_C_CHAR, psp->cIzOsPr_KL, 32, &Ind);
	SQLGetData(h_sqlstmt, 3, SQL_C_CHAR, psp->cPL_OS, 32, &Ind);
	SQLGetData(h_sqlstmt, 4, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &psp->stPOSFOR_DAT);
	SQLGetData(h_sqlstmt, 5, SQL_C_CHAR, psp->cPosForPr_KL, 32, &Ind);
	SQLGetData(h_sqlstmt, 6, SQL_C_DATE, &sqlDat, sizeof(SQL_C_DATE), &Ind);
	if( Ind != -1 ) SqlDateToSysTime(sqlDat, &psp->stPOSOSV_DAT);
	SQLGetData(h_sqlstmt, 7, SQL_C_CHAR, psp->cPosOsvPr_KL, 32, &Ind);
	SQLGetData(h_sqlstmt, 8, SQL_C_CHAR, psp->cRedName, 32, &Ind);
	SQLGetData(h_sqlstmt,12, SQL_C_UBIGINT, &psp->qwIKP, 8, &Ind);
	SQLGetData(h_sqlstmt,13, SQL_C_USHORT, &psp->wGruz, 2, &Ind);
	SQLGetData(h_sqlstmt,14, SQL_C_ULONG, &psp->dwIzOsPr_ID, 4, &Ind);
	SQLGetData(h_sqlstmt,15, SQL_C_ULONG, &psp->dwPosForPr_ID, 4, &Ind);
	SQLGetData(h_sqlstmt,16, SQL_C_ULONG, &psp->dwPosOsvPr_ID, 4, &Ind);
	SQLGetData(h_sqlstmt,17, SQL_C_CHAR, &psp->cTKP, 16, &Ind);
	SQLGetData(h_sqlstmt,18, SQL_C_ULONG, &psp->dwRedTypeID, 4, &Ind);
	SQLGetData(h_sqlstmt,19, SQL_C_CHAR, &psp->cNKP, 16, &Ind);
	SQLGetData(h_sqlstmt,20, SQL_C_ULONG, &psp->dwTKP, 4, &Ind);



	SQLCloseCursor(h_sqlstmt);
	return 0;
}

CString CDBWire::GetFIOByID(DWORD dwID)
{
    CString cQ;
    long    Ind = 0;
    char    cText[64] = "";
    cQ.Format("pTov_GetFIOByID %u", dwID);
    ExecSQL(cQ);
    Fetch();
    GetData(1, SQL_C_CHAR, cText, 64, &Ind);
    CloseCursor();
    return cText;
}
extern int g_iAutoPrihodKP;
extern int g_iAutoRashodKP;
extern int g_iKP4624IzapReq;
int CDBWire::GetDepoName(DWORD dwID, CString &Name, CString &SName, DWORD &DepoType, DWORD &dwGruzPas)
{
    CString cQ;
    long    Ind = 0;
    char    cText[64] = "";
	g_dwPrID = 0;
    cQ.Format("pTov_GetDepoName %u", dwID);
    ExecSQL(cQ);
    Fetch();
    GetData(1, SQL_C_CHAR, cText, 64, &Ind);
    Name = cText;
    GetData(2, SQL_C_CHAR, cText, 64, &Ind);
    SName = cText;
    GetData(3, SQL_C_ULONG, &DepoType, 4, &Ind);
    GetData(4, SQL_C_ULONG, &dwGruzPas, 4, &Ind);
    GetData(5, SQL_C_CHAR, cText, 64, &Ind);
	GetData(6, SQL_C_ULONG, &g_dwPrID, 4, &Ind);	
    if( Ind != -1 ) g_strDepoKl = cText;
    else g_strDepoKl = "";
	GetData(7, SQL_C_CHAR, g_cDepESR, 16, &Ind);
	GetData(8, SQL_C_ULONG, &g_iAutoPrihodKP, 4, &Ind);
	GetData(9, SQL_C_ULONG, &g_iAutoRashodKP, 4, &Ind);
	GetData(10, SQL_C_ULONG, &g_iKP4624IzapReq, 4, &Ind);

    CloseCursor();
	//WriteLog("YO!");
    return 0;
}

int CDBWire::GetGlobalOption(CString OptionName, int *Value)
{
    if( !Value ) return -1;
    CString cQ;
    long Ind = 0;
    cQ.Format("pTov_GetOption '%s'", OptionName);
    ExecSQL(cQ);
    g_sqlret = Fetch();
    GetData(1, SQL_C_SLONG, Value, sizeof(int), &Ind);
    CloseCursor();
    if( g_sqlret == SQL_NO_DATA ) return 0;
    if( g_sqlret == SQL_ERROR ) return -1;
    return 1;
}
    

void CDBWire::FillComboWithProfessions(CComboBox *cb)
{
    if( !cb ) return;
    long    Ind = 0;
    DWORD   dwNum = 0;
    char    cText[64] = "";
    ExecSQL("pTov_GetJobs");
    for( int i=0; (sqlret = Fetch()) != SQL_NO_DATA && sqlret != SQL_ERROR; i++ )
    {        
        GetData(1, SQL_C_CHAR, cText, 64, &Ind);
        GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind);
        cb->AddString(cText);
        cb->SetItemData(i, dwNum);
    }
    CloseCursor();   
    return;
}

void CDBWire::FillComboWithOsRezRepairs(CComboBox *cb)
{
    if( !cb ) return;
    long    Ind = 0;
    DWORD   dwNum = 0;
    char    cText[64] = "";
    ExecSQL("pTov_GetAllOsRezRepairs");
    cb->AddString("Нет");
    cb->SetItemData(0, 0);
    cb->AddString("Да");
    cb->SetItemData(1, 1);

    for( int i=2; (sqlret = Fetch()) != SQL_NO_DATA && sqlret != SQL_ERROR; i++ )
    {        
        GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
        GetData(2, SQL_C_CHAR, cText, 64, &Ind);
        cb->AddString(cText);
        cb->SetItemData(i, dwNum);
    }
    CloseCursor();
    return;
}

void CDBWire::FillComboWithSmazkaType(CComboBox *cb)
{
    if( !cb ) return;
    long    Ind = 0;
    DWORD   dwNum = 0;
    char    cText[64] = "";
    ExecSQL("pTov_GetSmazkaKind");
    for( int i=0; (sqlret = Fetch()) != SQL_NO_DATA && sqlret != SQL_ERROR; i++ )
    {   
        GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
        GetData(2, SQL_C_CHAR, cText, 64, &Ind);        
        cb->AddString(cText);
        cb->SetItemData(i, dwNum);
    }
    CloseCursor();
}

void CDBWire::WriteServerDebug(CString Q)
{
    if( !gs_EnableServerDebug ) return;
//    char cQ[100];
/*    
    sprintf(cQ, "pTov_WriteDebug %u, %s",  g_iDep, Q);
    sqlret = SQLExecDirect(h_sqlstmt, (unsigned char *)cQ, SQL_NTS);
    DBW.CloseCursor();
    DBW.ReallocHandle();
*/
}

int CDBWire::FillComboWithRepairsKP(CComboBox * cb)
{
	if( !cb ) return -1;
    long    Ind = 0;
    DWORD   dwNum = 0;
    char    cText[64] = "";
    ExecSQL("pTov_GetTypeRemKP");
    for( int i=0; (sqlret = Fetch()) != SQL_NO_DATA && sqlret != SQL_ERROR; i++ )
    {   
		GetData(1, SQL_C_CHAR, cText, 64, &Ind);  
        GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind);              
        cb->AddString(cText);
        cb->SetItemData(i, dwNum);
    }
    CloseCursor();
    return 0;
}

int CDBWire::DisplayHtmlReport(CString cQ)
{
	long Ind = 0;
	FILE *f = fopen("html\\tmp.html", "w");		
	if( !f ) 
	{
		AfxMessageBox("Невозможно открыть файл для сохранения отчета");
		return -1;
	}
	int err = 0;
	char ccc[15120] = "";
	ExecSQL(cQ);
	if( g_sqlret != SQL_ERROR )
	{
//		g_sqlret = DBW.Fetch();
		for( int i = 0; i < 5256 && (g_sqlret = DBW.Fetch())!= SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
		{
			DBW.GetData(1, SQL_C_CHAR, ccc, 15120, &Ind);
			fprintf(f, "%s\r\n", ccc);
		}
	} else
		err = -1;
	DBW.CloseCursor();
	DBW.ReallocHandle();
	fclose(f);
	if( !err ) ShellExecute(NULL, "open", "html\\tmp.html", NULL, NULL, SW_SHOWNORMAL);

	return err;
}
CString CDBWire::GetTKPNameByID(DWORD dwITKP)
{
	long    Ind = 0;
    DWORD   dwNum = 0;
    char    cText[32] = "";
    ExecSQL("pTov_GetTKP");
    for( int i=0; (sqlret = Fetch()) != SQL_NO_DATA && sqlret != SQL_ERROR; i++ )
    {
        GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
        GetData(2, SQL_C_CHAR, cText, 32, &Ind);
		if( dwNum == dwITKP )
		{
			CloseCursor();  
			return (CString) cText;
		}
    }
    CloseCursor();  
	return (CString)"";
}

int CDBWire::GetGlobalOption(CString OptionName, CString *strValue)
{
//    if( !Value ) return -1;
    CString cQ;
	char cText[256] = "";
    long Ind = 0;
    cQ.Format("pTov_GetOption '%s'", OptionName);
    ExecSQL(cQ);
    g_sqlret = Fetch();
    GetData(1, SQL_C_CHAR, cText, 256, &Ind);
    CloseCursor();
    if( g_sqlret == SQL_NO_DATA ) return 0;
    if( g_sqlret == SQL_ERROR ) return -1;
	*strValue = cText;
    return 1;
}
extern cd_TeleI teleObj;	
extern cd_TeleI *tele;
extern CString g_strReserveServer;
extern void Shuffle(char* pcSeq);
extern int g_iEnableReserve;

int CDBWire::ExecSQLRzv(char * cQ)
{
//	DBW.WriteLog(cQ);
	if( !tele || g_strReserveServer == "" ) return -1;
	if( !g_iEnableReserve ) return 1;
	DBW.WriteLog("rez");
	DBW.WriteLog(cQ);
	Shuffle(cQ);
	CString strScript;
	strScript.Format("(:4936 %d 4624\r\n[%s]:)", g_iFam, cQ);

	tele->SendMessageDst(strScript, &g_strReserveServer);

	return 0;
}
