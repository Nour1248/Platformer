find_package(Qt6 ${minQt6Version} REQUIRED COMPONENTS Core Widgets Gui)

set(GUISRC window.cpp)
add_library(GUI STATIC ${GUISRC})

if(NOT BUILD_DIST)
target_precompile_headers(GUI PRIVATE PCH.hpp)
endif()

target_link_libraries(GUI PRIVATE Qt::Core Qt::Gui Qt::Widgets)