// DlgZapressKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgZapressKP.h"
#include "DlgSprav1.h"
#include "DlgSpravKdr.h"
#include ".\dlgzapresskp.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgZapressKP dialog


CDlgZapressKP::CDlgZapressKP(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgZapressKP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgZapressKP)
	//}}AFX_DATA_INIT
     dOS_PODST1 = 0;
     dOS_PODST2 = 0;
     dDSK1 = 0;
     dDSK2 = 0;
     iTSK1 = 0;
     iTSK2 = 0;
     iDLSK1 = 0;
     iDLSK2 = 0;
     dNZapr1 = 0;
     dNZapr2 = 0;
     iUZapr1 = 0;
     iUZapr2 = 0;


    dwIPR_IzOs = 0;
    dwIPR_R = 0;
    dwIPR_L = 0;
    dwPriznRas = 0;
    dwGruz = 0;
    m_d1.QInit(32);
    m_d2.QInit(32);
    m_d3.QInit(32);
    m_d4.QInit(32);
    m_d5.QInit(20);
    m_d6.QInit(20);
    m_d7.QInit(30);
    m_d8.QInit(30);
    m_d9.QInit(32);
    m_d10.QInit(32);
    m_d11.QInit(30);
    m_d12.QInit(30);
    m_EdNWheel_R.QInit(80);
    m_EdNWheel_L.QInit(80);
    m_EdYear_R.QInit(40);
    m_EdYear_L.QInit(40);
    m_EdNDiag.QInit(50);
    m_EdNpos.QInit(80);
    m_EdNPWheel_R.QInit(60);
    m_EdNPWheel_L.QInit(60);
    iUpdate = 0;

}


void CDlgZapressKP::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgZapressKP)
	DDX_Control(pDX, IDC_EDIT2, m_EdType);
	DDX_Control(pDX, IDC_EDIT1, m_EdNum);
	DDX_Control(pDX, IDC_CHECK3, m_Check2);
	DDX_Control(pDX, IDC_CHECK2, m_Check1);
	DDX_Control(pDX, IDC_EDIT12, m_EdNPWheel_L);
	DDX_Control(pDX, IDC_EDIT11, m_EdNPWheel_R);
	DDX_Control(pDX, IDC_EDIT8, m_EdNpos);
	DDX_Control(pDX, IDC_EDIT5, m_EdNDiag);
	DDX_Control(pDX, IDC_EDIT14, m_EdYear_L);
	DDX_Control(pDX, IDC_EDIT13, m_EdYear_R);
	DDX_Control(pDX, IDC_EDIT10, m_EdNWheel_L);
	DDX_Control(pDX, IDC_EDIT9, m_EdNWheel_R);
	DDX_Control(pDX, IDC_EDIT28, m_d12);
	DDX_Control(pDX, IDC_EDIT27, m_d11);
	DDX_Control(pDX, IDC_EDIT26, m_d10);
	DDX_Control(pDX, IDC_EDIT25, m_d9);
	DDX_Control(pDX, IDC_EDIT34, m_d8);
	DDX_Control(pDX, IDC_EDIT31, m_d7);
	DDX_Control(pDX, IDC_EDIT33, m_d6);
	DDX_Control(pDX, IDC_EDIT30, m_d5);
	DDX_Control(pDX, IDC_EDIT32, m_d4);
	DDX_Control(pDX, IDC_EDIT29, m_d3);
	DDX_Control(pDX, IDC_EDIT24, m_d2);
	DDX_Control(pDX, IDC_EDIT23, m_d1);
	DDX_Control(pDX, IDC_EDIT36, m_FIO2);
	DDX_Control(pDX, IDC_EDIT35, m_FIO1);
	DDX_Control(pDX, IDC_EDIT18, m_EdPrName_L);
	DDX_Control(pDX, IDC_EDIT16, m_EdKlPr_L);
	DDX_Control(pDX, IDC_EDIT17, m_EdPrName_R);
	DDX_Control(pDX, IDC_EDIT15, m_EdKlPr_R);
	DDX_Control(pDX, IDC_EDIT7, m_EdKlPr1);
	DDX_Control(pDX, IDC_EDIT6, m_Dat2);
	DDX_Control(pDX, IDC_EDIT4, m_Dat1);
	//}}AFX_DATA_MAP m_EdParkNum
	DDX_Control(pDX, IDC_EDIT38, m_EdParkNum);
	DDX_Control(pDX, IDC_EDIT3, m_DatRasfor);
	DDX_Control(pDX, IDC_EDIT37, m_EdFamRasfor);
	DDX_Control(pDX, IDC_BUTTON6, m_ButSles);
	DDX_Control(pDX, IDC_STATIC1, m_Lab1);
	DDX_Control(pDX, IDC_STATIC2, m_Lab2);
	DDX_Control(pDX, IDC_CHECK22, m_CheckT);
}


