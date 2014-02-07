#include "StdAfx.h"
#include ".\msg4624dispatcher.h"

/*
Âåðñèÿ îò 25.11.2004 

Âåðñèÿ îò 25.10.2004 
èñïðàâëåíà îáðàáîòêà ñîîáùåíèé íå ñîäåðæàùèõ ñåêöèè 4624

Âåðñèÿ îò 16.12.2004
Ñîîáùåíèÿ áåç ñëîâà ÌÀÊÅÒ462õ

*/

void WriteLog(char *cText)
{
	/*
	FILE *f = fopen("c:\\dbg2730", "ab+");
	fprintf(f, "%s\n", cText);    
	fclose(f);
	*/
}

void WriteMem(void *cMem, int size)
{
	/*
    FILE *f = fopen("c:\\dbg2730", "ab+");
    fwrite(cMem, size, 1, f);
//	fprintf(f, "%s\n", cText);
	fclose(f);
	*/
}

//CString *srez = NULL;

void Dos2Win(char * cLine)
{
//	if( !bDosCodePage ) return;
	for( int i=0; cLine[i]; i++ )
	{
		if( cLine[i] >= (char)0x80 && cLine[i] <= (char)0xAF )
		{
			cLine[i] += 64;
		}
		else
		if( cLine[i] >= (char)0xE0 && cLine[i] <= (char)0xEF )
		{
			cLine[i] += 16;
		}
	}
}

/*extern char cAbcRus[];
extern char cAbcEng[];*/


char cAbcRus[] = "ÀÁÂÃÄÅÆÇÈÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÜÝÞß";
char cAbcEng[] = "AÁBÃÄEÆÇÈKËMHOÏPCTÓÔXÖ×ØÙÚÜÝÞß";

//void Rus2Eng(unsigned char * cLine)
void Rus2Eng(char * cLine)
{
	for( int i=0; cLine[i]; i++ )
	{
		for( int j=0; cAbcRus[j]; j++ )
		{
			if( cLine[i] == cAbcRus[j] )
			{
				cLine[i] = cAbcEng[j];
				break;
			}
		}
	}
}

void Eng2Rus(CString &strLine)
{
	for( int j=0; cAbcEng[j]; j++ )
	{
		strLine.Replace(cAbcEng[j], cAbcRus[j]);
	}
}

void Eng2Rus(char * cLine)
{
	for( int i=0; cLine[i]; i++ )
	{
		for( int j=0; cAbcEng[j]; j++ )
		{
			if( cLine[i] == cAbcEng[j] )
			{
				cLine[i] = cAbcRus[j];
				break;
			}
		}
	}
}

char cLower[] = "àáâãäå¸æçèéêëìíîïðñòóôõö÷øùûúüýþÿabcdefghijklmnopqrstuvwxyz";
char cUpper[] = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÛÚÜÝÞßABCDEFGHIJKLMNOPQRSTUVWXYZ";

CString g_month_[] = {"ßÍÂÀÐß", "ÔÅÂÐÀËß", "ÌÀÐÒÀ", "ÀÏÐÅËß", "ÌÀß", "ÈÞÍß", "ÈÞËß", "ÀÂÃÓÑÒÀ", "ÑÅÍÒßÁÐß", "ÎÊÒßÁÐß", "ÍÎßÁÐß", "ÄÅÊÀÁÐß"};
CString g_month2_[] = {"ßÍÂÀÐÜ", "ÔÅÂÐÀËÜ", "ÌÀÐÒ", "ÀÏÐÅËÜ", "ÌÀÉ", "ÈÞÍÜ", "ÈÞËÜ", "ÀÂÃÓÑÒ", "ÑÅÍÒßÁÐÜ", "ÎÊÒßÁÐÜ", "ÍÎßÁÐÜ", "ÄÅÊÀÁÐÜ"};
CString g_month3_[] = {"ßÍÂÀÐß", "ÔÅÂÐÀËß", "ÌÀÐÒÀ", "ÀÏÐÅËß", "ÌÀß", "ÈÞÍß", "ÈÞËß", "ÀÂÃYÑÒÀ", "ÑÅÍÒßÁÐß", "ÎÊÒßÁÐß", "ÍÎßÁÐß", "ÄÅÊÀÁÐß"};

//void Rus2Eng(unsigned char * cLine)
void ToUpperCase(char * cLine)
{
	for( int i=0; cLine[i]; i++ )
	{
		for( int j=0; cLower[j]; j++ )
		{
			if( cLine[i] == cLower[j] )
			{
				cLine[i] = cUpper[j];
				break;
			}
		}
	}
}
/*
CString isNull(WORD Val)
{
    CString s;
    if( Val ) s.Format("%u", Val);
    else s = "NULL";
    return s;
}

CString isNull(__int64 Val)
{
    CString s;
//	if(!srez) s = new CString;
    if( Val ) s.Format("%I64u", Val);
    else s = "NULL";
    return s;
}


CString isNull(CString Val)
{
    CString s;
    if( Val == "" || Val == "NULL" || !Val.GetLength() )
    {
        s = "NULL";
    } else
        s.Format("'%s'", Val);
    return s;
}
*/
CSection *CShelves::GetSection(DWORD dwSectionID)
{
	for( int i=0; i < iSecionCount + 1; i++ )
	{
		if( dwSectionID == Section[i].dwSectionID )
		{
			return &Section[i];
		}
	}
	return NULL;
}

void CShelves::AddSection(CString Name, DWORD dwSubSectionID)
{
	Section[dwLastSectionID].strName = Name;
	Section[dwLastSectionID].dwSectionID = dwLastSectionID;
	Section[dwLastSectionID].dwSubSectionID = dwSubSectionID;
	dwLastSectionID++;
	iSecionCount++;
}

DWORD CShelves::GetSectionID(CString Name, int iSubSecID)
{
	for( int i=0; i < iSecionCount + 1; i++ )
	{
		if( Name == Section[i].strName && Section[i].dwSubSectionID == iSubSecID) return Section[i].dwSectionID;
	}
	return 0;
}

void CShelves::AddVar(CString Name, int SecID)
{
	Var[iVarCount].strName = Name;
	Var[iVarCount].iSecionID = SecID;
	iVarCount++;
}

