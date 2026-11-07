@echo off
title compiler


if exists build (
    echo.
    echo build directory already exists, removing it
    rmdir /s /q build
    if errorlevel 1 (
        echo.
        echo failed to remove build directory
        pause
        exit /b 1
    )
)

cmake -S . -B build -A x64
if errorlevel 1 (
    echo.
    echo cmake configuration failed
    pause
    exit /b 1
)


cmake --build build --config Debug
if errorlevel 1 (
    echo.
    echo build failed
    pause
    exit /b 1
)

echo.
echo build finished successfully
echo build directory: %cd%\build\Debug
pause