#pragma once

#include <SDL3/SDL.h>
#include "Math/Vector.hpp"
#include "Math/Rect.hpp"
#include "Math/Point.hpp"
#include "Color.hpp"

namespace Volt
{
    enum FlipMode
    {
        FLIP_NONE,
        FLIP_HORIZONTAL,
        FLIP_VERTICAL,
        FLIP_BOTH,
    };

    enum DrawMode
    {
        DRAW_NORMAL,
        DRAW_ADDITIVE,
        DRAW_MULTIPlY,
        DRAW_MODULATE,
    };

    class Window;

    struct RenderCommand
    {
        SDL_Texture* texture;
        FRect dst;
        FRect src;
        Color color;
        DrawMode drawMode;
        Rect clip;
        double rotation;
        FPoint center;
        FlipMode flipMode;
    };

    struct LineCommand
    {
        FPoint startPos;
        FPoint endPos;
        Color color;
        DrawMode drawMode;
    };

    struct RectCommand
    {
        FRect rect;
        bool fillIn;
        Color color;
        DrawMode drawMode;
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

    public:
        Renderer(Window* window);
        ~Renderer();

        SDL_Renderer* GetRenderer();
        SDL_Window* GetWindow();

        void Render();

        
    public://Functions related to drawing images, lines, etc
        void Draw(RenderCommand command);
        void DrawLine(LineCommand command);
        void DrawRect(RectCommand command);
    };

    inline SDL_BlendMode GetBlendMode(DrawMode voltDrawMode)
    {
        switch (voltDrawMode)
        {
        case DRAW_ADDITIVE:
            return SDL_BLENDMODE_ADD;
        case DRAW_MULTIPlY:
            return SDL_BLENDMODE_MUL;
        case DRAW_MODULATE:
            return SDL_BLENDMODE_MOD;
        default:
            return SDL_BLENDMODE_BLEND;
        }
    }

    extern Renderer* g_Renderer;
}
