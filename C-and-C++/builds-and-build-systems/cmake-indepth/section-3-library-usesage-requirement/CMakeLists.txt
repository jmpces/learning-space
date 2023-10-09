cmake_minimum_required(VERSION 3.10)

project(cmake_lib_optional VERSION 0.0.1)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(config_file config.hpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS mymath foo)

  # removed because we are now using the "usage-requirement" instead of the classical way of including headers
  # list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()


add_executable(cmake-with-lib.out main.cpp)

target_link_libraries(cmake-with-lib.out PUBLIC ${EXTRA_LIBS})

target_include_directories(
    cmake-with-lib.out PUBLIC
    "${PROJECT_BINARY_DIR}"

    # removed because we are now using "usage-requirement" instead of the classical way of including headers
    # ${EXTRA_INCLUDES}
)