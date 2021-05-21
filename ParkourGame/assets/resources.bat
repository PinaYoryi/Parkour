cd ../../P32021/bin
copy /Y resources.cfg "../../ParkourGame/bin/resources.cfg"
cd ../../ParkourGame/assets
echo [General] >> ../bin/resources.cfg
echo FileSystem=../assets/OgreResources >> ../bin/resources.cfg
for %%f in (*.zip) do echo Zip=../assets/OgreResources/%%~nxf >> ../bin/resources.cfg