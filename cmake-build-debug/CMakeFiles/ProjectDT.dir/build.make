# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stanbrunau/Documents/ProgAlg/ProjectDT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stanbrunau/Documents/ProgAlg/ProjectDT/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjectDT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjectDT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjectDT.dir/flags.make

CMakeFiles/ProjectDT.dir/main.cpp.o: CMakeFiles/ProjectDT.dir/flags.make
CMakeFiles/ProjectDT.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stanbrunau/Documents/ProgAlg/ProjectDT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProjectDT.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectDT.dir/main.cpp.o -c /Users/stanbrunau/Documents/ProgAlg/ProjectDT/main.cpp

CMakeFiles/ProjectDT.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectDT.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stanbrunau/Documents/ProgAlg/ProjectDT/main.cpp > CMakeFiles/ProjectDT.dir/main.cpp.i

CMakeFiles/ProjectDT.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectDT.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stanbrunau/Documents/ProgAlg/ProjectDT/main.cpp -o CMakeFiles/ProjectDT.dir/main.cpp.s

# Object files for target ProjectDT
ProjectDT_OBJECTS = \
"CMakeFiles/ProjectDT.dir/main.cpp.o"

# External object files for target ProjectDT
ProjectDT_EXTERNAL_OBJECTS =

ProjectDT: CMakeFiles/ProjectDT.dir/main.cpp.o
ProjectDT: CMakeFiles/ProjectDT.dir/build.make
ProjectDT: CMakeFiles/ProjectDT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stanbrunau/Documents/ProgAlg/ProjectDT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ProjectDT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjectDT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjectDT.dir/build: ProjectDT

.PHONY : CMakeFiles/ProjectDT.dir/build

CMakeFiles/ProjectDT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjectDT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjectDT.dir/clean

CMakeFiles/ProjectDT.dir/depend:
	cd /Users/stanbrunau/Documents/ProgAlg/ProjectDT/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stanbrunau/Documents/ProgAlg/ProjectDT /Users/stanbrunau/Documents/ProgAlg/ProjectDT /Users/stanbrunau/Documents/ProgAlg/ProjectDT/cmake-build-debug /Users/stanbrunau/Documents/ProgAlg/ProjectDT/cmake-build-debug /Users/stanbrunau/Documents/ProgAlg/ProjectDT/cmake-build-debug/CMakeFiles/ProjectDT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjectDT.dir/depend

