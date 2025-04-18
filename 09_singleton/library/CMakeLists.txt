cmake_minimum_required(VERSION 3.22)

project(singleton_library)

add_library(
    ${PROJECT_NAME}
    source/singleton.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    # If not PRIVATE and used in another CMake project, use relative path.
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # Like when there was only include/
        $<INSTALL_INTERFACE:include> # Same location of the installation of the header-s.
)

install(
    FILES 
        include/09_singleton/singleton.hpp
    DESTINATION 
        include/09_singleton
)

# Allow the use of find_package(): create the EXPORT name in install().
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME} # How you wanna call the package of the target-s.
    # It'll install it in /usr/local/lib/ even if I delete this last part.
    DESTINATION 
        lib/09_singleton
)

# Allow the use of find_package(): create the first .cmake files and install it.
install(
    EXPORT
        ${PROJECT_NAME}
    FILE
        ${PROJECT_NAME}.cmake # The file created directly in DESTINATION?
    # Here DESTINATION is mandatory.
    DESTINATION
        lib/cmake/${PROJECT_NAME}
)

# Make target usable by find_package(): create the second .cmake files and...
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in             # Input file.
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake # Output file.
    # The generated file needs to know where it'll be installed.
    INSTALL_DESTINATION
        lib/cmake/${PROJECT_NAME}
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION 
        lib/cmake/${PROJECT_NAME}
) 
