cmake_minimum_required(VERSION 3.15)

project(state_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(
    ${PROJECT_NAME}
    source/context.cpp
    source/state_concrete.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# UT.
add_subdirectory(unit_test)

# Install.
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}
    DESTINATION
        lib/
)
install(
    FILES
        include/13_state/context.hpp
        include/13_state/state_interface.hpp
        include/13_state/state_concrete.hpp
    DESTINATION
        include/13_state/
)

# Pack.
install(
    EXPORT
        ${PROJECT_NAME}
    FILE
        ${PROJECT_NAME}.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}
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
        lib/cmake/${PROJECT_NAME}
)