!include "MUI2.nsh"

Name "Ogrevedad"
OutFile "Ogrevedad setup.exe"
Unicode True
InstallDir "$PROGRAMFILES64\Ogrevedad"
RequestExecutionLevel admin

Var StartMenuFolder
Var "GameName"

!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP "header_bitmap.bmp" ; NOTE: images have to be 8 bits in depth
!define MUI_HEADERIMAGE_UNBITMAP "header_bitmap.bmp" ; NOTE: images have to be 8 bits in depth

!define MUI_WELCOMEFINISHPAGE_BITMAP "welcomepage_bitmap.bmp"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "welcomepage_bitmap.bmp"

Function finishpageaction
	CreateShortcut "$desktop\$GameName.lnk" "$INSTDIR\Ogrevedad.exe"
FunctionEnd

!define MUI_FINISHPAGE_SHOWREADME ""
!define MUI_FINISHPAGE_SHOWREADME_NOTCHECKED
!define MUI_FINISHPAGE_SHOWREADME_TEXT "Create Desktop Shortcut"
!define MUI_FINISHPAGE_SHOWREADME_FUNCTION finishpageaction

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_STARTMENU PinaYoryi $StartMenuFolder
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

Section

	StrCpy $GameName "Ogrevedad"
	
    # set the directory and files to go to the output directory
	File /r "..\ParkourGame\bin\*"
	#end of files
 
 
    # create the uninstaller
    WriteUninstaller "$INSTDIR\uninstall $GameName.exe"
	
	!insertmacro MUI_STARTMENU_WRITE_BEGIN PinaYoryi
	
    ;Create shortcuts
    CreateDirectory "$SMPROGRAMS\$StartMenuFolder"
    CreateShortcut "$SMPROGRAMS\$StartMenuFolder\uninstall $GameName.lnk" "$INSTDIR\uninstall $GameName.exe"
    CreateShortcut "$SMPROGRAMS\$StartMenuFolder\$GameName.lnk" "$INSTDIR\Ogrevedad.exe"
	
	!insertmacro MUI_STARTMENU_WRITE_END

SectionEnd

# uninstaller section start
Section "Uninstall"
 
 	StrCpy $GameName "Ogrevedad"
	
    # first, delete the uninstaller
    Delete "$INSTDIR\uninstall $GameName.exe"
	
	# second, remove the link from the start menu	
   !insertmacro MUI_STARTMENU_GETFOLDER PinaYoryi $StartMenuFolder
   
    Delete "$SMPROGRAMS\$StartMenuFolder\uninstall $GameName.lnk"
    Delete "$SMPROGRAMS\$StartMenuFolder\$GameName.lnk"
	Delete "$desktop\$GameName.lnk"
	RMDir "$SMPROGRAMS\$StartMenuFolder"
	
	RMDir /r $INSTDIR

# uninstaller section end
SectionEnd