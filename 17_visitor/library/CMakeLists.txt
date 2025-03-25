cmake_minimum_required(VERSION 3.15)

project(visitor_lib)

add_executable(
    ${PROJECT_NAME}
    source/element_concrete.cpp
    source/visitor_concrete.cpp
    source/object_structure.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/>
)

