cmake_minimum_required(VERSION 3.15)

project(composite_pattern)

find_package(composite_lib)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        composite_lib
)
