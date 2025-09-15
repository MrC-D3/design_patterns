cmake_minimum_required(VERSION 3.15)

project(subclass_sandbox)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        client_main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        subclass_sandbox_lib
)
