cmake_minimum_required(VERSION 3.9)
project(Struct)

set(CMAKE_CXX_STANDARD 11)

add_executable(Struct main.cpp List.h memory.h memory.cpp List.cpp Dictionary.h Compare.h Compare.cpp)