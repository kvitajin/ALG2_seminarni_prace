cmake_minimum_required(VERSION 3.8)
project(sem)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp List.cpp List.h)
add_executable(sem ${SOURCE_FILES})