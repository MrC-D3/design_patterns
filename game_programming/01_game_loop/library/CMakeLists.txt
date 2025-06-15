cmake_minimum_required(VERSION 3.15)

project(game_loop_lib)

add_library(
    ${PROJECT_NAME}
        source/game_loop.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)

# Unit Test.
add_subdirectory(unit_test)

# Install.
install(
    TARGETS
        ${PROJECT_NAME}
    DESTINATION
        lib/
)
install(
    FILES
        include/01_game_loop/game_loop.hpp
    DESTINATION
        include/01_game_loop/
)
