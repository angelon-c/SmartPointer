cmake_minimum_required(VERSION 3.26)
project(ejemplopunteros)

set(CMAKE_CXX_STANDARD 17)

add_executable(ejemplopunteros main.cpp
        my_shared_ptr.cpp
        my_shared_ptr.h)
