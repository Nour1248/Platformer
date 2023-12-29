cmake_minimum_required(VERSION 3.12)
project(Platformer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS 0)#disable compiler specific extentions

if(NOT DEFINED BUILD_DIST)
    set(CMAKE_EXPORT_COMPILE_COMMANDS 1)#for clangd
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src/)