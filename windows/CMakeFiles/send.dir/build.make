# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "C:\Program Files\CodeBlocks\MinGW\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CodeBlocks\MinGW\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\codes\wol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\codes\wol\windows

# Include any dependencies generated for this target.
include CMakeFiles/send.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/send.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/send.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/send.dir/flags.make

CMakeFiles/send.dir/send.cpp.obj: CMakeFiles/send.dir/flags.make
CMakeFiles/send.dir/send.cpp.obj: ../send.cpp
CMakeFiles/send.dir/send.cpp.obj: CMakeFiles/send.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\codes\wol\windows\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/send.dir/send.cpp.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/send.dir/send.cpp.obj -MF CMakeFiles\send.dir\send.cpp.obj.d -o CMakeFiles\send.dir\send.cpp.obj -c D:\codes\wol\send.cpp

CMakeFiles/send.dir/send.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/send.dir/send.cpp.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\codes\wol\send.cpp > CMakeFiles\send.dir\send.cpp.i

CMakeFiles/send.dir/send.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/send.dir/send.cpp.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\codes\wol\send.cpp -o CMakeFiles\send.dir\send.cpp.s

# Object files for target send
send_OBJECTS = \
"CMakeFiles/send.dir/send.cpp.obj"

# External object files for target send
send_EXTERNAL_OBJECTS =

send.exe: CMakeFiles/send.dir/send.cpp.obj
send.exe: CMakeFiles/send.dir/build.make
send.exe: libconfigure_util.a
send.exe: libwake_on_lan.a
send.exe: CMakeFiles/send.dir/linklibs.rsp
send.exe: CMakeFiles/send.dir/objects1.rsp
send.exe: CMakeFiles/send.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\codes\wol\windows\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable send.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\send.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/send.dir/build: send.exe
.PHONY : CMakeFiles/send.dir/build

CMakeFiles/send.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\send.dir\cmake_clean.cmake
.PHONY : CMakeFiles/send.dir/clean

CMakeFiles/send.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\codes\wol D:\codes\wol D:\codes\wol\windows D:\codes\wol\windows D:\codes\wol\windows\CMakeFiles\send.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/send.dir/depend

