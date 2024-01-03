set(src
Animation.cpp 
Event.cpp
Game.cpp
main.cpp
MainChar.cpp
SAT.cpp
Texture.cpp)

add_executable(Platformer ${src})

find_package(Qt6 ${minQt6Version} REQUIRED COMPONENTS Core)

target_include_directories(Platformer PRIVATE ../thirdParty/)

target_link_libraries(Platformer PRIVATE SDL3 SDL3_image GUI Qt::Core)

if(NOT BUILD_DIST)
target_precompile_headers(Platformer PRIVATE PCH.hpp)
endif()

add_subdirectory(GUI/)