cmake_minimum_required(VERSION 3.3)
project(ProgettoTimer)


set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "/Users/Edoardo/Qt/5.7/clang_64/lib/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp day.h day.cpp lcdclock.cpp lcdclock.h mainwindow.cpp mainwindow.h observer.h subject.h
        qroundprogressbar.cpp qroundprogressbar.h ui_mainwindow.h Data.cpp Data.h Tempo.cpp Tempo.h)

add_executable(ProgettoTimer ${SOURCE_FILES})

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)



target_link_libraries(ProgettoTimer Qt5::Widgets Qt5::Multimedia)




## Preferenze->run and debug ->cmake->cmake Options ->  -DCMAKE_PREFIX_PATH=/Users/Edoardo/Qt/5.7/clang_64/lib/cmak
## al posto di set(CMAKE_PREFIX_PATH "/Users/Edoardo/Qt/5.7/clang_64/lib/cmake")