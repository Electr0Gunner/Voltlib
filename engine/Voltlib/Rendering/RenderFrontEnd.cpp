#include "RenderFrontend.hpp"
#include "App.hpp"
#include "Renderer.hpp"
#include "Math/Rect.hpp"

void Volt::Draw(Texture* texture, float x, float y, float scaleX, float scaleY, double rotation, FPoint* center, FlipMode flipmode, Rect* cliprect, FRect* srcrect, const Color& color, DrawMode drawMode)
{
    Rect newClipRect;
    if (cliprect)
        newClipRect = Rect(cliprect->x, cliprect->y, cliprect->width, cliprect->height);
    else
        newClipRect = Rect(0,0, g_App->m_Width, g_App->m_Height);
    FRect newSrcRect;
    if (srcrect)
        newSrcRect = FRect(srcrect->x, srcrect->y, srcrect->width, srcrect->height);
    else
        newSrcRect = FRect(0,0, texture->m_Width, texture->m_Height);
    FPoint centerPoint;
    if (center)
        centerPoint = FPoint(center->x, center->y);
    else
        centerPoint = FPoint(0,0);

    g_Renderer->Draw({texture->GetTexture(), FRect(x, y, (float)texture->m_Width * scaleX, (float)texture->m_Height * scaleY), newSrcRect, color, drawMode, newClipRect, rotation, centerPoint, flipmode});
}

void Volt::DrawLine(FPoint startPos, FPoint endPos, const Color& color, DrawMode drawMode)
{
    g_Renderer->DrawLine({startPos, endPos, color, drawMode});
}

void Volt::DrawRect(FRect* rect, bool fillIn, const Color& color, DrawMode drawMode)
{
    FRect newRect;
    if (rect)
        newRect = FRect(rect->x, rect->y, rect->width, rect->height);
    else
        newRect = FRect(0,0, g_App->m_Width, g_App->m_Height);
    g_Renderer->DrawRect({newRect, fillIn, color, drawMode});
}