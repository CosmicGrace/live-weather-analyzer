

@echo off
REM Disable command echoing (cleaner output)

REM Set the project directory
set PROJECT_DIR=%cd%

REM Compile all source files
echo Compiling Weather Analyzer...
g++ -std=c++17 -o weather.exe main.cpp functions.cpp classes.cpp -lcurl -I./Include

REM Check if compilation was successful
if %errorlevel% equ 0 (
    echo.
    echo Build successful! Running program...
    echo.
    weather.exe
    pause
) else (
    echo.
    echo Build failed! Check errors above.
    pause
)
