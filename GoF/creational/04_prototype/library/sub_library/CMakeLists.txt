project(prototype_static)

add_library(
    ${PROJECT_NAME}
    source/PrototypeConcrete.cpp
)

# PIC on, to make this static library included in a shared library.
set_target_properties(
    ${PROJECT_NAME} 
    PROPERTIES
        POSITION_INDEPENDENT_CODE ON
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        include/
)

# Installations not needed when building the shared library, 
#  but when including it in building another target. 
install(
    TARGETS
        ${PROJECT_NAME}
    DESTINATION
        lib/
)

install(
    FILES
        include/04_prototype/PrototypeInterface.hpp
    DESTINATION
        include/04_prototype/
)
