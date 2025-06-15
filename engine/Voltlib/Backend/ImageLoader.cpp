#include "ImageLoader.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace Volt;

LoadedImage Volt::LoadImage(std::string image_path, bool has_alpha_mask, std::string alpha_mask_path)
{
    int w;
    int h;
    int comp;
    unsigned char* image = stbi_load(image_path.c_str(), &w, &h, &comp, NULL);

    return {image, w, h, comp};
}