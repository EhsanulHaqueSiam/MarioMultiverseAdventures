# Mario Multiverse Adventures

## Overview
This project is a C++ game called **MarioMultiverseAdventures**. It uses **OpenGL**, **GLUT**, **GLEW**, **GLU**, **glm**, **SFML**, and **SQLite** libraries. This guide provides detailed instructions for setting up the development environment on macOS, Windows, and Linux using CLion, Xcode, Visual Studio, and VSCode.

---

## Prerequisites
Before you begin, ensure you have the following tools installed:

- **CMake 3.16 or higher**  
  [Download CMake](https://cmake.org/download/)

- **vcpkg** (for managing dependencies)

- **Git**  
  [Download Git](https://git-scm.com/downloads)

- **Compilers:**
    - **Windows:** MinGW or MSVC
    - **Linux:** GCC
    - **macOS:** Clang  
      [Setup Guide](https://code.visualstudio.com/docs/languages/cpp#_set-up-your-c-environment)

- **Ninja Build Tools** (for VSCode)  
  [Download Ninja](https://github.com/ninja-build/ninja/releases)

---

## Installing SFML and SQLite Dependencies

### Linux 🐧
Run the following commands to install SFML, SQLite, and other dependencies:

```sh
sudo apt-get update
sudo apt-get install -y build-essential libxi-dev libxrandr-dev libxinerama-dev libxcursor-dev libgl1-mesa-dev libglu1-mesa-dev libopenal-dev libvorbis-dev libsfml-dev libasound2-dev libpulse-dev libxrandr-dev libx11-dev libudev-dev libflac-dev libogg-dev libjpeg-dev libfreetype6-dev sqlite3 libsqlite3-dev
```

### Windows 🖥️

1. **Download SFML:**  
   Visit the official SFML releases page: [SFML Releases](https://www.sfml-dev.org/download.php)
   Download the version compatible with Visual Studio or MinGW, depending on your setup.

2. **Download SQLite:**
    - Visit the official SQLite downloads page: [SQLite Releases](https://www.sqlite.org/download.html)
    - Download the precompiled binaries for Windows.

3. **Extract and Set Environment Variables:**
    - Extract both SFML and SQLite archives to directories, e.g., `C:\SFML` and `C:\SQLite`.
    - Add paths to the `bin` directories of SFML and SQLite in the System Environment Variables under `Path`.

4. **Verify Installation:**
   ```sh
   sfml-example.exe --version
   sqlite3 --version
   ```

### macOS 🍎

1. **Install Homebrew:**
   ```sh
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Install SFML and SQLite:**
   ```sh
   brew install sfml sqlite
   ```

3. **Verify Installation:**
   ```sh
   sfml --version
   sqlite3 --version
   ```

---

## Cloning the Repository 🌐

1. Open a terminal or command prompt.
2. Clone the repository recursively:
   ```sh
   git clone --recurse-submodules https://github.com/EhsanulHaqueSiam/MarioMultiverseAdventures.git
   cd MarioMultiverseAdventures
   ```

   **OR (SSH):**
   ```sh
   git clone --recurse-submodules git@github.com:EhsanulHaqueSiam/MarioMultiverseAdventures.git
   cd MarioMultiverseAdventures
   ```

---

## Setting Up vcpkg 📦

### Linux or macOS:

```sh
cd external/vcpkg
./bootstrap-vcpkg.sh
```

### Windows:

```sh
cd external/vcpkg
./bootstrap-vcpkg.bat
```

### Adding vcpkg to PATH:

- **Temporary:**
  ```sh
  export VCPKG_ROOT=$(pwd)
  export PATH=$VCPKG_ROOT:$PATH
  ```

- **Permanent:**
  Add `VCPKG_ROOT` to your system environment variables.

### Installing Dependencies:

```sh
cd ../..
vcpkg install sfml sqlite3
```

---

## IDE Setup 💻

### CLion Setup 🧑‍💻

1. **Verify vcpkg Installation:**
   ```sh
   echo $VCPKG_ROOT
   ```

2. **Open the Project in CLion:**
    - Launch CLion and select `Open` to open the project directory.

3. **Set CMake Options:**
    - Go to **File** > **Settings** > **Build, Execution, Deployment** > **CMake**.
    - Set the **CMake options** field to:
      ```sh
      -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
      ```

4. **Apply and Reload:**
    - Click **Apply** and then **OK**.
    - CLion will reload the project with the updated CMake options.

---

### Xcode Setup (macOS) 🍎

1. Run the setup script:
   ```sh
   ./scripts/generate_mac.sh
   ```

2. Open the project:
   ```sh
   open build/MarioMultiverseAdventures.xcodeproj
   ```

3. Build and run the project.

---

### Visual Studio Setup (Windows) 🖥️

1. Run the setup script:
   ```bat
   scripts\generate_windows.bat
   ```

2. Open the solution file:
   ```sh
   start build\MarioMultiverseAdventures.sln
   ```

3. Build and run the project.

---

### VSCode Setup 🖋️

1. Ensure the `.vscode` folder contains the following files:
    - `settings.json`
    - `tasks.json`
    - `launch.json`
    - `CMakePresets.json`

2. **Configure CMake:**
   ```sh
   Ctrl+Shift+P -> CMake: Configure
   ```

3. **Build the Project:**
   ```sh
   CMake: Build
   ```

4. **Start Debugging:**
   ```sh
   Debug -> Start Debugging
   ```

---

## Platform-Specific Build Steps ⚙️

### Linux Setup 🐧

```sh
./scripts/generate_linux.sh
cmake --build build
./build/MarioMultiverseAdventures
```

### macOS Setup 🍎

```sh
./scripts/generate_mac.sh
cmake --build build
./build/MarioMultiverseAdventures
```

### Windows Setup 🖥️

```sh
scripts\generate_windows.bat
cmake --build build
build\MarioMultiverseAdventures.exe
```

---

## Contributing 🤝

1. **Fork the repository.**
2. **Create a new branch:**
   ```sh
   git checkout -b feature-branch
   ```
3. **Commit your changes:**
   ```sh
   git add .
   git commit -m "Description of changes"
   ```
4. **Push the changes:**
   ```sh
   git push origin feature-branch
   ```
5. **Submit a pull request.**

---

Follow these steps to set up and start developing the **MarioMultiverseAdventures** project on your preferred platform and IDE. 🚀

