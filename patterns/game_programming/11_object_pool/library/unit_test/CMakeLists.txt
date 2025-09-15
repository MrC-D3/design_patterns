project(${CMAKE_PROJECT_NAME}_ut)

find_package(GTest)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        object_pool_ut.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_PROJECT_NAME}
        GTest::gtest_main
)
