cmake_minimum_required(VERSION 3.15)
project(N_Queens)

set(CMAKE_CXX_STANDARD 14)

add_executable(N_Queens main.cpp Queens.h Queens.cpp)