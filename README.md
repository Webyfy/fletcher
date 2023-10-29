# fletcher

C library for calculation of fletcher16 & fletcher32.

## Build & Test
```shell
mkdir build && cd build
cmake ..
cmake --build .
ctest
```
By default static library is built. In order to build shared library set `BUILD_SHARED` option to `ON`
```shell
# replce second line in above command set with
cmake -DBUILD_SHARED=ON ..
``` 

## Dependencies

Testing depends on [criterion](https://github.com/Snaipe/Criterion).
