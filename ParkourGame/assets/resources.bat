cd ../../P32021/bin
copy /Y resources.cfg "../../ParkourGame/bin/resources.cfg"
cd ../../ParkourGame/assets
xcopy ..\..\P32021\assets\resources ..\bin\resources /y /e /i
xcopy .\resources ..\bin\resources /y /e /i
cd ..\bin\resources
echo [General] >> ../resources.cfg
echo FileSystem=%CD%/resources >> ../resources.cfg
for /r %CD% %%f in (*.zip) do echo Zip=%%~pnxf >> ../resources.cfg
if not exist ../resources/gui goto ceguiend
if exist ../resources/gui/animations echo [animations] >> ../resources.cfg & echo FileSystem=%CD%/gui/animations >> ../resources.cfg
if exist ../resources/gui/fonts echo [fonts] >> ../resources.cfg & echo FileSystem=%CD%/gui/fonts >> ../resources.cfg
if exist ../resources/gui/imagesets echo [imagesets] >> ../resources.cfg & echo FileSystem=%CD%/gui/imagesets >> ../resources.cfg
if exist ../resources/gui/layouts echo [layouts] >> ../resources.cfg & echo FileSystem=%CD%/gui/layouts >> ../resources.cfg
if exist ../resources/gui/looknfeel echo [looknfeel] >> ../resources.cfg & echo FileSystem=%CD%/gui/looknfeel >> ../resources.cfg
if exist ../resources/gui/lua_scripts echo [luaScripts] >> ../resources.cfg & echo FileSystem=%CD%/gui/lua_scripts >> ../resources.cfg
if exist ../resources/gui/schemes echo [schemes] >> ../resources.cfg & echo FileSystem=%CD%/gui/schemes >> ../resources.cfg
if exist ../resources/gui/xml_schemas echo [xmlSchemas] >> ../resources.cfg & echo FileSystem=%CD%/gui/xml_schemas >> ../resources.cfg
:ceguiend