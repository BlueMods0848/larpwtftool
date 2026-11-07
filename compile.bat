@echo off
title compiler


@REM  if exist build (
@REM      echo.
@REM      echo build directory already exists, removing it
@REM      rmdir /s /q build
@REM      if errorlevel 1 (
@REM          echo.
@REM          echo failed to remove build directory
@REM          pause
@REM          exit /b 1
@REM      )
@REM  )

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