cmake_minimum_required(VERSION 3.15)

project(bytecode_lib)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET 
            ${PROJECT_NAME}_headers 
        TYPE HEADERS 
        BASE_DIRS 
            ./include
        FILES 
            include/03_bytecode/bytecode.hpp
    PRIVATE
        source/bytecode.cpp
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