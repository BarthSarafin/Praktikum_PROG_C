cmake_minimum_required(VERSION 2.8.4)
project(Praktikum)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/Lab03_generic_function/genericPrinter.c)
add_executable(Praktikum ${SOURCE_FILES} src/Lab03_generic_function/genericPrinter.h src/Lab03_generic_function/genericPrinter.c)