#pragma once

#include <memory>
#include <vector>
#include <assert.h>
#include "Scene.hpp"

namespace Volt
{
    class SceneManager
    {
    private:
        std::vector<std::unique_ptr<Scene>> m_Scenes;
    public:
        SceneManager();
        ~SceneManager();

        void Update();
        void Draw();
        void PauseScene(Scene* scene);
        void ResumeScene(Scene* scene);

        template <typename T, typename... Args>
        T* CreateScene(Args&&... args)
        {
            auto scene = std::make_unique<T>(std::forward<Args>(args)...);
            T* ptr = scene.get();
            scene->Init();
            scene->Start();
            assert(scene != nullptr);
            m_Scenes.emplace_back(std::move(scene));
            return ptr;
        }

        void RemoveScene(Scene* sceneToRemove);
    };

} // namespace Volt
