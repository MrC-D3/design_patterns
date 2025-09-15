cmake_minimum_required(VERSION 3.15)

project(dirty_flag_lib)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET
            ${PROJECT_NAME}_headers
        TYPE HEADERS
        BASE_DIRS
            ./include/
        FILES
            include/10_dirty_flag/dirty_flag.hpp
    PRIVATE
        source/dirty_flag.cpp
)

add_subdirectory(unit_test)

install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}_export
    FILE_SET
        ${PROJECT_NAME}_headers
)