BEGIN_MESSAGE_MAP(CDlgZapressKP, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgZapressKP)
	ON_BN_CLICKED(IDC_BUTTON1, OnButPr1)
	ON_EN_KILLFOCUS(IDC_EDIT7, OnKillfocusEdKlPr1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonKlPr_R)
	ON_BN_CLICKED(IDC_BUTTON3, OnButtonKlPr_L)
	ON_EN_KILLFOCUS(IDC_EDIT15, OnKillfocusEdiKlPr_R)
	ON_EN_KILLFOCUS(IDC_EDIT16, OnKillfocusEdiKlPr_L)
	ON_BN_CLICKED(IDC_BUTTON4, OnButtonFIO1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButtonFIO2)
	ON_EN_CHANGE(IDC_EDIT23, OnChangeEdit_d1)
	ON_EN_CHANGE(IDC_EDIT29, OnChangeEdit_d3)
	ON_EN_CHANGE(IDC_EDIT24, OnChangeEdit_d2)
	ON_EN_CHANGE(IDC_EDIT32, OnChangeEdit_d4)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON6, OnBnClickedButton6)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK22, OnBnClickedCheck22)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgZapressKP message handlers

void CDlgZapressKP::OnButPr1() 
{
    CDlgSprav1 Dlg;
    if(Dlg.DoModal() == IDCANCEL) return;
    dwIPR_IzOs = Dlg.ret_dwIPR;
    m_EdKlPr1.SetWindowText(Dlg.cKodPr);

}

BOOL CDlgZapressKP::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
    m_Dat1.SetMode(1);
    m_Dat2.SetMode(3);
	m_EdParkNum.QInit(60, 1);
    m_FIO1.SetMode(5);
    m_FIO2.SetMode(5);
    DBW.FillEmplArray(m_FIO1.lpEmpl, 11);
    DBW.FillEmplArray(m_FIO2.lpEmpl, 12);

	m_EdFamRasfor.SetMode(5);
	DBW.FillEmplArray(m_EdFamRasfor.lpEmpl, 41);
	m_DatRasfor.SetMode(1);

    m_d9.ModifyStyle(0, WS_DISABLED);
    m_d10.ModifyStyle(0, WS_DISABLED);
    FillFormFields();

    char cQ[255] = "";
    long Ind = 0;
    sprintf(cQ, "pTov_GetDopuskZapress %u, %u", dwTKP, dwTypeRem);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR )
    {
        DBW.GetData(1, SQL_C_DOUBLE, &dOS_PODST1, sizeof(double), &Ind);
        DBW.GetData(2, SQL_C_DOUBLE, &dOS_PODST2, sizeof(double), &Ind);
        DBW.GetData(3, SQL_C_DOUBLE, &dDSK1, sizeof(double), &Ind);
        DBW.GetData(4, SQL_C_DOUBLE, &dDSK2, sizeof(double), &Ind);
        DBW.GetData(5, SQL_C_SLONG, &iTSK1, sizeof(int), &Ind);
        DBW.GetData(6, SQL_C_SLONG, &iTSK2, sizeof(int), &Ind);
        DBW.GetData(7, SQL_C_SLONG, &iDLSK1, sizeof(int), &Ind);
        DBW.GetData(8, SQL_C_SLONG, &iDLSK2, sizeof(int), &Ind);
        DBW.GetData(9, SQL_C_DOUBLE, &dNZapr1, sizeof(double), &Ind);
        DBW.GetData(10, SQL_C_DOUBLE, &dNZapr2, sizeof(double), &Ind);
        DBW.GetData(11, SQL_C_SLONG, &iUZapr1, sizeof(int), &Ind);
        DBW.GetData(12, SQL_C_SLONG, &iUZapr1, sizeof(int), &Ind);        
    }
    DBW.CloseCursor();
    m_EdNum.SetWindowText(strNum);
    m_EdType.SetWindowText(strType);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgZapressKP::OnKillfocusEdKlPr1() 
{
    CString str;
    m_EdKlPr1.GetWindowText(str);
    if( str == "" )
    {
        dwIPR_IzOs = 0;
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwIPR_IzOs, 4, &Ind);
/*    DBW.GetData( 2, SQL_C_CHAR, cText, 32, &Ind);
    DBW.GetData( 4, SQL_C_BIT, &lbCanForm, 1, &Ind);*/
    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        MessageBox("Введено некорректное клеймо предприятия изготовления оси!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdKlPr1.SetWindowText("");
		m_EdKlPr1.SetFocus();
        return;        
    }
//    m_Picker3.SetFocus();	
}

