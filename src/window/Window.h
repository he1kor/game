//
// Created by helko on 04.04.2023.
//
#define GLEW_STATIC
#include <gl/glew.h>
#include <SDL.h>

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H


class Window {
    private:
        SDL_Window *window;
        SDL_GLContext GL_context;
        SDL_Event event;
    public:
        Window();
        ~Window();
        static const GLint WIDTH;
        static const GLint HEIGHT;
        static const char *window_name;
        void update();
};


#endif //GAME_WINDOW_H
