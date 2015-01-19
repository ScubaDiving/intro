cmake_minimum_required(VERSION 2.8.4)
project(Ex3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Ex3.2.c)
add_executable(Ex3.2 ${SOURCE_FILES})
add_executable(Ex3.3 Ex3.3.c)
add_executable(Ex3.1 Ex3.1.c)