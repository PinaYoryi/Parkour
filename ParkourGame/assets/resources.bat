cd ../../P32021/bin
copy /Y resources.cfg "../../ParkourGame/bin/resources.cfg"
cd ../../ParkourGame/assets
echo [General] >> ../bin/resources.cfg
echo FileSystem=%CD%/resources >> ../bin/resources.cfg
for /r %CD% %%f in (*.zip) do echo Zip=%%~pnxf >> ../bin/resources.cfg
cd ..
if not exist assets/resources/gui goto ceguiend
if exist assets/resources/gui/animations echo [animations] >> bin/resources.cfg & echo FileSystem=%CD%/assets/resources/gui/animations >> bin/resources.cfg
if exist assets/resources/gui/fonts echo [fonts] >> bin/resources.cfg & echo FileSystem=%CD%/assets/resources/gui/fonts >> bin/resources.cfg
if exist assets/resources/gui/imagesets echo [imagesets] >> bin/resources.cfg & echo FileSystem=%CD%/assets/resources/gui/imagesets >> bin/resources.cfg
if exist assets/resources/gui/layouts echo [layouts] >> bin/resources.cfg & echo FileSystem=%CD%/assets/resources/gui/layouts >> bin/resources.cfg
if exist assets/resources/gui/looknfeel echo [looknfeel] >> bin/resources.cfg & echo FileSystem=%CD%/assets/resources/gui/looknfeel >> bin/resources.cfg
if exist assets/resources/gui/lua_scripts echo [luaScripts] >> bin/resources.cfg & echo FileSystem=%CD%/assets/resources/gui/lua_scripts >> bin/resources.cfg
if exist assets/resources/gui/schemes echo [schemes] >> bin/resources.cfg & echo FileSystem=%CD%/assets/resources/gui/schemes >> bin/resources.cfg
if exist assets/resources/gui/xml_schemas echo [xmlSchemas] >> bin/resources.cfg & echo FileSystem=%CD%/assets/resources/gui/xml_schemas >> bin/resources.cfg
:ceguiend
cd assets/
