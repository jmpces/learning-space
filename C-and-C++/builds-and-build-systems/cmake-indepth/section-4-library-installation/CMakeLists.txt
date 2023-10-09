cmake_minimum_required(VERSION 3.10)

project(cmake_lib_optional VERSION 0.0.1)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(config_file config.hpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS mymath foo)
endif()

add_executable(cmake-with-lib.out main.cpp)

target_link_libraries(cmake-with-lib.out PUBLIC ${EXTRA_LIBS})

target_include_directories(
    cmake-with-lib.out PUBLIC
    "${PROJECT_BINARY_DIR}"
)

# copy the "compile executable" into the "bin" folder of your system.
install(TARGETS cmake-with-lib.out DESTINATION bin)

# copy the "configuration header file" needed by the executable to
# the "include" folder of your system.
install(FILES "${PROJECT_BINARY_DIR}/config.hpp"
  DESTINATION include
)

# after "configuring" and "building" the executable and library we can install them using the following commands :

# for older version of cmake below 3.15
# make install

# a newer version that is more compatible friendly
# cmake --install .

# overloading the install prefix
# cmake --install . --prefix "/home/myuser/installdir"

# take note that this assumes you are in the "configured build" folder,
# the folder where the output of the "configuration" phase is saved.

# after installation an "install_manifest.txt" file will be generated, it will contain
# all lists of the file paths where the files of the library is installed.