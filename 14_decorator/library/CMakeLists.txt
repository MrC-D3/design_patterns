cmake_minimum_required(VERSION 3.15)

project(decorator_lib)

add_library(
    ${PROJECT_NAME}
    source/component_concrete.cpp
    source/decorator_concrete.cpp
    source/decorator_interface.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)

# Unit Test.
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
        include/14_decorator/component_concrete.hpp
        include/14_decorator/component_interface.hpp
        include/14_decorator/decorator_concrete.hpp
        include/14_decorator/decorator_interface.hpp
    DESTINATION
        include/14_decorator/
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
        lib/cmake/${PROJECT_NAME}
)
install(
    FILES
        ${CMAKE_CURRENT_BIN_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}/
)