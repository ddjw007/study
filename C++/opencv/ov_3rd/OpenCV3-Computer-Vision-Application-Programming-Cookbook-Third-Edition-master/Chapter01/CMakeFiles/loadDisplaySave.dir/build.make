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
CMAKE_SOURCE_DIR = /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01

# Include any dependencies generated for this target.
include CMakeFiles/loadDisplaySave.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/loadDisplaySave.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/loadDisplaySave.dir/flags.make

CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.o: CMakeFiles/loadDisplaySave.dir/flags.make
CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.o: loadDisplaySave.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.o -c /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01/loadDisplaySave.cpp

CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01/loadDisplaySave.cpp > CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.i

CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01/loadDisplaySave.cpp -o CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.s

# Object files for target loadDisplaySave
loadDisplaySave_OBJECTS = \
"CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.o"

# External object files for target loadDisplaySave
loadDisplaySave_EXTERNAL_OBJECTS =

loadDisplaySave: CMakeFiles/loadDisplaySave.dir/loadDisplaySave.cpp.o
loadDisplaySave: CMakeFiles/loadDisplaySave.dir/build.make
loadDisplaySave: /usr/local/lib/libopencv_highgui.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_ml.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_objdetect.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_photo.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_stitching.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_video.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_videoio.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_imgcodecs.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_calib3d.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_dnn.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_features2d.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_flann.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_imgproc.so.4.5.2
loadDisplaySave: /usr/local/lib/libopencv_core.so.4.5.2
loadDisplaySave: CMakeFiles/loadDisplaySave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable loadDisplaySave"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/loadDisplaySave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/loadDisplaySave.dir/build: loadDisplaySave

.PHONY : CMakeFiles/loadDisplaySave.dir/build

CMakeFiles/loadDisplaySave.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/loadDisplaySave.dir/cmake_clean.cmake
.PHONY : CMakeFiles/loadDisplaySave.dir/clean

CMakeFiles/loadDisplaySave.dir/depend:
	cd /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01 /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01 /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01 /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01 /home/djw/study/C++/opencv/ov_3rd/OpenCV3-Computer-Vision-Application-Programming-Cookbook-Third-Edition-master/Chapter01/CMakeFiles/loadDisplaySave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/loadDisplaySave.dir/depend

