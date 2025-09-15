cmake_minimum_required(VERSION 3.15)

project(event_queue_pattern)

add_executable(${PROJECT_NAME})

# Files.
target_sources(${PROJECT_NAME}
    PRIVATE
        client_main.cpp
)

# Libraries.
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        event_queue_lib
)
