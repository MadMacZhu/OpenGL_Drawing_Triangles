# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build

# Include any dependencies generated for this target.
include src/CMakeFiles/GLEW.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/GLEW.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/GLEW.dir/flags.make

src/CMakeFiles/GLEW.dir/glew.c.o: src/CMakeFiles/GLEW.dir/flags.make
src/CMakeFiles/GLEW.dir/glew.c.o: ../src/glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/GLEW.dir/glew.c.o"
	cd /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GLEW.dir/glew.c.o   -c /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/src/glew.c

src/CMakeFiles/GLEW.dir/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GLEW.dir/glew.c.i"
	cd /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/src/glew.c > CMakeFiles/GLEW.dir/glew.c.i

src/CMakeFiles/GLEW.dir/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GLEW.dir/glew.c.s"
	cd /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/src/glew.c -o CMakeFiles/GLEW.dir/glew.c.s

# Object files for target GLEW
GLEW_OBJECTS = \
"CMakeFiles/GLEW.dir/glew.c.o"

# External object files for target GLEW
GLEW_EXTERNAL_OBJECTS =

src/libGLEW.a: src/CMakeFiles/GLEW.dir/glew.c.o
src/libGLEW.a: src/CMakeFiles/GLEW.dir/build.make
src/libGLEW.a: src/CMakeFiles/GLEW.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libGLEW.a"
	cd /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/GLEW.dir/cmake_clean_target.cmake
	cd /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GLEW.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/GLEW.dir/build: src/libGLEW.a

.PHONY : src/CMakeFiles/GLEW.dir/build

src/CMakeFiles/GLEW.dir/clean:
	cd /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/GLEW.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/GLEW.dir/clean

src/CMakeFiles/GLEW.dir/depend:
	cd /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/src /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/src /home/yaoguang/Dev/CppDev/OpenGL_Projs/OpenGL_Learning_Project/build/src/CMakeFiles/GLEW.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/GLEW.dir/depend

