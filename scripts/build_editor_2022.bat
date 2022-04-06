@echo off

taskkill /IM halley-editor.exe /F
taskkill /IM halley-cmd.exe /F

cd ..
if not exist build mkdir build
cd build

mkdir "%~dp0..\halley\bin\"
xcopy "%~dp0..\halley_deps\bin\SDL2.dll" "%~dp0..\halley\bin\" /C /Q /Y
xcopy "%~dp0..\halley_deps\bin\dxcompiler.dll" "%~dp0..\halley\bin\" /C /Q /Y
xcopy "%~dp0..\halley_deps\bin\ShaderConductor.dll" "%~dp0..\halley\bin\" /C /Q /Y

cmake -G "Visual Studio 17 2022" ^
    -A x64 ^
    -DHALLEY_PATH=../halley ^
    -DBUILD_HALLEY_TOOLS=1 ^
    -DBUILD_HALLEY_TESTS=0 ^
    -DHALLEY_IGNORE_CONSOLES=1 ^
    -DCMAKE_INCLUDE_PATH="%~dp0\..\halley_deps\include" ^
    -DCMAKE_LIBRARY_PATH="%~dp0\..\halley_deps\lib64" ^
    -DBOOST_LIBRARYDIR="%~dp0\..\halley_deps\Boost\lib" ^
    -DBOOST_INCLUDEDIR="%~dp0\..\halley_deps\Boost\include\boost-1_72" ^
    -DBoost_USE_STATIC_LIBS=1 ^
    .. || goto ERROR

cmake.exe --build . --target halley-cmd --config RelWithDebInfo || goto ERROR
"%~dp0..\halley\bin\halley-cmd.exe" import %~dp0..\halley\ %~dp0..\halley\

cmake.exe --build . --target halley-editor --config RelWithDebInfo || goto ERROR

echo Build successful.
pause
exit /b 0

:ERROR
echo Build failed.
pause
exit /b 1

