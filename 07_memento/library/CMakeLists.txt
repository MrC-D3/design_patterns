cmake_minimum_required(VERSION 3.22)

project(memento_lib)

add_library(
    ${PROJECT_NAME}
    source/care_taker.cpp
    source/memento_concrete.cpp
    source/originator_concrete.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC # Not PRIVATE
        include/
)

install(
    TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
)
