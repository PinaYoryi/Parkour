cd ../../P32021/bin
copy /Y resources.cfg "../../ParkourGame/bin/resources.cfg"
cd ../../ParkourGame/assets
echo [General] >> ../bin/resources.cfg
echo FileSystem=%CD%/resources >> ../bin/resources.cfg
for /r %CD% %%f in (*.zip) do echo Zip=%%~pnxf >> ../bin/resources.cfg