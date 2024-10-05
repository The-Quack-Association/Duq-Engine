# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name and version
project(Duq-Engine VERSION 1.0)

# Set C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)

# Include directories (for header files)
include_directories(include)

# Add the source files
set(SOURCES

	src/main.cpp

)

# Find packages
find_package(SFML 2.6.1 REQUIRED graphics window system)
find_package(GLEW REQUIRED)
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# Define the executable target
add_executable(Duq-Engine ${SOURCES})

# Link libraries (SFML and GLEW)
target_link_libraries(Duq-Engine
    sfml-graphics
    sfml-window
    sfml-system
    GLEW::GLEW
	OpenGL::GL
)