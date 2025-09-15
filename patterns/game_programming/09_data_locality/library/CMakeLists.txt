cmake_minimum_required(VERSION 3.15)

project(data_locality_lib)

set(CMAKE_BUILD_TYPE Debug)
# Profile always as the programm will run, so optimization ON.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET
            ${PROJECT_NAME}_headers
        TYPE HEADERS
        BASE_DIRS
            ./include/
        FILES
            ./include/09_data_locality/data_locality.hpp
    PRIVATE
        source/data_locality.cpp
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
