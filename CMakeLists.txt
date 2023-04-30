cmake_minimum_required(VERSION 3.23.2)
project(game)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(GLEW_VERBOSE ON)

list(APPEND CMAKE_PREFIX_PATH "lib/glew-2.2.0")
list(APPEND CMAKE_LIBRARY_PATH "lib/glew-2.2.0/lib/Release/x64")
set(SDL2_PATH lib/sdl-2.26.5/i686-w64-mingw32)

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(game src/main.cpp src/window/Window.cpp src/window/Window.h src/engine/Loop.cpp src/engine/Loop.h src/engine/EventHandler.cpp src/engine/EventHandler.h src/graphic/Render.cpp src/graphic/Render.h src/game/entity/Entity.cpp src/game/entity/Entity.h)


target_link_libraries(game
        ${SDL2_LIBRARY}
        GLEW::GLEW
        OpenGL::GL)