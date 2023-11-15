cd ..
mkdir build
cd build
cmake -G "Visual Studio 17 2022" ^
    -A x64 ^
    -DHALLEY_PATH=../halley ^
    -DCMAKE_INCLUDE_PATH="%~dp0\..\halley\deps\include" ^
    -DCMAKE_LIBRARY_PATH="%~dp0\..\halley\deps\lib64" ^
    -DBOOST_INCLUDEDIR="%~dp0\..\halley\deps\Boost\include\boost-1_81" ^
    -DBoost_USE_STATIC_LIBS=1 ^
    -DBUILD_HALLEY_TOOLS=1 ^
    -DBUILD_HALLEY_TESTS=1 ^
    -DBUILD_HALLEY_LAUNCHER=1 ^
    ..
pause