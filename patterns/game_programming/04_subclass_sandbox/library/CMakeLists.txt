cmake_minimum_required(VERSION 3.15)

project(subclass_sandbox_lib)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET 
            ${PROJECT_NAME}_headers 
        TYPE HEADERS 
        BASE_DIRS 
            ./include
        FILES 
            include/04_subclass_sandbox/subclass_sandbox.hpp
    PRIVATE
        source/subclass_sandbox.cpp
)

# Unit test.
add_subdirectory(unit_test)

# Install.
install(
    TARGETS 
        ${PROJECT_NAME}
    EXPORT 
        ${PROJECT_NAME}_export
    FILE_SET 
        ${PROJECT_NAME}_headers
)