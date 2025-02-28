add_library(
    ${PROJECT_NAME}_shared
    SHARED
        source/system.cpp
)

target_include_directories(
    ${PROJECT_NAME}_shared
    PRIVATE
        include/
)
