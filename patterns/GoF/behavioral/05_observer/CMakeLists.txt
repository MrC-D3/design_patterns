cmake_minimum_required(VERSION 3.15)

find_package(observer_lib)

project(observer_pattern)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        observer_lib
)
