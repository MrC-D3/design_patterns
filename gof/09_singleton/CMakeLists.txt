cmake_minimum_required(VERSION 3.22)

project(singleton_pattern)

find_package(singleton_library)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        pthread
        singleton_library
)