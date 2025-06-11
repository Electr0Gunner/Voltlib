#include "Texture.hpp"
#include "Renderer.hpp"

using namespace Volt;
 
Texture::Texture(/* args */)
{
}
    
Texture::~Texture()
{
    SDL_DestroyTexture(m_Texture);
}
    
void Texture::SetTexture(int width, int height, unsigned char* pixels)
{
    SDL_Surface* surface = SDL_CreateSurfaceFrom(width, height, SDL_PIXELFORMAT_RGBA8888, pixels, width * 4);

    m_Texture = SDL_CreateTextureFromSurface(g_Renderer->GetRenderer(), surface);

    SDL_DestroySurface(surface);
}

SDL_Texture* Texture::GetTexture()
{
    return m_Texture;
}