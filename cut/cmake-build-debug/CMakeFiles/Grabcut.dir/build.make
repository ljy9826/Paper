# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/j11218gpu/Downloads/clion-2018.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/j11218gpu/Downloads/clion-2018.2.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/j11218gpu/ljy_projects/paper/cut

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/j11218gpu/ljy_projects/paper/cut/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Grabcut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Grabcut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Grabcut.dir/flags.make

CMakeFiles/Grabcut.dir/main.cpp.o: CMakeFiles/Grabcut.dir/flags.make
CMakeFiles/Grabcut.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j11218gpu/ljy_projects/paper/cut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Grabcut.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Grabcut.dir/main.cpp.o -c /home/j11218gpu/ljy_projects/paper/cut/main.cpp

CMakeFiles/Grabcut.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Grabcut.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j11218gpu/ljy_projects/paper/cut/main.cpp > CMakeFiles/Grabcut.dir/main.cpp.i

CMakeFiles/Grabcut.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Grabcut.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j11218gpu/ljy_projects/paper/cut/main.cpp -o CMakeFiles/Grabcut.dir/main.cpp.s

# Object files for target Grabcut
Grabcut_OBJECTS = \
"CMakeFiles/Grabcut.dir/main.cpp.o"

# External object files for target Grabcut
Grabcut_EXTERNAL_OBJECTS =

Grabcut: CMakeFiles/Grabcut.dir/main.cpp.o
Grabcut: CMakeFiles/Grabcut.dir/build.make
Grabcut: /usr/local/lib/libopencv_cudabgsegm.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudaobjdetect.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudastereo.so.3.4.0
Grabcut: /usr/local/lib/libopencv_dnn.so.3.4.0
Grabcut: /usr/local/lib/libopencv_ml.so.3.4.0
Grabcut: /usr/local/lib/libopencv_shape.so.3.4.0
Grabcut: /usr/local/lib/libopencv_stitching.so.3.4.0
Grabcut: /usr/local/lib/libopencv_superres.so.3.4.0
Grabcut: /usr/local/lib/libopencv_videostab.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudafeatures2d.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudaoptflow.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudalegacy.so.3.4.0
Grabcut: /usr/local/lib/libopencv_calib3d.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudawarping.so.3.4.0
Grabcut: /usr/local/lib/libopencv_features2d.so.3.4.0
Grabcut: /usr/local/lib/libopencv_flann.so.3.4.0
Grabcut: /usr/local/lib/libopencv_highgui.so.3.4.0
Grabcut: /usr/local/lib/libopencv_objdetect.so.3.4.0
Grabcut: /usr/local/lib/libopencv_photo.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudaimgproc.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudafilters.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudaarithm.so.3.4.0
Grabcut: /usr/local/lib/libopencv_video.so.3.4.0
Grabcut: /usr/local/lib/libopencv_videoio.so.3.4.0
Grabcut: /usr/local/lib/libopencv_imgcodecs.so.3.4.0
Grabcut: /usr/local/lib/libopencv_imgproc.so.3.4.0
Grabcut: /usr/local/lib/libopencv_core.so.3.4.0
Grabcut: /usr/local/lib/libopencv_cudev.so.3.4.0
Grabcut: CMakeFiles/Grabcut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/j11218gpu/ljy_projects/paper/cut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Grabcut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Grabcut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Grabcut.dir/build: Grabcut

.PHONY : CMakeFiles/Grabcut.dir/build

CMakeFiles/Grabcut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Grabcut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Grabcut.dir/clean

CMakeFiles/Grabcut.dir/depend:
	cd /home/j11218gpu/ljy_projects/paper/cut/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/j11218gpu/ljy_projects/paper/cut /home/j11218gpu/ljy_projects/paper/cut /home/j11218gpu/ljy_projects/paper/cut/cmake-build-debug /home/j11218gpu/ljy_projects/paper/cut/cmake-build-debug /home/j11218gpu/ljy_projects/paper/cut/cmake-build-debug/CMakeFiles/Grabcut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Grabcut.dir/depend

