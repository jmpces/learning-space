add_library(mymath mysquared.cpp mypow.cpp)
add_library(foo Foo.cpp)

# this will enable "usage-requirement" so we don't need to pass this directory
# in the top level CMakeLists.txt
target_include_directories(mymath
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)