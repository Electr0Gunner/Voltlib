#pragma once

#include <map>
#include <string>

namespace Volt
{
    class Texture;

    class ResourceRegistry
    {
    private:
        std::map<std::string, Texture*> m_TextureMap;
    public:
        ResourceRegistry(/* args */);
        ~ResourceRegistry();

        Texture* GetTexture(std::string id);
    };
    
} // namespace Volt
