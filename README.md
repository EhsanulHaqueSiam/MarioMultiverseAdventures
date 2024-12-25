# MarioMultiverseAdventures

## Overview
This project is a C++ game called MarioMultiverseAdventures. It uses OpenGL, GLUT, GLEW, and glm libraries. This guide will help you set up the development environment on macOS, Windows, and Linux using CLion, Xcode, Visual Studio, and VSCode.

## Prerequisites
- CMake 3.16 or higher
- vcpkg (for managing dependencies)
- Git
- Ninja Build tools (if VSCode is used)

## Installing Ninja Build Tools on Windows and Adding to Environment Path (for VSCode)

1. **Download Ninja Build Tools:**
   - Go to the official Ninja releases page: [Ninja Releases](https://github.com/ninja-build/ninja/releases)
   - Download the latest `ninja-win.zip` file.

2. **Extract the Zip File:**
   - Extract the contents of the `ninja-win.zip` file to a directory of your choice, e.g., `C:\ninja`.

3. **Add Ninja to the System PATH:**
   - Open the Start Menu and search for "Environment Variables".
   - Click on "Edit the system environment variables".
   - In the System Properties window, click on the "Environment Variables" button.
   - In the Environment Variables window, find the "Path" variable in the "System variables" section and select it.
   - Click on the "Edit" button.
   - In the Edit Environment Variable window, click on the "New" button and add the path to the directory where you extracted Ninja, e.g., `C:\ninja`.
   - Click "OK" to close all windows.

4. **Verify the Installation:**
   - Open a new Command Prompt window.
   - Type `ninja --version` and press Enter.
   - You should see the version of Ninja printed, indicating that it is correctly installed and added to the PATH.

## Cloning the Repository
1. Open a terminal or command prompt.
2. Clone the repository:
    ```sh
    git clone --recurse-submodules https://github.com/EhsanulHaqueSiam/MarioMultiverseAdventures.git
    cd MarioMultiverseAdventures
    ```

   or if you have SSH set up in your GitHub account, you can clone the repository using the following command:
    ```sh
    git clone --recurse-submodules git@github.com:EhsanulHaqueSiam/MarioMultiverseAdventures.git
    cd MarioMultiverseAdventures
    ```

## Setting Up vcpkg
1. **Setup vcpkg (Linux or macOS):**
    ```sh
    git clone https://github.com/microsoft/vcpkg.git
    cd external/vcpkg
    ./bootstrap-vcpkg.sh
    ```

   **Setup vcpkg (Windows PowerShell):**
    ```sh
    git clone https://github.com/microsoft/vcpkg.git
    cd external/vcpkg
    ./bootstrap-vcpkg.bat
    ```

2. **Add vcpkg to your PATH:**
   - **Temporary:**
    ```sh
    export VCPKG_ROOT=$(pwd)
    export PATH=$VCPKG_ROOT:$PATH
    ```
   - **Permanent:**
     Set the environment variable `VCPKG_ROOT` to the path of the vcpkg directory and add the vcpkg directory to the PATH environment variable. For Linux, you can add it to `.bashrc` or `.zshrc` file, and for Windows, you can add it to the environment variable. For macOS, you can add it to the `.zshrc` file.

   For Windows, an extra step is needed to integrate vcpkg with Visual Studio:
    ```sh
    vcpkg integrate install
    ```

3. **Install the required libraries:**
   Navigate to the project directory (MarioMultiverseAdventures):
    ```sh
    cd ../..
    ```
   Then run the following command:
    ```sh
    vcpkg install
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

## CLion Setup (Alternative)
1. Go to `View` > `Tool Windows` > `Vcpkg`.
2. Hit the `+` button, a window will pop up. Add Vcpkg Repository and select `OK`.

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