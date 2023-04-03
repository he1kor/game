#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL.h>

const GLint WIDTH = 800, HEIGHT = 600;

bool quit = false;

void processKey(SDL_Keysym keysym)
{
    switch (keysym.sym)
    {
        case SDLK_UP:
            quit = true;
    }
}


int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_Window *window = SDL_CreateWindow("Minecraft", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);


    SDL_GLContext context = SDL_GL_CreateContext(window);

    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW";

        return EXIT_FAILURE;
    }
    glViewport(0, 0, WIDTH, HEIGHT);

    SDL_Event windowEvent;

    while (true)
    {
        while (SDL_PollEvent(&windowEvent))
        {
            switch (windowEvent.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    processKey(windowEvent.key.keysym);
                    break;
            }
            if (quit) goto ExitProgram;
        }
        SDL_Delay(20);

        glClearColor(1.12f, 1.1f, 1.12f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }
    ExitProgram:

    SDL_GL_DeleteContext(context);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}
