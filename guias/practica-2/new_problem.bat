@echo off
setlocal enabledelayedexpansion

:: Pedir nombre del problema
set /p pname=Nombre del problema: 

:: Archivo de salida
set fname=%pname%.cpp

:: Verificar si existe el template
if not exist template.cpp (
    echo ERROR: No se encuentra template.cpp en esta carpeta.
    pause
    exit /b
)

:: Copiar template.cpp con el nuevo nombre
copy template.cpp %fname% >nul

echo Archivo creado: %fname%
pause
