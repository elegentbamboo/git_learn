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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build

# Include any dependencies generated for this target.
include tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/depend.make

# Include the progress variables for this target.
include tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/progress.make

# Include the compile flags for this target's objects.
include tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/flags.make

tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/__/embed.cpp.o: tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/flags.make
tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/__/embed.cpp.o: ../tests/test_cmake_build/embed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/__/embed.cpp.o"
	cd /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/tests/test_cmake_build/subdirectory_embed && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_embed_lib.dir/__/embed.cpp.o -c /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/tests/test_cmake_build/embed.cpp

tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/__/embed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_embed_lib.dir/__/embed.cpp.i"
	cd /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/tests/test_cmake_build/subdirectory_embed && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/tests/test_cmake_build/embed.cpp > CMakeFiles/test_embed_lib.dir/__/embed.cpp.i

tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/__/embed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_embed_lib.dir/__/embed.cpp.s"
	cd /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/tests/test_cmake_build/subdirectory_embed && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/tests/test_cmake_build/embed.cpp -o CMakeFiles/test_embed_lib.dir/__/embed.cpp.s

# Object files for target test_embed_lib
test_embed_lib_OBJECTS = \
"CMakeFiles/test_embed_lib.dir/__/embed.cpp.o"

# External object files for target test_embed_lib
test_embed_lib_EXTERNAL_OBJECTS =

tests/test_cmake_build/subdirectory_embed/libtest_embed_lib.a: tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/__/embed.cpp.o
tests/test_cmake_build/subdirectory_embed/libtest_embed_lib.a: tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/build.make
tests/test_cmake_build/subdirectory_embed/libtest_embed_lib.a: tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtest_embed_lib.a"
	cd /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/tests/test_cmake_build/subdirectory_embed && $(CMAKE_COMMAND) -P CMakeFiles/test_embed_lib.dir/cmake_clean_target.cmake
	cd /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/tests/test_cmake_build/subdirectory_embed && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_embed_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/build: tests/test_cmake_build/subdirectory_embed/libtest_embed_lib.a

.PHONY : tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/build

tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/clean:
	cd /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/tests/test_cmake_build/subdirectory_embed && $(CMAKE_COMMAND) -P CMakeFiles/test_embed_lib.dir/cmake_clean.cmake
.PHONY : tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/clean

tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/depend:
	cd /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11 /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/tests/test_cmake_build/subdirectory_embed /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/tests/test_cmake_build/subdirectory_embed /Project/ros_project/pypcl_ros-master/src/pyrosmsg/src/pybind11/build/tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/test_cmake_build/subdirectory_embed/CMakeFiles/test_embed_lib.dir/depend

