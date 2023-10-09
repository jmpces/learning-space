cmake_minimum_required(VERSION 3.10)

project(cmake_library VERSION 0.0.1)

configure_file(config_file config.hpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the directory of the MathFunctions library. This executes in the "configure" phase
add_subdirectory(MathFunctions)

add_executable(cmake-with-lib.out main.cpp)

# add the libraries to the executable, the "library names" provided should
# match the "library names" in the CMakeLists.txt call of `add_library` in the
# MathFunctions library directory. This executes in the "build" phase.
target_link_libraries(cmake-with-lib.out PUBLIC mymath foo)

target_include_directories(
    cmake-with-lib.out PUBLIC
    "${PROJECT_BINARY_DIR}"

    # add the directory of the MathFunctions library in the target include directory
    # to make the "header files" available during the "build" compilation.
    "${PROJECT_SOURCE_DIR}/MathFunctions"
)

# WARNING - using consexpr and templated function or classes in the main.cpp programs
# might fail your compilation because constant exressions should be evaluated in one (1)
# translation unit, in this setup the library is built first then the main.cpp is built after
# that means it has two (2) translation units so compilation will fail because the compile
# will not be able to find the definition of functions declared in the MathFunction.hpp
# to work around this problem we should just put the declarations and definitions of the
# classes, methods, function that are constexpr or is using templates into the headerfiles
# or just include the source (mypow.cpp, mysquare.cpp) of the library in the top-level
# cmakelist file if they are a constexpr function, method, template, class.
