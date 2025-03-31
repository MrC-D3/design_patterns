add_library(
    ${PROJECT_NAME}_lib
    source/colleague_concrete.cpp
    source/colleague_interface.cpp
    source/mediator_concrete.cpp
)

target_include_directories(
    ${PROJECT_NAME}_lib
    PUBLIC
        include/
)
