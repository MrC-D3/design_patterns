add_library(
    ${PROJECT_NAME}_shared
    SHARED
        source/system.cpp
)

target_include_directories(
    ${PROJECT_NAME}_shared
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
