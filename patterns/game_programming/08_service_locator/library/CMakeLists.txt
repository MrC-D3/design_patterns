cmake_minimum_required(VERSION 3.15)

project(service_locator_lib)

add_library(${PROJECT_NAME})

# Source.
target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET
            ${PROJECT_NAME}_headers
        TYPE HEADERS
        BASE_DIRS
            ./include/
        FILES
            ./include/08_service_locator/service_locator.hpp
    PRIVATE
        source/service_locator.cpp
)

# UT.
add_subdirectory(unit_test)

# Install.
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}_export
    FILE_SET
        ${PROJECT_NAME}_headers
)
