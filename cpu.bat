echo off

setlocal enabledelayedexpansion
:loop
set Times=0

for /f "skip=1" %%p in ('wmic cpu get loadpercentage') do (

set Cpusage!Times!=%%p

set /A Times=!Times! + 1

)

echo Percentage = %Cpusage0%
if %Cpusage0% gtr 5 send.exe h
goto loop