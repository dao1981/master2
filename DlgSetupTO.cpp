// DlgSetupTO.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSetupTO.h"
#include ".\dlgsetupto.h"
#include <string>


// CDlgSetupTO dialog

extern char cConfigFileName[];
extern int g_iEnableTelecom;
extern CString g_conf_strMessagePath;
extern CString g_conf_strMessageReturnPath;
extern CString g_conf_strMessageUnprocessedPath;
extern int g_iStandAlone;
extern CMasterApp theApp;
IMPLEMENT_DYNAMIC(CDlgSetupTO, CDialog)
CDlgSetupTO::CDlgSetupTO(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetupTO::IDD, pParent)
{
}

CDlgSetupTO::~CDlgSetupTO()
{
}

void CDlgSetupTO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_EDIT1, m_EdName1);
	DDX_Control(pDX, IDC_EDIT7, m_EdName2);
	DDX_Control(pDX, IDC_EDIT8, m_EdName3);
	DDX_Control(pDX, IDC_EDIT2, m_EdAuto1);
	DDX_Control(pDX, IDC_EDIT5, m_EdAuto2);
	DDX_Control(pDX, IDC_EDIT9, m_EdAuto3);
	DDX_Control(pDX, IDC_EDIT4, m_EdAddr1);
	DDX_Control(pDX, IDC_EDIT93, m_EdAddr2);
	DDX_Control(pDX, IDC_EDIT123, m_EdAddr3);
	DDX_Control(pDX, IDC_EDIT120, m_EdPort1);
	DDX_Control(pDX, IDC_EDIT146, m_EdPort2);
	DDX_Control(pDX, IDC_EDIT152, m_EdPort3);
	DDX_Control(pDX, IDC_EDIT3, m_EdPathSnd);
	DDX_Control(pDX, IDC_EDIT116, m_EdPathRcv);
	DDX_Control(pDX, IDC_EDIT74, m_EdPathBad);
	DDX_Control(pDX, IDC_CHECK2, m_Check2);
}


BEGIN_MESSAGE_MAP(CDlgSetupTO, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedCreateDir2)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedCreateDir3)
END_MESSAGE_MAP()


// CDlgSetupTO message handlers

BOOL CDlgSetupTO::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdName1.SetMode(0, 1, 15);
	m_EdName2.SetMode(0, 1, 15);
	m_EdName3.SetMode(0, 1, 15);

	m_EdAuto1.SetMode(0, 1, 20);
	m_EdAuto2.SetMode(0, 1, 20);
	m_EdAuto3.SetMode(0, 1, 20);

	m_EdAddr1.SetMode(0, 1, 20);
	m_EdAddr2.SetMode(0, 1, 20);
	m_EdAddr3.SetMode(0, 1, 20);

	m_EdPort1.QInit(50, 1);
	m_EdPort2.QInit(50, 1);
	m_EdPort3.QInit(50, 1);

	m_EdName2.SetWindowText("ASOUP");
//	m_EdPort1.SetWindowText("6002");
	
	ReadSetupFiles();

	if( g_iStandAlone )
	{
		m_Check2.SetCheck(1);		
	}
	m_Check2.EnableWindow(FALSE);

	m_EdPathRcv.SetMode(0, 1, 128);
	m_EdPathSnd.SetMode(0, 1, 128);
	m_EdPathBad.SetMode(0, 1, 128);

	m_EdPathRcv.SetWindowText(g_conf_strMessageReturnPath);
	m_EdPathSnd.SetWindowText(g_conf_strMessagePath);
	m_EdPathBad.SetWindowText(g_conf_strMessageUnprocessedPath);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

int SetServerProp (const char name[128], const char auto_ans[128], const char addr[16], const char port[6], char * filename, const char default_param[256], const char newname[128] = NULL);