void CShelves::InitShelves(int s1, int s2, int s3, int s4, int s5)
{
	WriteLog("InitShelves - 1P");
	AddVar("KOÄ ÆEË. AÄM. COÁCTBEHHÈKA K.Ï.", s1);
	AddVar("MECßÖ È ÃOÄ ÏOËHOÃO OCBÈÄET. K.Ï.", s1);
	AddVar("ÏPEÄÏPÈßTÈE ÏOËHOÃO OCBÈÄET.", s1);
	AddVar("ÃOÄ ÈÇÃOTOBËEHÈß OCÈ", s1);
	AddVar("ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ OCÈ", s1);
	AddVar("HOMEP OCÈ", s1);
	AddVar("TOËÙÈHA OÁOÄA ÏPABOÃO KOËECA", s1);
	AddVar("TOËÙÈHA ÃPEÁHß ÏPABOÃO KOËECA", s1);
	AddVar("ÏPOKAT ÏPABOÃO KOËECA", s1);
	AddVar("TOËÙÈHA OÁOÄA ËEBOÃO KOËECA", s1);
	AddVar("TOËÙÈHA ÃPEÁHß ËEBOÃO KOËECA", s1);
	AddVar("ÏPOKAT ËEBOÃO KOËECA", s1);
	
//	Section[2].Set("2. HAÄPECCOPHAß ÁAËKA", 15, 25);

	AddVar("KOÄ ÆEË. AÄM. COÁCTBEHHÈKA", s2);
	AddVar("ÃOÄ ÈÇÃOTOBËEHÈß", s2);
	AddVar("ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ", s2);
	AddVar("HOMEP", s2);
	AddVar("ÃËÓÁÈHA ÏOÄÏßTHÈKA", s2);
	AddVar("ÄÈAMETP ÏOÄÏßTHÈKA", s2);
	AddVar("BOCCTAHOBËEHÈE ÏOÄÏßTHÈKA", s2);
	AddVar("ÃOÄ OKOH×AH. CPOKA CËÓÆÁÛ", s2);
	AddVar("MEC. È ÃOÄ ÏPOÄËEH. CPOKA CËÓÆÁÛ", s2);
	AddVar("ÏPEÄÏPÈßTÈE ÏPOÄËEHÈß\nCPOKA CËÓÆÁÛ", s2);
	AddVar("OÁÚEM PEMOHTA", s2);

//	Section[3].Set("3. ÁOKOBÛE PAMÛ", 26, 35);
	AddVar("OÁÚEM PEMOHTA", s3);
	AddVar("KOÄ ÆEË. AÄM. COÁCTBEHHÈKA", s3);
	AddVar("ÃOÄ ÈÇÃOTOBËEHÈß", s3);
	AddVar("ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ", s3);
	AddVar("HOMEP", s3);
	AddVar("ÁAÇA ÁOKOBOÉ PAMÛ", s3);
	AddVar("BOCCTAHOBËEHÈE OÏOPHOÉ\nÏOBEPXHOCTÈ ÁÓKCOBOÃO ÏPOEMA", s3);
	AddVar("ÃOÄ OKOH×AH. CPOKA CËÓÆÁÛ", s3);
	AddVar("MEC. È ÃOÄ ÏPOÄËEH. CPOKA CËÓÆÁÛ", s3);
	AddVar("ÏPEÄÏPÈßTÈE ÏPOÄËEHÈß\nCPOKA CËÓÆÁÛ", s3);
	

//	Section[4].Set("4. XAPAKTEPÈCTÈKA TEËEÆKÈ", 36, 25);
	
	AddVar("OÁÚEM PEMOHTA TEËEÆKÈ", s4);
	AddVar("ÇABÛØEHÈE(ÇAHÈÆEHÈE)\nËEBOÃO ÔPÈKÖÈOHHOÃO KËÈHA", s4);
	AddVar("ÇABÛØEHÈE(ÇAHÈÆEHÈE)\nÏPABOÃO ÔPÈKÖÈOHHOÃO KËÈHA", s4);
	AddVar("ÏPOÄOËÜHÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ËEBÛÉ)", s4);
	AddVar("ÏPOÄOËÜHÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ÏPABÛÉ)", s4);
	AddVar("ÏOÏEPE×HÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ËEBÛÉ)", s4);
	AddVar("ÏOÏEPE×HÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ÏPABÛÉ)", s4);
	AddVar("ÇAÇOP MEÆÄÓ CKOËÜÇÓHAMÈ\nTEËEÆKÈ È PAMÛ", s4);

// Ñîåä áàëêè
	if( s5 )
	{
		AddVar("ÃOÄ ÈÇÃOTOBËEHÈß", s5);
		AddVar("ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ", s5);
		AddVar("HOMEP", s5);
		AddVar("ÄÈAMETP ÏOÄÏßTHÈKA", s5);
	}
	WriteLog("ok");
}


CShelves::CShelves()
{
	WriteLog("CShelves");
	dwLastSectionID = 1;
	iVarCount = 0;
	iSecionCount = 0;

//	Section[0].Set("MAKET 4624", 0, 2);
	AddSection("MAKET 4624", 0);				//1
	AddSection("ÄAHHÛE ÏO TEËEÆKE N 1", 1);		//2
	AddSection("ÄAHHÛE ÏO TEËEÆKE N 2", 1);		//3
	AddSection("ÄAHHÛE ÏO TEËEÆKE N 3", 1);		//4
	AddSection("ÄAHHÛE ÏO TEËEÆKE N 4", 1);		//5

	AddSection("1. KOËECHÛE ÏAPÛ:", 2 );		//6
	AddSection("2. HAÄPECCOPHAß ÁAËKA", 2 );	//7
	AddSection("3. ÁOKOBÛE PAMÛ", 2 );			//8
	AddSection("4. XAPAKTEPÈCTÈKA TEËEÆKÈ", 2);	//9

	AddSection("1. KOËECHÛE ÏAPÛ:", 3 );		//10
	AddSection("2. HAÄPECCOPHAß ÁAËKA", 3 );	//11
	AddSection("3. ÁOKOBÛE PAMÛ", 3 );			//12
	AddSection("4. XAPAKTEPÈCTÈKA TEËEÆKÈ", 3);	//13
	AddSection("5. COEÄÈHÈTEËÜHAß ÁAËKA", 3);	//14


	AddSection("1. KOËECHÛE ÏAPÛ:", 4 );		//15
	AddSection("2. HAÄPECCOPHAß ÁAËKA", 4 );	//16
	AddSection("3. ÁOKOBÛE PAMÛ", 4 );			//17
	AddSection("4. XAPAKTEPÈCTÈKA TEËEÆKÈ", 4);	//18

	AddSection("1. KOËECHÛE ÏAPÛ:", 5 );		//19
	AddSection("2. HAÄPECCOPHAß ÁAËKA", 5 );	//20
	AddSection("3. ÁOKOBÛE PAMÛ", 5 );			//21
	AddSection("4. XAPAKTEPÈCTÈKA TEËEÆKÈ", 5); //22
	AddSection("5. COEÄÈHÈTEËÜHAß ÁAËKA", 5);	//23

	AddVar("ÄATA ÏEPEÄA×È COOÁÙEHÈß", 1);
	AddVar("ÏPEÄÏP ÏEPEÄA×È COOÁÙEHÈß", 1);
	AddVar("BÈÄ PAÁOTÛ C BAÃOHOM", 1);
	AddVar("ÏTO ÓCTAHOBKÈ ÏOÄ BAÃOH", 1);


	InitShelves(6, 7, 8, 9, 0);
	InitShelves(10, 11, 12, 13, 14);
	InitShelves(15, 16, 17, 18, 0);
	InitShelves(19, 20, 21, 22, 23);
	WriteLog("ok");
//	AddVar("ÃOÄ ÈÇÃOTOBËEHÈß", 

//	iVarCount = 26;
//	iSecionCount = 3;
}

void CShelves::ReplaceVarName(CString strOldName, CString strNewName)
{
	for( int i=0; i < iSecionCount; i++ )
	{
		if( Section[i].strName == strOldName )
		{
			Section[i].strName = strNewName;
			return;
		}
	}
}

CMsg4624Dispatcher::CMsg4624Dispatcher(void)
{
	//srez = new CString;
	i2731 = 0;
	iGot2731Script = 0;
}	
	
CMsg4624Dispatcher::~CMsg4624Dispatcher(void)
{
	//delete srez;
}


