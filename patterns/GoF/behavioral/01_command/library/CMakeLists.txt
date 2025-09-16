cmake_minimum_required(VERSION 3.15)

project(command_lib)

add_library(
    ${PROJECT_NAME}
    source/command_concrete.cpp
    source/invoker.cpp
    source/receiver.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)

# Test.
enable_testing()
add_subdirectory(unit_test)

# Install.
install(
    FILES
        include/01_command/command_concrete.hpp
        include/01_command/command_interface.hpp
        include/01_command/invoker.hpp
        include/01_command/receiver.hpp
    DESTINATION
        include/01_command/
)
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}
    DESTINATION
        lib/
)

# Pack.
include(CMakePackageConfigHelpers)
configure_package_config_file(
    Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION
        lib/cmake/${PROJECT_NAME}
)
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}
)
install(
    EXPORT
        ${PROJECT_NAME}
    FILE
        ${PROJECT_NAME}.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}
)