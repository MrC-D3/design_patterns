cmake_minimum_required(VERSION 3.22)

project(memento_lib)

add_library(
    ${PROJECT_NAME}
    source/memento_concrete.cpp
    source/originator_concrete.cpp
    source/care_taker.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE # OK, since the headers are installed.
        include/
)

# Go in the default prefix /usr/local/, under lib/.
install(
    TARGETS 
        ${PROJECT_NAME}
    DESTINATION 
    # Putting in lib/<subDir> forces Client to know what <subDir>.
        lib/
)

# Go in the default /usr/local/ include/11_memento/.
install(
    FILES
        include/11_memento/originator_interface.hpp
        include/11_memento/originator_concrete.hpp
        include/11_memento/memento_interface.hpp
        include/11_memento/memento_concrete.hpp
        include/11_memento/care_taker.hpp
    DESTINATION
        include/11_memento/
)
