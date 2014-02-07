#pragma once

struct CContainerKP4624
{
	CString OwnerCode;
	CString OsvDat;
	CString OsvPr;
	CString IsgOsYr;
	CString IzgOsPr;
	CString OsNum;
	CString WidthObodR;
	CString WidthGrebR;
	CString ProkatR;
	CString WidthObodL;
	CString WidthGrebL;
	CString ProkatL;
};

struct CContainerNadrBl4624
{
	CString OwnerCode;
	CString IzgYr;
	CString IzgPr;
	CString Number;
	CString GlPodp;
	CString DmPodp;
	CString VstPodp;
	CString DatProdSl;
	CString PrProdSl;
	CString Rem;
	CString FinishYr;
};

struct CContainerBkRam4624
{
	CString OwnerCode;
	CString IzgYr;
	CString IzgPr;
	CString Number;
	CString BazaBR;
	CString VstOpr;
	CString DatProdSl;
	CString PrProdSl;
	CString Rem;
	CString FinishYr;
};

struct CContainerTlSide4624
{
	CString FrkKlL;
	CString FrkKlR;
	CString ZazorProdL;
	CString ZazorProdR;
	CString ZazorPoprL;
	CString ZazorPoprR;
	CString ZazorSklz;
};

struct CContainerSB4624
{
	CString IzgYr;
	CString IzgPr;
	CString Number;
	CString PodpD;
};

struct CContainerTl4624
{
	CContainerKP4624 KP1;
	CContainerKP4624 KP2;

	CContainerNadrBl4624 NadrBl;

	CContainerBkRam4624 RamR;
	CContainerBkRam4624 RamL;
	CString TlRem;
	CContainerTlSide4624 TlLeft;
	CContainerTlSide4624 TlRight;

};

struct CContainer4624
{
	CString SendDat;
	CString SendPr;
	CString RemVag;
	CString VagNum;
	CString PtoVag;
	CContainerTl4624 Tl1;
	CContainerTl4624 Tl2;
	CContainerTl4624 Tl3;
	CContainerTl4624 Tl4;

	CContainerSB4624 SB1;
	CContainerSB4624 SB2;

	int i8Os;
};

struct CValueKeeper
{
	CString strName;
	CString strVal1;
	CString strVal2;
	int iSecionID;
	void Set(CString n, int id)
	{
		strName = n;
		iSecionID = id;
	}
};

struct CSection
{
	DWORD dwSectionID;
	DWORD dwSubSectionID;
	CString strName;
	void Set(CString name, DWORD dwSectionID)
	{
		strName = name;
	};
	CSection()
	{
		dwSectionID = 0;
		dwSubSectionID = 0;
		strName = "";
	}
};

struct CShelves
{
	CValueKeeper Var[250];
	CSection Section[50];

	DWORD dwLastSectionID;
	void InitShelves(int s1, int s2, int s3, int s4, int s5);

	void AddSection(CString Name, DWORD dwSubSectionID);
	DWORD GetSectionID(CString Name, int);
	CSection * GetSection(DWORD dwSectionID);
	void ReplaceVarName(CString strOldName, CString strNewName);

	void AddVar(CString Name, int SecID);
	int iSecionCount;
	int	iVarCount;
	CShelves();
};

#define MAX_MSG_LENGTH 25800

class CMsg4624Dispatcher
{

public:
	int i2731;
	CMsg4624Dispatcher(void);
	~CMsg4624Dispatcher(void);
	int Dispatch2731();
	int Get2731Script(char *);
	CContainer4624 Cont4624;
	void SetSourceText(char *str, int len);
	void Dispatch();
	int GetOsCount();
	CShelves Values;
	int iGot2731Script;
private:
	void DispatchSection(DWORD dwSectionID, int iStartIndex, int iEndIndex);
	CString strSourceText;
	char cScript2731[20000];
	//	char	cSourceText[MAX_MSG_LENGTH];
	void FillStruct(CContainer4624 *pCont);
	CString GetValue(CString strTitle);
	CString GetValue(CString sec1, CString VarName);
	CString GetValue(CString sec1, CString sec2, CString sec3, CString VarName, int iSide, int DateConvert=0);
	void FillTL(CString TlHead, CContainerTl4624 *, CContainerSB4624 *sb = NULL);
	CString strMessID;    
public:		
	void GetInsSlString(CString &str);
	void GetInsInfTlString(int nTl, __int64 qwIDS, int nPhrase, char *str);
	int  GotNVag();
	int ourMessage;

	CString GetRazmerScript ();
};

void Dos2Win(char * cLine);
void Rus2Eng(char * cLine);
void Eng2Rus(CString &strLine);
void Eng2Rus(char * cLine);
void ToUpperCase(char * cLine);
