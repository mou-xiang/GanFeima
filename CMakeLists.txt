cmake_minimum_required(VERSION 4.0)

project(GanFeima)

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_executable( gfma
    main.cpp
    fm_finder.cpp
    audiomgr.cpp
)

target_link_libraries(gfma PRIVATE SDL2::SDL2 SDL2_mixer::SDL2_mixer)
