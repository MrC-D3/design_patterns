cmake_minimum_required(VERSION 3.22)

project(iterator_lib)

add_library(
    ${PROJECT_NAME}
    source/aggregate.cpp
    source/iterator.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        include
)

add_subdirectory(unit_tests)