void CDlgSetupTO::OnBnClickedOk()
{

	//if( m_Check1.GetCheck() )
	//{
	
		if( m_EdName1.GetAsString() == "NULL" )
		{
			AfxMessageBox("Не указано имя клиента АИС ХЧ!");
			m_EdName1.SetFocus();
			return;
		}
		if( m_EdName2.GetAsString() == "NULL" )
		{
			AfxMessageBox("Не указано имя сервера АСОУП!");
			m_EdName2.SetFocus();
			return;
		}
		if( m_EdName3.GetAsString() == "NULL" )
		{
			AfxMessageBox("Не указано имя сервера центральной ТО!");
			m_EdName2.SetFocus();
			return;
		}
		if( m_EdAddr1.GetAsString() == "NULL" )
		{
			AfxMessageBox("Не указан адрес клиента АИС ХЧ!");
			m_EdAddr1.SetFocus();
			return;
		}
		if( m_EdAddr2.GetAsString() == "NULL" )
		{
			AfxMessageBox("Не указан адрес сервера АСОУП!");
			m_EdAddr2.SetFocus();
			return;
		}
		if( m_EdAddr3.GetAsString() == "NULL" )
		{
			AfxMessageBox("Не указан адрес сервера центральной ТО!");
			m_EdAddr2.SetFocus();
			return;
		}
		if( m_EdPort1.isNull() )
		{
			AfxMessageBox("Не указан порт клиента АИС ХЧ!");
			m_EdPort1.SetFocus();
			return;
		}
		if( m_EdPort2.isNull() )
		{
			AfxMessageBox("Не указан порт сервера АСОУП!");
			m_EdPort2.SetFocus();
			return;
		}
		if( m_EdPort3.isNull() )
		{
			AfxMessageBox("Не указан порт сервера центральной ТО!");
			m_EdPort2.SetFocus();
			return;
		}
		if( m_EdAuto1.GetAsString() == "NULL" )
		{
			AfxMessageBox("Не указан автоответ клиента АИС ХЧ!");
			m_EdAuto1.SetFocus();
			return;
		}
		if( m_EdAuto2.GetAsString() == "NULL" )
		{
			AfxMessageBox("Не указан автоответ сервера АСОУП!");
			m_EdAuto2.SetFocus();
			return;
		}
		if( m_EdAuto3.GetAsString() == "NULL" )
		{
			AfxMessageBox("Не указан автоответ сервера центральной ТО!");
			m_EdAuto2.SetFocus();
			return;
		}
	//}
	if( m_Check2.GetCheck() )
	{
		if( m_EdPathSnd.isNull() )
		{
			AfxMessageBox("Необходимо указать путь для отправки сообщений!");
			m_EdPathSnd.SetFocus();
			return;
		}
		if( m_EdPathRcv.isNull() )
		{
			AfxMessageBox("Нобходимо указать путь для входящих сообщений!");
			m_EdPathRcv.SetFocus();
			return;
		}
		if( m_EdPathBad.isNull() )
		{
			AfxMessageBox("Нобходимо указать путь для необработанных сообщений!");
			m_EdPathBad.SetFocus();
			return;
		}			

		CString strTest = "";
		m_EdPathSnd.GetWindowText(strTest);
		FILE *f = fopen(strTest + "\\1.vvv", "w");
		if( !f )
		{
			AfxMessageBox("Путь для отправки сообщений указан не верно!\nВозможно указан несуществующий каталог.");
			m_EdPathSnd.SetFocus();
			return;
		} else
		{
			fclose(f);
			DeleteFile(strTest + "\\1.vvv");
		}

		m_EdPathRcv.GetWindowText(strTest);
		f = fopen(strTest + "\\1.vvv", "w");
		if( !f )
		{
			AfxMessageBox("Путь для входящих сообщений указан не верно!\nВозможно указан несуществующий каталог.");
			m_EdPathRcv.SetFocus();
			return;
		} else
		{
			fclose(f);
			DeleteFile(strTest + "\\1.vvv");
		}

		m_EdPathBad.GetWindowText(strTest);
		f = fopen(strTest + "\\1.vvv", "w");
		if( !f )
		{
			AfxMessageBox("Путь для необработанных сообщений указан не верно!\nВозможно указан несуществующий каталог.");
			m_EdPathBad.SetFocus();
			return;
		} else
		{
			fclose(f);
			DeleteFile(strTest + "\\1.vvv");
		}

	}

	/* запись user.net и setup.net */
	char cUserNet[5120] = "";
	char cSetupNet[512] = "";
//	if( m_Ed

	/*if( m_Check1.GetCheck() )
	{		

		sprintf(cSetupNet,"[TELE]\n\
TELEDIR=.\\tele\n\
USERSDIR=.\n\
STDP=Пост 10 3 20\
TELEAPI=* %s 20\n\
DefaultUser=%s", m_EdName1.GetString(), m_EdName2.GetString());


		sprintf(cUserNet, "%s %s 3 3 1 0 0 0 %s %s\n\
%s %s 0 1 1 0 0 0 %s %s", 
			m_EdName1.GetString(),
			m_EdAuto1.GetString(),
			m_EdAddr1.GetString(),
			m_EdPort1.GetString(),
			m_EdName2.GetString(),
			m_EdAuto2.GetString(),
			m_EdAddr2.GetString(),
			m_EdPort2.GetString());

		FILE *f = fopen("setup.net", "w");
		if( f ) 
		{
			fprintf(f, cSetupNet);
			fclose(f);
		}

		f = fopen("user.net", "w");
		if( f ) 
		{
			fprintf(f, cUserNet);
			fclose(f);
		}

	}*/

	char name[128];
		
	GetPrivateProfileString ("TELE", "TELEAPI", NULL, name, sizeof name, "./setup.net");

	int i;
	if (strlen (name) > 2)
	{
		strcpy (name, name + 2);
		for (i = 0; name[i] != ' ' && name[i] != 0; i++)
			;
		name[i] = 0;
	}

	WritePrivateProfileString ("TELE", "TELEAPI", "* " + m_EdName1.GetString () + ' ' + (name + i + 1), "./setup.net");

	SetServerProp (name,                   m_EdAuto1.GetString (), m_EdAddr1.GetString (), m_EdPort1.GetString (), "./user.net", "3 3 1 0 0 0", m_EdName1.GetString ());
	SetServerProp (m_EdName2.GetString (), m_EdAuto2.GetString (), m_EdAddr2.GetString (), m_EdPort2.GetString (), "./user.net", "0 1 1 0 0 0");
	SetServerProp (m_EdName3.GetString (), m_EdAuto3.GetString (), m_EdAddr3.GetString (), m_EdPort3.GetString (), "./user.net", "3 3 1 0 0 0");

	GetPrivateProfileString ("TELE", "TELEDIR", ".\\tele", name, sizeof name, "./setup.net");
	WritePrivateProfileString ("TELE", "TELEDIR", name, "./setup.net");

	GetPrivateProfileString ("TELE", "USERSDIR", ".", name, sizeof name, "./setup.net");
	WritePrivateProfileString ("TELE", "USERSDIR", name, "./setup.net");

	GetPrivateProfileString ("TELE", "STDP", "Пост 10 3 20", name, sizeof name, "./setup.net");
	WritePrivateProfileString ("TELE", "STDP", name, "./setup.net");

	GetPrivateProfileString ("TELE", "DefaultUser", m_EdName2.GetString (), name, sizeof name, "./setup.net");
	WritePrivateProfileString ("TELE", "DefaultUser", name, "./setup.net");

	if( m_Check1.GetCheck() )
		WritePrivateProfileString("ARM", "DisableTelecom", "0", cConfigFileName);
	else
		WritePrivateProfileString("ARM", "DisableTelecom", "1", cConfigFileName);
	
	WritePrivateProfileString("ARM", "ASOUPTeleName", m_EdName2.GetString(), cConfigFileName);
	WritePrivateProfileString("ARM", "TeleServer", m_EdName3.GetString(), cConfigFileName);

	/* Запись каталогов для сообщении*/
	m_EdPathSnd.GetWindowText(g_conf_strMessagePath);
	m_EdPathRcv.GetWindowText(g_conf_strMessageReturnPath);
	m_EdPathBad.GetWindowText(g_conf_strMessageUnprocessedPath);

	WritePrivateProfileString("ARM", "MsgPath", g_conf_strMessagePath, cConfigFileName);
	WritePrivateProfileString("ARM", "MsgReturnPath", g_conf_strMessageReturnPath, cConfigFileName);
	WritePrivateProfileString("ARM", "BadMsgPath", g_conf_strMessageUnprocessedPath, cConfigFileName);
	
	AfxMessageBox("Теперь необходимо перезапустить приложение!");
	OnOK();
}

