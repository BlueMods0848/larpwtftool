
@echo off
title git push

git add .

set /p commitMsg="Enter commit message: "

if "%commitMsg%"=="" (
    echo commit message cannot be empty
    pause
    exit /b 1
)

git commit -m "%commitMsg%"

if errorlevel 1 (
    echo failed to commit changes
    pause
    exit /b 1
)

git push

if errorlevel 1 (
    echo failed
    pause
    exit /b 1
)

echo.
echo changes pushed to github
pause
