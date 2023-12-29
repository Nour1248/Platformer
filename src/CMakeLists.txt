cmake_minimum_required(VERSION 3.12)

set(src
Animation.cpp 
Eventable.cpp
Game.cpp
main.cpp
MainChar.cpp
Texture.cpp)

include_directories( ../thirdParty/)
link_libraries(SDL3 SDL3_image)

add_executable(Platformer ${src})
