cmake_minimum_required(VERSION 2.6)

project(Tp2)

add_subdirectory(Hop)
add_subdirectory(Tennis)

set( CMAKE_IGNORE_PATH C:/cygwin64/bin)
set( CMAKE_IGNORE_PATH C:/cygwin/bin)

set( DCMAKE_BUILD_TYPE Debug)
