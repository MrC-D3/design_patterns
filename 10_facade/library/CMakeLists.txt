cmake_minimum_required(VERSION 3.22)

project(facade_lib)

add_subdirectory(sub_library)

add_library(
    ${PROJECT_NAME}_static
    source/facade.cpp
)

target_include_directories(
    ${PROJECT_NAME}_static
    PUBLIC
        include/
)
