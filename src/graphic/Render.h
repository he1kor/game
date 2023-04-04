#ifndef GAME_RENDER_H
#define GAME_RENDER_H
#define GLEW_STATIC
#include <gl/glew.h>
#include "../window/Window.h"

class Render {

    public:
        Render(Window *window);
        void renderFrame();
    private:
        Window *window;
};


#endif //GAME_RENDER_H
