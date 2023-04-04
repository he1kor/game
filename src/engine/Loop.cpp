#include "Loop.h"
#include "EventHandler.h"
#include <cmath>
#include <iostream>

Loop::Loop(Window* window) : event_handler(window), render(window)
{
    this->window = window;
}

void Loop::launch()
{
    const float BASIC_DELAY = 1.0f / FPS_MAX;
    bool quit;
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    while (true)
    {
        Uint64 start_counter = SDL_GetPerformanceCounter();
        quit = event_handler.handle();
        render.renderFrame();
        Uint64 end_counter = SDL_GetPerformanceCounter();
        float elapsed_seconds = (end_counter - start_counter) / (float)SDL_GetPerformanceFrequency();
        SDL_Delay(int (1000 * (std::max(0.0f,(BASIC_DELAY - elapsed_seconds)))));
        if (quit) break;
    }
}