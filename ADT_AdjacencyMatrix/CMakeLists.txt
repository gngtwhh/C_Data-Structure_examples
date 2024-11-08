cmake_minimum_required(VERSION 3.27)
project(ADT_AdjacencyMatrix C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ADT_AdjacencyMatrix
        AdjacentMatrix.c
        AdjacentMatrix.h
        test.c
)
