#include <iostream>
#include "Render.h"
#include "../window/Window.h"

Render::Render(Window *window)
{
    this->window = window;
};

void Render::renderFrame() {
    auto color = float(SDL_GetPerformanceCounter() % 2);
    glClearColor(color, color, color, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    window->update();
}
