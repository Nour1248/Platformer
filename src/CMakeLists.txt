set(src
Animation.cpp 
Event.cpp
Game.cpp
main.cpp
MainChar.cpp
SAT.cpp
Texture.cpp)

add_executable(Platformer ${src})

target_include_directories(Platformer PRIVATE ../thirdParty/)
target_link_libraries(Platformer SDL3 SDL3_image GUI)

if(NOT BUILD_DIST)
target_precompile_headers(Platformer PRIVATE PCH.hpp)
endif()

add_subdirectory(GUI/)