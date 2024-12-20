#!/bin/bash

# Ensure script exits on error
set -e

# Generate build files
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \ 
    -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake

echo "Build files generated for Linux/MacOS."
