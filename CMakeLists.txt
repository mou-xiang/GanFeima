cmake_minimum_required(VERSION 4.0)

project(GanFeima LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(SDL2_DIR "C:/deps/SDL2/cmake")
    set(SDL2_mixer_DIR "C:/deps/SDL2_mixer/cmake")
endif()

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)

add_executable(gfma
    main.cpp
    fm_finder.cpp
    audiomgr.cpp
)

target_link_libraries(gfma PRIVATE
    $<$<PLATFORM_ID:Windows>:SDL2::SDL2main>
    SDL2::SDL2
    SDL2_mixer::SDL2_mixer
)

target_compile_options(gfma PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/utf-8>
)

if(WIN32)
    # The sources include <SDL2/SDL.h>, while SDL's package target exposes
    # C:/deps/SDL2/include for the alternative <SDL.h> spelling.
    set(SDL2_COMPAT_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/include")
    file(COPY "C:/deps/SDL2/include/"
        DESTINATION "${SDL2_COMPAT_INCLUDE_DIR}/SDL2"
    )
    target_include_directories(gfma PRIVATE "${SDL2_COMPAT_INCLUDE_DIR}")

    add_custom_command(TARGET gfma POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL2::SDL2>
            $<TARGET_FILE:SDL2_mixer::SDL2_mixer>
            $<TARGET_FILE_DIR:gfma>
        COMMENT "Copying SDL2 runtime DLLs"
        COMMAND_EXPAND_LISTS
    )
endif()
