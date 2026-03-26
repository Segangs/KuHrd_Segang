cmake_minimum_required(VERSION 3.10)
project(HonGong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# 소스 파일들을 변수에 명시적으로 나열
set(SOURCES
    05_180
    )

add_executable(HonGong_test ${SOURCES}.c)