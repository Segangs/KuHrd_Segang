cmake_minimum_required(VERSION 3.10)
project(segang)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# 1. 한줄씩 추가하는 방법. 실전에서도 파일 관리를 위해 애드익스큐터블을 사용하는 편이다.
# add_executable(AtoZ AtoZ.c) 

# 2. 파일들 정보 함수로 파일 한꺼번에 처리하는 방법. CMakeLists.txt파일이 있는 현재 폴더를 EXECUTABLES변수에 넣어 돌린다. (c문법이 아닌 CMake 문법이다.)
# 파일명 뒤의 .c 확장자를 제거하여 텍스트 추출
file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")

# foreach문법을 사용하여 돌림
foreach(EXECUTABLE ${EXECUTABLES})
    # 파일명 추출
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    
    # 실행
    add_executable(${EXE_NAME} ${EXECUTABLE})

endforeach()