#pragma once

namespace Volt
{
    class Entity;

    class Component
    {
    public:
        Entity* m_Owner = nullptr;
        ~Component() = default;

        virtual void Init() {}
        virtual void Start() {}
        virtual void Update() {}
    };
} // namespace Volt
