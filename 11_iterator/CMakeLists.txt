cmake_minimum_required(VERSION 3.22)

# Even if unuseful for a header-only library.
find_package(iterator_lib)

set(CMAKE_CXX_STANDARD 17)

project(iterator_pattern)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
)