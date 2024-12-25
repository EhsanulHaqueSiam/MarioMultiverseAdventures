@echo off

:: Ensure script exits on error
setlocal enabledelayedexpansion

:: Delete existing build directory if it exists
rmdir /s /q build

:: Generate build files
cmake -S . -B build -G "Visual Studio 17 2022" ^
    -DCMAKE_BUILD_TYPE=Release ^
    -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake

echo Build files generated for Windows.
