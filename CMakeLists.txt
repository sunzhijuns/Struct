cmake_minimum_required(VERSION 3.9)
project(Struct)

set(CMAKE_CXX_STANDARD 11)

SET(SRC_LIST
        main.cpp
        List.cpp
        memory.cpp
        Compare.cpp
        String.cpp
        Stack.cpp
        Queue.cpp
        BinaryTree.cpp
        MaxHeap.cpp)

message(status "this is binary dir " ${STRUCT_BINARY_DIR})
message(status "this is binary dir " ${PROJECT_BINARY_DIR})
message(status "this is source dir" ${STRUCT_SOURCE_DIR})
message(status "this is source dir" ${PROJECT_SOURCE_DIR})

add_executable(Struct ${SRC_LIST})