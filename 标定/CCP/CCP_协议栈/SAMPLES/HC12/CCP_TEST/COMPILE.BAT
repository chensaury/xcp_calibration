@echo off
REM ----------------------------------------------------------------------------
REM PROJECT INFO
REM ----------------------------------------------------------------------------
echo.
echo ----------------------------------------------------------------------------
echo Compiling CCP_TEST - CCP integration with free CAN driver VERSION 3.3.3
echo Motorola HC12 D60
echo Copyright (c) 2001 by Vector Informatik GmbH. All rights reserved.
echo ----------------------------------------------------------------------------
echo.
echo.
REM ----------------------------------------------------------------------------



REM ----------------------------------------------------------------------------
REM CREATE NEW FOLDERS
REM ----------------------------------------------------------------------------
echo þþ creating new folders
md Errors
md Hex
md Linker
md Object
echo.
REM ----------------------------------------------------------------------------



REM ----------------------------------------------------------------------------
REM DELETE OLD FILES
REM ----------------------------------------------------------------------------
echo þþ delete old files  (error, hex, map)
del Errors\*.err
del Hex\*.hex
del Linker\*.map
echo.
REM ----------------------------------------------------------------------------



REM ----------------------------------------------------------------------------
REM CREATE OBJECT FILES FOR LINKER
REM ----------------------------------------------------------------------------
echo þþ create object .o-file from ccp_test.c
D:\CX32\cx6812 -i .\Include -co Object  -ce Errors -e Source\ccp_test.c
echo.
if errorlevel 1 goto fail

echo þþ create object .o-file from boot_can.c
D:\CX32\cx6812 -i .\Include -co Object -ce Errors -e Source\boot_can.c
echo.
if errorlevel 1 goto fail

echo þþ create object .o-file from ccp.c
D:\CX32\cx6812 -i .\Include -co Object -ce Errors -e Source\ccp.c
echo.
if errorlevel 1 goto fail

echo þþ create object .o-file from ecu.c
D:\CX32\cx6812 -i .\Include -co Object -dCOSMIC_HC12D60_TwinPEEK -ce Errors -e Source\ecu.c
echo.
if errorlevel 1 goto fail

echo þþ create object .o-file from timer.c
D:\CX32\cx6812 -i .\Include -co Object -ce Errors -e Source\timer.c
echo.
if errorlevel 1 goto fail

echo þþ create object .o-file from vectable.c
D:\CX32\cx6812 -i .\Include -co Object -ce Errors -e Source\vectable.c
echo.
if errorlevel 1 goto fail

echo þþ create object .o-file from ccp_can_interface.c
D:\CX32\cx6812 -i .\Include -co Object -ce Errors -e Source\ccp_can_interface.c
echo.
if errorlevel 1 goto fail
REM ----------------------------------------------------------------------------



REM ----------------------------------------------------------------------------
REM LINK OBJECT FILES TOGETHER
REM ----------------------------------------------------------------------------
echo þþ creating H12 and MAP file
D:\CX32\clnk -o Linker\ccp_test.h12  -m Linker\ccp_test.map -e Errors\ccp_test.err ccp_test.lkf
echo.
if errorlevel 1 goto fail
REM ----------------------------------------------------------------------------



REM ----------------------------------------------------------------------------
REM CONVERT GENERATED H12 FILE TO EXECUTABLE HEX FILE
REM ----------------------------------------------------------------------------
echo þþ convert H12 file to HEX
D:\CX32\chex Linker\ccp_test.h12 > Hex\ccp_test.hex
echo.
if errorlevel 1 goto fail
REM ----------------------------------------------------------------------------



REM ----------------------------------------------------------------------------
REM DELETE H12 AND OBJECT FILES / COMPILATION OK!
REM ----------------------------------------------------------------------------
echo þþ delete object files
del Linker\*.h12
del Object\*.o
echo.
echo.
echo.
CLS
echo.
echo ----------------------------------------------------------------------------
echo CCP_TEST - CCP integration with free CAN driver VERSION 3.3.3
echo Motorola HC12 D60
echo Copyright (c) 2001 by Vector Informatik GmbH. All rights reserved.
echo ----------------------------------------------------------------------------
echo.
echo.
echo.
echo þþþþþþþþþþþþþ Compilation Completed!
goto end
REM ----------------------------------------------------------------------------



REM ----------------------------------------------------------------------------
REM COMPILATION FAILED!
REM ----------------------------------------------------------------------------
:fail
echo.
echo.
echo.
echo !!!! Compilation Failed !!!!
echo.
REM ----------------------------------------------------------------------------
:end
echo.
echo.
echo.
echo.
echo.
echo.
pause
