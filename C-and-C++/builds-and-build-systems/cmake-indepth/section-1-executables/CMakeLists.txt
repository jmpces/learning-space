# Section A - configure and build command, basic cmake setup, configuration file, executable compilation.
# Section B - adding libraries

# Section A - when choosing a cmake project name avoid the "-" character or any
# white spaces, it is better to only have one word project name or
# use "_" as a substitute for spaces, or use a camel case project name.

# Section A - set minimum cmake version requirement, this will prevent lower version of cmake to configure the project
cmake_minimum_required(VERSION 3.10)

# Section A - set the project name, this name will be used in your
# configuration header file like in the version number.
# project(cmake_executable)

# Section A - set the project name and version, the name will be used in
# your configuration header file like in the version number.
project(cmake_executable VERSION 0.0.1)

# Section A - create a configuration file to pass the version number to the source code
# when the project is configured by "cmake .." (not build/compiled), this will
# produce the output file "config.hpp" in the "build/" binary directory.
configure_file(config_file config.hpp)

# Section A - specify the C++ standard, this call should always be above the call to add_executable()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Section A - add the executable, the first argument is the output executable of your program.
# the other arguments are the source code files.
add_executable(cmake-executable main.cpp)

# Section A - Since the configured file will be written into the binary tree, we must add that
# directory to the list of paths to search for include files using target_include_directories.
# always add the this function to the end of the CMakeLists.txt file.
target_include_directories(
    cmake-executable PUBLIC
    "${PROJECT_BINARY_DIR}"
)