// Ñþäà ñîîáùåíèå äîëæíî ïðèõîäèòü â âèíäîâîé êîäèðîâêå!!! 
void CMsg4624Dispatcher::SetSourceText(char *str, int len)
{
//	WriteLog("SetSourceText");
    //WriteLog(str);    
//    WriteLog("+");
	i2731 = 0;
	iGot2731Script = 0;	
	if( len > MAX_MSG_LENGTH ) len = MAX_MSG_LENGTH;
	str[len] = 0;
//	Rus2Eng(str);
	ToUpperCase(str);
	Rus2Eng(str);
	WriteMem((void *)str, len);
	strSourceText = str;
	

    ourMessage = 0;
	int xx = strSourceText.Find("MAKET 4623",0);
	if( xx != -1 ) 
	{
		strMessID = "MAKET 4623";
		Values.ReplaceVarName("MAKET 4624", "MAKET 4623");
		Values.ReplaceVarName("MAKET 4635", "MAKET 4623");
		Values.ReplaceVarName("ÈHÔOPMAÖÈß HOMEP 1", "MAKET 4623");
        ourMessage = 1;
	}

	int xxx = strSourceText.Find("CÏPABKA 2731",0);
	if( xxx != -1 )
	{
		i2731 = 1;
		ourMessage = 1;
		strSourceText.Replace("\r\n\r\n", "\r\n");
		strSourceText.Replace("\r", "\n");
		return;
	}

	int dd = strSourceText.Find("MAKET 4624",0);
	if( dd != -1 ) 
	{
		strMessID = "MAKET 4624";
		Values.ReplaceVarName("MAKET 4623", "MAKET 4624");
		Values.ReplaceVarName("MAKET 4635", "MAKET 4624");
		Values.ReplaceVarName("ÈHÔOPMAÖÈß HOMEP 1", "MAKET 4624");
        ourMessage = 1;
	}

	int mm = strSourceText.Find("MAKET 4635",0);
	if( mm != -1 ) 
	{
		strMessID = "MAKET 4635";
		Values.ReplaceVarName("MAKET 4623", "MAKET 4635");
		Values.ReplaceVarName("MAKET 4624", "MAKET 4635");
		Values.ReplaceVarName("ÈHÔOPMAÖÈß HOMEP 1", "MAKET 4635");
        ourMessage = 1;
	}

	int nn = strSourceText.Find("ÈHÔOPMAÖÈß HOMEP 1",0);
	if( nn != -1 )
	{
		strMessID = "ÈHÔOPMAÖÈß HOMEP 1";
		Values.ReplaceVarName("MAKET 4623", "ÈHÔOPMAÖÈß HOMEP 1");
		Values.ReplaceVarName("MAKET 4624", "ÈHÔOPMAÖÈß HOMEP 1");
		Values.ReplaceVarName("MAKET 4635", "ÈHÔOPMAÖÈß HOMEP 1");
		
		Values.ReplaceVarName("ÄATA ÏEPEÄA×È COOÁÙEHÈß", "ÄATA ÓCTAHOBKÈ ÏOÄ BAÃOH");
		Values.ReplaceVarName("ÏPEÄÏP ÏEPEÄA×È COOÁÙEHÈß", "ÏPEÄÏP ÓCTAHOBKÈ ÏOÄ BAÃOH");
//		Values.ReplaceVarName("BÈÄ PAÁOTÛ C BAÃOHOM", "ÈHÔOPMAÖÈß HOMEP 1");
/*
	    pCont->SendDat = GetValue(strMessID, "ÄATA ÏEPEÄA×È COOÁÙEHÈß");
	    pCont->SendPr = GetValue(strMessID, "ÏPEÄÏP ÏEPEÄA×È COOÁÙEHÈß");
	    pCont->RemVag = GetValue(strMessID, "BÈÄ PAÁOTÛ C BAÃOHOM");		
		*/
		ourMessage = 1;
	}

	if( dd != -1 && xx != -1)
	{
		for( int i=xx; i < dd && i < MAX_MSG_LENGTH && i < len; i++ )
		{
			str[i] = str[i + dd - xx];
		}
	} else
		dd = 0;
//	unsigned char *cStr = new unsigned char [strSourceText.GetLength()];
//	unsigned char cStr[MAX_MSG_LENGTH];
	char cStr[MAX_MSG_LENGTH] = "";
	strcpy((char *)cStr, str);
	xx = strSourceText.Find("ÏPABAß", 0);
	if( xx == -1 ) Dos2Win((char *)cStr);
	ToUpperCase(cStr);
	Rus2Eng(cStr);
	strSourceText = cStr;    

	char cTest[64] = "4. ÕÀÐÀÊÒÅÐÈÑÒÈÊÀ ÒÅËÅÆÊÈ";
	Rus2Eng(cTest);
	WriteLog(cTest);
//    xx = strSourceText.Replace("4. ÕÀÐÀÊÒÅÐÈÑÒÈÊÀ ÒÅËÅÆÊÈ     ", "     4. ÕÀÐÀÊÒÅÐÈÑÒÈÊÀ ÒÅËÅÆÊÈ");
//	AfxMessageBox(itoa(xx, cStr, 10));
	strSourceText.Replace("\r\n\r\n", "\r\n");
    strSourceText.Replace("\r", "\n");

	strSourceText.Replace("                                                          ", "");
	strSourceText.Replace("                                                         ", "");
	strSourceText.Replace("                                                       ", "");

    strSourceText.Replace("\n\n\n", "\n");
    strSourceText.Replace("\n\n", "\n");
	strSourceText.Replace(" \n", "\n");

	strSourceText.Replace ("BÈÄ ÏOCËEÄHEÉ PAÁOTÛ C BAÃOHOM:","BÈÄ ÏOCËEÄHEÉ PAÁOTÛ C BAÃOHOM");
	strSourceText.Replace ("ÄATA ÏOCËEÄHEÉ PAÁOTÛ C BAÃOHOM:","ÄATA ÏOCËEÄHEÉ PAÁOTÛ C BAÃOHOM");
	strSourceText.Replace ("ÏPEÄÏPÈßTÈE ÏOCËEÄHEÉ PAÁOTÛ C BAÃOHOM:","ÏPEÄÏPÈßTÈE ÏOCËEÄHEÉ PAÁOTÛ C BAÃOHOM");
	strSourceText.Replace ("BÈÄ PAÁOTÛ C BAÃOHOM:","BÈÄ PAÁOTÛ C BAÃOHOM");
	strSourceText.Replace ("ÄAHHÛE ÏO TEËEÆKE    ","ÄAHHÛE ÏO TEËEÆKE N ");
	strSourceText.Replace ("¹ ","N");
	strSourceText.Replace ("TOËÙÈHA OÁOÄA ËEBOÃO  KOËECA", "TOËÙÈHA OÁOÄA ËEBOÃO KOËECA");
	strSourceText.Replace ("TOËÙÈHA ÃPEÁHß ËEBOÃO  KOËECA", "TOËÙÈHA ÃPEÁHß ËEBOÃO KOËECA");
	strSourceText.Replace ("ÏPOKAT ËEBOÃO  KOËECA", "ÏPOKAT ËEBOÃO KOËECA");
	//strSourceText.Replace ("OÁÜEM PEMOHTA TEËEÆKÈ", "OÁÚEM PEMOHTA TEËEÆKÈ");
	strSourceText.Replace ("OÁÜEM PEMOHTA", "OÁÚEM PEMOHTA");

/*
	strcpy(str, strSourceText);
	
	WriteLog("REPLACED SPACE");
	WriteLog(str);
*/	

	/*strSourceText.Replace ("ÂÈÄ ÏÎÑËÅÄÍÅÉ ÐÀÁÎÒÛ Ñ ÂÀÃÎÍÎÌ:","ÂÈÄ ÏÎÑËÅÄÍÅÉ ÐÀÁÎÒÛ Ñ ÂÀÃÎÍÎÌ");
	strSourceText.Replace ("ÄÀÒÀ ÏÎÑËÅÄÍÅÉ ÐÀÁÎÒÛ Ñ ÂÀÃÎÍÎÌ:","ÄÀÒÀ ÏÎÑËÅÄÍÅÉ ÐÀÁÎÒÛ Ñ ÂÀÃÎÍÎÌ");
	strSourceText.Replace ("ÏÐÅÄÏÐÈßÒÈÅ ÏÎÑËÅÄÍÅÉ ÐÀÁÎÒÛ Ñ ÂÀÃÎÍÎÌ:","ÏÐÅÄÏÐÈßÒÈÅ ÏÎÑËÅÄÍÅÉ ÐÀÁÎÒÛ Ñ ÂÀÃÎÍÎÌ");
	strSourceText.Replace ("ÂÈÄ ÐÀÁÎÒÛ Ñ ÂÀÃÎÍÎÌ:","ÂÈÄ ÐÀÁÎÒÛ Ñ ÂÀÃÎÍÎÌ");
	strSourceText.Replace ("ÄAHHÛE ÏO TEËEÆKE    ","ÄAHHÛE ÏO TEËEÆKE N ");
	strSourceText.Replace ("¹","N");*/


//	strncpy(cSourceText, (char *)cStr, MAX_MSG_LENGTH); --###
//	delete cStr;
}