int SetServerProp (const char name[128], const char auto_ans[128], const char addr[16], const char port[6], char * filename, const char default_param[256], const char newname[128])
{
	char cText[128] = "";
	char buffer[64 * 256 + 1], newbuffer[64 * 256 + 1];//предельный размер 64* 256 плюс один символ для упрощения алгоритма
	size_t size;
	FILE *f = fopen(filename, "r");
	if( f )
	{
		size = fread (buffer, sizeof (char), 64 * 256, f);
		fclose(f);
	}

	int i, j, k;
	char c;
	j = 0;
	do
	{
		for(i = 0, k = j; (c = buffer[j]) != ' ' && j < size; i++, j++)
		{
			if (i == 128)//Ошибка. Имя больше 127 символов
				return 1;
			cText[i] = c;
		}

		cText[i] = 0;

		if (strcmp (name, cText) != 0)
		{
			while( (c = buffer[j]) != '\n' && c != '\r' && j < size)
				j++;
			j++;
		}
	}
	while (strcmp (name, cText) != 0 && j < size);

	if (j < size)
	{
		if (k) memcpy (newbuffer, buffer, k);

		char *t = (char*)(newname ? newname : name);
		memcpy (newbuffer + k, t, strlen (t));
		k += strlen (t);
		newbuffer[k++] = ' ';

		memcpy (newbuffer + k, auto_ans, strlen (auto_ans));
		k += strlen (auto_ans);
		newbuffer[k++] = ' ';

		while( buffer[j] != '(' &&  j < size)
			j++;

		for( i=0; buffer[j] != ')' && j < size; i++, j++ )
		{
			if (i == 128)//Ошибка. Часть автоответа больше 127 символов
				return 1;
		}

		if (i == 128)//Ошибка. Часть автоответа в скобках больше 127 символов
			return 1;

		for(; buffer[j] != ' ' && j < size; i++, j++ )
		{
			if (i == 128)//Ошибка. Автоответ больше 127 символов
				return 1;
		}

		j++; 

		for(i = 0; i < 6 && j < size; j++) 
		{
			newbuffer[k++] = buffer[j];

			if( buffer[j] == ' ')
				i++;
		}

		j++;

		memcpy (newbuffer + k, addr, strlen (addr));
		k += strlen (addr);
		newbuffer[k++] = ' ';

		memcpy (newbuffer + k, port, strlen (port));
		k += strlen (port);

		for(i = 0; buffer[j] != ' ' && j < size; i++, j++ )
		{
			if (i == 16)//Ошибка. Адрес больше 15 символов
				return 1;
		}

		j++;

		for(i = 0; (c = buffer[j]) != ' ' && c != '\n' && c != '\r' && c != ';' && j < size; i++, j++)
		{
			if (i == 6)//Ошибка. Порт больше 5 символов
				return 1;
		}

		memcpy (newbuffer + k, buffer + j, size - j);
		k += size - j;
	}
	else
	{
		memcpy (newbuffer, buffer, size);
		newbuffer[size] = 0;
		std::string s = newbuffer;
		s += "\n";
		s += (char*)(newname ? newname : name);
		s += ' ';
		s += auto_ans;
		s += ' ';
		s += default_param;
		s += ' ';
		s += addr;
		s += ' ';
		s += port;
		k = strlen (s.c_str ());
		memcpy (newbuffer, s.c_str (), k);
	}

	f = fopen(filename, "w");
	if( f )
	{
		fwrite (newbuffer, sizeof (char), k, f);
		fclose(f);
	}

	return 0;
}

