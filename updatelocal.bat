@echo off
title git update local

git merge --abort
git fetch origin
git merge -X theirs --no-edit origin/main

echo.
echo updated local
pause