cmake_minimum_required(VERSION 3.15)

project(abstract_factory_lib)

add_library(
    ${PROJECT_NAME}
    source/element_concrete.cpp
    source/concrete_factory.cpp
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
        include/18_abstract_factory/abstract_factory.hpp
        include/18_abstract_factory/concrete_factory.hpp
        include/18_abstract_factory/element_interface.hpp
        include/18_abstract_factory/element_concrete.hpp
    DESTINATION
        include/18_abstract_factory/
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
        lib/cmake/${PROJECT_NAME}/
)
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}/
)