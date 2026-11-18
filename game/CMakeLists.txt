# Collect game source files
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Game executable
add_executable(Duq-Engine
    ${GAME_SOURCES}
)

# Game include directories
target_include_directories(Duq-Engine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Link engine
target_link_libraries(Duq-Engine PRIVATE
    duq_engine
)

# Copy assets next to executable
add_custom_command(TARGET Duq-Engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:Duq-Engine>/assets"
    COMMENT "Copying game assets"
)