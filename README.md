# MarioMultiverseAdventures

## Overview
This project is a C++ game called MarioMultiverseAdventures. It uses OpenGL, GLUT, GLEW, and glm libraries. This guide will help you set up the development environment on macOS, Windows, and Linux using CLion, Xcode, Visual Studio, and VSCode.

## Prerequisites
- CMake 3.16 or higher
- vcpkg (for managing dependencies)
- Git

## Cloning the Repository
1. Open a terminal or command prompt.
2. Clone the repository:
    ```sh
    git clone https://github.com/EhsanulHaqueSiam/MarioMultiverseAdventures.git
    cd MarioMultiverseAdventures
    ```
   
or if you have ssh setup in your github account then you can clone the repository using the following command:
```sh
git clone git@github.com:EhsanulHaqueSiam/MarioMultiverseAdventures.git
cd MarioMultiverseAdventures
```

## Setting Up vcpkg
1. Clone the vcpkg repository:
    ```sh
    git clone https://github.com/microsoft/vcpkg.git
    cd vcpkg
    ./bootstrap-vcpkg.sh
    ```

2. Add vcpkg to your PATH:
    ```sh
    export VCPKG_ROOT=$(pwd)
    export PATH=$VCPKG_ROOT:$PATH
    ```

3. Install the required libraries:
    ```sh
    vcpkg install opengl freeglut glew glm
    ```

## CLion Setup
1. Open CLion and select `Open` to open the project directory.
2. Go to `File` > `Settings` > `Build, Execution, Deployment` > `CMake`.
3. Set the `CMake options` to:
    ```sh
    -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
    ```
4. Click `Apply` and `OK`.
5. Click the `Reload CMake Project` button.

## Xcode Setup (macOS)
1. Open Terminal and navigate to the project directory.
2. Run the `generate_mac.sh` script:
    ```sh
    ./scripts/generate_mac.sh
    ```
3. Open the generated Xcode project:
    ```sh
    open build/MarioMultiverseAdventures.xcodeproj
    ```
4. Build and run the project in Xcode.

## Visual Studio Setup (Windows)
1. Open Command Prompt and navigate to the project directory.
2. Run the `generate_windows.bat` script:
    ```bat
    scripts\generate_windows.bat
    ```
3. Open the generated Visual Studio solution:
    ```sh
    start build\MarioMultiverseAdventures.sln
    ```
4. Build and run the project in Visual Studio.

## VSCode Setup
1. Open VSCode and select `Open Folder` to open the project directory.
2. Ensure the `.vscode` directory contains the following files:
    - `settings.json`
    - `tasks.json`
    - `launch.json`
    - `CMakePresets.json`
3. Open the Command Palette (`Ctrl+Shift+P` or `Cmd+Shift+P`) and run `CMake: Configure`.
4. Build the project by running the `CMake: build` task.
5. Start debugging by running the `Debug` configuration.

## Linux Setup
1. Open Terminal and navigate to the project directory.
2. Run the `generate_linux.sh` script:
    ```sh
    ./scripts/generate_linux.sh
    ```
3. Build the project:
    ```sh
    cmake --build build
    ```
4. Run the executable:
    ```sh
    ./build/MarioMultiverseAdventures
    ```

## macOS Setup
1. Open Terminal and navigate to the project directory.
2. Run the `generate_mac.sh` script:
    ```sh
    ./scripts/generate_mac.sh
    ```
3. Build the project:
    ```sh
    cmake --build build
    ```
4. Run the executable:
    ```sh
    ./build/MarioMultiverseAdventures
    ```

## Windows Setup
1. Open Command Prompt and navigate to the project directory.
2. Run the `generate_windows.bat` script:
    ```bat
    scripts\generate_windows.bat
    ```
3. Build the project:
    ```sh
    cmake --build build
    ```
4. Run the executable:
    ```sh
    build\MarioMultiverseAdventures.exe
    ```

## Contributing
1. Fork the repository on GitHub.
2. Create a new branch for your feature or bugfix:
    ```sh
    git checkout -b my-feature-branch
    ```
3. Make your changes and commit them:
    ```sh
    git add .
    git commit -m "Description of my changes"
    ```
4. Push your changes to your fork:
    ```sh
    git push origin my-feature-branch
    ```
5. Create a pull request on GitHub.

Follow these steps to set up and start developing the MarioMultiverseAdventures project on your preferred platform and IDE.