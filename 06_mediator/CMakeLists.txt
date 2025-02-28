cmake_minimum_required(VERSION 3.22)

project(moderator_pattern)

add_subdirectory(library)

# Executable.
add_executable(
    ${PROJECT_NAME}
    client_main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        ${PROJECT_NAME}_lib
)

# No need to say where the headers of the consumed library are, because managed
#  by CMake thanks to how you defined the library: target_include_directories()
#  with the PUBLIC keyword.
