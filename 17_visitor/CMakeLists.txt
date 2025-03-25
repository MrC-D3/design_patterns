cmake_minimum_required(VERSION 3.15)

project(visitor_pattern)

find_package(visitor_lib)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        visitor_lib
)
