# Microsoft Developer Studio Project File - Name="CruelTruck" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=CruelTruck - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CruelTruck.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CruelTruck.mak" CFG="CruelTruck - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CruelTruck - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CruelTruck - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CruelTruck - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "include" /I "include/sdl" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386 /out:"../CruelTruck.exe"

!ELSEIF  "$(CFG)" == "CruelTruck - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "include" /I "include/sdl" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"libcd.lib" /out:"../CruelTruck.exe" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "CruelTruck - Win32 Release"
# Name "CruelTruck - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Calc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Calc.cpp
# End Source File
# End Group
# Begin Group "Init"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Init.cpp
# End Source File
# End Group
# Begin Group "Render"

# PROP Default_Filter ""
# Begin Group "gui"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Button.cpp
# End Source File
# Begin Source File

SOURCE=.\Chouse.cpp
# End Source File
# Begin Source File

SOURCE=.\Gui.cpp
# End Source File
# Begin Source File

SOURCE=.\Icon.cpp
# End Source File
# Begin Source File

SOURCE=.\Scroll.cpp
# End Source File
# Begin Source File

SOURCE=.\Text.cpp
# End Source File
# End Group
# Begin Group "Scene"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Scene.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\Render.cpp
# End Source File
# End Group
# Begin Group "Input"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Input.cpp
# End Source File
# End Group
# Begin Group "Conf"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Conf.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Calch"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Calc.h
# End Source File
# End Group
# Begin Group "Inith"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Init.h
# End Source File
# End Group
# Begin Group "Renderh"

# PROP Default_Filter ""
# Begin Group "guih"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Button.h
# End Source File
# Begin Source File

SOURCE=.\Chouse.h
# End Source File
# Begin Source File

SOURCE=.\Gui.h
# End Source File
# Begin Source File

SOURCE=.\Icon.h
# End Source File
# Begin Source File

SOURCE=.\Scroll.h
# End Source File
# Begin Source File

SOURCE=.\Text.h
# End Source File
# End Group
# Begin Group "Sceneh"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Scene.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Render.h
# End Source File
# End Group
# Begin Group "Inputh"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Input.h
# End Source File
# End Group
# Begin Group "Confh"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Conf.h
# End Source File
# End Group
# End Group
# End Target
# End Project
