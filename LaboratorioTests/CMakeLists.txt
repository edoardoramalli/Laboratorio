cmake_minimum_required(VERSION 3.3)
project(Laboratorio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES  Tempo.cpp Tempo.h Data.cpp Data.h  cifraIndex.cpp   isLeapYear.h dayWeek.h dayWeek.cpp)
add_executable(eseguibile main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(eseguibile core)