//
// Created by helko on 04.04.2023.
//
#include <SDL.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>

#include "Window.h"

const GLint Window::WIDTH = 800;
const GLint Window::HEIGHT = 600;
const char *Window::window_name = "Space";


Window::Window()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(window_name,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    GL_context = SDL_GL_CreateContext(window);

    if (GLEW_OK != glewInit())
    {
        throw EXIT_FAILURE;
    }
    glViewport(0, 0, WIDTH, HEIGHT);
}
void Window::update()
{
    SDL_GL_SwapWindow(window);
}

Window::~Window() {
    SDL_GL_DeleteContext(GL_context);

    SDL_DestroyWindow(window);
    SDL_Quit();
}