# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sublunary/repos/sfml-backgammon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sublunary/repos/sfml-backgammon/build

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/src/Application.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Application.cpp.o: ../src/Application.cpp
CMakeFiles/app.dir/src/Application.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app.dir/src/Application.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Application.cpp.o -MF CMakeFiles/app.dir/src/Application.cpp.o.d -o CMakeFiles/app.dir/src/Application.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/Application.cpp

CMakeFiles/app.dir/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/Application.cpp > CMakeFiles/app.dir/src/Application.cpp.i

CMakeFiles/app.dir/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/Application.cpp -o CMakeFiles/app.dir/src/Application.cpp.s

CMakeFiles/app.dir/src/Board.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Board.cpp.o: ../src/Board.cpp
CMakeFiles/app.dir/src/Board.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/app.dir/src/Board.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Board.cpp.o -MF CMakeFiles/app.dir/src/Board.cpp.o.d -o CMakeFiles/app.dir/src/Board.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/Board.cpp

CMakeFiles/app.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/Board.cpp > CMakeFiles/app.dir/src/Board.cpp.i

CMakeFiles/app.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/Board.cpp -o CMakeFiles/app.dir/src/Board.cpp.s

CMakeFiles/app.dir/src/Button.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Button.cpp.o: ../src/Button.cpp
CMakeFiles/app.dir/src/Button.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/app.dir/src/Button.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Button.cpp.o -MF CMakeFiles/app.dir/src/Button.cpp.o.d -o CMakeFiles/app.dir/src/Button.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/Button.cpp

CMakeFiles/app.dir/src/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/Button.cpp > CMakeFiles/app.dir/src/Button.cpp.i

CMakeFiles/app.dir/src/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/Button.cpp -o CMakeFiles/app.dir/src/Button.cpp.s

CMakeFiles/app.dir/src/Chip.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Chip.cpp.o: ../src/Chip.cpp
CMakeFiles/app.dir/src/Chip.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/app.dir/src/Chip.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Chip.cpp.o -MF CMakeFiles/app.dir/src/Chip.cpp.o.d -o CMakeFiles/app.dir/src/Chip.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/Chip.cpp

CMakeFiles/app.dir/src/Chip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Chip.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/Chip.cpp > CMakeFiles/app.dir/src/Chip.cpp.i

CMakeFiles/app.dir/src/Chip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Chip.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/Chip.cpp -o CMakeFiles/app.dir/src/Chip.cpp.s

CMakeFiles/app.dir/src/Game.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Game.cpp.o: ../src/Game.cpp
CMakeFiles/app.dir/src/Game.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/app.dir/src/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Game.cpp.o -MF CMakeFiles/app.dir/src/Game.cpp.o.d -o CMakeFiles/app.dir/src/Game.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/Game.cpp

CMakeFiles/app.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/Game.cpp > CMakeFiles/app.dir/src/Game.cpp.i

CMakeFiles/app.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/Game.cpp -o CMakeFiles/app.dir/src/Game.cpp.s

CMakeFiles/app.dir/src/Player.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Player.cpp.o: ../src/Player.cpp
CMakeFiles/app.dir/src/Player.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/app.dir/src/Player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Player.cpp.o -MF CMakeFiles/app.dir/src/Player.cpp.o.d -o CMakeFiles/app.dir/src/Player.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/Player.cpp

CMakeFiles/app.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/Player.cpp > CMakeFiles/app.dir/src/Player.cpp.i

CMakeFiles/app.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/Player.cpp -o CMakeFiles/app.dir/src/Player.cpp.s

CMakeFiles/app.dir/src/Random.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Random.cpp.o: ../src/Random.cpp
CMakeFiles/app.dir/src/Random.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/app.dir/src/Random.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Random.cpp.o -MF CMakeFiles/app.dir/src/Random.cpp.o.d -o CMakeFiles/app.dir/src/Random.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/Random.cpp

CMakeFiles/app.dir/src/Random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Random.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/Random.cpp > CMakeFiles/app.dir/src/Random.cpp.i

CMakeFiles/app.dir/src/Random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Random.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/Random.cpp -o CMakeFiles/app.dir/src/Random.cpp.s

CMakeFiles/app.dir/src/Slot.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Slot.cpp.o: ../src/Slot.cpp
CMakeFiles/app.dir/src/Slot.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/app.dir/src/Slot.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/Slot.cpp.o -MF CMakeFiles/app.dir/src/Slot.cpp.o.d -o CMakeFiles/app.dir/src/Slot.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/Slot.cpp

CMakeFiles/app.dir/src/Slot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Slot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/Slot.cpp > CMakeFiles/app.dir/src/Slot.cpp.i

CMakeFiles/app.dir/src/Slot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Slot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/Slot.cpp -o CMakeFiles/app.dir/src/Slot.cpp.s

CMakeFiles/app.dir/src/main.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/app.dir/src/main.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/app.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/main.cpp.o -MF CMakeFiles/app.dir/src/main.cpp.o.d -o CMakeFiles/app.dir/src/main.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/main.cpp

CMakeFiles/app.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/main.cpp > CMakeFiles/app.dir/src/main.cpp.i

CMakeFiles/app.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/main.cpp -o CMakeFiles/app.dir/src/main.cpp.s

