find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    observer_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PRIVATE
        gtest
        gtest_main
        pthread
)