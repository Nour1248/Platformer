set(src
Animation.cpp 
Event.cpp
Game.cpp
main.cpp
MainChar.cpp
SAT.cpp
Texture.cpp)

include_directories(../thirdParty/)
link_libraries(SDL3 SDL3_image)

add_executable(Platformer ${src})

if(NOT BUILD_DIST)
target_precompile_headers(Platformer PRIVATE PCH.hpp)
endif()
