# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/pacman.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pacman.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pacman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pacman.dir/flags.make

CMakeFiles/pacman.dir/src/character.cxx.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/src/character.cxx.o: ../src/character.cxx
CMakeFiles/pacman.dir/src/character.cxx.o: CMakeFiles/pacman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pacman.dir/src/character.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pacman.dir/src/character.cxx.o -MF CMakeFiles/pacman.dir/src/character.cxx.o.d -o CMakeFiles/pacman.dir/src/character.cxx.o -c "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/character.cxx"

CMakeFiles/pacman.dir/src/character.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/src/character.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/character.cxx" > CMakeFiles/pacman.dir/src/character.cxx.i

CMakeFiles/pacman.dir/src/character.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/src/character.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/character.cxx" -o CMakeFiles/pacman.dir/src/character.cxx.s

CMakeFiles/pacman.dir/src/model.cxx.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/src/model.cxx.o: ../src/model.cxx
CMakeFiles/pacman.dir/src/model.cxx.o: CMakeFiles/pacman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pacman.dir/src/model.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pacman.dir/src/model.cxx.o -MF CMakeFiles/pacman.dir/src/model.cxx.o.d -o CMakeFiles/pacman.dir/src/model.cxx.o -c "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/model.cxx"

CMakeFiles/pacman.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/src/model.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/model.cxx" > CMakeFiles/pacman.dir/src/model.cxx.i

CMakeFiles/pacman.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/src/model.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/model.cxx" -o CMakeFiles/pacman.dir/src/model.cxx.s

CMakeFiles/pacman.dir/src/view.cxx.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/src/view.cxx.o: ../src/view.cxx
CMakeFiles/pacman.dir/src/view.cxx.o: CMakeFiles/pacman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pacman.dir/src/view.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pacman.dir/src/view.cxx.o -MF CMakeFiles/pacman.dir/src/view.cxx.o.d -o CMakeFiles/pacman.dir/src/view.cxx.o -c "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/view.cxx"

CMakeFiles/pacman.dir/src/view.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/src/view.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/view.cxx" > CMakeFiles/pacman.dir/src/view.cxx.i

CMakeFiles/pacman.dir/src/view.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/src/view.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/view.cxx" -o CMakeFiles/pacman.dir/src/view.cxx.s

CMakeFiles/pacman.dir/src/controller.cxx.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/src/controller.cxx.o: ../src/controller.cxx
CMakeFiles/pacman.dir/src/controller.cxx.o: CMakeFiles/pacman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pacman.dir/src/controller.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pacman.dir/src/controller.cxx.o -MF CMakeFiles/pacman.dir/src/controller.cxx.o.d -o CMakeFiles/pacman.dir/src/controller.cxx.o -c "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/controller.cxx"

CMakeFiles/pacman.dir/src/controller.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/src/controller.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/controller.cxx" > CMakeFiles/pacman.dir/src/controller.cxx.i

CMakeFiles/pacman.dir/src/controller.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/src/controller.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/controller.cxx" -o CMakeFiles/pacman.dir/src/controller.cxx.s

CMakeFiles/pacman.dir/src/main.cxx.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/src/main.cxx.o: ../src/main.cxx
CMakeFiles/pacman.dir/src/main.cxx.o: CMakeFiles/pacman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pacman.dir/src/main.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pacman.dir/src/main.cxx.o -MF CMakeFiles/pacman.dir/src/main.cxx.o.d -o CMakeFiles/pacman.dir/src/main.cxx.o -c "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/main.cxx"

CMakeFiles/pacman.dir/src/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/src/main.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/main.cxx" > CMakeFiles/pacman.dir/src/main.cxx.i

CMakeFiles/pacman.dir/src/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/src/main.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/src/main.cxx" -o CMakeFiles/pacman.dir/src/main.cxx.s

# Object files for target pacman
pacman_OBJECTS = \
"CMakeFiles/pacman.dir/src/character.cxx.o" \
"CMakeFiles/pacman.dir/src/model.cxx.o" \
"CMakeFiles/pacman.dir/src/view.cxx.o" \
"CMakeFiles/pacman.dir/src/controller.cxx.o" \
"CMakeFiles/pacman.dir/src/main.cxx.o"

# External object files for target pacman
pacman_EXTERNAL_OBJECTS =

pacman: CMakeFiles/pacman.dir/src/character.cxx.o
pacman: CMakeFiles/pacman.dir/src/model.cxx.o
pacman: CMakeFiles/pacman.dir/src/view.cxx.o
pacman: CMakeFiles/pacman.dir/src/controller.cxx.o
pacman: CMakeFiles/pacman.dir/src/main.cxx.o
pacman: CMakeFiles/pacman.dir/build.make
pacman: .cs211/lib/ge211/src/libge211.a
pacman: /opt/homebrew/lib/libSDL2.dylib
pacman: /opt/homebrew/lib/libSDL2_image.dylib
pacman: /opt/homebrew/lib/libSDL2_mixer.dylib
pacman: /opt/homebrew/lib/libSDL2_ttf.dylib
pacman: CMakeFiles/pacman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable pacman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pacman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pacman.dir/build: pacman
.PHONY : CMakeFiles/pacman.dir/build

CMakeFiles/pacman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pacman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pacman.dir/clean

CMakeFiles/pacman.dir/depend:
	cd "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man" "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man" "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug" "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug" "/Users/varoonenjeti/Documents/Northwestern University/Fall Quarter (2022)/COMP_SCI 211/Pac-Man/cmake-build-debug/CMakeFiles/pacman.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/pacman.dir/depend