CMakeFiles/app.dir/src/states/GameState.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/states/GameState.cpp.o: ../src/states/GameState.cpp
CMakeFiles/app.dir/src/states/GameState.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/app.dir/src/states/GameState.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/states/GameState.cpp.o -MF CMakeFiles/app.dir/src/states/GameState.cpp.o.d -o CMakeFiles/app.dir/src/states/GameState.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/states/GameState.cpp

CMakeFiles/app.dir/src/states/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/states/GameState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/states/GameState.cpp > CMakeFiles/app.dir/src/states/GameState.cpp.i

CMakeFiles/app.dir/src/states/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/states/GameState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/states/GameState.cpp -o CMakeFiles/app.dir/src/states/GameState.cpp.s

CMakeFiles/app.dir/src/states/MenuState.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/states/MenuState.cpp.o: ../src/states/MenuState.cpp
CMakeFiles/app.dir/src/states/MenuState.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/app.dir/src/states/MenuState.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/states/MenuState.cpp.o -MF CMakeFiles/app.dir/src/states/MenuState.cpp.o.d -o CMakeFiles/app.dir/src/states/MenuState.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/states/MenuState.cpp

CMakeFiles/app.dir/src/states/MenuState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/states/MenuState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/states/MenuState.cpp > CMakeFiles/app.dir/src/states/MenuState.cpp.i

CMakeFiles/app.dir/src/states/MenuState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/states/MenuState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/states/MenuState.cpp -o CMakeFiles/app.dir/src/states/MenuState.cpp.s

CMakeFiles/app.dir/src/states/State.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/states/State.cpp.o: ../src/states/State.cpp
CMakeFiles/app.dir/src/states/State.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/app.dir/src/states/State.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/states/State.cpp.o -MF CMakeFiles/app.dir/src/states/State.cpp.o.d -o CMakeFiles/app.dir/src/states/State.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/states/State.cpp

CMakeFiles/app.dir/src/states/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/states/State.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/states/State.cpp > CMakeFiles/app.dir/src/states/State.cpp.i

CMakeFiles/app.dir/src/states/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/states/State.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/states/State.cpp -o CMakeFiles/app.dir/src/states/State.cpp.s

CMakeFiles/app.dir/src/states/StateStack.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/states/StateStack.cpp.o: ../src/states/StateStack.cpp
CMakeFiles/app.dir/src/states/StateStack.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/app.dir/src/states/StateStack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/states/StateStack.cpp.o -MF CMakeFiles/app.dir/src/states/StateStack.cpp.o.d -o CMakeFiles/app.dir/src/states/StateStack.cpp.o -c /home/sublunary/repos/sfml-backgammon/src/states/StateStack.cpp

CMakeFiles/app.dir/src/states/StateStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/states/StateStack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sublunary/repos/sfml-backgammon/src/states/StateStack.cpp > CMakeFiles/app.dir/src/states/StateStack.cpp.i

CMakeFiles/app.dir/src/states/StateStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/states/StateStack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sublunary/repos/sfml-backgammon/src/states/StateStack.cpp -o CMakeFiles/app.dir/src/states/StateStack.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/src/Application.cpp.o" \
"CMakeFiles/app.dir/src/Board.cpp.o" \
"CMakeFiles/app.dir/src/Button.cpp.o" \
"CMakeFiles/app.dir/src/Chip.cpp.o" \
"CMakeFiles/app.dir/src/Game.cpp.o" \
"CMakeFiles/app.dir/src/Player.cpp.o" \
"CMakeFiles/app.dir/src/Random.cpp.o" \
"CMakeFiles/app.dir/src/Slot.cpp.o" \
"CMakeFiles/app.dir/src/main.cpp.o" \
"CMakeFiles/app.dir/src/states/GameState.cpp.o" \
"CMakeFiles/app.dir/src/states/MenuState.cpp.o" \
"CMakeFiles/app.dir/src/states/State.cpp.o" \
"CMakeFiles/app.dir/src/states/StateStack.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/src/Application.cpp.o
app: CMakeFiles/app.dir/src/Board.cpp.o
app: CMakeFiles/app.dir/src/Button.cpp.o
app: CMakeFiles/app.dir/src/Chip.cpp.o
app: CMakeFiles/app.dir/src/Game.cpp.o
app: CMakeFiles/app.dir/src/Player.cpp.o
app: CMakeFiles/app.dir/src/Random.cpp.o
app: CMakeFiles/app.dir/src/Slot.cpp.o
app: CMakeFiles/app.dir/src/main.cpp.o
app: CMakeFiles/app.dir/src/states/GameState.cpp.o
app: CMakeFiles/app.dir/src/states/MenuState.cpp.o
app: CMakeFiles/app.dir/src/states/State.cpp.o
app: CMakeFiles/app.dir/src/states/StateStack.cpp.o
app: CMakeFiles/app.dir/build.make
app: /usr/lib/x86_64-linux-gnu/libGLX.so
app: /usr/lib/x86_64-linux-gnu/libOpenGL.so
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sublunary/repos/sfml-backgammon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app
.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /home/sublunary/repos/sfml-backgammon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sublunary/repos/sfml-backgammon /home/sublunary/repos/sfml-backgammon /home/sublunary/repos/sfml-backgammon/build /home/sublunary/repos/sfml-backgammon/build /home/sublunary/repos/sfml-backgammon/build/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend

