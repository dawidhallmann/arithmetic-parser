cmake_minimum_required(VERSION 3.17)
project(arithmetic_parser)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(arithmetic_parser
        basic.h
        main.cpp
        validation.h)
