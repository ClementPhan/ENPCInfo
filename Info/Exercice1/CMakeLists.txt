cmake_minimum_required(VERSION 2.6)
list(APPEND CMAKE_MODULE_PATH $ENV{IMAGINEPP_ROOT}/CMake) #For old Imagine++
find_package(Imagine REQUIRED)


project(exercice1)

add_executable(exercice1 exercice1.cpp)

ImagineUseModules(exercice1 Graphics)

set( CMAKE_IGNORE_PATH C:/cygwin64/bin )
set( CMAKE_IGNORE_PATH C:/cygwin/bin )


set( DCMAKE_BUILD_TYPE Debug)
