cmake_minimum_required(VERSION 3.6)
project(nodeInC_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Header.cpp
    Header.h)

include_directories(.)

add_executable(nodeInC_ ${SOURCE_FILES})