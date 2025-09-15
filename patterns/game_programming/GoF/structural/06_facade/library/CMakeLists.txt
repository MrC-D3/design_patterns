cmake_minimum_required(VERSION 3.22)

project(facade_lib)

add_subdirectory(sub_library)

add_library(
    ${PROJECT_NAME}_static
    source/facade.cpp
)

target_include_directories(
    ${PROJECT_NAME}_static
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(
    ${PROJECT_NAME}_static 
    PRIVATE
        ${PROJECT_NAME}_shared
)

# Installation, but not enough in this case because depending on shared library.
install(
    TARGETS 
    # Target _static requires _shared, so both should be exported.
    #  And when exported, paths should distinguish between BUILD_ and INSTALL.
        ${PROJECT_NAME}_static ${PROJECT_NAME}_shared
    EXPORT 
        ${PROJECT_NAME}
    DESTINATION 
        lib
)
install(
    FILES 
        include/06_facade/facade.hpp 
    DESTINATION 
        include/06_facade
)

# Packaging.
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
