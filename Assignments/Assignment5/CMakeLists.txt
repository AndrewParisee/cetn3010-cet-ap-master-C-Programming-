cmake_minimum_required(VERSION 3.13)
project(Assignment5 C)

set(CMAKE_C_STANDARD 99)

configure_file(maze.txt maze.txt COPYONLY)

add_executable(Assignment5 main.c)