cmake_minimum_required(VERSION 3.15)

project(template_method_lib)

add_library(
    ${PROJECT_NAME}
    source/abstract_class.cpp
    source/concrete_class.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)

add_subdirectory(unit_test)

# Install.
install(
    FILES
        include/16_template_method/abstract_class.hpp
        include/16_template_method/concrete_class.hpp
    DESTINATION
        include/16_template_method/
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
        lib/cmake/${PROJECT_NAME}
)
install(
    FILES
        ${CMAKE_CURRENT_BIN_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}/
)