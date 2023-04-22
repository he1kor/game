#include "EventHandler.h"



EventHandler::EventHandler(Window *window) {
    this->window = window;
}

bool EventHandler::handle()
{
    SDL_Event event;
    bool quit = false;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                return true;
        }
    }
    return false;
}