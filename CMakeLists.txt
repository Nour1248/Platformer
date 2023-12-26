cmake_minimum_required(VERSION 3.12)
project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS 0)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)#for clangd
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src/)
