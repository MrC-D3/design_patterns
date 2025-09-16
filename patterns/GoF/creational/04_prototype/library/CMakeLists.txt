cmake_minimum_required(VERSION 3.22)

project(prototype_shared)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(sub_library)

add_library(
    ${PROJECT_NAME} SHARED
    source/prototype_client.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        include/
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        prototype_static
)

install(
    TARGETS
        ${PROJECT_NAME}
    DESTINATION
        lib/
)

install(
    FILES
        include/04_prototype/prototype_client.hpp
    DESTINATION
        include/04_prototype/
)
