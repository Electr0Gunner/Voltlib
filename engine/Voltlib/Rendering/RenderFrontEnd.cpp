#include "RenderFrontend.hpp"
#include "Application.hpp"
#include "Renderer.hpp"
#include "Math/Rect.hpp"

void Volt::Draw(Texture* texture, float x, float y, float scaleX, float scaleY, double rotation, FPoint* center, FlipMode flipmode, Rect* cliprect, FRect* srcrect, const Color& color, DrawMode drawMode)
{
    
    Rect newClipRect;
    if (cliprect)
        newClipRect = Rect(cliprect->x, cliprect->y, cliprect->width, cliprect->height);
    else
        newClipRect = Rect(0,0, Application::Instance()->appWidth, Application::Instance()->appHeight);
    FRect newSrcRect;
    if (srcrect)
        newSrcRect = FRect(srcrect->x, srcrect->y, srcrect->width, srcrect->height);
    else
        newSrcRect = FRect(0,0, texture->width, texture->height);
    FPoint centerPoint;
    if (center)
        centerPoint = FPoint(center->x, center->y);
    else
        centerPoint = FPoint(0,0);

    Renderer::Instance()->Draw({texture->GetTexture(), FRect(x, y, (float)texture->width * scaleX, (float)texture->height * scaleY), newSrcRect, color, drawMode, newClipRect, rotation, centerPoint, flipmode});
}

void Volt::DrawLine(FPoint startPos, FPoint endPos, const Color& color, DrawMode drawMode)
{
    Renderer::Instance()->DrawLine({startPos, endPos, color, drawMode});
}

void Volt::DrawRect(FRect* rect, bool fillIn, const Color& color, DrawMode drawMode)
{
    FRect newRect;
    if (rect)
        newRect = FRect(rect->x, rect->y, rect->width, rect->height);
    else
        newRect = FRect(0,0, Application::Instance()->appWidth, Application::Instance()->appHeight);
    Renderer::Instance()->DrawRect({newRect, fillIn, color, drawMode});
}