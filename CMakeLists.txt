cmake_minimum_required(VERSION 3.31)
project(raylib_game)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/raylib)

add_executable(raylib_game
        src/Pinball.cpp
        src/Application.cpp
        src/Application.h
        src/Systems/Time.cpp
        src/Systems/Time.h
)

target_link_libraries(raylib_game raylib)
