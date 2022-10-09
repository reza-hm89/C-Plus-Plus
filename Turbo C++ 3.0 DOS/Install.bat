@ECHO OFF
CLS
ECHO Copying files to a temporary directory C:\TCTEMP
MD C:\TCTEMP
XCOPY TURBOC.EXE C:\TCTEMP
CD\TCTEMP
ECHO Extracting files to C:\TC
TURBOC -D C:\
ECHO Extraction Successful.
ECHO Deleting C:\TCTEMP
DELTREE -Y C:\TCTEMP
RD C:\TCTEMP
CLS
ECHO Borland Turbo C++ 3.0 Successfully installed.
ECHO To run Turbo C
ECHO CD\TC\BIN
ECHO TC.EXE


