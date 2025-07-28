find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    abstract_factory_ut.cpp
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
        ${PROJECT_NAME}_ut --gtest_output=xml:${CMAKE_BINARY_DIR}/unit_test/${PROJECT_NAME}_ut.xml
)

set_tests_properties(
    ${PROJECT_NAME}_ut
    PROPERTIES
        LABELS
            unit_test
)