@echo off
@echo #define VERSION_BUILD 0 > ..\src\build_version.h
@echo #define COMMIT_SHA "" >> ..\src\build_version.h
@echo #define BRANCH_NAME "" >> ..\src\build_version.h

cd ..
halley\bin\halley-cmd.exe import %cd% %cd%\halley
cd scripts
pause