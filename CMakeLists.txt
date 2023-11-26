cmake_minimum_required(VERSION 3.12)
project(Game)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(src/ thirdParty/)
link_libraries(SDL3 SDL3_image)

add_executable(Game ${SOURCES})