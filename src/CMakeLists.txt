# Collect engine source files
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/*.cpp"
)

# Engine library
add_library(duq_engine STATIC
    ${ENGINE_SOURCES}
)

# Public include directories
target_include_directories(duq_engine PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

# Link raylib
target_link_libraries(duq_engine PUBLIC
    raylib
)

# Compiler warnings
if(MSVC)
    target_compile_options(duq_engine PRIVATE /W4)
else()
    target_compile_options(duq_engine PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
