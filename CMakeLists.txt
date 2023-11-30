cmake_minimum_required(VERSION 3.12)
project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)#for clangd

file(GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(src/ thirdParty/)
link_libraries(SDL3 SDL3_image)

add_executable(Game ${SOURCES})