cmake_minimum_required(VERSION 3.22)

project(prototype_pattern)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        prototype_shared
)