# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/mikhail/9thlab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mikhail/9thlab

# Include any dependencies generated for this target.
include CMakeFiles/io.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/io.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/io.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/io.dir/flags.make

CMakeFiles/io.dir/matrixio.cpp.o: CMakeFiles/io.dir/flags.make
CMakeFiles/io.dir/matrixio.cpp.o: matrixio.cpp
CMakeFiles/io.dir/matrixio.cpp.o: CMakeFiles/io.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/9thlab/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/io.dir/matrixio.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/io.dir/matrixio.cpp.o -MF CMakeFiles/io.dir/matrixio.cpp.o.d -o CMakeFiles/io.dir/matrixio.cpp.o -c /home/mikhail/9thlab/matrixio.cpp

CMakeFiles/io.dir/matrixio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/io.dir/matrixio.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/9thlab/matrixio.cpp > CMakeFiles/io.dir/matrixio.cpp.i

CMakeFiles/io.dir/matrixio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/io.dir/matrixio.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/9thlab/matrixio.cpp -o CMakeFiles/io.dir/matrixio.cpp.s

# Object files for target io
io_OBJECTS = \
"CMakeFiles/io.dir/matrixio.cpp.o"

# External object files for target io
io_EXTERNAL_OBJECTS =

libio.a: CMakeFiles/io.dir/matrixio.cpp.o
libio.a: CMakeFiles/io.dir/build.make
libio.a: CMakeFiles/io.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mikhail/9thlab/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libio.a"
	$(CMAKE_COMMAND) -P CMakeFiles/io.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/io.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/io.dir/build: libio.a
.PHONY : CMakeFiles/io.dir/build

CMakeFiles/io.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/io.dir/cmake_clean.cmake
.PHONY : CMakeFiles/io.dir/clean

CMakeFiles/io.dir/depend:
	cd /home/mikhail/9thlab && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mikhail/9thlab /home/mikhail/9thlab /home/mikhail/9thlab /home/mikhail/9thlab /home/mikhail/9thlab/CMakeFiles/io.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/io.dir/depend