void CMsg4624Dispatcher::DispatchSection(DWORD dwSectionID, int iStartIndex, int iEndIndex)
{
	char cMess[128] ="";	

	CSection *pSec = Values.GetSection(dwSectionID);
	if (!pSec ) 
		return;

	sprintf(cMess, "[%d][%s]", dwSectionID, pSec->strName);
	WriteLog(cMess);

//	if( pSec->strName == "ÄAHHÛE ÏO TEËEÆKE N 4" )
/*	int zzz = 0;
	if( pSec->strName == "ÄAHHÛE ÏO TEËEÆKE N 4" )
	{
		cMess[0] = 0;
		zzz = strSourceText.GetLength();
	}
*/
	int x = strSourceText.Find(pSec->strName, iStartIndex);
	if( x == -1 ) 
		return;

	int iNewEndIndex = iEndIndex;
	char c1 = pSec->strName[0];
	char next_s[255] = "";
	if( c1 >= '0' && c1 <= '9' )
	{
		c1 += 1;
		sprintf(next_s, "%c. ", c1);
		iNewEndIndex = strSourceText.Find(next_s, iStartIndex);
		if( iNewEndIndex == -1 )
		{
			iNewEndIndex = iEndIndex;
//			strSourceText.Delete(x, strSourceText.GetLength() - x);
		}
	}


	for( int i=0; i < Values.iSecionCount + 1; i++ )
	{
		if( Values.Section[i].dwSubSectionID == dwSectionID )
		{
			DispatchSection(Values.Section[i].dwSectionID, x, iNewEndIndex);
		}
	}

	char *p = NULL;
	char cText[MAX_MSG_LENGTH] = "";
	strncpy(cText, strSourceText, iNewEndIndex);
	for(int i=0; i < Values.iVarCount; i++ )
	{
		if( Values.Var[i].iSecionID == dwSectionID )
		{            
			int z = strSourceText.Find(Values.Var[i].strName, x);

			char cMesss[100] = "";
			//sprintf(cMesss, "%s", Values.Var[i].strName);
            //WriteLog( cMesss );       

			if( z == -1 ) 
            {
                continue;
            }
            itoa(z, cMess, 10);
            sprintf(cMesss, "+%s+", cMess);
//            WriteLog( cMesss );            
			p = &cText[z + Values.Var[i].strName.GetLength()];
//            sprintf(cMess, "0x%08X", p);
			char cVal[128 + 1] = "";
			
			while( *p == ' ' ) p++;
            long p1 = 0, p2 = 0;
            p1 = (long)p;
            p1 = (long)p - (long)cText;//[z - Values.Var[i].strName.GetLength(); // îò íà÷àëà ôàéëà
			for( z=0; *p != ' ' && *p != 0x0D && *p != 0x0A && z < 128; z++, p++ )
			{
				cVal[z] = *p;
			}

			Values.Var[i].strVal1 = cVal;
			int dd = Values.Var[i].strVal1.Find(".",0);
			if( dd != -1 ) Values.Var[i].strVal1.Delete(dd);
            
			if( *p == 0x0D || *p == 0x0A)
			{
				sprintf(cMess, "-1- %s = [%s (0x%08X)]", Values.Var[i].strName, Values.Var[i].strVal1, p1);
				WriteLog(cMess);
				continue;
			}

			ZeroMemory(cVal, 128 + 1);
			while( *p == ' ' ) p++;
            p2 =(long) p - (long)cText;//z - Values.Var[i].strName.GetLength();
			for( z=0; *p != ' ' && *p != 0x0D && *p != 0x0A && z < 128; z++, p++ )
			{
				cVal[z] = *p;
			} 
			Values.Var[i].strVal2 = cVal;
			dd = Values.Var[i].strVal2.Find( ".", 0 );
			if( dd != -1 ) Values.Var[i].strVal2.Delete(dd);
			sprintf(cMess, "-2- %s = [%s (0x%08X)][%s (0x%08X)]", Values.Var[i].strName, Values.Var[i].strVal1, p1, Values.Var[i].strVal2, p2);
			WriteLog(cMess);
		}
	}
	WriteLog("ok");
}

int MonthNum1( char *cMonth )
{
	for( int i=0; i < 12; i++ )
		if( strcmp(cMonth, g_month_[i]) == 0 ||
			strcmp(cMonth, g_month2_[i]) == 0 ||
			strcmp(cMonth, g_month3_[i]) == 0) 
				return i + 1;
	return 0;
}


int  CMsg4624Dispatcher::Dispatch2731()
{
	WriteLog("In dsp2731");
	int p = 0, p1 = 0;
	char cText[256] = "", cText1[64] = "", cText2[64] = "", cDat[16] = "", cNVag[12] = "";
	char cDat2[16] = "", cKlPr[10] = "";
	int iKodRem = 0;
	char cScript[20000] = "";

	sprintf(cScript, "begin tran\ncreate table #reslt ( ids bigint, ilk varchar(300) )\n\n\
declare @ids bigint\n\n");

	p = strSourceText.Find("CÏPABKA 2731. ", 0);
	if( p == -1 )
	{
		iGot2731Script = 0;
		i2731 = 0;
		return -1;
	}
	p = strSourceText.Find(" ", p + strlen("CÏPABKA 2731. "));
	p1 = strSourceText.Find(" ", p + 1);
	strncpy(cText, strSourceText.Mid(p + 1, p1 - p - 1), p1 - p );
	p1++;
	p = p1;
	p1 = strSourceText.Find(" ", p1);
	ZeroMemory(cText1, sizeof(cText1));
	strncpy(cText1, strSourceText.Mid(p, p1 - p), p1 - p );
	p1++;
	p = p1;
	p1 = strSourceText.Find(" ", p1);
	strncpy(cText2, strSourceText.Mid(p, p1 - p), p1 - p );

	Eng2Rus(cText1);
	sprintf( cDat, "%s%.2d%.2d", cText2, MonthNum1(cText1), atoi(cText) );
	p = strSourceText.Find("C B E Ä E H È ß  O  K O M Ï Ë E K T A Ö È È  BAÃOHA ", p );
	if( p == -1 ) { iGot2731Script = 0; i2731 = 0; return -1; }
	p += strlen("C B E Ä E H È ß  O  K O M Ï Ë E K T A Ö È È  BAÃOHA ");
	strncpy( cNVag, strSourceText.Mid(p, 8), 10);
	
	p = strSourceText.Find("ÏOCËEÄHÈE ÄAHHÛE ÏOËÓ×EHÛ ", p);		     
	p += strlen("ÏOCËEÄHÈE ÄAHHÛE ÏOËÓ×EHÛ ");
	p1 = strSourceText.Find(" ", p + 1);
	strncpy(cText, strSourceText.Mid(p, p1 - p), p1 - p );
	p1++;
	p = p1;
	p1 = strSourceText.Find(" ", p1);
	ZeroMemory(cText1, sizeof(cText1));
	strncpy(cText1, strSourceText.Mid(p, p1 - p), p1 - p );
	p1++;
	p = p1;
	p1 = strSourceText.Find(" ", p1);
	strncpy(cText2, strSourceText.Mid(p, p1 - p), p1 - p );
	
	Eng2Rus(cText1);
	sprintf( cDat2, "%s%.2d%.2d", cText2, MonthNum1(cText1), atoi(cText) );

	p = strSourceText.Find("ÏOCËE ", p);
	p += strlen("ÏOCËE ");
	p1 = strSourceText.Find("\n", p + 1);
	strncpy(cText, strSourceText.Mid(p, p1 - p), p1 - p );
	p1++;

	if( strcmp( cText, "ÄEÏ.PEMOHTA") == 0 ) iKodRem = 1;
	if( strcmp( cText, "TEKÓÙEÃO") == 0 ) iKodRem = 3;
	if( strcmp( cText, "KAÏ.PEMOHTA") == 0 ) iKodRem = 2;


	p = strSourceText.Find("ÈÇ ÄEÏO ", p);
	p += strlen("ÈÇ ÄEÏO ");
	p1 = strSourceText.Find(" ", p + 1);
	strncpy(cKlPr, strSourceText.Mid(p, p1 - p), p1 - p );
	p1++;
	
	sprintf(cScript, "%s\ninsert into #reslt exec pTov_S4634InsSL null, null, null,    null, null, null, null, null, null,   %s, %s, %s, %s, %s, '%s', '%s',   null, null, 0\n\nselect @ids = ids from #reslt\n\
if (@ids > 0)\nbegin\n\n", 
		cScript,
		"null", //NLK
		cNVag,
		cKlPr,
		"null",
		isNull((WORD)iKodRem),
		cDat,
		cDat2);

	char cKodDtl[6] = "", cSobst[6] = "", cZavod[10] = "", cNum[20] = "", cYearIzg[8] = "", cDepo[10] = "", cDatUst[20] = "", cVRem[10] = "", cObodL[10] ="", cObodR[10] = "";

	int iStart = strSourceText.Find("KOË.ÏAPA", p);
	//Íàéäåì íà÷àëî ñëåä ñîîáùåíèÿ
	int iEnd = strSourceText.Find("CÏPABKA 2731", p);
	if( iEnd == -1 ) iEnd = strSourceText.GetLength();

	p = iStart;
	for( int i=1; p != -1 && p < iEnd; i++ )
	{
		strcpy( cKodDtl,  strSourceText.Mid(p + 9, 2) );
		strcpy( cSobst,   strSourceText.Mid(p + 12, 2) );

		strcpy( cZavod,   strSourceText.Mid(p + 16, 5).TrimLeft() );
		strcpy( cNum,     strSourceText.Mid(p + 22, 10).TrimLeft() );
		strcpy( cYearIzg, strSourceText.Mid(p + 33, 4) );
		strcpy( cDepo,	  strSourceText.Mid(p + 39, 4) );
		strncpy(cText,    strSourceText.Mid(p + 44, 7), 8 );
		
		if( atoi(cText + 3) ) 
		{
			if( strncmp("00", cText, 2) ) sprintf(cDatUst, "'%.2s%.4s'", cText, cText + 3 );
			else sprintf(cDatUst, "'%.4s'", cText + 3 );
		} else
			strcpy( cDatUst,   "'0000'" );

		strcpy( cVRem,    strSourceText.Mid(p + 51, 2) );
		if( cKodDtl[0] == '5' )
		{
			strcpy( cObodL,   strSourceText.Mid(p + 56, 3) );
			strcpy( cObodR,   strSourceText.Mid(p + 60, 3) );
		} else
		{
			strcpy( cObodL,   "null" );
			strcpy( cObodR,   "null" );
		}

		sprintf( cScript, "%s exec pTov_S4634InsInf @IDS, %c0, %d, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n",
			cScript, cKodDtl[0], i, cKodDtl, "0", cSobst, cZavod, cNum, cYearIzg, cDepo, cDatUst, cVRem, cObodL, cObodR);


		p += 52;
		p1 = strSourceText.Find("KOË.ÏAPA", p );
		if( p1 == -1 || p1 > iEnd ) p1 = strSourceText.Find("HAÄP.ÁAË", p );
		if( p1 == -1 || p1 > iEnd ) p1 = strSourceText.Find("ÁOK.PAMA", p );
		p = p1;
		
	}

	strcat(cScript, "\nend\ndrop table #reslt\ncommit tran");
	WriteLog(cScript);
	strncpy(cScript2731, cScript, 20000);
	iGot2731Script = 1;

	return 0;
}

