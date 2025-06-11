#pragma once

#include <SDL3/SDL.h>
namespace Volt
{
    class Texture
    {
    private:
        SDL_Texture* m_Texture;
    public:
        Texture(/* args */);
        ~Texture();

        void SetTexture(int width, int height, unsigned char* pixels);
        SDL_Texture* GetTexture();
    };

}