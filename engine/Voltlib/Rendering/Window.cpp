#include "Window.hpp"

using namespace Volt;

Window::Window(int width, int height, const std::string& title)
{
    m_Window = SDL_CreateWindow(title.c_str(), width, height, 0);

    m_Renderer = SDL_CreateRenderer(m_Window, nullptr);
}

Window::~Window()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
}