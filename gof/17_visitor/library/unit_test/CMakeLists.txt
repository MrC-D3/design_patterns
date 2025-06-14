enable_testing()

find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    visitor_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PRIVATE
        ${PROJECT_NAME}
        GTest::gtest_main
        GTest::gmock
)

add_test(
    NAME
        ${PROJECT_NAME}_ut
    COMMAND
        ${PROJECT_NAME}_ut 
)

set_tests_properties(
    ${PROJECT_NAME}_ut # Test name
    PROPERTIES 
        LABELS 
            unit_test
)