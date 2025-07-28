cmake_minimum_required(VERSION 3.15)

project(strategy_pattern)

find_package(strategy_lib)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        strategy_lib
)
