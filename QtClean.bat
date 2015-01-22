
echo on
cd %~dp0

:: set environment path
set PATH=C:\Qt5\5.3\mingw482_32\bin;%PATH%
set PATH=C:\Qt5\Tools\mingw482_32\bin;%PATH%
:: make
mingw32-make.exe clean
