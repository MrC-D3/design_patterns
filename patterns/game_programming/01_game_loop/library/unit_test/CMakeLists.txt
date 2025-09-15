find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
        game_loop_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PRIVATE
        ${PROJECT_NAME}
        GTest::gtest_main
        GTest::gmock
)