cmake_minimum_required(VERSION 3.15)

project(template_method_lib)

add_library(
    ${PROJECT_NAME}
    source/abstract_class.cpp
    source/concrete_class.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)

add_subdirectory(unit_test)

# Install.


# Pack.