REM THIS BATCH FILE HAS TO BE CALLED BY A X64 NATIVE TOOLS COMMAND PROMPT

cd P32021
call PinaMotor.bat
cd ..

echo BUILD PARKOUR
cd ParkourGame
msbuild ParkourGame.sln -p:Configuration=Debug
msbuild ParkourGame.sln -p:Configuration=Release
echo BUILDING DONE