cmake_minimum_required(VERSION 3.25)

project(factory_method_pattern)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
    source/creator.cpp
    source/concrete_creator.cpp
    source/concrete_product.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE # No alternatives since you're building an executable.
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
