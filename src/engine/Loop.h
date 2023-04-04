#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "../Window/Window.h"
#include "EventHandler.h"
#include "../graphic/Render.h"

class Loop {
    private:
        static const int FPS_MAX = 60;
        Window* window;
        EventHandler event_handler;
        Render render;
    public:
        Loop(Window* window);
        void launch();
};


#endif //GAME_LOOP_H