void CDlgZapressKP::OnButtonKlPr_R() 
{
    CDlgSprav1 Dlg;
    if(Dlg.DoModal() == IDCANCEL) return;
    dwIPR_R = Dlg.ret_dwIPR;
    m_EdKlPr_R.SetWindowText(Dlg.cKodPr);
    m_EdPrName_R.SetWindowText(Dlg.cPrName);
}

void CDlgZapressKP::OnButtonKlPr_L() 
{
    CDlgSprav1 Dlg;
    if(Dlg.DoModal() == IDCANCEL) return;
    dwIPR_L = Dlg.ret_dwIPR;
    m_EdKlPr_L.SetWindowText(Dlg.cKodPr);
    m_EdPrName_L.SetWindowText(Dlg.cPrName);
}

void CDlgZapressKP::OnKillfocusEdiKlPr_R() 
{
    CString str;
    m_EdKlPr_R.GetWindowText(str);
    if( str == "" )
    {
        dwIPR_R = 0;
        return;
    }
    char cText[255] = "";
    char cQ[128] = "";
    long Ind = 0;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwIPR_R, 4, &Ind);
    DBW.GetData( 7, SQL_C_CHAR, cText, 254, &Ind);
/*    DBW.GetData( 4, SQL_C_BIT, &lbCanForm, 1, &Ind);*/
    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        MessageBox("Введено некорректное клеймо предприятия изготовителя правого колеса!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdKlPr_R.SetWindowText("");
        m_EdPrName_R.SetWindowText("");
		m_EdKlPr_R.SetFocus();
        return;        
    }
    m_EdPrName_R.SetWindowText(cText);
}

void CDlgZapressKP::OnKillfocusEdiKlPr_L() 
{
    CString str;
    m_EdKlPr_L.GetWindowText(str);
    if( str == "" )
    {
        dwIPR_L = 0;
        return;
    }
    char cText[255] = "";
    char cQ[128] = "";
    long Ind = 0;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwIPR_L, 4, &Ind);
    DBW.GetData( 7, SQL_C_CHAR, cText, 254, &Ind);
/*    DBW.GetData( 4, SQL_C_BIT, &lbCanForm, 1, &Ind);*/
    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        MessageBox("Введено некорректное клеймо предприятия изготовителя левого колеса!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdKlPr_L.SetWindowText("");
        m_EdPrName_L.SetWindowText("");
		m_EdKlPr_L.SetFocus();
        return;
    }
    m_EdPrName_L.SetWindowText(cText);
}

void CDlgZapressKP::OnButtonFIO1() 
{
    CDlgSpravKdr Dlg;
    Dlg.iFilter = 11;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_FIO1.SetFamTextByID(Dlg.dwFio);
}

