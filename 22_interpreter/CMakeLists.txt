cmake_minimum_required(VERSION 3.15)

project(interpreter_pattern)

find_package(interpreter_lib)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        interpreter_lib
)
