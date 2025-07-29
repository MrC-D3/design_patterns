cmake_minimum_required(VERSION 3.22)

project(observer_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(
    ${PROJECT_NAME}
    source/subject_interface.cpp
    source/observer_interface.cpp
    source/subject.cpp
    source/observer.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)

add_subdirectory(unit_test)

# Install & Pack.
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
        include/05_observer/subject_interface.hpp
        include/05_observer/observer_interface.hpp
        include/05_observer/subject.hpp
        include/05_observer/observer.hpp
    DESTINATION
        include/05_observer/
)

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