#pragma once

#include <string>

namespace Volt
{
    struct LoadedImage
    {
        unsigned char* pixels;
        int w;
        int h;
        int channelCount;
    };

    LoadedImage LoadImage(std::string image_path, bool has_alpha_mask, std::string alpha_mask_path);
    
} // namespace Volt
