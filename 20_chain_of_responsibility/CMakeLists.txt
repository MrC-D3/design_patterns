cmake_minimum_required(VERSION 3.15)

project(chain_of_responsibility_pattern)

find_package(chain_of_responsibility_lib)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        chain_of_responsibility_lib
)