#ifndef GAME_EVENTHANDLER_H
#define GAME_EVENTHANDLER_H

#include "SDL.h"
#include "../window/Window.h"

class EventHandler {
    public:
        EventHandler(Window* window);
        bool handle();
    private:
        Window *window;
};



#endif //GAME_EVENTHANDLER_H
