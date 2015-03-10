cmake_minimum_required(VERSION 2.8.4)
project(Praktikum1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/ggT.c)
add_executable(Praktikum1 ${SOURCE_FILES})