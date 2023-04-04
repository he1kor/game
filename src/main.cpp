#include "window/Window.h"
#include "engine/Loop.h"

int main(int argc, char *argv[])
{
    Window window;
    Loop loop(&window);
    loop.launch();
    return 0;
}
