cmake_minimum_required(VERSION 3.15)

project(double_buffer_pattern)

add_executable(
    ${PROJECT_NAME}
        client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        double_buffer_lib
)