find_package(GTest)

add_executable(
    ${PROJECT_NAME}_ut
    state_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_ut
    PRIVATE
        ${PROJECT_NAME}
        gtest
        gtest_main
        pthread
)
