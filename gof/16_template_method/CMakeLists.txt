cmake_minimum_required(VERSION 3.15)

find_package(template_method_lib)

project(template_method_pattern)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        template_method_lib
)