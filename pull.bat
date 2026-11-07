
@echo off
title git pull

echo getting latest changes from github
git fetch origin

if errorlevel 1 (
    echo failed to get latest changes from github
    pause
    exit /b 1
)

echo.
echo updating main branch with latest changes
git pull origin main

if errorlevel 1 (
    echo.
    echo pull failed
    pause
    exit /b 1
)

echo.
echo main updated
pause
