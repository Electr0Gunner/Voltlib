#include "Texture.hpp"
#include "Renderer.hpp"

using namespace Volt;
 
Texture::Texture(/* args */)
{
    scaleMode = FILTER_NEAREST;
    width = -1;
    height = -1;
}
    
Texture::~Texture()
{
    SDL_DestroyTexture(rawTexture);
}
    
void Texture::SetTexture(int width, int height, int channelcount, unsigned char* pixels)
{
    if (rawTexture)
        SDL_DestroyTexture(rawTexture);

    SDL_PixelFormat pixelformat = channelcount == 4 ? SDL_PIXELFORMAT_RGBA32  : SDL_PIXELFORMAT_XRGB32;
    SDL_Surface* surface = SDL_CreateSurfaceFrom(width, height, pixelformat, pixels, width * 4);

    rawTexture = SDL_CreateTextureFromSurface(Renderer::Instance()->GetRenderer(), surface);
    width = width;
    height = height;

    if (scaleMode == FILTER_NEAREST)
        SDL_SetTextureScaleMode(rawTexture, SDL_SCALEMODE_NEAREST);
    else if (scaleMode == FILTER_LINEAR)
        SDL_SetTextureScaleMode(rawTexture, SDL_SCALEMODE_LINEAR);
    else if (scaleMode == FILTER_PIXELART)
        SDL_SetTextureScaleMode(rawTexture, SDL_SCALEMODE_PIXELART);

    SDL_DestroySurface(surface);
}

void Texture::SetTexture(SDL_Texture* texture)
{
    if (rawTexture)
        SDL_DestroyTexture(rawTexture);

    rawTexture = texture;

    float w,h;
    //since when image pixels are floats? is there a 100.4 by 30.2 image?
    SDL_GetTextureSize(rawTexture, &w, &h);
    
    if (scaleMode == FILTER_NEAREST)
        SDL_SetTextureScaleMode(rawTexture, SDL_SCALEMODE_NEAREST);
    else if (scaleMode == FILTER_LINEAR)
        SDL_SetTextureScaleMode(rawTexture, SDL_SCALEMODE_LINEAR);
    else if (scaleMode == FILTER_PIXELART)
        SDL_SetTextureScaleMode(rawTexture, SDL_SCALEMODE_PIXELART);

    width = (int)w;
    height = (int)h;
}

SDL_Texture* Texture::GetTexture()
{
    return rawTexture;
}