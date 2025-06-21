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
        SDL_Texture* rawTexture;
    public:
        int width;
        int height;
        ScaleMode scaleMode;

    public:
        Texture(/* args */);
        ~Texture();

        void SetTexture(int width, int height, int channelcount, unsigned char* pixels);
        void SetTexture(SDL_Texture* texture);
        SDL_Texture* GetTexture();
    };

}