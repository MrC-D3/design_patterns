cmake_minimum_required(VERSION 3.15)

project(update_method_lib)

add_library(${PROJECT_NAME})
#add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# So you don't need to distinguish between BUILD_ and INSTALL_ interface.
target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET 
            ${PROJECT_NAME}_headers 
        TYPE HEADERS 
        BASE_DIRS 
            ./include
        FILES 
            include/02_update_method/updatable_interface.hpp
            include/02_update_method/updatable_concrete.hpp
    PRIVATE
        source/updatable_concrete.cpp
        source/updatable_interface.cpp
)

# Unit test.
add_subdirectory(unit_test)

# Install.
install(
    TARGETS 
        ${PROJECT_NAME}
    EXPORT 
        ${PROJECT_NAME}_export
    # Install the binary and its headers in one shot.
    FILE_SET 
        ${PROJECT_NAME}_headers
)
#install( 
#    EXPORT 
#        ${PROJECT_NAME}_export 
#    DESTINATION 
#        share/cmake/foo 
#    NAMESPACE foo::
#)
#install( 
#    FILES 
#        ./cmake/fooConf.cmake # include(${CMAKE_CURRENT_LIST_DIR}/fooTargets.cmake)
#    DESTINATION 
#        share/cmake/foo
#)