cmake_minimum_required(VERSION 3.15)

project(strategy_lib)

# Add compile options for the whole CMake project, so for every target.
add_compile_options(
    -Werror            # Treat warnings as errors
    -Wall              # Enable all common warnings
    -Wextra            # Enable extra warnings (optional)
)

add_library(
    ${PROJECT_NAME}
    source/context.cpp
    source/strategy_concrete.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

add_subdirectory(unit_test)

# Install.
install(
    FILES
        include/15_strategy/context.hpp
        include/15_strategy/strategy_concrete.hpp
        include/15_strategy/strategy_interface.hpp
    DESTINATION
        include/15_strategy/
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
        lib/cmake/${PROJECT_NAME}
)
include(CMakePackageConfigHelpers)
configure_package_config_file(
    Config.cmake.in
    ${CMAKE_CURRENT_BIN_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION
        lib/cmake/${PROJECT_NAME}/
)
install(
    FILES
        ${CMAKE_CURRENT_BIN_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}/
)