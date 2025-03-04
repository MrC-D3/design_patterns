find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    iterator_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PRIVATE
        ${PROJECT_NAME}
        gtest
        pthread
)