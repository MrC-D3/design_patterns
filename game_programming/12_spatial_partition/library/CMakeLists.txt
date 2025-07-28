cmake_minimum_required(VERSION 3.15)

project(spatial_partition_lib)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET
            ${PROJECT_NAME}_headers
        TYPE HEADERS
        BASE_DIRS
            ./include/
        FILES
            ./include/12_spatial_partition/spatial_partition.hpp
    PRIVATE
        source/spatial_partition.cpp
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
