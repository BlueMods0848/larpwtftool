@echo off
title compiler

cmake --build build

if errorlevel 1 (
    echo.
    echo build failed
    pause
    exit /b 1
)

echo.
echo build finished successfully
pause