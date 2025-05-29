cmake_minimum_required(VERSION 3.15)

project(interpreter_lib)

set(CMAKE_BUILD_TYPE Debug)

add_library(
    ${PROJECT_NAME}
    source/terminal_expression.cpp
    source/nonterminal_expression.cpp
    source/context.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)

# Unit test.
enable_testing()
add_subdirectory(unit_test)

# Install.
install(
    FILES
        include/22_interpreter/abstract_expression.hpp
        include/22_interpreter/terminal_expression.hpp
        include/22_interpreter/nonterminal_expression.hpp
        include/22_interpreter/context.hpp
    DESTINATION
        include/22_interpreter/
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
install(
    EXPORT
        ${PROJECT_NAME}
    FILE
        ${PROJECT_NAME}.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}/
)
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
        lib/cmake/${PROJECT_NAME}/
)