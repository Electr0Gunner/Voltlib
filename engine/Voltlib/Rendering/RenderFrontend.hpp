#pragma once
#include "Texture.hpp"
#include "Renderer.hpp"
#include <optional>

namespace Volt
{
    void Draw(Texture* texture, float x,
        float y,
        float scaleX = 1.0f,
        float scaleY = 1.0f,
        double rotation = 0.0, 
        FPoint* center = nullptr, 
        FlipMode flipmode = FLIP_NONE,
        Rect* cliprect = nullptr, 
        FRect* srcrect = nullptr,
        const Color& color = Color(), 
        DrawMode drawMode = DRAW_NORMAL
    );

    void DrawLine(FPoint startPos, FPoint endPos, const Color& color = Color(), DrawMode drawMode = DRAW_NORMAL);
    void DrawRect(FRect* rect = nullptr, bool fillIn = false, const Color& color = Color(), DrawMode drawMode = DRAW_NORMAL);
}