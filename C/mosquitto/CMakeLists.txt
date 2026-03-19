cmake_minimum_required(VERSION 3.10)
project(mosquitto)

include_directories(${CMAKE_CURRENT_LIST_DIR}) // h의 라이브러리 검색하여 경로 찾아줌

find_library(PAHO_MQTT_LIB paho-mqtt3c)
add_executable(mos mos.c)

target_link_libraries(mos ${PAHO_MQTT_LIB})