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
REM if not exist ../../ParkourGame/bin/OgreMeshLodGenerator.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/OgreMeshLodGenerator_d.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/OgrePaging.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/OgrePaging_d.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/OgreProperty.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/OgreProperty_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreRTShaderSystem.dll goto copydependencies
if not exist ../../ParkourGame/bin/OgreRTShaderSystem_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/Plugin_ParticleFX.dll copydependencies
if not exist ../../ParkourGame/bin/Plugin_ParticleFX_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/RenderSystem_GL.dll goto copydependencies
if not exist ../../ParkourGame/bin/RenderSystem_GL_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/SDL2.dll goto copydependencies
if not exist ../../ParkourGame/bin/zlib.dll goto copydependencies

if not exist ../../ParkourGame/bin/CEGUIBase-0.dll goto copydependencies
if not exist ../../ParkourGame/bin/CEGUIBase-0_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/CEGUIOgreRenderer-0.dll goto copydependencies
if not exist ../../ParkourGame/bin/CEGUIOgreRenderer-0_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/CEGUIExpatParser.dll goto copydependencies
if not exist ../../ParkourGame/bin/CEGUIExpatParser_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/CEGUICoreWindowRendererSet.dll goto copydependencies
if not exist ../../ParkourGame/bin/CEGUICoreWindowRendererSet_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/freetype.dll goto copydependencies
if not exist ../../ParkourGame/bin/freetype_d.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/glew.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/glew_d.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/glfw.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/glfw_d.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/jpeg.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/jpeg_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/libexpat.dll goto copydependencies
if not exist ../../ParkourGame/bin/libexpat_d.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/libpng.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/libpng_d.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/pcre.dll goto copydependencies
REM if not exist ../../ParkourGame/bin/pcre_d.dll goto copydependencies
if not exist ../../ParkourGame/bin/SILLY.dll goto copydependencies
if not exist ../../ParkourGame/bin/SILLY_d.dll goto copydependencies

goto endcopy

:copydependencies
echo hace falta copiar
cd ../../ParkourGame & mkdir bin & cd ../P32021/bin
copy /Y plugins.cfg "../../ParkourGame/bin/plugins.cfg"
copy /Y resources.cfg "../../ParkourGame/bin/resources.cfg"
copy /Y Codec_STBI.dll "../../ParkourGame/bin/Codec_STBI.dll"
copy /Y Codec_STBI_d.dll "../../ParkourGame/bin/Codec_STBI_d.dll"
copy /Y fmodL64.dll "../../ParkourGame/bin/fmodL64.dll"
copy /Y lua54.dll "../../ParkourGame/bin/lua54.dll"
copy /Y OgreMain.dll "../../ParkourGame/bin/OgreMain.dll"
copy /Y OgreMain_d.dll "../../ParkourGame/bin/OgreMain_d.dll"
REM copy /Y OgreMeshLodGenerator.dll "../../ParkourGame/bin/OgreMeshLodGenerator.dll"
REM copy /Y OgreMeshLodGenerator_d.dll "../../ParkourGame/bin/OgreMeshLodGenerator_d.dll"
REM copy /Y OgrePaging.dll "../../ParkourGame/bin/OgrePaging.dll"
REM copy /Y OgrePaging_d.dll "../../ParkourGame/bin/OgrePaging_d.dll"
REM copy /Y OgreProperty.dll "../../ParkourGame/bin/OgreProperty.dll"
REM copy /Y OgreProperty_d.dll "../../ParkourGame/bin/OgreProperty_d.dll"
copy /Y OgreRTShaderSystem.dll "../../ParkourGame/bin/OgreRTShaderSystem.dll"
copy /Y OgreRTShaderSystem_d.dll "../../ParkourGame/bin/OgreRTShaderSystem_d.dll"
copy /Y Plugin_ParticleFX.dll "../../ParkourGame/bin/Plugin_ParticleFX.dll"
copy /Y Plugin_ParticleFX_d.dll "../../ParkourGame/bin/Plugin_ParticleFX_d.dll"
copy /Y RenderSystem_GL.dll "../../ParkourGame/bin/RenderSystem_GL.dll"
copy /Y RenderSystem_GL_d.dll "../../ParkourGame/bin/RenderSystem_GL_d.dll"
copy /Y SDL2.dll "../../ParkourGame/bin/SDL2.dll"
copy /Y zlib.dll "../../ParkourGame/bin/zlib.dll"

copy /Y CEGUIBase-0.dll "../../ParkourGame/bin/CEGUIBase-0.dll"
copy /Y CEGUIBase-0_d.dll "../../ParkourGame/bin/CEGUIBase-0_d.dll"
copy /Y CEGUIOgreRenderer-0.dll "../../ParkourGame/bin/CEGUIOgreRenderer-0.dll"
copy /Y CEGUIOgreRenderer-0_d.dll "../../ParkourGame/bin/CEGUIOgreRenderer-0_d.dll"
copy /Y CEGUIExpatParser.dll "../../ParkourGame/bin/CEGUIExpatParser.dll"
copy /Y CEGUIExpatParser_d.dll "../../ParkourGame/bin/CEGUIExpatParser_d.dll"
copy /Y CEGUICoreWindowRendererSet.dll "../../ParkourGame/bin/CEGUICoreWindowRendererSet.dll"
copy /Y CEGUICoreWindowRendererSet_d.dll "../../ParkourGame/bin/CEGUICoreWindowRendererSet_d.dll"
copy /Y freetype.dll "../../ParkourGame/bin/freetype.dll"
copy /Y freetype_d.dll "../../ParkourGame/bin/freetype_d.dll"
REM copy /Y glew.dll "../../ParkourGame/bin/glew.dll"
REM copy /Y glew_d.dll "../../ParkourGame/bin/glew_d.dll"
REM copy /Y glfw.dll "../../ParkourGame/bin/glfw.dll"
REM copy /Y glfw_d.dll "../../ParkourGame/bin/glfw_d.dll"
REM copy /Y jpeg.dll "../../ParkourGame/bin/jpeg.dll"
REM copy /Y jpeg_d.dll "../../ParkourGame/bin/jpeg_d.dll"
copy /Y libexpat.dll "../../ParkourGame/bin/libexpat.dll"
copy /Y libexpat_d.dll "../../ParkourGame/bin/libexpat_d.dll"
REM copy /Y libpng.dll "../../ParkourGame/bin/libpng.dll"
REM copy /Y libpng_d.dll "../../ParkourGame/bin/libpng_d.dll"
REM copy /Y pcre.dll "../../ParkourGame/bin/pcre.dll"
REM copy /Y pcre_d.dll "../../ParkourGame/bin/pcre_d.dll"
copy /Y SILLY.dll "../../ParkourGame/bin/SILLY.dll"
copy /Y SILLY_d.dll "../../ParkourGame/bin/SILLY_d.dll"

:endcopy
echo fin

cd ../../ParkourGame