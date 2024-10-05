cmake_minimum_required(VERSION 3.27)
project(CppCompiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(CppCompiler main.cpp
        common.h
        chunk.h
        chunk.h
        chunk.cpp
        debug.h
        debug.cpp
        value.h
        value.cpp
        scanner.h
        scanner.cpp
)
