cmake_minimum_required(VERSION 3.22)

project(memento_lib)

add_library(
    ${PROJECT_NAME}
    source/care_taker.cpp
    source/memento_concrete.cpp
    source/originator_concrete.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE # OK, since the headers are installed.
        include/
)

# Go in the default /usr/local/ lib/.
install(
    TARGETS 
        ${PROJECT_NAME}
    DESTINATION lib/
)

# Go in the default /usr/local/ include/07_memento/.
install(
    FILES
        include/07_memento/originator_concrete.hpp
        include/07_memento/care_taker.hpp
        include/07_memento/originator.hpp
        include/07_memento/memento_interface.hpp
        include/07_memento/memento_concrete.hpp
    DESTINATION
        include/07_memento/
)