int CMsg4624Dispatcher::Get2731Script(char *cScript)
{
	if( !iGot2731Script ) return -1;
	strncpy(cScript, cScript2731, 20000);
	return 1;
}

void CMsg4624Dispatcher::Dispatch()
{
	if( i2731 )
	{
		Dispatch2731();
		return;
	}
    for( int i=0; i < Values.iVarCount; i++ )
    {
        Values.Var[i].strVal1 = "";
        Values.Var[i].strVal2 = "";
    }
    if( !ourMessage ) return;
	DispatchSection(1,0, strSourceText.GetLength());
	FillStruct(&Cont4624);

}

void CMsg4624Dispatcher::FillStruct(CContainer4624 *pCont)
{
	int id = strSourceText.Find("HOMEP BAÃOHA", 0);

    if( id != -1 )
    {
	    int l = (int)strlen("HOMEP BAÃOHA");
	    l++;
    //	strcpy( cSourceText, strSourceText);
	    char cVagNum[32] = "";
	    int i;
	    for( i=0; strSourceText[id + i + l] != ' ' && strSourceText[id + i + l]; i++ )
	    {
		    cVagNum[i] = strSourceText[id + i + l];
	    }
	    cVagNum[i] = 0;
	    Cont4624.VagNum = cVagNum;

	    if( strSourceText.Find("ÄAHHÛE ÏO TEËEÆKE N 3", 0) != -1 ) Cont4624.i8Os = 1;
	    else  Cont4624.i8Os = 0;
	    
	    pCont->SendDat = GetValue(strMessID, "ÄATA ÏEPEÄA×È COOÁÙEHÈß");
		if( pCont->SendDat == "" )
			pCont->SendDat = GetValue(strMessID, "ÄATA ÓCTAHOBKÈ ÏOÄ BAÃOH");

	    pCont->SendPr = GetValue(strMessID, "ÏPEÄÏP ÏEPEÄA×È COOÁÙEHÈß");
		if( pCont->SendDat == "" )
			pCont->SendPr = GetValue(strMessID, "ÏPEÄÏP ÓCTAHOBKÈ ÏOÄ BAÃOH");

	    pCont->RemVag = GetValue(strMessID, "BÈÄ PAÁOTÛ C BAÃOHOM");
		
		pCont->PtoVag = GetValue(strMessID, "ÏTO ÓCTAHOBKÈ ÏOÄ BAÃOH");
    }
	FillTL("ÄAHHÛE ÏO TEËEÆKE N 1", &pCont->Tl1);
	FillTL("ÄAHHÛE ÏO TEËEÆKE N 2", &pCont->Tl2, &pCont->SB1);
	if( !Cont4624.i8Os ) return;
	FillTL("ÄAHHÛE ÏO TEËEÆKE N 3", &pCont->Tl3);
	FillTL("ÄAHHÛE ÏO TEËEÆKE N 4", &pCont->Tl4, &pCont->SB2);
}


/*
void CMsg4624Dispatcher::GetSQLStringSl(CString * str, int * iInfCount)
{
	CString s;
	s.Format("pTov_S4624InsSL NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, %s, NULL, NULL, %s, %s, NULL, NULL, NULL, NULL, NULL, NULL, NULL",
			
}
*/
CString CMsg4624Dispatcher::GetValue(CString strTitle)
{
//	for( int i=0; i < 
	return CString();
}

CString CMsg4624Dispatcher::GetValue(CString sec1, CString sec2, CString sec3, CString VarName, int iSide, int DateConvert)
{
	DWORD dwID = Values.GetSectionID(sec1, 0);
	dwID = Values.GetSectionID(sec2, dwID);
	dwID = Values.GetSectionID(sec3, dwID);
	for( int i=0; i < Values.iVarCount; i++ )
	{
		if( VarName == Values.Var[i].strName && 
			dwID == Values.Var[i].iSecionID )
		{
//			AfxMessageBox(Values.Var[i].strVal1);
			if( !iSide )
			{
				if( DateConvert && Values.Var[i].strVal1.GetLength() > 4 )
					Values.Var[i].strVal1.Delete(2, 2);
				return Values.Var[i].strVal1;
			}
			else
			{
				if( DateConvert && Values.Var[i].strVal2.GetLength() > 4 )
					Values.Var[i].strVal2.Delete(2, 2);
				return Values.Var[i].strVal2;
			}
		}
	}
	return "";
}

void CMsg4624Dispatcher::FillTL(CString TlHead, CContainerTl4624 *t, CContainerSB4624 *sb)
{
//	if( !t ) return;
	t->KP1.OwnerCode = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "KOÄ ÆEË. AÄM. COÁCTBEHHÈKA K.Ï.", 0);
	t->KP1.OsvDat = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "MECßÖ È ÃOÄ ÏOËHOÃO OCBÈÄET. K.Ï.", 0, 1);
	t->KP1.OsvPr =  GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÏPEÄÏPÈßTÈE ÏOËHOÃO OCBÈÄET.", 0);
	t->KP1.IsgOsYr = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÃOÄ ÈÇÃOTOBËEHÈß OCÈ", 0);
	t->KP1.IzgOsPr = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ OCÈ", 0);
	t->KP1.OsNum = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "HOMEP OCÈ", 0);
	t->KP1.WidthObodR = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "TOËÙÈHA OÁOÄA ÏPABOÃO KOËECA", 0);
	t->KP1.WidthGrebR = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "TOËÙÈHA ÃPEÁHß ÏPABOÃO KOËECA", 0);
	t->KP1.ProkatR = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÏPOKAT ÏPABOÃO KOËECA", 0);
	t->KP1.WidthObodL = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "TOËÙÈHA OÁOÄA ËEBOÃO KOËECA", 0);
	t->KP1.WidthGrebL = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "TOËÙÈHA ÃPEÁHß ËEBOÃO KOËECA", 0);
	t->KP1.ProkatL = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÏPOKAT ËEBOÃO KOËECA", 0);	

	t->KP2.OwnerCode = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "KOÄ ÆEË. AÄM. COÁCTBEHHÈKA K.Ï.", 1);
	t->KP2.OsvDat = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "MECßÖ È ÃOÄ ÏOËHOÃO OCBÈÄET. K.Ï.", 1, 1);
	t->KP2.OsvPr =  GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÏPEÄÏPÈßTÈE ÏOËHOÃO OCBÈÄET.", 1);
	t->KP2.IsgOsYr = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÃOÄ ÈÇÃOTOBËEHÈß OCÈ", 1);
	t->KP2.IzgOsPr = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ OCÈ", 1);
	t->KP2.OsNum = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "HOMEP OCÈ", 1);
	t->KP2.WidthObodR = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "TOËÙÈHA OÁOÄA ÏPABOÃO KOËECA", 1);
	t->KP2.WidthGrebR = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "TOËÙÈHA ÃPEÁHß ÏPABOÃO KOËECA", 1);
	t->KP2.ProkatR = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÏPOKAT ÏPABOÃO KOËECA", 1);
	t->KP2.WidthObodL = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "TOËÙÈHA OÁOÄA ËEBOÃO KOËECA", 1);
	t->KP2.WidthGrebL = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "TOËÙÈHA ÃPEÁHß ËEBOÃO KOËECA", 1);
	t->KP2.ProkatL = GetValue(strMessID, TlHead, "1. KOËECHÛE ÏAPÛ:", "ÏPOKAT ËEBOÃO KOËECA", 1);	
