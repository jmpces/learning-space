add_library(mymath mysquared.cpp mypow.cpp)
add_library(foo Foo.cpp)

# Remember INTERFACE means things that consumers require but the producer doesn't.
target_include_directories(mymath
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)