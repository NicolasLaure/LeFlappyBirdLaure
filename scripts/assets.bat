echo off

set solutionDir=%1
set outDir=%2

xcopy /s/y %solutionDir% %outDir%