// òåëåæêà 1 (Íàäðåññîðíàÿ áàëêà)
	t->NadrBl.OwnerCode = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "KOÄ ÆEË. AÄM. COÁCTBEHHÈKA", 0);
	t->NadrBl.IzgYr = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "ÃOÄ ÈÇÃOTOBËEHÈß", 0);
	t->NadrBl.IzgPr = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ", 0);
	t->NadrBl.Number = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "HOMEP", 0);
	t->NadrBl.GlPodp = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "ÃËÓÁÈHA ÏOÄÏßTHÈKA", 0);
	t->NadrBl.DmPodp = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "ÄÈAMETP ÏOÄÏßTHÈKA", 0);
	t->NadrBl.VstPodp = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "BOCCTAHOBËEHÈE ÏOÄÏßTHÈKA", 0);
	t->NadrBl.DatProdSl = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "MEC. È ÃOÄ ÏPOÄËEH. CPOKA CËÓÆÁÛ", 0);
	t->NadrBl.PrProdSl = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "ÏPEÄÏPÈßTÈE ÏPOÄËEHÈß\nCPOKA CËÓÆÁÛ", 0);
	t->NadrBl.Rem = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "OÁÚEM PEMOHTA", 0);
	t->NadrBl.FinishYr = GetValue(strMessID, TlHead, "2. HAÄPECCOPHAß ÁAËKA", "ÃOÄ OKOH×AH. CPOKA CËÓÆÁÛ", 0);
// òåëåæêà 1 (Áîêîâûå ðàìû)
	t->RamR.Rem = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "OÁÚEM PEMOHTA", 0);
	t->RamR.OwnerCode = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "KOÄ ÆEË. AÄM. COÁCTBEHHÈKA", 0);
	t->RamR.IzgYr = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÃOÄ ÈÇÃOTOBËEHÈß", 0);
	t->RamR.IzgPr = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ", 0);
	t->RamR.Number = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "HOMEP", 0);
	t->RamR.BazaBR = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÁAÇA ÁOKOBOÉ PAMÛ", 0);
	t->RamR.VstOpr = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "BOCCTAHOBËEHÈE OÏOPHOÉ\nÏOBEPXHOCTÈ ÁÓKCOBOÃO ÏPOEMA", 0);
	t->RamR.DatProdSl = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "MEC. È ÃOÄ ÏPOÄËEH. CPOKA CËÓÆÁÛ", 0);
	t->RamR.PrProdSl = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÏPEÄÏPÈßTÈE ÏPOÄËEHÈß\nCPOKA CËÓÆÁÛ", 0);
	t->RamR.FinishYr = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÃOÄ OKOH×AH. CPOKA CËÓÆÁÛ", 0);

	t->RamL.Rem = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "OÁÚEM PEMOHTA", 1);
	t->RamL.OwnerCode = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "KOÄ ÆEË. AÄM. COÁCTBEHHÈKA", 1);
	t->RamL.IzgYr = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÃOÄ ÈÇÃOTOBËEHÈß", 1);
	t->RamL.IzgPr = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ", 1);
	t->RamL.Number = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "HOMEP", 1);
	t->RamL.BazaBR = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÁAÇA ÁOKOBOÉ PAMÛ", 1);
	t->RamL.VstOpr = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "BOCCTAHOBËEHÈE OÏOPHOÉ\nÏOBEPXHOCTÈ ÁÓKCOBOÃO ÏPOEMA", 1);
	t->RamL.DatProdSl = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "MEC. È ÃOÄ ÏPOÄËEH. CPOKA CËÓÆÁÛ", 1);
	t->RamL.PrProdSl = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÏPEÄÏPÈßTÈE ÏPOÄËEHÈß\nCPOKA CËÓÆÁÛ", 1);
	t->RamL.FinishYr = GetValue(strMessID, TlHead, "3. ÁOKOBÛE PAMÛ", "ÃOÄ OKOH×AH. CPOKA CËÓÆÁÛ", 1);
	
	// òåëåæêà 1 (õàðàêòåðèñòèêà òåëåæêè)
	t->TlRem = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "OÁÚEM PEMOHTA TEËEÆKÈ", 0);
	//ïðàâàÿ ñòîðîíà
	t->TlRight.FrkKlL = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÇABÛØEHÈE(ÇAHÈÆEHÈE)\nËEBOÃO ÔPÈKÖÈOHHOÃO KËÈHA", 0);
	t->TlRight.FrkKlR = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÇABÛØEHÈE(ÇAHÈÆEHÈE)\nÏPABOÃO ÔPÈKÖÈOHHOÃO KËÈHA", 0);
	t->TlRight.ZazorProdL = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÏPOÄOËÜHÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ËEBÛÉ)", 0);
	t->TlRight.ZazorProdR = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÏPOÄOËÜHÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ÏPABÛÉ)", 0);
	t->TlRight.ZazorPoprL = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÏOÏEPE×HÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ËEBÛÉ)", 0);
	t->TlRight.ZazorPoprR = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÏOÏEPE×HÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ÏPABÛÉ)", 0);
	t->TlRight.ZazorSklz = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÇAÇOP MEÆÄÓ CKOËÜÇÓHAMÈ\nTEËEÆKÈ È PAMÛ", 0);
	//ëåâàÿ ñòîðîíà
	t->TlLeft.FrkKlL = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÇABÛØEHÈE(ÇAHÈÆEHÈE)\nËEBOÃO ÔPÈKÖÈOHHOÃO KËÈHA", 1);
	t->TlLeft.FrkKlR = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÇABÛØEHÈE(ÇAHÈÆEHÈE)\nÏPABOÃO ÔPÈKÖÈOHHOÃO KËÈHA", 1);
	t->TlLeft.ZazorProdL = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÏPOÄOËÜHÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ËEBÛÉ)", 1);
	t->TlLeft.ZazorProdR = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÏPOÄOËÜHÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ÏPABÛÉ)", 1);
	t->TlLeft.ZazorPoprL = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÏOÏEPE×HÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ËEBÛÉ)", 1);
	t->TlLeft.ZazorPoprR = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÏOÏEPE×HÛÉ ÇAÇOP MEÆÄÓ ÁOKOBOÉ\nPAMOÉ È KOPÏÓCOM ÁÓKCÛ(ÏPABÛÉ)", 1);
	t->TlLeft.ZazorSklz = GetValue(strMessID, TlHead, "4. XAPAKTEPÈCTÈKA TEËEÆKÈ", "ÇAÇOP MEÆÄÓ CKOËÜÇÓHAMÈ\nTEËEÆKÈ È PAMÛ", 1);
// òåëåæêà (ñîåäèíèòåëüíàÿ áàëêà)
	if( sb )
	{
		sb->IzgYr  = GetValue(strMessID, TlHead, "5. COEÄÈHÈTEËÜHAß ÁAËKA", "ÃOÄ ÈÇÃOTOBËEHÈß", 0);
		sb->IzgPr  = GetValue(strMessID, TlHead, "5. COEÄÈHÈTEËÜHAß ÁAËKA", "ÏPEÄÏPÈßTÈE-ÈÇÃOTOBÈTEËÜ", 0);
		sb->Number = GetValue(strMessID, TlHead, "5. COEÄÈHÈTEËÜHAß ÁAËKA", "HOMEP", 0);
		sb->PodpD  = GetValue(strMessID, TlHead, "5. COEÄÈHÈTEËÜHAß ÁAËKA", "ÄÈAMETP ÏOÄÏßTHÈKA", 0);
	}
}

