cmake_minimum_required(VERSION 3.15)

project(double_buffer_lib)

add_library(
    ${PROJECT_NAME}
    source/double_buffer.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)

# Unit Test.
add_subdirectory(unit_test)
