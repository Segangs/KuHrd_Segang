cmake_minimum_required(VERSION 3.16)

project(cpp_code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -pedantic)
endif()

file(GLOB_RECURSE CPP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/chap*/*.cpp"
)

foreach(source_file IN LISTS CPP_SOURCES)
    get_filename_component(target_name "${source_file}" NAME_WE)
    get_filename_component(source_dir "${source_file}" DIRECTORY)
    file(RELATIVE_PATH relative_dir "${CMAKE_SOURCE_DIR}" "${source_dir}")

    add_executable("${target_name}" "${source_file}")
    set_target_properties("${target_name}" PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${relative_dir}"
    )
endforeach()
