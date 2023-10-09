# Same setup in SECTION-2 now using modern cmake "usage-requirement"

cmake_minimum_required(VERSION 3.10)

project(cmake_library VERSION 0.0.1)

configure_file(config_file config.hpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(MathFunctions)

add_executable(cmake-with-lib.out main.cpp)

target_link_libraries(cmake-with-lib.out PUBLIC mymath foo)

target_include_directories(
    cmake-with-lib.out PUBLIC
    "${PROJECT_BINARY_DIR}"

    # removed because we are now using "usage-requirement"
    # "${PROJECT_SOURCE_DIR}/MathFunctions"
)