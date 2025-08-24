@echo off
setlocal enabledelayedexpansion

:: Verificar argumento
if "%~1"=="" (
    echo Uso: run_problem ruta\archivo.cpp
    exit /b
)

:: Ruta absoluta al archivo fuente
set src=%~1

:: Carpeta donde está el archivo
set dir=%~dp1

:: Nombre base del archivo (sin extensión)
set name=%~n1

:: Verificar si existe
if not exist "%src%" (
    echo ERROR: No se encuentra %src%
    exit /b
)

:: Ir a la carpeta del archivo
pushd "%dir%"

:: Compilar con g++
echo Compilando %src% ...
g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fstack-protector "%src%" -o "%name%.exe"
if errorlevel 1 (
    echo Error en la compilacion.
    popd
    exit /b
)

:: Ejecutar
echo ====================================
echo Ejecutando %name%.exe
echo ====================================
"%name%.exe"

:: Volver a la carpeta original
popd
