### Common cmake build command format

##### Format :

```cmake
cmake -G "Specify Generator (Optional)" -D_FLAGS_YOU_WANT_TO_ENABLE_OPTIONAL -DCMAKE_INSTALL_PREFIX="install/path" "CMakeList.txt path"
```

ex (OpenCV for windows):

```cmake
cd OpenCV
mkdir lib
mkdir build
cd build
cmake -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Release -D OPENCV_ENABLE_ALLOCATOR_STATS=OFF -D BUILD_SHARED_LIBS=OFF -D CMAKE_INSTALL_PREFIX=../lib ..
make
make install
```

- Generator -> ```-G "MinGW Makefiles"```
  - By default cmake will search your environment variables and will look for an available C/C++ compiler, but you can specify it directly using a generator like in the example, the compiler is MinGW for windows

- D build flags -> ```-D CMAKE_BUILD_TYPE=Release -D OPENCV_ENABLE_ALLOCATOR_STATS=OFF -D BUILD_SHARED_LIBS=OFF```
  - these D flags can modify the type of build you want for your application, or library, either release or debug, single or multithreaded, static or shared, etc.

- Installation path -> ```-D CMAKE_INSTALL_PREFIX=../lib```
  - this is where the final binaries and header file will go if you type ```make install```

- CMakeList.txt path -> ```..```
  - this is where the **CMakeList.txt** file is located, in the examples case, it is one directory before the current directory. The current directory is OpenCV/build, while OpenCV is the directory where CMakeList.txt is located, hence we go one directory down using ```..``` 
