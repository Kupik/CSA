cmake_minimum_required(VERSION 3.27)
project(CC C)

set(CMAKE_C_STANDARD 11)

add_library(CC STATIC library.c
        cmake-build-debug/Program2.c
        P2.c
        P3.c
        P4.c
        P5.c
        Practica1.c
        Practica2.c)
