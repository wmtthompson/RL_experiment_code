cmake_minimum_required(VERSION 3.14)
project(tests)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git 
    GIT_TAG 33af80a883ddc33d9c0fac0a5b4578301efb18de
)

FetchContent_MakeAvailable(googletest)


add_executable(${PROJECT_NAME} simple_tests.cc)

target_link_libraries(${PROJECT_NAME} GTest::gtest_main rl_experiment)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})