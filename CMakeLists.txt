cmake_minimum_required(VERSION 3.27)
project(lr1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lr1 main.cpp
        UnqPtr.h
        ShrdPtr.h
        UnqPtrTests.h
        ShrdPtrTests.h
        DynamicArray.h
        DynamicArrayTests.h
)
