find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    command_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PRIVATE
        GTest::gtest_main
        GTest::gmock
        ${PROJECT_NAME}
)

add_test(
    NAME
        ${PROJECT_NAME}_ut
    COMMAND
        ${PROJECT_NAME}_ut --gtest_output=xml:${CMAKE_BINARY_DIR}/gtest_result.xml
)

set_tests_properties(
    ${PROJECT_NAME}_ut
    PROPERTIES
        LABELS
            unit_test
)