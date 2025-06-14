cmake_minimum_required(VERSION 3.15)

find_package(command_lib)

project(command_pattern)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        command_lib
)