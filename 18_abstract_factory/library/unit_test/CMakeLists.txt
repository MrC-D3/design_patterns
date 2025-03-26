add_test(
    NAME
        ${PROJECT_NAME}_ut
    COMMAND
        ${PROJECT_NAME} --gtest_output=xml:${CMAKE_BINARY_DIR}/unit_test/${PROJECT_NAME}_ut.xml
)