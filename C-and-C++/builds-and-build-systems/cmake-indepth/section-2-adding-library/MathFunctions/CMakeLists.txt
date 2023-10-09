# add the name of the library and its source code dependencies
# the first argument will be the name of the library that will
# be used when linking it to the executable, in linux systems
# this will output "libmymath.a" for a static library, but
# it could be different for other systems like msvc compiler.
add_library(mymath mysquared.cpp mypow.cpp)
add_library(foo Foo.cpp)