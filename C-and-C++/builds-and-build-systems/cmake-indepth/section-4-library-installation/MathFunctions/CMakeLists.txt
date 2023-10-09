add_library(mymath mysquared.cpp mypow.cpp)
add_library(foo Foo.cpp)

target_include_directories(mymath
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

# copy the "mymath" compiled library in the "lib" folder of your system.  
install(TARGETS mymath DESTINATION lib)

# copy the "header files" needed by the library
install(FILES MathFunctions.hpp DESTINATION include)