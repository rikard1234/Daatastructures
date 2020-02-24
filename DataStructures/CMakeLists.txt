cmake_minimum_required(VERSION 3.14)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructures main.cpp DynamicArray.cpp DynamicArray.h DList.cpp DList.h NodeDLL.cpp NodeDLL.h BinaryTree.cpp BinaryTree.h Node.cpp Node.h)