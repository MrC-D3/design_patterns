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
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/> # Like when there was only include/
        $<INSTALL_INTERFACE:include/> # Same location of the installation of the header-s.
)

# Make the target usable by find_package(): create the EXPORT name in install().
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME} # How you wanna call all the target-s package.
    # It'll install it in /usr/local/lib/ even if I delete this last part.
    DESTINATION 
        lib
)

install(
    EXPORT
        ${PROJECT_NAME}
    FILE
        ${PROJECT_NAME}.cmake # The file created directly in DESTINATION?
    # Here DESTINATION is mandatory.
    DESTINATION
        lib/cmake/${PROJECT_NAME}
)