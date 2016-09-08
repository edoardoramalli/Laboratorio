cmake_minimum_required(VERSION 3.3)

add_subdirectory(lib/googletest)
set(gtest_SOURCE_DIR, lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp TempoTest.cpp DataTest.cpp)
add_executable(runTests ${TEST_SOURCE_FILES})
target_link_libraries(runTests gtest gtest_main core)