int GetServerProp (char name[128], char auto_ans[128], char addr[16], char port[6], char * filename)
{
	char cText[128] = "";
	FILE *f = fopen(filename, "r");
	if( f )
	{
		int i;
		char c;
		do
		{
			c = fgetc(f);
			for(i = 0; c != ' ' && !feof(f); i++)
			{
				if (i == 128)//Ошибка. Имя больше 127 символов
				{
					fclose(f);
					return 1;
				}
				cText[i] = c;
				c = fgetc(f);
			}
			cText[i] = 0;

			if (strcmp (name, cText) != 0)
			{
				while( c != '\n' && c != '\r' && !feof(f))
					c = fgetc(f);
			}
		}
		while (strcmp (name, cText) != 0 && !feof(f));

		while( c != '(' && !feof(f) )
			c = fgetc(f);

		for( i=0; c != ')' && !feof(f); i++ )
		{
			if (i == 128)//Ошибка. Часть автоответа больше 127 символов
			{
				fclose(f);
				return 1;
			}
			cText[i] = c;
			c = fgetc(f);
		}

		if (i == 128)//Ошибка. Часть автоответа в скобках больше 127 символов
		{
			fclose(f);
			return 1;
		}

		cText[i] = ')';

		for(; c != ' ' && !feof(f); i++ )
		{
			if (i == 128)//Ошибка. Автоответ больше 127 символов
			{
				fclose(f);
				return 1;
			}
			cText[i] = c;
			c = fgetc(f);
		}
		cText[i] = 0;

		strcpy (auto_ans, cText);

		for(i=0; i < 7 && !feof(f); c = fgetc(f)) 
		{
			if( c == ' ' ) i++;
		}
		

		for(i = 0; c!= ' ' && !feof(f); i++ )
		{
			if (i == 16)//Ошибка. Адрес больше 15 символов
			{
				fclose(f);
				return 1;
			}
			cText[i] = c;
			c = fgetc(f);
		}		
		cText[i] = 0;
		strcpy (addr, cText);

		c = fgetc(f);
		for(i = 0; c!= ' ' && c!= '\n' && c!= '\r' && c!= ';' && !feof(f); i++)
		{
			if (i == 6)//Ошибка. Порт больше 5 символов
			{
				fclose(f);
				return 1;
			}
			cText[i] = c;
			c = fgetc(f);
		}
		cText[i] = 0;
		strcpy (port, cText);
	}
	return 0;
}