void CDlgZapressKP::OnButtonFIO2() 
{
    CDlgSpravKdr Dlg;
    Dlg.iFilter = 12;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_FIO2.SetFamTextByID(Dlg.dwFio);
}

int CDlgZapressKP::CheckLimits()
{
    CString mess;
    if( dOS_PODST1 && !m_d1.isNull() && dOS_PODST1 > m_d1.GetAsDouble() )
    {
        mess.Format("Правый диаметр подступичной части оси меньше минимально допустимого (%f)!", dOS_PODST1);
        AfxMessageBox(mess);
        m_d1.SetFocus();
        return -1;
    }
    if( dOS_PODST2 && !m_d1.isNull() && dOS_PODST2 < m_d1.GetAsDouble() )
    {
        mess.Format("Правый диаметр подступичной части оси больше максимально допустимого (%f)!", dOS_PODST2);
        AfxMessageBox(mess);
        m_d1.SetFocus();
        return -1;
    }
    if( dOS_PODST1 && !m_d2.isNull() && dOS_PODST1 > m_d2.GetAsDouble() )
    {
        mess.Format("Левый диаметр подступичной части оси меньше минимально допустимого (%f)!", dOS_PODST1);
        AfxMessageBox(mess);
        m_d2.SetFocus();
        return -1;
    }
    if( dOS_PODST2 && !m_d2.isNull() && dOS_PODST2 < m_d2.GetAsDouble() )
    {
        mess.Format("Левый диаметр подступичной части оси больше максимально допустимого (%f)!", dOS_PODST2);
        AfxMessageBox(mess);
        m_d2.SetFocus();
        return -1;
    }
// Размеры ступицы колеса

    //Диаметр
    if( dDSK1 && !m_d3.isNull() && dDSK1 > m_d3.GetAsDouble() )
    {
        mess.Format("Правый диаметр ступицы оси меньше минимально допустимого (%f)!", dDSK1);
        AfxMessageBox(mess);
        m_d3.SetFocus();
        return -1;
    }
    if( dDSK2 && !m_d3.isNull() && dDSK2 < m_d3.GetAsDouble() )
    {
        mess.Format("Правый диаметр ступицы оси больше максимально допустимого (%f)!", dDSK2);
        AfxMessageBox(mess);
        m_d3.SetFocus();
        return -1;
    }
    if( dDSK1 && !m_d4.isNull() && dDSK1 > m_d4.GetAsDouble() )
    {
        mess.Format("Левый диаметр ступицы оси меньше минимально допустимого (%f)!", dDSK1);
        AfxMessageBox(mess);
        m_d4.SetFocus();
        return -1;
    }
    if( dDSK2 && !m_d4.isNull() && dDSK2 < m_d4.GetAsDouble() )
    {
        mess.Format("Левый диаметр ступицы оси больше максимально допустимого (%f)!", dDSK2);
        AfxMessageBox(mess);
        m_d4.SetFocus();
        return -1;
    }
    //Толщина
    if( iTSK1 && !m_d5.isNull() && iTSK1 > m_d5.GetAsDouble() )
    {
        mess.Format("Толщина ступицы правой части оси меньше минимально допустимого (%d)!", iTSK1);
        AfxMessageBox(mess);
        m_d5.SetFocus();
        return -1;
    }
    if( iTSK2 && !m_d5.isNull() && iTSK2 < m_d5.GetAsDouble() )
    {
        mess.Format("Толщина ступицы правой части оси больше максимально допустимого (%d)!", iTSK2);
        AfxMessageBox(mess);
        m_d5.SetFocus();
        return -1;
    }
    if( iTSK1 && !m_d6.isNull() && iTSK1 > m_d6.GetAsDouble() )
    {
        mess.Format("Толщина ступицы левой части оси меньше минимально допустимого (%d)!", iTSK1);
        AfxMessageBox(mess);
        m_d6.SetFocus();
        return -1;
    }
    if( iTSK2 && !m_d6.isNull() && iTSK2 < m_d6.GetAsDouble() )
    {
        mess.Format("Толщина ступицы левой части оси больше максимально допустимого (%d)!", iTSK2);
        AfxMessageBox(mess);
        m_d6.SetFocus();
        return -1;
    }
    // Длина
    if( iDLSK1 && !m_d7.isNull() && iDLSK1 > m_d7.GetAsDouble() )
    {
        mess.Format("Длина ступицы правой части оси меньше минимально допустимого (%d)!", iDLSK1);
        AfxMessageBox(mess);
        m_d7.SetFocus();
        return -1;
    }
    if( iDLSK2 && !m_d7.isNull() && iDLSK2 < m_d7.GetAsDouble() )
    {
        mess.Format("Длина ступицы правой части оси больше максимально допустимого (%d)!", iDLSK2);
        AfxMessageBox(mess);
        m_d7.SetFocus();
        return -1;
    }
    if( iDLSK1 && !m_d8.isNull() && iDLSK1 > m_d8.GetAsDouble() )
    {
        mess.Format("Длина ступицы левой части оси меньше минимально допустимого (%d)!", iDLSK1);
        AfxMessageBox(mess);
        m_d8.SetFocus();
        return -1;
    }
    if( iDLSK2 && !m_d8.isNull() && iDLSK2 < m_d8.GetAsDouble() )
    {
        mess.Format("Длина ступицы левой части оси больше максимально допустимого (%d)!", iDLSK2);
        AfxMessageBox(mess);
        m_d8.SetFocus();
        return -1;
    }
    // Натяг
    if( dNZapr1 && !m_d9.isNull() && dNZapr1 > m_d9.GetAsDouble() )
    {
        mess.Format("Натяг правой части оси меньше минимально допустимого (%f)!", dNZapr1);
        AfxMessageBox(mess);
        m_d9.SetFocus();
        return -1;
    }
    if( dNZapr2 && !m_d9.isNull() && dNZapr2 < m_d9.GetAsDouble() )
    {
        mess.Format("Натяг правой части оси больше максимально допустимого (%f)!", dNZapr2);
        AfxMessageBox(mess);
        m_d9.SetFocus();
        return -1;
    }
    if( dNZapr1 && !m_d10.isNull() && dNZapr1 > m_d10.GetAsDouble() )
    {
        mess.Format("Натяг левой части оси меньше минимально допустимого (%f)!", dNZapr1);
        AfxMessageBox(mess);
        m_d10.SetFocus();
        return -1;
    }
    if( dNZapr2 && !m_d10.isNull() && dNZapr2 < m_d10.GetAsDouble() )
    {
        mess.Format("Натяг левой части оси больше максимально допустимого (%f)!", dNZapr2);
        AfxMessageBox(mess);
        m_d10.SetFocus();
        return -1;
    }
    // Усилие запрессовки
    if( iUZapr1 && !m_d11.isNull() && iUZapr1 > m_d11.GetAsDouble() )
    {
        mess.Format("Усилие запрессовки правой части оси меньше минимально допустимого (%d)!", iUZapr1);
        AfxMessageBox(mess);
        m_d11.SetFocus();
        return -1;
    }
    if( iUZapr2 && !m_d11.isNull() && iUZapr2 < m_d11.GetAsDouble() )
    {
        mess.Format("Усилие запрессовки правой части оси больше максимально допустимого (%d)!", iUZapr2);
        AfxMessageBox(mess);
        m_d11.SetFocus();
        return -1;
    }
    if( iUZapr1 && !m_d12.isNull() && iUZapr1 > m_d12.GetAsDouble() )
    {
        mess.Format("Усилие запрессовки левой части оси меньше минимально допустимого (%d)!", iUZapr1);
        AfxMessageBox(mess);
        m_d12.SetFocus();
        return -1;
    }
    if( iUZapr2 && !m_d12.isNull() && iUZapr2 < m_d12.GetAsDouble() )
    {
        mess.Format("Усилие запрессовки левой части оси больше максимально допустимого (%d)!", iUZapr2);
        AfxMessageBox(mess);
        m_d12.SetFocus();
        return -1;
    }
    return 0;
}

