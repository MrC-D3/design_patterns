find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    strategy_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PRIVATE
        GTest::gtest_main
        GTest::gmock
        ${PROJECT_NAME}
)