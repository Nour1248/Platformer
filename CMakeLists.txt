cmake_minimum_required(VERSION 3.16)
project(Platformer 
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS 0)#disable compiler specific extentions

option(BUILD_DIST "Build for distribution" OFF)

if(NOT BUILD_DIST)
    set(CMAKE_CXX_FLAGS "-Wall -Werror")
    set(CMAKE_EXPORT_COMPILE_COMMANDS 1)#for clangd
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src/)