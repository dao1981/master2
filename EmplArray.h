// EmplArray.h: interface for the CEmplArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMPLARRAY_H__F5987CA9_F56C_4DDA_B396_E46F63B75341__INCLUDED_)
#define AFX_EMPLARRAY_H__F5987CA9_F56C_4DDA_B396_E46F63B75341__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct CEmployee
{
    int     iID;
    char    cFIO[64];
    DWORD   dwTabNumber;
    CEmployee()
    {
        iID = 0;
        cFIO[0] = 0;
        dwTabNumber = 0;
    }
};



class CEmplArray  
{
public:
	CString GetFamByID(DWORD dwID);
	void Clear();
	CEmplArray();
	virtual ~CEmplArray();
    
    CEmployee  Empl[3000];
    int        iCount;
    int GetEmployee(char *cFilter, char *cDestFam, DWORD *dwDestID);
    int AddEmployee(int iID, char *cFIO, DWORD dwTab);
    int GetIDbyFIO(char *);
    DWORD GetTabNumByID(int iID);
};

#endif // !defined(AFX_EMPLARRAY_H__F5987CA9_F56C_4DDA_B396_E46F63B75341__INCLUDED_)
