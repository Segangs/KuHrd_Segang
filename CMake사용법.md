#CMake 사용법

---
- CMakeLists.txt로 빌드 하는 방법

```shell
mkdir build
cd build
cmake ..
make
```

- makefile 사용법
    - 우선 소스를 오브젝트로 만든다.

```shell
cc -c main.c 
cc -c serial.c 
cc -o carSerial_main.o serial.o