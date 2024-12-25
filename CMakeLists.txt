cmake_minimum_required(VERSION 3.16)
project(MarioMultiverseAdventures)

# Enable C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include vcpkg
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "")

# Find required packages
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Define asset path
add_definitions(-DASSET_PATH="${CMAKE_SOURCE_DIR}/assets")

# Source files
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)

# Executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS}
        src/Coin.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} OpenGL::GL GLUT::GLUT GLEW::GLEW glm::glm)