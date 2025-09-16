cmake_minimum_required(VERSION 3.15)

project(chain_of_responsibility_lib)

add_library(
    ${PROJECT_NAME}
    source/handler_interface.cpp
    source/handler_concrete.cpp
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
        include/08_chain_of_responsibility/handler_interface.hpp
        include/08_chain_of_responsibility/handler_concrete.hpp
    DESTINATION
        include/08_chain_of_responsibility/
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
        lib/cmake/${PROJECT_NAME}/
)
install(
    EXPORT
        ${PROJECT_NAME}
    FILE
        ${PROJECT_NAME}.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}/
)
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION
        lib/cmake/${PROJECT_NAME}/
)