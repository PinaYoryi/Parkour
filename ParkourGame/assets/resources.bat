cd ../../P32021/bin
copy /Y resources.cfg "../../ParkourGame/bin/resources.cfg"
cd ../../ParkourGame/assets
echo [General] >> ../bin/resources.cfg
echo FileSystem=%CD%/resources >> ../bin/resources.cfg
for /r %CD% %%f in (*.zip) do echo Zip=%%~pnxf >> ../bin/resources.cfg
cd ..
echo [animations] >> bin/resources.cfg
echo FileSystem=%CD%/assets/resources/gui/animations >> bin/resources.cfg
echo [fonts] >> bin/resources.cfg
echo FileSystem=%CD%/assets/resources/gui/fonts >> bin/resources.cfg
echo [imagesets] >> bin/resources.cfg
echo FileSystem=%CD%/assets/resources/gui/imagesets >> bin/resources.cfg
echo [layouts] >> bin/resources.cfg
echo FileSystem=%CD%/assets/resources/gui/layouts >> bin/resources.cfg
echo [looknfeel] >> bin/resources.cfg
echo FileSystem=%CD%/assets/resources/gui/looknfeel >> bin/resources.cfg
echo [luaScripts] >> bin/resources.cfg
echo FileSystem=%CD%/assets/resources/gui/lua_scripts >> bin/resources.cfg
echo [schemes] >> bin/resources.cfg
echo FileSystem=%CD%/assets/resources/gui/schemes >> bin/resources.cfg
echo [xmlSchemas] >> bin/resources.cfg
echo FileSystem=%CD%/assets/resources/gui/xml_schemas >> bin/resources.cfg
cd assets/