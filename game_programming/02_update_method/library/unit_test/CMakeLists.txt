find_package(GTest)

# CMAKE_PROJECT_NAME refers to the top level call of project().
project(${CMAKE_PROJECT_NAME}_ut)

add_executable(
    # PROJECT_NAME refers to the last call of project().
    ${PROJECT_NAME}
)

target_sources(${PROJECT_NAME}
    PRIVATE
        update_method_ut.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        ${CMAKE_PROJECT_NAME}
        GTest::gtest_main
        GTest::gmock
)