#pragma once

#include <SDL3/SDL.h>
#include <string>

namespace Volt
{
    class Window
    {
    //VARIABLES
    public:
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;

    //FUNCTIONS
    private:

    public:
        Window(int width, int height, const std::string& title);
        ~Window();
    };
}
