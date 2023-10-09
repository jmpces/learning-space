# Build Citra From Source With Clang

## Configure Build

remove the `-stdlib=libc++` if not working

```
cmake ../ -DCMAKE_BUILD_TYPE=Release -DENABLE_FFMPEG_AUDIO_DECODER=ON -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_FLAGS="-fbracket-depth=1024 -O3 -stdlib=libc++"
```

## Compile Build 

```
cmake --build . -- -j"$(nproc)"
```

## Install build

This is optional

```
sudo make install
```
