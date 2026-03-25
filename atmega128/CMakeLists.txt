cmake_minimum_required(VERSION 3.10)

# standalone configure일 때만 기본 AVR 툴체인 파일을 지정한다.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/avr-toolchain.cmake")
endif()

project(Atmega128_Project C)

# --- 하드웨어 설정 ---
set(MCU atmega128)
set(F_CPU 16000000UL)
set(AVRDUDE_MCU m128 CACHE STRING "avrdude MCU id")
set(AVRDUDE_PROGRAMMER AVRISPmkII CACHE STRING "avrdude programmer id")
set(AVRDUDE_PORT usb CACHE STRING "avrdude port")
set(AVRDUDE_EXTRA_ARGS "" CACHE STRING "additional avrdude arguments")

# --- 실행 파일 및 옵션 ---
add_executable(${PROJECT_NAME}.elf
    src/uart3.c
    lib/lcd/lcd.c
    lib/uart0/uart0.c
)

target_include_directories(${PROJECT_NAME}.elf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lcd
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/uart0
)

target_compile_options(${PROJECT_NAME}.elf PUBLIC
    -mmcu=${MCU}
    -DF_CPU=${F_CPU}
    -Os -Wall
)

target_link_options(${PROJECT_NAME}.elf PUBLIC -mmcu=${MCU})

# --- 빌드 후처리 (HEX 생성) ---
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMAND avr-size --format=avr --mcu=${MCU} ${PROJECT_NAME}.elf
    COMMENT "Generating Intel HEX file and analysis"
)

# --- 업로드 타겟 추가 ---
find_program(AVRDUDE_EXECUTABLE avrdude REQUIRED)

add_custom_target(upload
    COMMAND ${AVRDUDE_EXECUTABLE}
        -p ${AVRDUDE_MCU}
        -c ${AVRDUDE_PROGRAMMER}
        -P ${AVRDUDE_PORT}
        ${AVRDUDE_EXTRA_ARGS}
        -U flash:w:${PROJECT_NAME}.hex:i
    DEPENDS ${PROJECT_NAME}.elf
    COMMENT "Flashing ${PROJECT_NAME}.hex to hardware..."
    VERBATIM
)
