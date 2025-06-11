#pragma once

#include <SDL3/SDL.h>
#include "Math/Vector.hpp"
#include "Math/Rect.hpp"

namespace Volt
{
    class Window;

    struct RenderBatch
    {
        SDL_Texture* texture;
        Vector2 pos;
        FRect src;
    };

    class Renderer
    {
    //VARIABLES
    private:
        SDL_Window* m_WindowBackend;
        SDL_Renderer* m_RenderBackend;
        SDL_Texture* m_RenderBuffer;


    //FUNCTIONS
    private:
        void Draw(RenderBatch batch);
    public:
        Renderer(Window* window);
        ~Renderer();

        SDL_Renderer* GetRenderer();
        SDL_Window* GetWindow();

        void Render();
    };

    extern Renderer* g_Renderer;
}
