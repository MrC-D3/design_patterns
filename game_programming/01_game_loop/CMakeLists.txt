cmake_minimum_required(VERSION 3.15)

project(game_loop_pattern)

add_executable(
    ${PROJECT_NAME}
        client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        game_loop_lib
)
