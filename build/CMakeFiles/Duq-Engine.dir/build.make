# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/johnny/Desktop/Programming/C++/Duq-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johnny/Desktop/Programming/C++/Duq-Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/Duq-Engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Duq-Engine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Duq-Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Duq-Engine.dir/flags.make

CMakeFiles/Duq-Engine.dir/codegen:
.PHONY : CMakeFiles/Duq-Engine.dir/codegen

CMakeFiles/Duq-Engine.dir/src/main.cpp.o: CMakeFiles/Duq-Engine.dir/flags.make
CMakeFiles/Duq-Engine.dir/src/main.cpp.o: /home/johnny/Desktop/Programming/C++/Duq-Engine/src/main.cpp
CMakeFiles/Duq-Engine.dir/src/main.cpp.o: CMakeFiles/Duq-Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/johnny/Desktop/Programming/C++/Duq-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Duq-Engine.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Duq-Engine.dir/src/main.cpp.o -MF CMakeFiles/Duq-Engine.dir/src/main.cpp.o.d -o CMakeFiles/Duq-Engine.dir/src/main.cpp.o -c /home/johnny/Desktop/Programming/C++/Duq-Engine/src/main.cpp

CMakeFiles/Duq-Engine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Duq-Engine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/Desktop/Programming/C++/Duq-Engine/src/main.cpp > CMakeFiles/Duq-Engine.dir/src/main.cpp.i

CMakeFiles/Duq-Engine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Duq-Engine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/Desktop/Programming/C++/Duq-Engine/src/main.cpp -o CMakeFiles/Duq-Engine.dir/src/main.cpp.s

# Object files for target Duq-Engine
Duq__Engine_OBJECTS = \
"CMakeFiles/Duq-Engine.dir/src/main.cpp.o"

# External object files for target Duq-Engine
Duq__Engine_EXTERNAL_OBJECTS =

Duq-Engine: CMakeFiles/Duq-Engine.dir/src/main.cpp.o
Duq-Engine: CMakeFiles/Duq-Engine.dir/build.make
Duq-Engine: CMakeFiles/Duq-Engine.dir/compiler_depend.ts
Duq-Engine: include/glfw-3.4/src/libglfw3.a
Duq-Engine: libglad.a
Duq-Engine: /usr/lib/librt.a
Duq-Engine: /usr/lib/libm.so
Duq-Engine: CMakeFiles/Duq-Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/johnny/Desktop/Programming/C++/Duq-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Duq-Engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Duq-Engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Duq-Engine.dir/build: Duq-Engine
.PHONY : CMakeFiles/Duq-Engine.dir/build

CMakeFiles/Duq-Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Duq-Engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Duq-Engine.dir/clean

CMakeFiles/Duq-Engine.dir/depend:
	cd /home/johnny/Desktop/Programming/C++/Duq-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johnny/Desktop/Programming/C++/Duq-Engine /home/johnny/Desktop/Programming/C++/Duq-Engine /home/johnny/Desktop/Programming/C++/Duq-Engine/build /home/johnny/Desktop/Programming/C++/Duq-Engine/build /home/johnny/Desktop/Programming/C++/Duq-Engine/build/CMakeFiles/Duq-Engine.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Duq-Engine.dir/depend

