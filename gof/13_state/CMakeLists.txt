cmake_minimum_required(VERSION 3.15)

find_package(state_lib)

project(state_pattern)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        state_lib
)
