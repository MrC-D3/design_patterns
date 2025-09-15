cmake_minimum_required(VERSION 3.15)

project(dirty_flag_pattern)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        client_main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        dirty_flag_lib
)
