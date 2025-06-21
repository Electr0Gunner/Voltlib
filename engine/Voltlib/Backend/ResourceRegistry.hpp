#pragma once

#include <map>
#include <string>

namespace Volt
{
    enum ResRegError
    {
        ERR_NONE,
        ERR_RES_FILE_NOT_FOUND,
        ERR_INVALID_RES_FILE,
        ERR_INVALID_ID,
        ERR_IMAGE_NOT_FOUND,
    };


    class Texture;

    class ResourceRegistry
    {
    private:
        std::map<std::string, Texture*> textureMap;
    public:
        ResourceRegistry(/* args */);
        ~ResourceRegistry();

        ResRegError LoadResources(std::string resourceFilePath);
        Texture* GetTexture(std::string id);
    };
    
} // namespace Volt
