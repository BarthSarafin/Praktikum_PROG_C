cmake_minimum_required(VERSION 2.8.4)
project(Praktikum)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/Lab04_routing_table/routingTable.c)
add_executable(Praktikum ${SOURCE_FILES}  src/Lab04_routing_table/routingTable.c src/Lab04_routing_table/routingTable.h)