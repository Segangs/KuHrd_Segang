cmake_minimum_required(VERSION 3.10)
project(mystack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_executable(myStack2 main main.c stack3.c)