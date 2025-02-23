cmake_minimum_required(VERSION 3.22)

project(memento_pattern)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        include/
)
