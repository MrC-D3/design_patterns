find_package(GTest REQUIRED)

add_executable(
    ${PROJECT_NAME}_ut
    state_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PUBLIC
        ${PROJECT_NAME}
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        pthread
)
