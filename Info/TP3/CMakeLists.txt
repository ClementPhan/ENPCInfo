cmake_minimum_required(VERSION 2.6)
project(Tp3)

add_subdirectory(Mastermind)
add_subdirectory(MastermindGraphique)

set( CMAKE_IGNORE_PATH C:/cygwin64/bin)
set( CMAKE_IGNORE_PATH C:/cygwin/bin)

set( DCMAKE_BUILD_TYPE Debug )