void CDlgZapressKP::OnOK() 
{
    CString str;
    if( m_Dat1.isNull() )
    {
        MessageBox("Необходимо указать дату формирования!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !m_EdNDiag.GetWindowTextLength() )
    {
        MessageBox("Необходимо указать номер диаграммы!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( m_Dat1.isNull() )
    {
        MessageBox("Необходимо указать дату изготовления оси!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !dwIPR_IzOs )
    {
        MessageBox("Необходимо указать клеймо предприятия!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !m_EdNWheel_R.GetWindowTextLength() && !m_Check1.GetCheck())
    {
        MessageBox("Необходимо указать номер правого колеса!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !m_EdNWheel_L.GetWindowTextLength() && !m_Check2.GetCheck())
    {
        MessageBox("Необходимо указать номер левого колеса!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !m_EdYear_R.GetWindowTextLength() && !m_Check1.GetCheck())
    {
        MessageBox("Необходимо указать год изготовления правого колеса!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !m_EdYear_L.GetWindowTextLength() && !m_Check2.GetCheck())
    {
        MessageBox("Необходимо указать год изготовления левого колеса!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !dwIPR_R && !m_Check1.GetCheck())
    {
        MessageBox("Необходимо указать завод изготовитель правого колеса!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !dwIPR_L && !m_Check2.GetCheck())
    {
        MessageBox("Необходимо указать завод изготовитель левого колеса!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !m_FIO1.GetData() )
    {
        MessageBox("Необходимо указать фамилию мастера!","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
	
	char cText[64] = "";
	m_d9.GetWindowText(cText, 64);
	double fl = atof(cText);
	if( fl > 999.99 || fl * 100 > 99999 )
	{
		AfxMessageBox("Недопустимое значение натяга запрессовки!");
		m_d9.SetFocus();
		return;
	}
	m_d10.GetWindowText(cText, 64);
	fl = atof(cText);
	if( fl > 999.99 || fl * 100 > 99999 )
	{
		AfxMessageBox("Недопустимое значение натяга запрессовки!");
		m_d10.SetFocus();
		return;
	}
    if(  CheckLimits() ) return;
//    char d1[16], d2[16], d3[16], d4[16], d5[16], d6[16], d7[16], d8[16], d9[16], d10[16], d11[16], d12[16];
    char cQ[512] = "";
    CString s1, s2;
    if( !m_EdYear_R.isNull() )
        s1.Format("'%s0101'", m_EdYear_R.GetString());
    else s1 = "NULL";
    if(!m_EdYear_R.isNull() )
        s2.Format("'%s0101'", m_EdYear_L.GetString());
    else s2 = "NULL";
    sprintf(cQ, "pTov_ZapressKP %I64u, %I64u, %s, %s, %s, %u, %s, %s, %s, %s, %u, %u, %s, %s, %s, %u, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %u, %u, %s, %s, %d, %s",
        qwIZAP, qwIKP,
        m_Dat1.GetSQLDate(),
        m_EdNDiag.GetString(TRUE),
        m_Dat2.GetSQLDate(),
        dwIPR_IzOs,
        m_EdNpos.GetString(TRUE),
        m_EdNWheel_R.GetString(TRUE),
        m_EdNPWheel_R.GetString(TRUE),
        s1,
        m_Check1.GetCheck(),
        dwIPR_R,
        m_EdNWheel_L.GetString(TRUE),
        m_EdNPWheel_L.GetString(TRUE),
        s2,
        m_Check2.GetCheck(),
        dwIPR_L,
        m_d1.GetAsString(),
        m_d3.GetAsString(),
        m_d5.GetAsString(),
        m_d7.GetAsString(),
        m_d9.GetAsString(), //22
        m_d11.GetAsString(),
        m_d2.GetAsString(),
        m_d4.GetAsString(),
        m_d6.GetAsString(),
        m_d8.GetAsString(),
        m_d10.GetAsString(), //28
        m_d12.GetAsString(),
        m_FIO1.GetDataAsString(TRUE),
        m_FIO2.GetDataAsString(TRUE),
        dwPriznRas,
        dwGruz,
        iUpdate,
		m_DatRasfor.GetSQLDate(),
		isNull(m_EdFamRasfor.GetData()),
		m_CheckT.GetCheck(),
		isNull(m_EdParkNum.GetAsString())
		);
    long Ind = 0;
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    DBW.GetData(1, SQL_C_ULONG, &dwPriznRas, 4, &Ind);
    DBW.GetData(2, SQL_C_ULONG, &dwGruz, 4, &Ind);
    DBW.CloseCursor();

	CDlgWithAccelerators::OnOK();
}

void CDlgZapressKP::FillFormFields()
{
    char cQ[255] = "";
    sprintf(cQ, "pTov_GetZapressKP %I64u, %I64u", qwIZAP, qwIKP);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA || g_sqlret == SQL_NO_DATA )
    {
        iUpdate = 0;
        DBW.CloseCursor();
        return;
    }    
    long Ind = 0;
    SQL_DATE_STRUCT  sqlDat;
    SYSTEMTIME st;
    DWORD   dwNum = 0;
    double  dNum = 0;
    char cText[64] = "";

    DBW.GetData(1, SQL_C_DATE, &sqlDat, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        m_Dat2.SetTime(&st);
    }
    DBW.GetData(2, SQL_C_ULONG, &dwIPR_IzOs, 4, &Ind);
    DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
        m_EdKlPr1.SetWindowText(cText);

    DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
        m_EdNpos.SetWindowText(cText);

	DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
        if( strcmp(cText, "0") != 0 ) m_EdParkNum.SetWindowText(cText);
//-----
    DBW.GetData(6, SQL_C_DATE, &sqlDat, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        m_Dat1.SetTime(&st);
//        iUpdate = 1;
    }

    DBW.GetData(7, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( Ind != -1 )
    {
        ultoa(dwNum, cText, 10);
        m_EdNDiag.SetWindowText(cText);
//        iUpdate = 1;
    }

    //Wheel right
    DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
    {
        m_EdNWheel_R.SetWindowText(cText);        
//        iUpdate = 1;
    }
    DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
    {
        m_EdNPWheel_R.SetWindowText(cText);        
//        iUpdate = 1;
    }
    DBW.GetData(10, SQL_C_DATE, &sqlDat, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        m_EdYear_R.SetWindowText(isNull(st.wYear));
//        iUpdate = 1;
    }
    DBW.GetData(11, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        m_Check1.SetCheck(dwNum);
//        iUpdate = 1;
    }

    DBW.GetData(12, SQL_C_ULONG, &dwIPR_R, 4, &Ind);
    DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
    {
        m_EdKlPr_R.SetWindowText(cText);        
    }
    DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
    {
        m_EdPrName_R.SetWindowText(cText);        
    }

    //Wheel left
    DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
    {
        m_EdNWheel_L.SetWindowText(cText);        
    }
    DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
    {
        m_EdNPWheel_L.SetWindowText(cText);        
    }
    DBW.GetData(17, SQL_C_DATE, &sqlDat, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        m_EdYear_L.SetWindowText(isNull(st.wYear));
    }
    DBW.GetData(18, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Check2.SetCheck(dwNum);

    DBW.GetData(19, SQL_C_ULONG, &dwIPR_L, 4, &Ind);
    DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
    {
        m_EdKlPr_L.SetWindowText(cText);        
    }
    DBW.GetData(21, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
    {
        m_EdPrName_L.SetWindowText(cText);        
    }

    DBW.GetData(22, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind );
    if( Ind != -1 )
    {
        m_d1.SetValue(dNum);
    }
    DBW.GetData(23, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind );
    if( Ind != -1 )
    {
        m_d3.SetValue(dNum);
    }
    DBW.GetData(24, SQL_C_ULONG, &dwNum, 4, &Ind );
    if( Ind != -1 )
    {
        m_d5.SetValue(dwNum);
    }
    DBW.GetData(25, SQL_C_ULONG, &dwNum, 4, &Ind );
    if( Ind != -1 )
    {
        m_d7.SetValue(dwNum);
    }
    DBW.GetData(26, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind );
    if( Ind != -1 )
    {
        m_d9.SetValue(dNum);
    }
    DBW.GetData(27, SQL_C_ULONG, &dwNum, 4, &Ind );
    if( Ind != -1 )
    {
        m_d11.SetValue(dwNum);
    }
    DBW.GetData(28, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind );
    if( Ind != -1 )
    {
        m_d2.SetValue(dNum);
    }
    DBW.GetData(29, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind );
    if( Ind != -1 )
    {
        m_d4.SetValue(dNum);
    }
    DBW.GetData(30, SQL_C_ULONG, &dwNum, 4, &Ind );
    if( Ind != -1 )
    {
        m_d6.SetValue(dwNum);
    }
    DBW.GetData(31, SQL_C_ULONG, &dwNum, 4, &Ind );
    if( Ind != -1 )
    {
        m_d8.SetValue(dwNum);
    }
    DBW.GetData(32, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind );
    if( Ind != -1 )
    {
        m_d10.SetValue(dNum);
    }
    DBW.GetData(33, SQL_C_ULONG, &dwNum, 4, &Ind );
    if( Ind != -1 )
    {
        m_d12.SetValue(dwNum);
    }
    DBW.GetData(34, SQL_C_ULONG, &dwNum, 4, &Ind );
    if( Ind != -1 )
    {
        m_FIO1.SetData(dwNum);
        cText[0] = 0;
        DBW.GetData(35, SQL_C_CHAR, cText, 64, &Ind );
        m_FIO1.SetWindowText(cText);
    }
    DBW.GetData(36, SQL_C_ULONG, &dwNum, 4, &Ind );
    if( Ind != -1 )
    {
        m_FIO2.SetData(dwNum);
        cText[0] = 0;
        DBW.GetData(37, SQL_C_CHAR, cText, 64, &Ind );
        m_FIO2.SetWindowText(cText);
    }
//	SYSTEMTIME st;
	mgSQLGetSysDate(38, &st, &Ind);
	if( Ind != -1 ) m_DatRasfor.SetTime(&st);
	DBW.GetData(39, SQL_C_ULONG, &dwNum, 4, &Ind );
    if( Ind != -1 )
    {
        m_EdFamRasfor.SetData(dwNum);
        cText[0] = 0;
        DBW.GetData(40, SQL_C_CHAR, cText, 64, &Ind );
        m_EdFamRasfor.SetWindowText(cText);
    }
	DBW.GetData(41, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 && !dwNum)
	{
			m_ButSles.EnableWindow(FALSE);
			m_Lab1.EnableWindow(FALSE);
			m_Lab2.EnableWindow(FALSE);
			m_DatRasfor.EnableWindow(FALSE);
			m_EdFamRasfor.EnableWindow(FALSE);
	}
	DBW.GetData(42, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		m_CheckT.SetCheck(dwNum);
	}


    DBW.CloseCursor();
    
}

void CDlgZapressKP::OnChangeEdit_d1() 
{
    m_d9.SetValue(m_d1.GetAsDouble() - m_d3.GetAsDouble());
}

void CDlgZapressKP::OnChangeEdit_d3() 
{
    m_d9.SetValue(m_d1.GetAsDouble() - m_d3.GetAsDouble());
}

void CDlgZapressKP::OnChangeEdit_d2() 
{
    m_d10.SetValue(m_d2.GetAsDouble() - m_d4.GetAsDouble());
}

void CDlgZapressKP::OnChangeEdit_d4() 
{
    m_d10.SetValue(m_d2.GetAsDouble() - m_d4.GetAsDouble());
}

void CDlgZapressKP::OnBnClickedButton6()
{
    CDlgSpravKdr Dlg;
    Dlg.iFilter = 41;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFamRasfor.SetFamTextByID(Dlg.dwFio);
}

void CDlgZapressKP::OnBnClickedOk()
{
	OnOK();
}

void CDlgZapressKP::OnBnClickedCheck22()
{
	// TODO: Add your control notification handler code here
}
