cmake_minimum_required(VERSION 3.22)

project(iterator_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(
    ${PROJECT_NAME}
    INTERFACE
)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

add_subdirectory(unit_tests)

# Install and Pack.
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}.cmake
    DESTINATION 
        lib/
)

install(
    EXPORT
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
        include/iterator_interface.hpp
        include/aggregate_interface.hpp
        include/iterator.hpp
        include/aggregate.hpp
    DESTINATION
        include/${PROJECT_NAME}/
)

install(
    FILES
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}
)
