# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tuomas\OpenGLraycaster

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tuomas\OpenGLraycaster\build

# Include any dependencies generated for this target.
include CMakeFiles/OpenGLraycaster.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenGLraycaster.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGLraycaster.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGLraycaster.dir/flags.make

CMakeFiles/OpenGLraycaster.dir/src/main.cpp.obj: CMakeFiles/OpenGLraycaster.dir/flags.make
CMakeFiles/OpenGLraycaster.dir/src/main.cpp.obj: CMakeFiles/OpenGLraycaster.dir/includes_CXX.rsp
CMakeFiles/OpenGLraycaster.dir/src/main.cpp.obj: C:/Users/tuomas/OpenGLraycaster/src/main.cpp
CMakeFiles/OpenGLraycaster.dir/src/main.cpp.obj: CMakeFiles/OpenGLraycaster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tuomas\OpenGLraycaster\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGLraycaster.dir/src/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLraycaster.dir/src/main.cpp.obj -MF CMakeFiles\OpenGLraycaster.dir\src\main.cpp.obj.d -o CMakeFiles\OpenGLraycaster.dir\src\main.cpp.obj -c C:\Users\tuomas\OpenGLraycaster\src\main.cpp

CMakeFiles/OpenGLraycaster.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGLraycaster.dir/src/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tuomas\OpenGLraycaster\src\main.cpp > CMakeFiles\OpenGLraycaster.dir\src\main.cpp.i

CMakeFiles/OpenGLraycaster.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGLraycaster.dir/src/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tuomas\OpenGLraycaster\src\main.cpp -o CMakeFiles\OpenGLraycaster.dir\src\main.cpp.s

CMakeFiles/OpenGLraycaster.dir/src/App.cpp.obj: CMakeFiles/OpenGLraycaster.dir/flags.make
CMakeFiles/OpenGLraycaster.dir/src/App.cpp.obj: CMakeFiles/OpenGLraycaster.dir/includes_CXX.rsp
CMakeFiles/OpenGLraycaster.dir/src/App.cpp.obj: C:/Users/tuomas/OpenGLraycaster/src/App.cpp
CMakeFiles/OpenGLraycaster.dir/src/App.cpp.obj: CMakeFiles/OpenGLraycaster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tuomas\OpenGLraycaster\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGLraycaster.dir/src/App.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLraycaster.dir/src/App.cpp.obj -MF CMakeFiles\OpenGLraycaster.dir\src\App.cpp.obj.d -o CMakeFiles\OpenGLraycaster.dir\src\App.cpp.obj -c C:\Users\tuomas\OpenGLraycaster\src\App.cpp

CMakeFiles/OpenGLraycaster.dir/src/App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGLraycaster.dir/src/App.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tuomas\OpenGLraycaster\src\App.cpp > CMakeFiles\OpenGLraycaster.dir\src\App.cpp.i

CMakeFiles/OpenGLraycaster.dir/src/App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGLraycaster.dir/src/App.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tuomas\OpenGLraycaster\src\App.cpp -o CMakeFiles\OpenGLraycaster.dir\src\App.cpp.s

# Object files for target OpenGLraycaster
OpenGLraycaster_OBJECTS = \
"CMakeFiles/OpenGLraycaster.dir/src/main.cpp.obj" \
"CMakeFiles/OpenGLraycaster.dir/src/App.cpp.obj"

# External object files for target OpenGLraycaster
OpenGLraycaster_EXTERNAL_OBJECTS =

OpenGLraycaster.exe: CMakeFiles/OpenGLraycaster.dir/src/main.cpp.obj
OpenGLraycaster.exe: CMakeFiles/OpenGLraycaster.dir/src/App.cpp.obj
OpenGLraycaster.exe: CMakeFiles/OpenGLraycaster.dir/build.make
OpenGLraycaster.exe: CMakeFiles/OpenGLraycaster.dir/linkLibs.rsp
OpenGLraycaster.exe: CMakeFiles/OpenGLraycaster.dir/objects1.rsp
OpenGLraycaster.exe: CMakeFiles/OpenGLraycaster.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\tuomas\OpenGLraycaster\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OpenGLraycaster.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OpenGLraycaster.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGLraycaster.dir/build: OpenGLraycaster.exe
.PHONY : CMakeFiles/OpenGLraycaster.dir/build

CMakeFiles/OpenGLraycaster.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OpenGLraycaster.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OpenGLraycaster.dir/clean

CMakeFiles/OpenGLraycaster.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tuomas\OpenGLraycaster C:\Users\tuomas\OpenGLraycaster C:\Users\tuomas\OpenGLraycaster\build C:\Users\tuomas\OpenGLraycaster\build C:\Users\tuomas\OpenGLraycaster\build\CMakeFiles\OpenGLraycaster.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/OpenGLraycaster.dir/depend

