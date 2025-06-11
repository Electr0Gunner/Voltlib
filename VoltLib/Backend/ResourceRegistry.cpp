#include "ResourceRegistry.hpp"
#include "Rendering/Texture.hpp"

using namespace Volt;

ResourceRegistry::ResourceRegistry(/* args */)
{
}
    
ResourceRegistry::~ResourceRegistry()
{
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