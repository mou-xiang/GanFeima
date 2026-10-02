cmake_minimum_required(VERSION 4.0)

project(GanFeima)

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable( gfma
    cli/main.cpp
    core/fm_finder.cpp
    core/audiomgr.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui
    mainwindow.h
)

target_link_libraries(gfma PRIVATE SDL2::SDL2 SDL2_mixer::SDL2_mixer)
