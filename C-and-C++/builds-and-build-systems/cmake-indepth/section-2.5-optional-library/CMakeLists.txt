cmake_minimum_required(VERSION 3.10)

project(cmake_lib_optional VERSION 0.0.1)

# Now let us make the MathFunctions library optional, it should be above the `configure_file` call.
# Toggle Command Line : -DUSE_MYMATH=OFF -DUSE_MYMATH=ON
# You could also toggle this option in cmake-gui
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# the options will not be applied to the config header if `configure_file()` was
# called before `option()` because the USE_MYMATH macro will be undefined even if
# the option USE_MYMATH is toggled ON.
configure_file(config_file config.hpp)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_subdirectory(MathFunctions)
if(USE_MYMATH)
  # encloses the add_subdirectory call to an if cmake statement
  add_subdirectory(MathFunctions)

  # use a variable instead of directly adding the libraries in the `target_link_libraries`
  # you can add as many library here if you want for example the "foo" library.
  list(APPEND EXTRA_LIBS mymath)

  # use a variable instead of directly adding the  library's directory in `target_include_directories`
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()


add_executable(cmake-with-lib.out main.cpp)

# replaced the "mymath" library and used the CMAKE variable EXTRA_LIBS instead.
# you could also put the "foo" library in the EXTRA_LIBS variable if you want.
target_link_libraries(cmake-with-lib.out PUBLIC ${EXTRA_LIBS} foo)

target_include_directories(
    cmake-with-lib.out PUBLIC
    "${PROJECT_BINARY_DIR}"

    # replaced the old "${PROJECT_SOURCE_DIR}/MathFunctions" directory
    # and used the CMAKE variable EXTRA_INCLUDES instead.
    ${EXTRA_INCLUDES}
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
