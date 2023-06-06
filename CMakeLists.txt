cmake_minimum_required(VERSION 3.22.1)
project(Playlist VERSION 0.1 LANGUAGES CXX)

include_directories( include )

add_executable( program
                src/main.cpp
                src/menu.cpp
                src/Song.cpp
                src/Playlist.cpp
                )

set_property(TARGET program PROPERTY CXX_STANDARD 11)
