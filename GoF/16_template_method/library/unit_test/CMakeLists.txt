enable_testing()

find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    template_method_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PRIVATE
        ${PROJECT_NAME}
        GTest::gtest_main
        GTest::gmock
)

# CTest.
add_test(
    NAME 
        ${PROJECT_NAME}_ut
    COMMAND 
        ${PROJECT_NAME}_ut
)
