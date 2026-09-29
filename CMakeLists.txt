cmake_minimum_required(VERSION 4.3)
project(PigDice)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PigDice
        DIE.h
        PigDice.cpp
        DIE.cpp)
