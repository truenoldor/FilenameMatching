# FilenameMatching
To build the application, you need to install and download the latest cmake, as well as mingw, you can download it here - https://nuwen.net/mingw.html 
After the installation, add the path to the PATH variable:
C:\MinGW\bin
C:\Program Files\CMake\bin

Run build.bat

if all is well, a file will appear in the build folder - FilenameMatching.exe

Use:
FilenameMatching.exe name template

Example:
FilenameMatching.exe c:/work/findme_if_you_can.txt c:/?or**m*_if_you_ca?.txt
The file name matches the pattern
