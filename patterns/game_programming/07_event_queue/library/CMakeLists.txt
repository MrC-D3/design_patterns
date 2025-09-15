cmake_minimum_required(VERSION 3.15)

project(event_queue_lib)

set(CMAKE_BUILD_TYPE Debug)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET
            ${PROJECT_NAME}_headers
        TYPE HEADERS
        BASE_DIRS
            ./include/
        FILES
            ./include/07_event_queue/event_queue.hpp
    PRIVATE
        source/event_queue.cpp
)

# UT.
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
