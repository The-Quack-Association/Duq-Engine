cmake_minimum_required(VERSION 3.20)

project(Duq-Engine LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build options
option(BUILD_TESTING "Build tests" OFF)

# Raylib configuration
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.0
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)

# Project directories
add_subdirectory(engine)
add_subdirectory(game)


# cmake_minimum_required(VERSION 3.20)

# project(Duq-Engine LANGUAGES CXX)

# # C++20
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# # Don't build raylib's examples
# set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# # Download raylib automatically
# include(FetchContent)

# FetchContent_Declare(
#     raylib
#     GIT_REPOSITORY https://github.com/raysan5/raylib.git
#     GIT_TAG 6.0
#     GIT_SHALLOW TRUE
# )

# FetchContent_MakeAvailable(raylib)

# # Your executable
# add_executable(Duq-Engine
#     src/main.cpp
#     src/game.cpp
# )

# # Header Files
# target_include_directories(Duq-Engine PRIVATE
#     include
# )

# # Link raylib
# target_link_libraries(Duq-Engine PRIVATE raylib)

# # Include your own headers
# target_include_directories(Duq-Engine PRIVATE include)

# # Copy assets next to the executable
# add_custom_command(TARGET Duq-Engine POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#     "${CMAKE_SOURCE_DIR}/assets"
#     "$<TARGET_FILE_DIR:Duq-Engine>/assets"
# )
