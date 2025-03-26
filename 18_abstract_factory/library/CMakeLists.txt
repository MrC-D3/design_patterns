cmake_minimum_required(VERSION 3.15)

project(abstract_factory_lib)

add_library(
    ${PROJECT_NAME}
    source/concrete_factory.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERACE:include/>
)

# Test.