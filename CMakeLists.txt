cmake_minimum_required(VERSION 3.26)
project(Interpreter_lisp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Interpreter_lisp main.cpp
        tree.h
        atom.h
        tree.cpp
        atom.cpp
        const.cpp
        parser.h
        parser.cpp
        interpretator.h
        interpretator.cpp)
