cmake_minimum_required(VERSION 2.8.4)
project(Algo_PA1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp tic.cpp parse.cpp split.cpp graph.cpp)
add_executable(Algo_PA1 ${SOURCE_FILES})