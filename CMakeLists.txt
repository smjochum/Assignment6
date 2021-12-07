cmake_minimum_required(VERSION 3.20)
project(Assignment6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment6
        Fruit.cpp
        Fruit.h OnlineSuperMarket.cpp OnlineSuperMarket.h main.cpp)
