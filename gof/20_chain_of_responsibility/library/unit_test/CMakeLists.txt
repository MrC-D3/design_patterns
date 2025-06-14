find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    chain_of_responsibility_ut.cpp
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
        # Run the test and produce a low-level report.
        ${PROJECT_NAME}_ut --gtest_output=xml:${CMAKE_BINARY_DIR}/gtest_result.xml
)

set_tests_properties(
    ${PROJECT_NAME}_ut
    PROPERTIES
        LABELS
            unit_test
)