cmake_minimum_required(VERSION 3.12)

file(GLOB_RECURSE SOURCES "*.cpp")
include_directories( ../thirdParty/)
link_libraries(SDL3 SDL3_image)

add_executable(Game ${SOURCES})
