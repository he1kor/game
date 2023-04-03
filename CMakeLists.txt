cmake_minimum_required(VERSION 3.23.2)
project(game)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH libs/SDL2-2.26.4/x86_64-w64-mingw32)
set(CMAKE_EXE_LINKER_FLAGS "-static")


set(GLEW_VERBOSE ON)
set(GLEW_USE_STATIC_LIBS ON)


list(APPEND CMAKE_PREFIX_PATH "glew")
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(game src/main.cpp)


target_link_libraries(game
        ${SDL2_LIBRARY}
        GLEW::GLEW
        OpenGL::GL)