#pragma once

#include <vector>
#include <memory>
#include "Entity.hpp"

namespace Volt
{
    static inline std::size_t nextSceneId = 0;

    class Scene
    {
    protected:
        friend class SceneManager;
        std::size_t m_ID;

    public:
        std::vector<std::unique_ptr<Entity>> m_Entities;
        bool m_Paused = false;

        Scene() : m_ID(nextSceneId++) {}
        virtual ~Scene() = default;

        virtual void Init() {}
        virtual void Start() {}
        virtual void Update() {}
        virtual void Draw() {}
        virtual void Exit() {}

        virtual void OnPause() {m_Paused = true;}
        virtual void OnResume() {m_Paused = false;}

        template<typename T, typename... Args>
        T* CreateEntity(Args&&... args) {
            auto entity = std::make_unique<T>(std::forward<Args>(args)...);
            T* ptr = entity.get();
            m_Entities.emplace_back(std::move(entity));
            return ptr;
        }
    };
} // namespace Volt
