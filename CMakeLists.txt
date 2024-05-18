cmake_minimum_required(VERSION 3.0.0)
project(rl_experiment VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(rl_experiment stateValueTable.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(tests)
