cmake_minimum_required(VERSION 3.25)

project(factory_method_pattern)

# PROJECT_NAME refers to the last call to project(): ideally the current file.
# Instead, CMAKE_PROJECT_NAME refers to the top level project.
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
