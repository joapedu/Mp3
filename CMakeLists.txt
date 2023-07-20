cmake_minimum_required(VERSION 3.22.1)
project(Playlist VERSION 2.0 LANGUAGES CXX)

include_directories( include )

add_executable( mp3
                src/main.cpp
                src/menu.cpp
                src/musica.cpp
                src/playlist.cpp
                )

set_property(TARGET mp3 PROPERTY CXX_STANDARD 11)
#Adds the -Wall flag to the compiler
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