CString CMsg4624Dispatcher::GetValue(CString sec1, CString VarName)
{
	DWORD dwID = Values.GetSectionID(sec1, 0);
	for( int i=0; i < Values.iVarCount; i++ )
	{
		if( VarName == Values.Var[i].strName && 
			dwID == Values.Var[i].iSecionID )
		{
			return Values.Var[i].strVal1;
		}
	}
	return "";
}

void CMsg4624Dispatcher::GetInsSlString(CString &str)
{
//	CString str;
	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));
	char cDat[16] = "";
	GetLocalTime(&st);
	sprintf(cDat, "%.4d%.2d%.2d", st.wYear, st.wMonth, st.wDay);
    int os = 0;
    if( GetOsCount() == 8 ) os = 1;
	str.Format("pTov_S4624InsSL NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '%s', '%s', '%s', '%s', '%s', NULL, NULL, NULL, NULL, NULL, %d, NULL",
		Cont4624.VagNum,
		Cont4624.SendPr,
		Cont4624.PtoVag,
		Cont4624.RemVag,
		Cont4624.SendDat,//cDat,
        os);

//	return str;
}



//extern CString isNull(CString Val);

CString CMsg4624Dispatcher::GetRazmerScript ()
{
	CContainerTl4624 *t1 = &Cont4624.Tl1;
	CContainerTl4624 *t2 = &Cont4624.Tl2;
	CContainerTl4624 *t3 = &Cont4624.Tl3;
	CContainerTl4624 *t4 = &Cont4624.Tl4;


	char cQ[16384] = "";

	if( GetOsCount() > 4)
	{
		sprintf( cQ, "set nocount on\n\
set dateformat dmy\n\
declare @error int\n\
set @error = 0\n\
begin tran\n\
create table #VagonArxTovPairs (\n\
 VagID       int,\n\
 D_Test      datetime, --\n\
 Side        tinyint,    -- Ñòîðîíà 0 - ëåâàÿ, 1 - ïðàâàÿ\n\
 IsDevice    tinyint,    -- 4 - c.2730, 5 - c.4624\n\
 ID_Who      int,    -- Äëÿ ID_Device = 5, ID_Employee (ïàðîëü íà âõîäå)\n\
 Axle        tinyint,    -- Íîìåð îñè\n\
 Thickness   smallint,    -- òîëùèíà ãðåáíÿ\n\
 RimThickness smallint,    -- òîëùèíà îáîäà\n\
 RimWidth    smallint,    -- øèðèíà îáîäà - íåò\n\
 Roll        smallint,    -- Ïðîêàò    \n\
 Diameter    smallint,    -- Äèàìåòð êîëåñà - íåò\n\
 Jag         int,\n\
 Flat        int,\n\
 Welding     int\n\
)\n\
declare @VagID bigint\n\
select @VagID=VagId from dbo.Vagon where Nom_Vag='%s'\n\
if @VagID is null goto roll_\n\
--Ñþäà âñòàâëÿòü äàííûå:\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,1,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,1,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,2,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,2,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,3,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,3,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,4,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,4,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,5,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,5,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,6,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,6,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,7,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,7,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,8,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,8,%s,%s,null,%s,null)\n\
---------------------\n\
exec @error = dbo.pTovPos4936m5_75 2\n\
if @@error != 0 or @error != 0 goto roll_\n\
drop table #VagonArxTovPairs\n\
commit tran\n\
goto ok_\n\
roll_: rollback tran\n\
ok_:",
		Cont4624.VagNum,
		isNull(t1->KP1.WidthGrebL),/*Thickness*/ isNull(t1->KP1.WidthObodL),/*RimThickness*/ isNull(t1->KP1.ProkatL),/*Roll*/
		isNull(t1->KP1.WidthGrebR),/*Thickness*/ isNull(t1->KP1.WidthObodR),/*RimThickness*/ isNull(t1->KP1.ProkatR),/*Roll*/
		isNull(t1->KP2.WidthGrebL),/*Thickness*/ isNull(t1->KP2.WidthObodL),/*RimThickness*/ isNull(t1->KP2.ProkatL),/*Roll*/
		isNull(t1->KP2.WidthGrebR),/*Thickness*/ isNull(t1->KP2.WidthObodR),/*RimThickness*/ isNull(t1->KP2.ProkatR),/*Roll*/
		isNull(t2->KP1.WidthGrebL),/*Thickness*/ isNull(t2->KP1.WidthObodL),/*RimThickness*/ isNull(t2->KP1.ProkatL),/*Roll*/
		isNull(t2->KP1.WidthGrebR),/*Thickness*/ isNull(t2->KP1.WidthObodR),/*RimThickness*/ isNull(t2->KP1.ProkatR),/*Roll*/
		isNull(t2->KP2.WidthGrebL),/*Thickness*/ isNull(t2->KP2.WidthObodL),/*RimThickness*/ isNull(t2->KP2.ProkatL),/*Roll*/
		isNull(t2->KP2.WidthGrebR),/*Thickness*/ isNull(t2->KP2.WidthObodR),/*RimThickness*/ isNull(t2->KP2.ProkatR),/*Roll*/
		isNull(t3->KP1.WidthGrebL),/*Thickness*/ isNull(t3->KP1.WidthObodL),/*RimThickness*/ isNull(t3->KP1.ProkatL),/*Roll*/
		isNull(t3->KP1.WidthGrebR),/*Thickness*/ isNull(t3->KP1.WidthObodR),/*RimThickness*/ isNull(t3->KP1.ProkatR),/*Roll*/
		isNull(t3->KP2.WidthGrebL),/*Thickness*/ isNull(t3->KP2.WidthObodL),/*RimThickness*/ isNull(t3->KP2.ProkatL),/*Roll*/
		isNull(t3->KP2.WidthGrebR),/*Thickness*/ isNull(t3->KP2.WidthObodR),/*RimThickness*/ isNull(t3->KP2.ProkatR),/*Roll*/
		isNull(t4->KP1.WidthGrebL),/*Thickness*/ isNull(t4->KP1.WidthObodL),/*RimThickness*/ isNull(t4->KP1.ProkatL),/*Roll*/
		isNull(t4->KP1.WidthGrebR),/*Thickness*/ isNull(t4->KP1.WidthObodR),/*RimThickness*/ isNull(t4->KP1.ProkatR),/*Roll*/
		isNull(t4->KP2.WidthGrebL),/*Thickness*/ isNull(t4->KP2.WidthObodL),/*RimThickness*/ isNull(t4->KP2.ProkatL),/*Roll*/
		isNull(t4->KP2.WidthGrebR),/*Thickness*/ isNull(t4->KP2.WidthObodR),/*RimThickness*/ isNull(t4->KP2.ProkatR)/*Roll*/);
	
	}
	else
	{
		sprintf( cQ, "set nocount on\n\
set dateformat dmy\n\
declare @error int\n\
set @error = 0\n\
begin tran\n\
create table #VagonArxTovPairs (\n\
 VagID       int,\n\
 D_Test      datetime, --\n\
 Side        tinyint,    -- Ñòîðîíà 0 - ëåâàÿ, 1 - ïðàâàÿ\n\
 IsDevice    tinyint,    -- 4 - c.2730, 5 - c.4624\n\
 ID_Who      int,    -- Äëÿ ID_Device = 5, ID_Employee (ïàðîëü íà âõîäå)\n\
 Axle        tinyint,    -- Íîìåð îñè\n\
 Thickness   smallint,    -- òîëùèíà ãðåáíÿ\n\
 RimThickness smallint,    -- òîëùèíà îáîäà\n\
 RimWidth    smallint,    -- øèðèíà îáîäà - íåò\n\
 Roll        smallint,    -- Ïðîêàò    \n\
 Diameter    smallint,    -- Äèàìåòð êîëåñà - íåò\n\
 Jag         int,\n\
 Flat        int,\n\
 Welding     int\n\
 )\n\
declare @VagID bigint\n\
select @VagID=VagId from dbo.Vagon where Nom_Vag='%s'\n\
if @VagID is null goto roll_\n\
--Ñþäà âñòàâëÿòü äàííûå:\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,1,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,1,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,2,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,2,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,3,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,3,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,4,null,4,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,4,null,4,%s,%s,null,%s,null)\n\
---------------------\n\
exec @error = dbo.pTovPos4936m5_75 2\n\
if @@error != 0 or @error != 0 goto roll_\n\
drop table #VagonArxTovPairs\n\
commit tran\n\
goto ok_\n\
roll_: rollback tran\n\
ok_:",
		Cont4624.VagNum,
		isNull(t1->KP1.WidthGrebL),/*Thickness*/ isNull(t1->KP1.WidthObodL),/*RimThickness*/ isNull(t1->KP1.ProkatL),/*Roll*/
		isNull(t1->KP1.WidthGrebR),/*Thickness*/ isNull(t1->KP1.WidthObodR),/*RimThickness*/ isNull(t1->KP1.ProkatR),/*Roll*/
		isNull(t1->KP2.WidthGrebL),/*Thickness*/ isNull(t1->KP2.WidthObodL),/*RimThickness*/ isNull(t1->KP2.ProkatL),/*Roll*/
		isNull(t1->KP2.WidthGrebR),/*Thickness*/ isNull(t1->KP2.WidthObodR),/*RimThickness*/ isNull(t1->KP2.ProkatR),/*Roll*/
		isNull(t2->KP1.WidthGrebL),/*Thickness*/ isNull(t2->KP1.WidthObodL),/*RimThickness*/ isNull(t2->KP1.ProkatL),/*Roll*/
		isNull(t2->KP1.WidthGrebR),/*Thickness*/ isNull(t2->KP1.WidthObodR),/*RimThickness*/ isNull(t2->KP1.ProkatR),/*Roll*/
		isNull(t2->KP2.WidthGrebL),/*Thickness*/ isNull(t2->KP2.WidthObodL),/*RimThickness*/ isNull(t2->KP2.ProkatL),/*Roll*/
		isNull(t2->KP2.WidthGrebR),/*Thickness*/ isNull(t2->KP2.WidthObodR),/*RimThickness*/ isNull(t2->KP2.ProkatR)/*Roll*/);
	}

	return CString (cQ);
}

