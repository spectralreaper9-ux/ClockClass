cmake_minimum_required(VERSION 4.4)
project(ClockClassOverload)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClockClassOverload main.cpp
        Clock.cpp
        Clock.h)
