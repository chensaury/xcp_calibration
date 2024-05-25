:: Works with Tasking Compiler V6.0R2

call init.bat
call clear

c:\uti\c166\bin\mk166 %1 %2 %3 %4 %5 %6 >log.txt

dir *.err
dir test_f.*

copy test_f.map canape\ccptest.map
copy test_f.abs canape\ccptest.abs
copy test_f.hex canape\ccptest.hex
