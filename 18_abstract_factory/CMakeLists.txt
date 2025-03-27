cmake_minimum_required(VERSION 3.15)

project(abstract_factory_pattern)

find_package(abstract_factory_lib)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        abstract_factory_lib
)
