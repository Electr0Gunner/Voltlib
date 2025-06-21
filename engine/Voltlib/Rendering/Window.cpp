#include "Window.hpp"

using namespace Volt;

Window::Window(int width, int height, const std::string& title)
{
    window = SDL_CreateWindow(title.c_str(), width, height, 0);

    renderer = SDL_CreateRenderer(window, nullptr);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}