void CMsg4624Dispatcher::GetInsInfTlString(int nTl, __int64 qwIDS, int nPhrase, char *str)
{
//	CString str;
	CContainerTl4624 *t = NULL;
	CContainerSB4624 *b = NULL;
	switch( nTl )
    {
	case 1: t = &Cont4624.Tl1; b = &Cont4624.SB1; break;
	case 2: t = &Cont4624.Tl2; b = &Cont4624.SB1; break;
	case 3: t = &Cont4624.Tl3; b = &Cont4624.SB2; break;
	case 4: t = &Cont4624.Tl4; b = &Cont4624.SB2; break;
	}
    if( !str ) AfxMessageBox("str sucks");
    else 
    {
//        sprintf(str, "pTov_S4624InsInf %s, 1, %s", isNull(qwIDS), isNull((WORD)nPhrase));

//        AfxMessageBox((CString)"---->\n" + str);
    } 
/*
	AfxMessageBox("pre sprintf");
	sprintf(str, "%s", "Mailing-List: contact bugtraq-help@securityfocus.com; run by ezmlm Precedence: bulk List-Id: <bugtraq.list-id.securityfocus.com> List-Post: <mailto:bugtraq@securityfocus.com> List-Help: <mailto:bugtraq-help@securityfocus.com> List-Unsubscribe: <mailto:bugtraq-unsubscribe@securityfocus.com> List-Subscribe: <mailto:bugtraq-subscribe@securityfocus.com> Delivered-To: mailing list bugtraq@securityfocus.com Message-ID: <024601c228e7$47b0a2f0$82e893c3@XU5UDGJMHXJ300> Subject: Microsoft SQL Server 2000 'BULK INSERT' Buffer Overflow (#NISR11072002) Date: Thu, 11 Jul 2002 15:28:52 +0100 MIME-Version: 1.0 ");
	AfxMessageBox("after sprintf");
*/

	if( t->NadrBl.FinishYr.GetLength() ) t->NadrBl.DatProdSl = t->NadrBl.FinishYr;
	if( t->RamL.FinishYr.GetLength() ) t->RamL.DatProdSl = t->RamL.FinishYr;
	if( t->RamR.FinishYr.GetLength() ) t->RamR.DatProdSl = t->RamR.FinishYr;

	sprintf(str, "pTov_S4624InsInf @IDS, 1, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s,\
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s,\
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, \
%s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s",
//		isNull(qwIDS),
		isNull((WORD)nPhrase),

		isNull(t->KP1.OwnerCode),
		isNull(t->KP1.OsvDat),
		isNull(t->KP1.OsvPr),
		isNull(t->KP1.IzgOsPr),
		isNull(t->KP1.OsNum),
		isNull(t->KP1.IsgOsYr),
		isNull(t->KP1.WidthObodR),
		isNull(t->KP1.WidthGrebR),
		isNull(t->KP1.ProkatR),
		isNull(t->KP1.WidthObodL),
		isNull(t->KP1.WidthGrebL),
		isNull(t->KP1.ProkatL),
		
		isNull(t->KP2.OwnerCode),
		isNull(t->KP2.OsvDat),
		isNull(t->KP2.OsvPr),
		isNull(t->KP2.IzgOsPr),
		isNull(t->KP2.OsNum),
		isNull(t->KP2.IsgOsYr),
		isNull(t->KP2.WidthObodR),
		isNull(t->KP2.WidthGrebR),
		isNull(t->KP2.ProkatR),
		isNull(t->KP2.WidthObodL),
		isNull(t->KP2.WidthGrebL),
		isNull(t->KP2.ProkatL),

		isNull(t->NadrBl.OwnerCode),
		isNull(t->NadrBl.IzgPr),
		isNull(t->NadrBl.Number),
		isNull(t->NadrBl.IzgYr),
		isNull(t->NadrBl.GlPodp),
		isNull(t->NadrBl.DmPodp),
		isNull(t->NadrBl.VstPodp),
		isNull(t->NadrBl.DatProdSl),
		isNull(t->NadrBl.PrProdSl),
		isNull(t->NadrBl.Rem),

		isNull(t->RamR.OwnerCode),
		isNull(t->RamR.IzgPr),
		isNull(t->RamR.Number),
		isNull(t->RamR.IzgYr),
		isNull(t->RamR.BazaBR),
		isNull(t->RamR.VstOpr),
		isNull(t->RamR.DatProdSl),
		isNull(t->RamR.PrProdSl),
//		(CString)"+++" + isNull(t->RamR.Rem),
		isNull(t->RamR.Rem),

		isNull(t->RamL.OwnerCode),
		isNull(t->RamL.IzgPr),
		isNull(t->RamL.Number),
		isNull(t->RamL.IzgYr),
		isNull(t->RamL.BazaBR),
		isNull(t->RamL.VstOpr),
		isNull(t->RamL.DatProdSl),
		isNull(t->RamL.PrProdSl),
//		(CString)"+++" + isNull(t->RamL.Rem),
		isNull(t->RamL.Rem),

		isNull(t->TlRem),

		isNull(t->TlRight.FrkKlL),
		isNull(t->TlRight.FrkKlR),
		isNull(t->TlRight.ZazorProdL),
		isNull(t->TlRight.ZazorProdR),
		isNull(t->TlRight.ZazorPoprL),
		isNull(t->TlRight.ZazorPoprR),
		isNull(t->TlRight.ZazorSklz),

		isNull(t->TlLeft.FrkKlL),
		isNull(t->TlLeft.FrkKlR),
		isNull(t->TlLeft.ZazorProdL),
		isNull(t->TlLeft.ZazorProdR),
		isNull(t->TlLeft.ZazorPoprL),
		isNull(t->TlLeft.ZazorPoprR),
		isNull(t->TlLeft.ZazorSklz),

		isNull(b->IzgPr),
		isNull(b->Number),
		isNull(b->IzgYr),
		isNull(b->PodpD));
	
//	AfxMessageBox((CString)str + "\nIN DLL");
//	return str;
}

int CMsg4624Dispatcher::GetOsCount()
{
	if( Cont4624.i8Os ) return 8;
	return 4;
}

int CMsg4624Dispatcher::GotNVag()
{
	if( Cont4624.VagNum == "" ) return 0;
	return 1;
}
