cmake_minimum_required(VERSION 3.22)

project(memento_pattern)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        memento_lib # It'll look for libmemento_lib.a in /usr/local/lib
)