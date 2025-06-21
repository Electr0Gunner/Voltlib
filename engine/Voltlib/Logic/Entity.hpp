#pragma once

#include <memory>
#include <unordered_map>
#include <typeindex>
#include "Logic/Components/Component.hpp"

namespace Volt
{
    class Scene;
    struct ColliderInfo;

    class Entity
    {
    public:
        std::unordered_map<std::type_index, std::unique_ptr<Component>> m_Components;
        Scene* parentScene;

    public:
        template <typename T, typename... Args> T* AddComponent(Args&&... args)
        {
            if (T* component = GetComponent<T>()) 
                return component;

            auto component = std::make_unique<T>(std::forward<Args>(args)...);
            component->owner = this;
            T* ptr = component.get();
            m_Components[std::type_index(typeid(T))] = std::move(component);
            return ptr;
        }
        template <typename T> T* GetComponent()
        {
            std::type_index type = typeid(T);
            auto it = m_Components.find(type);
            if (it != m_Components.end())
                return static_cast<T*>(it->second.get());
            return nullptr;
        }

        Entity(Scene* scene): parentScene(scene) {};
        virtual ~Entity() = default;

        virtual void Init()
        {
            for (auto& it: m_Components)
            {
                it.second->Init();
            }
        }
        virtual void Start() 
        {
            for (auto& it: m_Components)
            {
                it.second->Start();
            }
        }
        virtual void Update()
        {
            for (auto& it: m_Components)
            {
                it.second->Update();
            }
        }
        virtual void Draw()
        {
            for (auto& it: m_Components)
            {
                it.second->Draw();
            }
        }

        virtual void OnCollision(ColliderInfo* info) {}
    };

} // namespace Volt
