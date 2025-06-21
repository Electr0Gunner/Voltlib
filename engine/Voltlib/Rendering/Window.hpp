#pragma once

#include <SDL3/SDL.h>
#include <string>

namespace Volt
{
    class Window
    {
    //VARIABLES
    public:
        SDL_Window* window;
        SDL_Renderer* renderer;

    //FUNCTIONS
    private:

    public:
        Window(int width, int height, const std::string& title);
        ~Window();
    };
}
