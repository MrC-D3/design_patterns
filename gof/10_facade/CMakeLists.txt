cmake_minimum_required(VERSION 3.22)

project(facade_pattern)

# Include the exported package or the linker fails for the shared-lib symbols. 
find_package(facade_lib)

add_executable(
    ${PROJECT_NAME}
    client_main.cpp 
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE 
        facade_lib_static
)