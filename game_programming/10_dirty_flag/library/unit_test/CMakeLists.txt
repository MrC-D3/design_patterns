project(${CMAKE_PROJECT_NAME}_ut)

find_package(GTest)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        dirty_flag_ut.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        GTest::gtest_main
        ${CMAKE_PROJECT_NAME}
)