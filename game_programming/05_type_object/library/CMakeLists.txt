cmake_minimum_required(VERSION 3.15)

project(type_object_lib)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET
            ${PROJECT_NAME}_headers
        TYPE HEADERS
        BASE_DIRS
            ./include
        FILES
            include/05_type_object/type_object.hpp
    PRIVATE
        source/type_object.cpp
)

# UT.
add_subdirectory(unit_test)

# Install (in default destination).
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}_export
    FILE_SET
        ${PROJECT_NAME}_headers
)