cmake_minimum_required(VERSION 3.22)

project(singleton_library)

add_library(
    ${PROJECT_NAME}
    source/singleton.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        include/
)