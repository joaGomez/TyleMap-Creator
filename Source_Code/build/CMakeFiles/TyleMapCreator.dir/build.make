# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/build

# Include any dependencies generated for this target.
include CMakeFiles/TyleMapCreator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TyleMapCreator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TyleMapCreator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TyleMapCreator.dir/flags.make

CMakeFiles/TyleMapCreator.dir/main.cpp.obj: CMakeFiles/TyleMapCreator.dir/flags.make
CMakeFiles/TyleMapCreator.dir/main.cpp.obj: ../main.cpp
CMakeFiles/TyleMapCreator.dir/main.cpp.obj: CMakeFiles/TyleMapCreator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TyleMapCreator.dir/main.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TyleMapCreator.dir/main.cpp.obj -MF CMakeFiles/TyleMapCreator.dir/main.cpp.obj.d -o CMakeFiles/TyleMapCreator.dir/main.cpp.obj -c C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/main.cpp

CMakeFiles/TyleMapCreator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TyleMapCreator.dir/main.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/main.cpp > CMakeFiles/TyleMapCreator.dir/main.cpp.i

CMakeFiles/TyleMapCreator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TyleMapCreator.dir/main.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/main.cpp -o CMakeFiles/TyleMapCreator.dir/main.cpp.s

CMakeFiles/TyleMapCreator.dir/Map.cpp.obj: CMakeFiles/TyleMapCreator.dir/flags.make
CMakeFiles/TyleMapCreator.dir/Map.cpp.obj: ../Map.cpp
CMakeFiles/TyleMapCreator.dir/Map.cpp.obj: CMakeFiles/TyleMapCreator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TyleMapCreator.dir/Map.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TyleMapCreator.dir/Map.cpp.obj -MF CMakeFiles/TyleMapCreator.dir/Map.cpp.obj.d -o CMakeFiles/TyleMapCreator.dir/Map.cpp.obj -c C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/Map.cpp

CMakeFiles/TyleMapCreator.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TyleMapCreator.dir/Map.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/Map.cpp > CMakeFiles/TyleMapCreator.dir/Map.cpp.i

CMakeFiles/TyleMapCreator.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TyleMapCreator.dir/Map.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/Map.cpp -o CMakeFiles/TyleMapCreator.dir/Map.cpp.s

# Object files for target TyleMapCreator
TyleMapCreator_OBJECTS = \
"CMakeFiles/TyleMapCreator.dir/main.cpp.obj" \
"CMakeFiles/TyleMapCreator.dir/Map.cpp.obj"

# External object files for target TyleMapCreator
TyleMapCreator_EXTERNAL_OBJECTS =

TyleMapCreator.exe: CMakeFiles/TyleMapCreator.dir/main.cpp.obj
TyleMapCreator.exe: CMakeFiles/TyleMapCreator.dir/Map.cpp.obj
TyleMapCreator.exe: CMakeFiles/TyleMapCreator.dir/build.make
TyleMapCreator.exe: CMakeFiles/TyleMapCreator.dir/linklibs.rsp
TyleMapCreator.exe: CMakeFiles/TyleMapCreator.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TyleMapCreator.exe"
	"C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f CMakeFiles/TyleMapCreator.dir/objects.a
	C:/MinGW/bin/ar.exe cr CMakeFiles/TyleMapCreator.dir/objects.a @CMakeFiles/TyleMapCreator.dir/objects1.rsp
	C:/MinGW/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/TyleMapCreator.dir/objects.a -Wl,--no-whole-archive -o TyleMapCreator.exe -Wl,--out-implib,libTyleMapCreator.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/TyleMapCreator.dir/linklibs.rsp
	C:/Windows/System32/WindowsPowerShell/v1.0/powershell.exe -noprofile -executionpolicy Bypass -file C:/dev/vcpkg/scripts/buildsystems/msbuild/applocal.ps1 -targetBinary C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/build/TyleMapCreator.exe -installedDir C:/dev/vcpkg/installed/x64-windows/debug/bin -OutVariable out

# Rule to build all files generated by this target.
CMakeFiles/TyleMapCreator.dir/build: TyleMapCreator.exe
.PHONY : CMakeFiles/TyleMapCreator.dir/build

CMakeFiles/TyleMapCreator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TyleMapCreator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TyleMapCreator.dir/clean

CMakeFiles/TyleMapCreator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/build C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/build C:/Users/joako/OneDrive/Escritorio/Storage/TyleMap-Creator/Source_Code/build/CMakeFiles/TyleMapCreator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TyleMapCreator.dir/depend

