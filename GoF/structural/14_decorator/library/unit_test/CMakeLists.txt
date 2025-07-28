find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    decorator_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PRIVATE
        ${PROJECT_NAME}
        GTest::gtest_main
        GTest::gmock
        pthread
)
