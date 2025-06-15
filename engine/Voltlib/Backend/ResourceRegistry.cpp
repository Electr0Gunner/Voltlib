#include "ResourceRegistry.hpp"
#include "Rendering/Texture.hpp"
#include "Rendering/Renderer.hpp"
#include "ImageLoader.hpp"
#include <filesystem>
#include <fstream>
#include <json.hpp>

using namespace Volt;
namespace fs = std::filesystem;
using json = nlohmann::json;

ResourceRegistry::ResourceRegistry(/* args */)
{
}
    
ResourceRegistry::~ResourceRegistry()
{
    for (const auto entry : m_TextureMap) {
        delete entry.second;
    }
    m_TextureMap.clear();
}

Texture* ResourceRegistry::GetTexture(std::string id)
{
    Texture* texture = nullptr;

    for (const auto entry : m_TextureMap) {
        if (entry.first == id)
            texture = entry.second;
    }

    return texture;
}

ResRegError ResourceRegistry::LoadResources(std::string resourceFilePath)
{
    if (!fs::exists(resourceFilePath))
    {
        return ERR_RES_FILE_NOT_FOUND;
    }
    
    std::ifstream file(resourceFilePath);
    json resJson;
    file >> resJson;

    for (const auto& entry : resJson) {
        std::string path = entry.at("path").get<std::string>();
        std::string entryType = entry.value("type", "INVALID");
        std::string id = entry.value("id", "NULL");
        if (id == "NULL")
        {
            return ERR_INVALID_ID;
        }
        if (entryType == "img")
        {
            LoadedImage img = LoadImage(fs::absolute(fs::path("assets") / path).string(), false, "");
            if (img.pixels == nullptr)
                return ERR_IMAGE_NOT_FOUND;

            SDL_PixelFormat pixelformat = img.channelCount == 4 ? SDL_PIXELFORMAT_RGBA32  : SDL_PIXELFORMAT_XRGB32;
            SDL_Surface* originSurface = SDL_CreateSurfaceFrom(img.w, img.h, pixelformat, img.pixels, img.w * 4);
            SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface(g_Renderer->GetRenderer(), originSurface);
        
            SDL_DestroySurface(originSurface);

            Texture* texture = new Texture();

            std::string filterMode = entry.value("filtering", "linear");
            if (filterMode == "linear")
                texture->m_ScaleMode = FILTER_LINEAR;
            else if (filterMode == "nearest")
                texture->m_ScaleMode = FILTER_NEAREST;
            else if (filterMode == "pixelart")
                texture->m_ScaleMode = FILTER_PIXELART;


            texture->SetTexture(sdl_texture);

            m_TextureMap[id] = texture;
        }

    }

    return ERR_NONE;
}