void CDlgSetupTO::ReadSetupFiles(void)
{
	char name[128], auto_ans[128], addr[16], port[6];


	//Настройки Клиент АИС ХЧ
	GetPrivateProfileString ("TELE", "TELEAPI", NULL, name, sizeof name, "./setup.net");
	for (int i = strlen (name) - 1; i >= 0; i--)
		name[i] = tolower (name[i]);

	//режем звездочку с пробелом и период опроса недоступных абонентов
	if (strlen (name) > 2)
	{
		strcpy (name, name + 2);
		int i;
		for (i = 0; name[i] != ' ' && name[i] != 0; i++)
			;
		name[i] = 0;
	}
	
	GetServerProp (name, auto_ans, addr, port, "./user.net");
	m_EdName1.SetWindowText(name);
	m_EdAuto1.SetWindowText(auto_ans);
	m_EdAddr1.SetWindowText(addr);
	m_EdPort1.SetWindowText(port);

	//Настройки АСОУП
	GetPrivateProfileString ("ARM", "ASOUPTeleName", NULL, name, sizeof name, cConfigFileName);
	for (int i = strlen (name) - 1; i >= 0; i--)
		name[i] = tolower (name[i]);
	GetServerProp (name, auto_ans, addr, port, "./user.net");
	m_EdName2.SetWindowText(name);
	m_EdAuto2.SetWindowText(auto_ans);
	m_EdAddr2.SetWindowText(addr);
	m_EdPort2.SetWindowText(port);

	//Настройки Сервер центральной ТО
	GetPrivateProfileString ("ARM", "TeleServer", NULL, name, sizeof name, cConfigFileName);
	for (int i = strlen (name) - 1; i >= 0; i--)
		name[i] = tolower (name[i]);
	GetServerProp (name, auto_ans, addr, port, "./user.net");
	m_EdName3.SetWindowText(name);
	m_EdAuto3.SetWindowText(auto_ans);
	m_EdAddr3.SetWindowText(addr);
	m_EdPort3.SetWindowText(port);

	if( g_iEnableTelecom ) m_Check1.SetCheck(1);

}
extern int CheckDirExists(CString strPath);

int myCreateFolder(char *cText)
{
	char *tok = NULL;
	BOOL bRez = 0;
	tok = strtok(cText, "\\");
	char cPath[512] = "";
	while( tok )
	{
		if( tok[1] != ':' ) sprintf(cPath, "%s\\%s", cPath, tok);
		else strcpy(cPath, tok);
		bRez = CreateDirectory(cPath, NULL);
		tok = strtok(NULL, "\\");
	}
	return bRez;

}

void CDlgSetupTO::OnBnClickedButton3()
{
	char cText[512] = "";
	m_EdPathSnd.GetWindowText(cText, 512);
	if( CheckDirExists(cText) == -1 && !myCreateFolder(cText) )
	{
		AfxMessageBox("Невозможно создать каталог. Путь указан некорректно!");
		m_EdPathSnd.SetFocus();
		return;
	}
}

void CDlgSetupTO::OnBnClickedCreateDir2()
{
	char cText[512] = "";
	m_EdPathRcv.GetWindowText(cText, 512);
	if( CheckDirExists(cText) == -1 && !myCreateFolder(cText) )
	{
		AfxMessageBox("Невозможно создать каталог. Путь указан некорректно!");
		m_EdPathRcv.SetFocus();
		return;
	}
}

void CDlgSetupTO::OnBnClickedCreateDir3()
{	
	char cText[512] = "";
	m_EdPathBad.GetWindowText(cText, 512);
	if( CheckDirExists(cText) == -1 && !myCreateFolder(cText) )
	{
		AfxMessageBox("Невозможно создать каталог. Путь указан некорректно!");
		m_EdPathBad.SetFocus();
		return;
	}
}
