# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\rockb\CLionProjects\Stacks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rockb\CLionProjects\Stacks\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Stacks.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Stacks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Stacks.dir/flags.make

CMakeFiles/Stacks.dir/main.cpp.obj: CMakeFiles/Stacks.dir/flags.make
CMakeFiles/Stacks.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rockb\CLionProjects\Stacks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Stacks.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stacks.dir\main.cpp.obj -c C:\Users\rockb\CLionProjects\Stacks\main.cpp

CMakeFiles/Stacks.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stacks.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rockb\CLionProjects\Stacks\main.cpp > CMakeFiles\Stacks.dir\main.cpp.i

CMakeFiles/Stacks.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stacks.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rockb\CLionProjects\Stacks\main.cpp -o CMakeFiles\Stacks.dir\main.cpp.s

# Object files for target Stacks
Stacks_OBJECTS = \
"CMakeFiles/Stacks.dir/main.cpp.obj"

# External object files for target Stacks
Stacks_EXTERNAL_OBJECTS =

Stacks.exe: CMakeFiles/Stacks.dir/main.cpp.obj
Stacks.exe: CMakeFiles/Stacks.dir/build.make
Stacks.exe: CMakeFiles/Stacks.dir/linklibs.rsp
Stacks.exe: CMakeFiles/Stacks.dir/objects1.rsp
Stacks.exe: CMakeFiles/Stacks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\rockb\CLionProjects\Stacks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Stacks.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Stacks.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Stacks.dir/build: Stacks.exe

.PHONY : CMakeFiles/Stacks.dir/build

CMakeFiles/Stacks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Stacks.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Stacks.dir/clean

CMakeFiles/Stacks.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rockb\CLionProjects\Stacks C:\Users\rockb\CLionProjects\Stacks C:\Users\rockb\CLionProjects\Stacks\cmake-build-debug C:\Users\rockb\CLionProjects\Stacks\cmake-build-debug C:\Users\rockb\CLionProjects\Stacks\cmake-build-debug\CMakeFiles\Stacks.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Stacks.dir/depend

