# Microsoft Developer Studio Project File - Name="master" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=master - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "master.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "master.mak" CFG="master - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "master - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "master - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "master - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "master - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "master - Win32 Release"
# Name "master - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AuthDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DBWire.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAccel1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAddKpSmall.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAddPeres.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAddPr.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAddRemVag.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgASNeispKp.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAuth1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBDSelectRez.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCreateAdm.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCreateIni.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgDBKPSelect.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgDBOsSelect.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgDBRemSelect.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgDepSelect.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgDisplRP.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgEditKP.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgEditPass.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgEdRsn.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgKpHisoryInp.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgKpVvod1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgListVCHD.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMakeLK.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMakeLK_KPOrder.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMakeLK_Send.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMntBuks.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgObmerKP.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOldKPList.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPeresKP.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPrihodKP.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPrihodOS.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPrObtIn.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRashod.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRazmGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRemKP.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRemVag.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRptVU36M.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRptVU53.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRptVU54.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRptVU90.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSelectOS.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSelRP.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSelZapress.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgShowTwin.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSotrEd.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSprav1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSpravDor.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSpravKdr.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSpravSmp.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSpravTKP.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgTLFromVag.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgVvodRP.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgWheelsToVan.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgZapressKP.cpp
# End Source File
# Begin Source File

SOURCE=.\EmplArray.cpp
# End Source File
# Begin Source File

SOURCE=.\FastGrid.cpp
# End Source File
# Begin Source File

SOURCE=.\ListEx.cpp
# End Source File
# Begin Source File

SOURCE=.\MainForm.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MaskEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\master.cpp
# End Source File
# Begin Source File

SOURCE=.\master.rc
# End Source File
# Begin Source File

SOURCE=.\NewMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintableDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PrinterSelectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\ViewPrintPreview.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AuthDlg.h
# End Source File
# Begin Source File

SOURCE=.\DBWire.h
# End Source File
# Begin Source File

SOURCE=.\DialogHeader.h
# End Source File
# Begin Source File

SOURCE=.\DlgAccel1.h
# End Source File
# Begin Source File

SOURCE=.\DlgAddKpSmall.h
# End Source File
# Begin Source File

SOURCE=.\DlgAddPeres.h
# End Source File
# Begin Source File

SOURCE=.\DlgAddPr.h
# End Source File
# Begin Source File

SOURCE=.\DlgAddRemVag.h
# End Source File
# Begin Source File

SOURCE=.\DlgASNeispKp.h
# End Source File
# Begin Source File

SOURCE=.\DlgAuth1.h
# End Source File
# Begin Source File

SOURCE=.\DlgBDSelectRez.h
# End Source File
# Begin Source File

SOURCE=.\DlgCreateAdm.h
# End Source File
# Begin Source File

SOURCE=.\DlgCreateIni.h
# End Source File
# Begin Source File

SOURCE=.\DlgDBKPSelect.h
# End Source File
# Begin Source File

SOURCE=.\DlgDBOsSelect.h
# End Source File
# Begin Source File

SOURCE=.\DlgDBRemSelect.h
# End Source File
# Begin Source File

SOURCE=.\DlgDepSelect.h
# End Source File
# Begin Source File

SOURCE=.\DlgDisplRP.h
# End Source File
# Begin Source File

SOURCE=.\DlgEditKP.h
# End Source File
# Begin Source File

SOURCE=.\DlgEditPass.h
# End Source File
# Begin Source File

SOURCE=.\DlgEdRsn.h
# End Source File
# Begin Source File

SOURCE=.\DlgKpHisoryInp.h
# End Source File
# Begin Source File

SOURCE=.\DlgKpVvod1.h
# End Source File
# Begin Source File

SOURCE=.\DlgListVCHD.h
# End Source File
# Begin Source File

SOURCE=.\DlgMakeLK.h
# End Source File
# Begin Source File

SOURCE=.\DlgMakeLK_KPOrder.h
# End Source File
# Begin Source File

SOURCE=.\DlgMakeLK_Send.h
# End Source File
# Begin Source File

SOURCE=.\DlgMntBuks.h
# End Source File
# Begin Source File

SOURCE=.\DlgObmerKP.h
# End Source File
# Begin Source File

SOURCE=.\DlgOldKPList.h
# End Source File
# Begin Source File

SOURCE=.\DlgPeresKP.h
# End Source File
# Begin Source File

SOURCE=.\DlgPrihodKP.h
# End Source File
# Begin Source File

SOURCE=.\DlgPrihodOS.h
# End Source File
# Begin Source File

SOURCE=.\DlgPrObtIn.h
# End Source File
# Begin Source File

SOURCE=.\DlgRashod.h
# End Source File
# Begin Source File

SOURCE=.\DlgRazmGroup.h
# End Source File
# Begin Source File

SOURCE=.\DlgRemKP.h
# End Source File
# Begin Source File

SOURCE=.\DlgRemVag.h
# End Source File
# Begin Source File

SOURCE=.\DlgRptVU36M.h
# End Source File
# Begin Source File

SOURCE=.\DlgRptVU53.h
# End Source File
# Begin Source File

SOURCE=.\DlgRptVU54.h
# End Source File
# Begin Source File

SOURCE=.\DlgRptVU90.h
# End Source File
# Begin Source File

SOURCE=.\DlgSelectOS.h
# End Source File
# Begin Source File

SOURCE=.\DlgSelRP.h
# End Source File
# Begin Source File

SOURCE=.\DlgSelZapress.h
# End Source File
# Begin Source File

SOURCE=.\DlgShowTwin.h
# End Source File
# Begin Source File

SOURCE=.\DlgSotrEd.h
# End Source File
# Begin Source File

SOURCE=.\DlgSprav1.h
# End Source File
# Begin Source File

SOURCE=.\DlgSpravDor.h
# End Source File
# Begin Source File

SOURCE=.\DlgSpravKdr.h
# End Source File
# Begin Source File

SOURCE=.\DlgSpravSmp.h
# End Source File
# Begin Source File

SOURCE=.\DlgSpravTKP.h
# End Source File
# Begin Source File

SOURCE=.\DlgTLFromVag.h
# End Source File
# Begin Source File

SOURCE=.\DlgVvodRP.h
# End Source File
# Begin Source File

SOURCE=.\DlgWheelsToVan.h
# End Source File
# Begin Source File

SOURCE=.\DlgZapressKP.h
# End Source File
# Begin Source File

SOURCE=.\EmplArray.h
# End Source File
# Begin Source File

SOURCE=.\FastGrid.h
# End Source File
# Begin Source File

SOURCE=.\ListEx.h
# End Source File
# Begin Source File

SOURCE=.\MainForm.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MaskEdit.h
# End Source File
# Begin Source File

SOURCE=.\master.h
# End Source File
# Begin Source File

SOURCE=.\NewMenu.h
# End Source File
# Begin Source File

SOURCE=.\PrintableDlg.h
# End Source File
# Begin Source File

SOURCE=.\PrinterSelectDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\ViewPrintPreview.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\11111.BMP
# End Source File
# Begin Source File

SOURCE=.\res\11111.jpg
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\ini.bmp
# End Source File
# Begin Source File

SOURCE=.\res\login.bmp
# End Source File
# Begin Source File

SOURCE=.\res\login1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\login2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\master.ico
# End Source File
# Begin Source File

SOURCE=.\res\master.rc2
# End Source File
# Begin Source File

SOURCE=.\res\masterDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\tl.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ToDoSome.txt
# End Source File
# Begin Source File

SOURCE=.\ODBC32.LIB
# End Source File
# End Target
# End Project
