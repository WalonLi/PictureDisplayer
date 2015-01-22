
echo on
cd %~dp0

:: set environment path
set PATH=C:\Qt5\5.3\mingw482_32\bin;%PATH%
set PATH=C:\Qt5\Tools\mingw482_32\bin;%PATH%
set PATH=G:\boost_1_57_0\stage\lib;%PATH%
set PATH=G:\boost_1_57_0;%PATH%

:: call qmake
qmake PictureDisplayer.pro -r -spec win32-g++ "CONFIG+=debug"
:: make
mingw32-make.exe
debug\PictureDisplayer.exe
PAUSE