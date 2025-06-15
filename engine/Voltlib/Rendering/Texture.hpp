#pragma once

#include <SDL3/SDL.h>
namespace Volt
{
    enum ScaleMode
    {
        FILTER_NEAREST,
        FILTER_LINEAR,
        FILTER_PIXELART,
    };

    class Texture
    {
    private:
        SDL_Texture* m_Texture;
    public:
        int m_Width;
        int m_Height;
        ScaleMode m_ScaleMode;

    public:
        Texture(/* args */);
        ~Texture();

        void SetTexture(int width, int height, int channelcount, unsigned char* pixels);
        void SetTexture(SDL_Texture* texture);
        SDL_Texture* GetTexture();
    };

}