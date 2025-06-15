#include "Texture.hpp"
#include "Renderer.hpp"

using namespace Volt;
 
Texture::Texture(/* args */)
{
    m_ScaleMode = FILTER_NEAREST;
    m_Width = -1;
    m_Height = -1;
}
    
Texture::~Texture()
{
    SDL_DestroyTexture(m_Texture);
}
    
void Texture::SetTexture(int width, int height, int channelcount, unsigned char* pixels)
{
    if (m_Texture)
        SDL_DestroyTexture(m_Texture);

    SDL_PixelFormat pixelformat = channelcount == 4 ? SDL_PIXELFORMAT_RGBA32  : SDL_PIXELFORMAT_XRGB32;
    SDL_Surface* surface = SDL_CreateSurfaceFrom(width, height, pixelformat, pixels, width * 4);

    m_Texture = SDL_CreateTextureFromSurface(g_Renderer->GetRenderer(), surface);
    m_Width = width;
    m_Height = height;

    if (m_ScaleMode == FILTER_NEAREST)
        SDL_SetTextureScaleMode(m_Texture, SDL_SCALEMODE_NEAREST);
    else if (m_ScaleMode == FILTER_LINEAR)
        SDL_SetTextureScaleMode(m_Texture, SDL_SCALEMODE_LINEAR);
    else if (m_ScaleMode == FILTER_PIXELART)
        SDL_SetTextureScaleMode(m_Texture, SDL_SCALEMODE_PIXELART);

    SDL_DestroySurface(surface);
}

void Texture::SetTexture(SDL_Texture* texture)
{
    if (m_Texture)
        SDL_DestroyTexture(m_Texture);

    m_Texture = texture;

    float w,h;
    //since when image pixels are floats? is there a 100.4 by 30.2 image?
    SDL_GetTextureSize(m_Texture, &w, &h);
    
    if (m_ScaleMode == FILTER_NEAREST)
        SDL_SetTextureScaleMode(m_Texture, SDL_SCALEMODE_NEAREST);
    else if (m_ScaleMode == FILTER_LINEAR)
        SDL_SetTextureScaleMode(m_Texture, SDL_SCALEMODE_LINEAR);
    else if (m_ScaleMode == FILTER_PIXELART)
        SDL_SetTextureScaleMode(m_Texture, SDL_SCALEMODE_PIXELART);

    m_Width = (int)w;
    m_Height = (int)h;
}

SDL_Texture* Texture::GetTexture()
{
    return m_Texture;
}