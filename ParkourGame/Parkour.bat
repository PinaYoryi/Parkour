echo COPY DEPENDENCIES
cd ../P32021/bin
echo comprobando si hay que a copiar
if not exist ../../ParkourGame/bin goto copydependencies
if not exist ../../ParkourGame/bin/plugins.cfg goto copydependencies
if not exist ../../ParkourGame/bin/resources.cfg goto copydependencies
if not exist ../../ParkourGame/bin/Codec_STBI.dll goto copydependencies
if not exist ../../ParkourGame/bin/Codec_STBI_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/fmodL64.dll goto copydependencies
if not exist ../../ParkourGame/bin/lua54.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreMain.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreMain_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreMeshLodGenerator.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreMeshLodGenerator_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreOverlay.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreOverlay_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgrePaging.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgrePaging_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreProperty.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreProperty_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreRTShaderSystem.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreRTShaderSystem_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/Plugin_ParticleFX.dll copydependencies
if not exist ../../ParkourGame/bin/Plugin_ParticleFX_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/RenderSystem_Direct3D11.dll goto copydependencies
if not exist ../../ParkourGame/bin/RenderSystem_Direct3D11_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/SDL2.dll goto copydependencies
if not exist ../../ParkourGame/bin/zlib.dll goto copydependencies
goto endcopy

:copydependencies
echo hace falta copiar
cd ../../ParkourGame & mkdir bin & cd ../P32021/bin
REM copy /Y ogre.cfg "../../ParkourGame/bin/ogre.cfg"
copy /Y plugins.cfg "../../ParkourGame/bin/plugins.cfg"
copy /Y resources.cfg "../../ParkourGame/bin/resources.cfg"
copy /Y Codec_STBI.dll "../../ParkourGame/bin/Codec_STBI.dll"
copy /Y Codec_STBI_d.dll "../../ParkourGame/bin/Codec_STBI_d.dll"
copy /Y fmodL64.dll "../../ParkourGame/bin/fmodL64.dll"
copy /Y lua54.dll "../../ParkourGame/bin/lua54.dll"
copy /Y OgreMain.dll "../../ParkourGame/bin/OgreMain.dll"
copy /Y OgreMain_d.dll "../../ParkourGame/bin/OgreMain_d.dll"
copy /Y OgreMeshLodGenerator.dll "../../ParkourGame/bin/OgreMeshLodGenerator.dll"
copy /Y OgreMeshLodGenerator_d.dll "../../ParkourGame/bin/OgreMeshLodGenerator_d.dll"
copy /Y OgreOverlay.dll "../../ParkourGame/bin/OgreOverlay.dll"
copy /Y OgreOverlay_d.dll "../../ParkourGame/bin/OgreOverlay_d.dll"
copy /Y OgrePaging.dll "../../ParkourGame/bin/OgrePaging.dll"
copy /Y OgrePaging_d.dll "../../ParkourGame/bin/OgrePaging_d.dll"
copy /Y OgreProperty.dll "../../ParkourGame/bin/OgreProperty.dll"
copy /Y OgreProperty_d.dll "../../ParkourGame/bin/OgreProperty_d.dll"
copy /Y OgreRTShaderSystem.dll "../../ParkourGame/bin/OgreRTShaderSystem.dll"
copy /Y OgreRTShaderSystem_d.dll "../../ParkourGame/bin/OgreRTShaderSystem_d.dll"
copy /Y Plugin_ParticleFX.dll "../../ParkourGame/bin/Plugin_ParticleFX.dll"
copy /Y Plugin_ParticleFX_d.dll "../../ParkourGame/bin/Plugin_ParticleFX_d.dll"
copy /Y RenderSystem_Direct3D11.dll "../../ParkourGame/bin/RenderSystem_Direct3D11.dll"
copy /Y RenderSystem_Direct3D11_d.dll "../../ParkourGame/bin/RenderSystem_Direct3D11_d.dll"
copy /Y SDL2.dll "../../ParkourGame/bin/SDL2.dll"
copy /Y zlib.dll "../../ParkourGame/bin/zlib.dll"
:endcopy
echo fin

cd ../../ParkourGame