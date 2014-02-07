// Dspm4624.h: interface for the CDspm4624 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DSPM4624_H__7EC5871A_B9BB_4070_AADC_DAC788BB326F__INCLUDED_)
#define AFX_DSPM4624_H__7EC5871A_B9BB_4070_AADC_DAC788BB326F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef DSP4624_EXPORTS
#define DSP4624_API __declspec(dllexport)
#else
#define DSP4624_API __declspec(dllimport)
#endif

class DSP4624_API CDspm4624  
{
public:
	int GetVersion();
	CDspm4624();
    int dGetOsCount();
    void dGetInsSlString(char *str);
    void dGetInsInfTlString(__int64 qwIDS, char *str);
    void Dispatch(char *cStr, int len);

    virtual ~CDspm4624();

};

#endif // !defined(AFX_DSPM4624_H__7EC5871A_B9BB_4070_AADC_DAC788BB326F__INCLUDED_)
