cmake_minimum_required(VERSION 3.22)

project(flyweight_pattern)

# Library.
add_library(
    ${PROJECT_NAME}_lib
    source/flyweight_factory.cpp
    source/flyweight_shared.cpp
    source/flyweight_unshared.cpp
)

target_include_directories(
    ${PROJECT_NAME}_lib
    PUBLIC
        include/
)

# Executable.
add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        ${PROJECT_NAME}_lib
)
