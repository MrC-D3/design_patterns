cmake_minimum_required(VERSION 3.15)

project(object_pool_lib)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET
            ${PROJECT_NAME}_headers
        TYPE HEADERS
        BASE_DIRS
            ./include/
        FILES
            ./include/11_object_pool/object_pool.hpp
    PRIVATE
        source/object_pool.cpp
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
