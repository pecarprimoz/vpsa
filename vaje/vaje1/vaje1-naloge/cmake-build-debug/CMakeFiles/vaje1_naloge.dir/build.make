# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/primoz/Downloads/CLion-2017.2.3/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/primoz/Downloads/CLion-2017.2.3/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vaje1_naloge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vaje1_naloge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vaje1_naloge.dir/flags.make

CMakeFiles/vaje1_naloge.dir/main.c.o: CMakeFiles/vaje1_naloge.dir/flags.make
CMakeFiles/vaje1_naloge.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/vaje1_naloge.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vaje1_naloge.dir/main.c.o   -c /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/main.c

CMakeFiles/vaje1_naloge.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vaje1_naloge.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/main.c > CMakeFiles/vaje1_naloge.dir/main.c.i

CMakeFiles/vaje1_naloge.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vaje1_naloge.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/main.c -o CMakeFiles/vaje1_naloge.dir/main.c.s

CMakeFiles/vaje1_naloge.dir/main.c.o.requires:

.PHONY : CMakeFiles/vaje1_naloge.dir/main.c.o.requires

CMakeFiles/vaje1_naloge.dir/main.c.o.provides: CMakeFiles/vaje1_naloge.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/vaje1_naloge.dir/build.make CMakeFiles/vaje1_naloge.dir/main.c.o.provides.build
.PHONY : CMakeFiles/vaje1_naloge.dir/main.c.o.provides

CMakeFiles/vaje1_naloge.dir/main.c.o.provides.build: CMakeFiles/vaje1_naloge.dir/main.c.o


# Object files for target vaje1_naloge
vaje1_naloge_OBJECTS = \
"CMakeFiles/vaje1_naloge.dir/main.c.o"

# External object files for target vaje1_naloge
vaje1_naloge_EXTERNAL_OBJECTS =

vaje1_naloge: CMakeFiles/vaje1_naloge.dir/main.c.o
vaje1_naloge: CMakeFiles/vaje1_naloge.dir/build.make
vaje1_naloge: CMakeFiles/vaje1_naloge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable vaje1_naloge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vaje1_naloge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vaje1_naloge.dir/build: vaje1_naloge

.PHONY : CMakeFiles/vaje1_naloge.dir/build

CMakeFiles/vaje1_naloge.dir/requires: CMakeFiles/vaje1_naloge.dir/main.c.o.requires

.PHONY : CMakeFiles/vaje1_naloge.dir/requires

CMakeFiles/vaje1_naloge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vaje1_naloge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vaje1_naloge.dir/clean

CMakeFiles/vaje1_naloge.dir/depend:
	cd /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/cmake-build-debug /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/cmake-build-debug /home/primoz/faks/vspa/vaje/vaje1/vaje1-naloge/cmake-build-debug/CMakeFiles/vaje1_naloge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vaje1_naloge.dir/depend
