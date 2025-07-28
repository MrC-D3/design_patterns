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

# Install and ...
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
        include/11_iterator/iterator_interface.hpp
        include/11_iterator/aggregate_interface.hpp
        include/11_iterator/iterator.hpp
        include/11_iterator/aggregate.hpp
    DESTINATION
        include/11_iterator/
)

# ... Pack (even if unuseful for a header-only library).
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
        lib/cmake/${PROJECT_NAME}
)
